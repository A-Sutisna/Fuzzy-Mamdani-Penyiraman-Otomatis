void fuzzySet () {

  
  // FuzzyInput suhuUdara
  FuzzyInput *suhuUdara = new FuzzyInput(1);

  suhuUdara->addFuzzySet(dingin);
  suhuUdara->addFuzzySet(normal_suhuUdara);
  suhuUdara->addFuzzySet(panas);
  fuzzy->addFuzzyInput(suhuUdara);



  // FuzzyInput kelembabanTanah
  FuzzyInput *kelembabanTanah = new FuzzyInput(2);

  kelembabanTanah->addFuzzySet(kering);
  kelembabanTanah->addFuzzySet(normal_kelembabanTanah);
  kelembabanTanah->addFuzzySet(basah);
  fuzzy->addFuzzyInput(kelembabanTanah);



  // FuzzyInput kelembabanUdara
  FuzzyInput *kelembabanUdara = new FuzzyInput(3);

  kelembabanUdara->addFuzzySet(rendah);
  kelembabanUdara->addFuzzySet(normal_kelembabanUdara);
  kelembabanUdara->addFuzzySet(tinggi);
  fuzzy->addFuzzyInput(kelembabanUdara);



  // FuzzyOutput RELAY (durasi)
  FuzzyOutput *durasi = new FuzzyOutput(1);

  durasi->addFuzzySet(sc);
  durasi->addFuzzySet(c);
  durasi->addFuzzySet(n_durasi);
  durasi->addFuzzySet(l);
  durasi->addFuzzySet(sl);
  fuzzy->addFuzzyOutput(durasi);



//  // FuzzyOutput LAMPU
//  FuzzyOutput *lampu = new FuzzyOutput(2);
//
//  lampu->addFuzzySet();
//  lampu->addFuzzySet(r);
//  lampu->addFuzzySet(n_lampu);
//  lampu->addFuzzySet(t);
//  lampu->addFuzzySet(st);
//  fuzzy->addFuzzyOutput(lampu);
  
}
