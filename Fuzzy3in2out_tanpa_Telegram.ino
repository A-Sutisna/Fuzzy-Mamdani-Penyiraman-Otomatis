//------------------------------------------------------------
//              DEKLARASI VARIABEL DAN FUNGSI
//------------------------------------------------------------

#include <Arduino.h>
#include <Wire.h>
#include <WiFi.h>
#include <Fuzzy.h>
#include <BlynkSimpleEsp32.h>


#define BLYNK_PRINT Serial
#define BLYNK_TEMPLATE_ID "TMPL6Dls-TyVo"
#define BLYNK_TEMPLATE_NAME "Mypriject"
#define BLYNK_AUTH_TOKEN "KocIGrNtJj_zs78Pmelelp-lCG3chx9V"

char auth[] = "KocIGrNtJj_zs78Pmelelp-lCG3chx9V";
//const char* ssid = "OPPO Find X2";
//const char* password = "90909099";
const char* ssid = "WIFI-2.4G-90122B";
const char* password = "A1DA776C";

//-------------  TELE -------------
#include <WiFiClientSecure.h>
#include <UniversalTelegramBot.h>
#include <ArduinoJson.h>
#define BOT_TOKEN "6433504147:AAFfJk3LCBd8-l8xpJgvAs-77zeMC-meVJY"
#define CHAT_ID "1474272939"

WiFiClientSecure secured_client;
UniversalTelegramBot bot(BOT_TOKEN, secured_client);
bool resetRequested = false; // Variabel untuk melacak apakah reset diminta


//-------------  DHT11 -------------
#include "DHT.h"
#define DHTPIN 4
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);
float humidity;
float temperature;

//-------------  LCD -------------
#include <LiquidCrystal_I2C.h>
#include <Wire.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);

//-------------  DEKALARSI PIN  -------------

float SoilValue;
float durasi;
int soilMoisturePin  = 32;
const int ledPin = 5;
const int buzzerPin = 19;
const int relayPin = 2;
//const int manualControlPin = 13;

//------------  Definisikan variabel   ----------
bool manualControl = false;
bool wifiConnected = false;
bool ledStatus = false;
bool internetConnected = false;


//-------------  FUZZY DAN SET NILAI TIAP VARIABEL -------------

Fuzzy *fuzzy = new Fuzzy();
// FuzzyInput
FuzzySet *dingin                  = new FuzzySet(0, 0, 15, 25);
FuzzySet *normal_suhuUdara        = new FuzzySet(20, 25, 25, 30);
FuzzySet *panas                   = new FuzzySet(25, 35, 60, 60);

// FuzzyInput
FuzzySet *kering                  = new FuzzySet(0, 0, 40, 60);
FuzzySet *normal_kelembabanTanah  = new FuzzySet(50, 65, 65, 80);
FuzzySet *basah                   = new FuzzySet(70, 90, 100, 100);

// FuzzyInput
FuzzySet *rendah                  = new FuzzySet(0, 0, 40, 60);
FuzzySet *normal_kelembabanUdara  = new FuzzySet(50, 60, 60, 70);
FuzzySet *tinggi                  = new FuzzySet(60, 80, 100, 100);

// FuzzyOutput
FuzzySet *sc                      = new FuzzySet(0, 0, 10, 20);   //Sangat Cepat
FuzzySet *c                       = new FuzzySet(10, 20, 20, 30); //Cepat
FuzzySet *n_durasi                = new FuzzySet(20, 30, 30, 40); //Normal
FuzzySet *l                       = new FuzzySet(30, 40, 40, 50); //Lama
FuzzySet *sl                      = new FuzzySet(40, 50, 60, 60); //Sangat Lama


//-------------  PANGGIL TAB LAIN -------------
#include "2_fuzzy_set.h"
#include "3_fuzzy_rule.h"


BLYNK_WRITE(V4) {
  int relayControl = param.asInt();
  if (relayControl == HIGH) {
    manualControl = true;  // Mengaktifkan manual kontrol saat tombol ditekan
  } else {
    manualControl = false;  // Menonaktifkan manual kontrol saat tombol dilepas
  }
}
unsigned long relayStartTime = 0; // Variabel untuk menyimpan waktu relay dinyalakan

String errorMessage;

//------------------------------------------------------------
//                        VOID SETUP
//------------------------------------------------------------

void setup()
{
  //WiFi.begin();
  Serial.begin(115200);
  Serial.println("Connecting to WiFi : ");
  Serial.print(ssid);
  Serial.print(".");
  
  //-------------  TELE -------------

  
  //---------  LCD ---------
  Wire.begin();
  lcd.begin();
  lcd.backlight();
  lcd.print("Connecting.....");
  lcd.print(".");
  lcd.setCursor(0, 1);
  lcd.print(ssid);


  //---------  DHT11 ---------
  dht.begin();
  Blynk.begin(auth, ssid, password);

  //---------  SET PINMODE ---------
  pinMode(relayPin , OUTPUT);
  pinMode(ledPin, OUTPUT);
  pinMode(soilMoisturePin , INPUT);
  pinMode(buzzerPin, OUTPUT);
  
  //---------  PANGGIL FUNGSI / FUNCTION FUZY DI TAB 2 DAN 3
  fuzzySet ();
  fuzzyRule ();
  
  secured_client.setCACert(TELEGRAM_CERTIFICATE_ROOT); 
  Serial.print("\nWiFi connected. IP address: ");
  Serial.println(WiFi.localIP());

  Serial.print("Retrieving time: ");
  configTime(0, 0, "pool.ntp.org"); // get UTC time via NTP
  time_t now = time(nullptr);
  while (now < 24 * 3600)
  {
    Serial.print(".");
    delay(100);
    now = time(nullptr);
  }
  Serial.println(now);
  bot.sendMessage(CHAT_ID, "The system is running \nStatus OFF");
}


 
//------------------------------------------------------------
//                        VOID LOOP
//------------------------------------------------------------

void loop() {

 
  static unsigned long lastMillis = 0;
  const unsigned long interval = 1000; // Interval antara pengukuran (dalam milidetik)
  float soilPercent;
  Blynk.run(); // Menjalankan Blynk


 
  unsigned long currentMillis = millis();
  if (currentMillis - lastMillis >= interval) {
    lastMillis = currentMillis;

    temperature = dht.readTemperature();
    humidity = dht.readHumidity();
    SoilValue = analogRead(soilMoisturePin );
    soilPercent = map(SoilValue, 1000, 4095, 100, 0);
   

    //---------------------
   
    Serial.println("------------------------------");
    Serial.print("Temperature ");
    Serial.print(temperature);  Serial.println(" *C");
    Serial.print("Humidity    ");
    Serial.print(humidity);     Serial.println(" %");
    Serial.print("Soil M      ");
    Serial.print(soilPercent);  Serial.println(" %");
    Serial.println("");
    //---------------------
    Serial.print("Hasil Perhitungan: ");
    Serial.print(durasi);
    Serial.println(" Detik");
    Serial.println("Status OFF");
    Serial.println("------------------------------"); 
   
    if (Blynk.connected()) {
      // Perintah untuk mengirim data ke tampilan di aplikasi Blynk
      Blynk.virtualWrite(V0, temperature);
      Blynk.virtualWrite(V1, humidity);
      Blynk.virtualWrite(V2, soilPercent);
      Blynk.virtualWrite(V3, durasi);
    }
  }

  fuzzy->setInput(1, temperature);
  fuzzy->setInput(2, humidity);
  fuzzy->setInput(3, soilPercent);
  fuzzy->fuzzify();
  durasi = fuzzy->defuzzify(1);


  // //merubah nilai float ke int
  int suhu = (temperature);
  int udara = (humidity);
  int tanah =(soilPercent);
  
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("T:");
  lcd.print(suhu); lcd.print("C ");
  lcd.print("H:");
  lcd.print(udara);// lcd.print("% ");
  lcd.print(" S:");
  lcd.print(tanah);
  lcd.print("% ");
  lcd.setCursor(0, 1);
  lcd.print("Pompa Air Mati");

 
  // Check for incoming messages
  int numNewMessages = bot.getUpdates(bot.last_message_received + 1);
  for (int i = 0; i < numNewMessages; i++) {
    String chat_id = String(bot.messages[i].chat_id);
    String text = bot.messages[i].text;

    // Check if the message contains the reset command
    if (text == "/reset") {
      // Set variabel resetRequested menjadi true
      resetRequested = true;
      String reply = "Reset Berhasil";
      bot.sendMessage(chat_id, reply);
    }
  }

  // Mengecek kondisi sensor terpasang atau tidak (error)
  if (isnan(temperature) || isnan(humidity) || isnan(soilMoisturePin)|| soilPercent < 5 ){
    Serial.println("1. Sistem Error Periksa Sensor");
    Serial.println("2. Reset Sistem");
    bot.sendMessage(CHAT_ID,"1. Sistem Error. \nKondisi berikut tidak terdeteksi atau ada kesalahan:\n");

    if (isnan(temperature)) {
      errorMessage += "- Sensor DHT11 tidak terdeteksi\n";
    }
    if (isnan(humidity)) {
      errorMessage += "- Sensor kelembaban Udara tidak terdeteksi\n";
    }
    if (isnan(soilMoisturePin)) {
      errorMessage += "- Sensor kelembaban tanah tidak terdeteksi\n";
    }
    if (soilPercent < 5) {
      errorMessage += "- Kelembaban tanah di bawah batas yang diharapkan\n";
    }
    bot.sendMessage(CHAT_ID, errorMessage);
    Serial.println();
    
  
    while (true) { // Loop akan berjalan terus menerus sampai kondisi berubah
      // Di dalam loop ini, tambahkan pengecekan pesan Telegram lagi
      int numNewMessages = bot.getUpdates(bot.last_message_received + 1);
      for (int i = 0; i < numNewMessages; i++) {
        String chat_id = String(bot.messages[i].chat_id);
        String text = bot.messages[i].text;

        // Check if the message contains the reset command
        if (text == "/reset") {
          // Set variabel resetRequested menjadi true
          resetRequested = true;
          String reply = "Perintah Reset diterima";
          bot.sendMessage(chat_id, reply);
        }
      }

      digitalWrite(buzzerPin, HIGH);
      digitalWrite(ledPin, HIGH);
      Blynk.virtualWrite(V3, HIGH);
      lcd.setCursor(0,1);
      lcd.print("Sensor Error!RST");
      delay(500);
      digitalWrite(buzzerPin, LOW);
      digitalWrite(ledPin, LOW);
      Blynk.virtualWrite(V3, LOW);
      Blynk.virtualWrite(V6, HIGH);
      delay(500);
    if (resetRequested) {
      Serial.println("Resetting ESP32...");
      ESP.restart();
    }
      // Keluar dari loop dalam jika reset diminta
      if (resetRequested) {
        break;
      }
    }
  }
  
  // Periksa koneksi internet
  if (Blynk.connected()) {  
    if (!internetConnected) {
      // Jika koneksi baru saja tersambung kembali
      // Kirim data yang diperbarui ke aplikasi Blynk
      Blynk.virtualWrite(V0, temperature);
      Blynk.virtualWrite(V1, humidity);
      Blynk.virtualWrite(V2, soilPercent);
      Blynk.virtualWrite(V3, durasi);
      internetConnected = true;
    }
  } else {
    internetConnected = false;
  }
  

// Perintah Manual Control ##############################
  if (manualControl && internetConnected) {
    bot.sendMessage(CHAT_ID, "Temperature    : "+String(temperature)+"C"+ "\nHumidity          : " +String(humidity)+"%"
    +"\nSoil Moisture   : "+String(soilPercent)+"%"+"\nKontrol manual ON");
    int detik = 0;
    while (manualControl && detik >= 0) {
      int detikSisa = detik % 60;
      humidity = dht.readHumidity();
      temperature = dht.readTemperature();
      SoilValue = analogRead(soilMoisturePin );
      soilPercent = map(SoilValue, 1000, 4095, 100, 0);
      
      Blynk.virtualWrite(V0, temperature);
      Blynk.virtualWrite(V1, humidity);
      Blynk.virtualWrite(V2, soilPercent);
      Blynk.virtualWrite(V3, durasi);
      Blynk.virtualWrite(V5, detikSisa); 
      digitalWrite(ledPin, HIGH);
      digitalWrite(relayPin, HIGH);
      Serial.println("Relay: ON");
      Serial.println("Kontrol Manual");
      
      //merubah nilai float ke int
      int suhu = (temperature);
      int udara = (humidity);
      int tanah = (soilPercent);
  
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("T:");
      lcd.print(suhu); lcd.print("C ");
      lcd.print("H:");
      lcd.print(udara);//lcd.print("% ");
      lcd.print(" S:");
      lcd.print(tanah); lcd.print("% ");
      lcd.setCursor(0, 1);
      lcd.print("Kontrol Manual  ");
      digitalWrite(buzzerPin, HIGH);
      delay(50);
      digitalWrite(buzzerPin, LOW);
      delay(550);
      Blynk.virtualWrite(V6, HIGH);  // Mengirim status relay ke pin V3 di aplikasi Blynk
      detik++;      // Kurangi 1 detik dari timer
           
      Blynk.run();  // Periksa koneksi internet
      if (!Blynk.connected()) {
        manualControl = false;
        digitalWrite(ledPin, LOW);// Matikan LED kontrol manual
        digitalWrite(relayPin, LOW);       
      }
    }
    digitalWrite(ledPin, LOW);// Matikan LED kontrol manual
    digitalWrite(relayPin, LOW);
    Blynk.virtualWrite(V5,0); 
    bot.sendMessage(CHAT_ID, "Temperature    : "+String(temperature)+"C"+ "\nHumidity          : " +String(humidity)+"%"
    +"\nSoil Moisture   : "+String(soilPercent)+"%"+"\nKontrol manual OFF");
  } else {
    if (soilPercent >= 50 && temperature <=45 ) { //########## Sistem OTOMATIS ######
      ledStatus = false;     
      digitalWrite(ledPin, LOW);
      digitalWrite(buzzerPin, LOW);
      Blynk.virtualWrite(V6, LOW);
      Blynk.virtualWrite(V4, LOW);
      Blynk.virtualWrite(V3, LOW);
    } else {
      bot.sendMessage(CHAT_ID, "Temperature   : "+String(temperature)+"C"+ "\nHumidity          : " +String(humidity)+"%"+
      "\nSoil Moisture  : "+String(soilPercent)+"%"+ "\n"+ " \nStatus ON. \nSelama\t: " + String(durasi) + " detik.");
            
      if (durasi > 0 && !ledStatus) {
        ledStatus = true;
        // Menampilkan timer mundur dari durasi
        int detik = durasi;

        digitalWrite(buzzerPin, HIGH);  // Bunyikan buzzer 1
        delay(800);                    // Bunyi buzzer selama satu detik (1000 milidetik)
        digitalWrite(buzzerPin, LOW);   // Hentikan bunyi buzzer 1
        delay(500);                     // Bunyi buzzer selama satu detik (1000 milidetik)
        digitalWrite(buzzerPin, HIGH);  // Bunyikan buzzer 2
        delay(700);                    // Bunyi buzzer selama satu detik (1000 milidetik)
        digitalWrite(buzzerPin, LOW);   // Hentikan bunyi buzzer 2


        // Tampilkan durasi Relay ON di Serial Monitor
        Serial.println("==============================");
        Serial.print("Temperature ");
        Serial.print(temperature);  Serial.println(" *C");
        Serial.print("Humidity    ");
        Serial.print(humidity);     Serial.println(" %");
        Serial.print("Soil M      ");
        Serial.print(soilPercent);  Serial.println(" %");
        Serial.println("");
        Serial.print("Status ON : ");
        Serial.print(durasi);
        Serial.println(" detik");
        Serial.println("");
        Serial.println("*****************************");

        while (detik >= 0) {
          digitalWrite(ledPin, HIGH);
          digitalWrite(relayPin, HIGH);
          Blynk.virtualWrite(V3, HIGH);
          lcd.setCursor(8, 1);
          int detikSisa = detik % 60;
          temperature = dht.readTemperature();
          humidity = dht.readHumidity();
          SoilValue = analogRead(soilMoisturePin );
          soilPercent = map(SoilValue, 1000, 4095, 100, 0);
          int tanah = (soilPercent);
          lcd.setCursor(0, 0);
          lcd.print("T:");
          lcd.print(suhu); lcd.print("C ");
          lcd.print("H:");
          lcd.print(udara); //lcd.print("% ");
          lcd.print(" S:");
          lcd.print(tanah); lcd.print("% ");
          lcd.setCursor(0,1);
          lcd.print("Menyala:");
          Blynk.virtualWrite(V0, temperature);
          Blynk.virtualWrite(V1, humidity);
          Blynk.virtualWrite(V2, soilPercent);
          Blynk.virtualWrite(V5, detikSisa);
          lcd.print(detikSisa);
          lcd.print(" detik   ");
          delay(1000);  // Tunda selama 1 detik
          detik--;      // Kurangi 1 detik dari timer
        }
        digitalWrite(buzzerPin, HIGH);  // Bunyikan Meahiri Penyiraman
        delay(500);
        digitalWrite(buzzerPin, LOW);
        digitalWrite(ledPin, LOW);
        digitalWrite(relayPin, LOW);
        Blynk.virtualWrite(V3, LOW);
        bot.sendMessage(CHAT_ID, "Temperature   : "+String(temperature)+"C"+ "\nHumidity          : " +String(humidity)+"%"+
        "\nSoil Moisture  : "+String(soilPercent)+"%"+ "\n"+ " \nStatus OFF");
        ledStatus = false;
        
        
        
      } else {
        if (ledStatus) {
          ledStatus = false;
          digitalWrite(ledPin, LOW);
          digitalWrite(relayPin, LOW);
          Blynk.virtualWrite(V3, LOW);
        }
      }
    }
    delay(1000);
  }
}
