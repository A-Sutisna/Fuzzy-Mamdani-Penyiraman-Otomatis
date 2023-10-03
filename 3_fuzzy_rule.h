void fuzzyRule () {
  
  // Building FuzzyRule////////////////////////////////////////////////////////////////// 1
  FuzzyRuleAntecedent *dingin_kering_1 = new FuzzyRuleAntecedent();
  dingin_kering_1->joinWithAND(dingin, kering);

  FuzzyRuleAntecedent *c_rendah = new FuzzyRuleAntecedent();
  c_rendah->joinSingle(rendah);

  FuzzyRuleAntecedent *dingin_kering_rendah_1 = new FuzzyRuleAntecedent();
  dingin_kering_rendah_1->joinWithAND(dingin_kering_1, c_rendah);

  FuzzyRuleConsequent *c_1 = new FuzzyRuleConsequent();
  c_1->addOutput(c);
//  c_t_1->addOutput(t);

  FuzzyRule *fuzzyRule1 = new FuzzyRule(1, dingin_kering_rendah_1, c_1);
  fuzzy->addFuzzyRule(fuzzyRule1);

  // Building FuzzyRule////////////////////////////////////////////////////////////////// 2
  FuzzyRuleAntecedent *dingin_kering_2 = new FuzzyRuleAntecedent();
  dingin_kering_2->joinWithAND(dingin, kering);

  FuzzyRuleAntecedent *c_normal_kelembabanUdara = new FuzzyRuleAntecedent();
  c_normal_kelembabanUdara->joinSingle(normal_kelembabanUdara);

  FuzzyRuleAntecedent *dingin_kering_normal_kelembabanUdara_2 = new FuzzyRuleAntecedent();
  dingin_kering_normal_kelembabanUdara_2->joinWithAND(dingin_kering_2, c_normal_kelembabanUdara);

  FuzzyRuleConsequent *c_2 = new FuzzyRuleConsequent();
  c_2->addOutput(c);
  //c_2->addOutput();

  FuzzyRule *fuzzyRule2 = new FuzzyRule(2, dingin_kering_normal_kelembabanUdara_2, c_2);
  fuzzy->addFuzzyRule(fuzzyRule2);

  // Building FuzzyRule////////////////////////////////////////////////////////////////// 3
  FuzzyRuleAntecedent *dingin_kering_3 = new FuzzyRuleAntecedent();
  dingin_kering_3->joinWithAND(dingin, kering);

  FuzzyRuleAntecedent *c_tinggi = new FuzzyRuleAntecedent();
  c_tinggi->joinSingle(tinggi);

  FuzzyRuleAntecedent *dingin_kering_tinggi_3 = new FuzzyRuleAntecedent();
  dingin_kering_tinggi_3->joinWithAND(dingin_kering_3, c_tinggi);

  FuzzyRuleConsequent *c_3 = new FuzzyRuleConsequent();
  c_3->addOutput(c);
 // c_3->addOutput(r);

  FuzzyRule *fuzzyRule3 = new FuzzyRule(3, dingin_kering_tinggi_3, c_3);
  fuzzy->addFuzzyRule(fuzzyRule3);

  // Building FuzzyRule////////////////////////////////////////////////////////////////// 4
  FuzzyRuleAntecedent *dingin_normal_kelembabanTanah_4 = new FuzzyRuleAntecedent();
  dingin_normal_kelembabanTanah_4->joinWithAND(dingin, normal_kelembabanTanah);

  FuzzyRuleAntecedent *dingin_normal_kelembabanTanah_rendah_4 = new FuzzyRuleAntecedent();
  dingin_normal_kelembabanTanah_rendah_4->joinWithAND(dingin_normal_kelembabanTanah_4, c_rendah);

  FuzzyRuleConsequent *sc_4 = new FuzzyRuleConsequent();
  sc_4->addOutput(sc);
  //sc_4->addOutput(t);

  FuzzyRule *fuzzyRule4 = new FuzzyRule(4, dingin_normal_kelembabanTanah_rendah_4, sc_4);
  fuzzy->addFuzzyRule(fuzzyRule4);

  // Building FuzzyRule////////////////////////////////////////////////////////////////// 5
  FuzzyRuleAntecedent *dingin_normal_kelembabanTanah_5 = new FuzzyRuleAntecedent();
  dingin_normal_kelembabanTanah_5->joinWithAND(dingin, normal_kelembabanTanah);

  FuzzyRuleAntecedent *dingin_normal_kelembabanTanah_normal_kelembabanUdara_5 = new FuzzyRuleAntecedent();
  dingin_normal_kelembabanTanah_normal_kelembabanUdara_5->joinWithAND(dingin_normal_kelembabanTanah_5, c_normal_kelembabanUdara);

  FuzzyRuleConsequent *sc_5 = new FuzzyRuleConsequent();
  sc_5->addOutput(sc);
  //sc_5->addOutput();

  FuzzyRule *fuzzyRule5 = new FuzzyRule(5, dingin_normal_kelembabanTanah_normal_kelembabanUdara_5, sc_5);
  fuzzy->addFuzzyRule(fuzzyRule5);

  // Building FuzzyRule////////////////////////////////////////////////////////////////// 6
  FuzzyRuleAntecedent *dingin_normal_kelembabanTanah_6 = new FuzzyRuleAntecedent();
  dingin_normal_kelembabanTanah_6->joinWithAND(dingin, normal_kelembabanTanah);

  FuzzyRuleAntecedent *dingin_normal_kelembabanTanah_tinggi_6 = new FuzzyRuleAntecedent();
  dingin_normal_kelembabanTanah_tinggi_6->joinWithAND(dingin_normal_kelembabanTanah_6, c_tinggi);

  FuzzyRuleConsequent *sc_6 = new FuzzyRuleConsequent();
  sc_6->addOutput(sc);
  //sc_r_6->addOutput(r);

  FuzzyRule *fuzzyRule6 = new FuzzyRule(6, dingin_normal_kelembabanTanah_tinggi_6, sc_6);
  fuzzy->addFuzzyRule(fuzzyRule6);

  // Building FuzzyRule////////////////////////////////////////////////////////////////// 7
  FuzzyRuleAntecedent *dingin_basah_7 = new FuzzyRuleAntecedent();
  dingin_basah_7->joinWithAND(dingin, basah);

  FuzzyRuleAntecedent *dingin_basah_rendah_7 = new FuzzyRuleAntecedent();
  dingin_basah_rendah_7->joinWithAND(dingin_basah_7, c_rendah);

  FuzzyRuleConsequent *sc_7 = new FuzzyRuleConsequent();
  sc_7->addOutput(sc);
  //sc_7->addOutput();

  FuzzyRule *fuzzyRule7 = new FuzzyRule(7, dingin_basah_rendah_7, sc_7);
  fuzzy->addFuzzyRule(fuzzyRule7);

  // Building FuzzyRule////////////////////////////////////////////////////////////////// 8
  FuzzyRuleAntecedent *dingin_basah_8 = new FuzzyRuleAntecedent();
  dingin_basah_8->joinWithAND(dingin, basah);

  FuzzyRuleAntecedent *dingin_basah_normal_kelembabanUdara_8 = new FuzzyRuleAntecedent();
  dingin_basah_normal_kelembabanUdara_8->joinWithAND(dingin_basah_8, c_normal_kelembabanUdara);

  FuzzyRuleConsequent *sc_8 = new FuzzyRuleConsequent();
  sc_8->addOutput(sc);
  //sc_t_8->addOutput(t);

  FuzzyRule *fuzzyRule8 = new FuzzyRule(8, dingin_basah_normal_kelembabanUdara_8, sc_8);
  fuzzy->addFuzzyRule(fuzzyRule8);

  // Building FuzzyRule////////////////////////////////////////////////////////////////// 9
  FuzzyRuleAntecedent *dingin_basah_9 = new FuzzyRuleAntecedent();
  dingin_basah_9->joinWithAND(dingin, basah);

  FuzzyRuleAntecedent *dingin_basah_tinggi_9 = new FuzzyRuleAntecedent();
  dingin_basah_tinggi_9->joinWithAND(dingin_basah_9, c_tinggi);

  FuzzyRuleConsequent *sc_9 = new FuzzyRuleConsequent();
  sc_9->addOutput(sc);
  //sc_9->addOutput();

  FuzzyRule *fuzzyRule9 = new FuzzyRule(9, dingin_basah_tinggi_9, sc_9);
  fuzzy->addFuzzyRule(fuzzyRule9);

  // Building FuzzyRule////////////////////////////////////////////////////////////////// 10
  FuzzyRuleAntecedent *normal_suhuUdara_kering_10 = new FuzzyRuleAntecedent();
  normal_suhuUdara_kering_10->joinWithAND(normal_suhuUdara, kering);

  FuzzyRuleAntecedent *normal_suhuUdara_kering_rendah_10 = new FuzzyRuleAntecedent();
  normal_suhuUdara_kering_rendah_10->joinWithAND(normal_suhuUdara_kering_10, c_rendah);

  FuzzyRuleConsequent *n_durasi_10 = new FuzzyRuleConsequent();
  n_durasi_10->addOutput(n_durasi);
//  n_durasi_10->addOutput();

  FuzzyRule *fuzzyRule10 = new FuzzyRule(10, normal_suhuUdara_kering_rendah_10, n_durasi_10);
  fuzzy->addFuzzyRule(fuzzyRule10);

  // Building FuzzyRule////////////////////////////////////////////////////////////////// 11
  FuzzyRuleAntecedent *normal_suhuUdara_kering_11 = new FuzzyRuleAntecedent();
  normal_suhuUdara_kering_11->joinWithAND(normal_suhuUdara, kering);

  FuzzyRuleAntecedent *normal_suhuUdara_kering_normal_kelembabanUdara_11 = new FuzzyRuleAntecedent();
  normal_suhuUdara_kering_normal_kelembabanUdara_11->joinWithAND(normal_suhuUdara_kering_11, c_normal_kelembabanUdara);

  FuzzyRuleConsequent *n_durasi_11 = new FuzzyRuleConsequent();
  n_durasi_11->addOutput(n_durasi);
 // n_durasi_11->addOutput(r);

  FuzzyRule *fuzzyRule11 = new FuzzyRule(11, normal_suhuUdara_kering_normal_kelembabanUdara_11, n_durasi_11);
  fuzzy->addFuzzyRule(fuzzyRule11);

  // Building FuzzyRule////////////////////////////////////////////////////////////////// 12
  FuzzyRuleAntecedent *normal_suhuUdara_kering_12 = new FuzzyRuleAntecedent();
  normal_suhuUdara_kering_12->joinWithAND(normal_suhuUdara, kering);

  FuzzyRuleAntecedent *normal_suhuUdara_kering_tinggi_12 = new FuzzyRuleAntecedent();
  normal_suhuUdara_kering_tinggi_12->joinWithAND(normal_suhuUdara_kering_12, c_tinggi);

  FuzzyRuleConsequent *n_durasi_12 = new FuzzyRuleConsequent();
  n_durasi_12->addOutput(n_durasi);
//  n_durasi_12->addOutput();

  FuzzyRule *fuzzyRule12 = new FuzzyRule(12, normal_suhuUdara_kering_tinggi_12, n_durasi_12);
  fuzzy->addFuzzyRule(fuzzyRule12);

  // Building FuzzyRule////////////////////////////////////////////////////////////////// 13
  FuzzyRuleAntecedent *normal_suhuUdara_normal_kelembabanTanah_13 = new FuzzyRuleAntecedent();
  normal_suhuUdara_normal_kelembabanTanah_13->joinWithAND(normal_suhuUdara, normal_kelembabanTanah);
  
  FuzzyRuleAntecedent *normal_suhuUdara_normal_kelembabanTanah_rendah_13 = new FuzzyRuleAntecedent();
  normal_suhuUdara_normal_kelembabanTanah_rendah_13->joinWithAND(normal_suhuUdara_normal_kelembabanTanah_13, c_rendah);

  FuzzyRuleConsequent *sc_13 = new FuzzyRuleConsequent();
  sc_13->addOutput(sc);
//  sc_13->addOutput();

  FuzzyRule *fuzzyRule13 = new FuzzyRule(13, normal_suhuUdara_normal_kelembabanTanah_rendah_13, sc_13);
  fuzzy->addFuzzyRule(fuzzyRule13);

  // Building FuzzyRule////////////////////////////////////////////////////////////////// 14
  FuzzyRuleAntecedent *normal_suhuUdara_normal_kelembabanTanah_14 = new FuzzyRuleAntecedent();
  normal_suhuUdara_normal_kelembabanTanah_14->joinWithAND(normal_suhuUdara, normal_kelembabanTanah);

  FuzzyRuleAntecedent *normal_suhuUdara_normal_kelembabanTanah_normal_kelembabanUdara_14 = new FuzzyRuleAntecedent();
  normal_suhuUdara_normal_kelembabanTanah_normal_kelembabanUdara_14->joinWithAND(normal_suhuUdara_normal_kelembabanTanah_14, c_normal_kelembabanUdara );

  FuzzyRuleConsequent *sc_14 = new FuzzyRuleConsequent();
  sc_14->addOutput(sc);
//  sc_14->addOutput();

  FuzzyRule *fuzzyRule14 = new FuzzyRule(14, normal_suhuUdara_normal_kelembabanTanah_normal_kelembabanUdara_14, sc_14);
  fuzzy->addFuzzyRule(fuzzyRule14);

  // Building FuzzyRule////////////////////////////////////////////////////////////////// 15
  FuzzyRuleAntecedent *normal_suhuUdara_normal_kelembabanTanah_15 = new FuzzyRuleAntecedent();
  normal_suhuUdara_normal_kelembabanTanah_15->joinWithAND(normal_suhuUdara, normal_kelembabanTanah);

  FuzzyRuleAntecedent *normal_suhuUdara_normal_kelembabanTanah_tinggi_15 = new FuzzyRuleAntecedent();
  normal_suhuUdara_normal_kelembabanTanah_tinggi_15->joinWithAND(normal_suhuUdara_normal_kelembabanTanah_15, c_tinggi);

  FuzzyRuleConsequent *sc_15 = new FuzzyRuleConsequent();
  sc_15->addOutput(sc);
//  sc_15->addOutput();

  FuzzyRule *fuzzyRule15 = new FuzzyRule(15, normal_suhuUdara_normal_kelembabanTanah_tinggi_15, sc_15);
  fuzzy->addFuzzyRule(fuzzyRule15);

  // Building FuzzyRule////////////////////////////////////////////////////////////////// 16
  FuzzyRuleAntecedent *normal_suhuUdara_basah_16 = new FuzzyRuleAntecedent();
  normal_suhuUdara_basah_16->joinWithAND(normal_suhuUdara, basah);

  FuzzyRuleAntecedent *normal_suhuUdara_basah_rendah_16 = new FuzzyRuleAntecedent();
  normal_suhuUdara_basah_rendah_16->joinWithAND(normal_suhuUdara_basah_16, c_rendah);

  FuzzyRuleConsequent *sc_16 = new FuzzyRuleConsequent();
  sc_16->addOutput(sc);
//  sc_16->addOutput();

  FuzzyRule *fuzzyRule16 = new FuzzyRule(16, normal_suhuUdara_basah_rendah_16, sc_16);
  fuzzy->addFuzzyRule(fuzzyRule16);

  // Building FuzzyRule////////////////////////////////////////////////////////////////// 17
  FuzzyRuleAntecedent *normal_suhuUdara_basah_17 = new FuzzyRuleAntecedent();
  normal_suhuUdara_basah_17->joinWithAND(normal_suhuUdara, basah);

  FuzzyRuleAntecedent *normal_suhuUdara_basah_normal_kelembabanUdara_17 = new FuzzyRuleAntecedent();
  normal_suhuUdara_basah_normal_kelembabanUdara_17->joinWithAND(normal_suhuUdara_basah_17, c_normal_kelembabanUdara);

  FuzzyRuleConsequent *sc_17 = new FuzzyRuleConsequent();
  sc_17->addOutput(sc);
//  sc_r_17->addOutput(r);

  FuzzyRule *fuzzyRule17 = new FuzzyRule(17, normal_suhuUdara_basah_normal_kelembabanUdara_17, sc_17);
  fuzzy->addFuzzyRule(fuzzyRule17);

  // Building FuzzyRule////////////////////////////////////////////////////////////////// 18
  FuzzyRuleAntecedent *normal_suhuUdara_basah_18 = new FuzzyRuleAntecedent();
  normal_suhuUdara_basah_18->joinWithAND(normal_suhuUdara, basah);

  FuzzyRuleAntecedent *normal_suhuUdara_basah_tinggi_18 = new FuzzyRuleAntecedent();
  normal_suhuUdara_basah_tinggi_18->joinWithAND(normal_suhuUdara_basah_18, c_tinggi);

  FuzzyRuleConsequent *sc_18 = new FuzzyRuleConsequent();
  sc_18->addOutput(sc);
//  sc_18->addOutput();

  FuzzyRule *fuzzyRule18 = new FuzzyRule(18, normal_suhuUdara_basah_tinggi_18, sc_18);
  fuzzy->addFuzzyRule(fuzzyRule18);

  // Building FuzzyRule////////////////////////////////////////////////////////////////// 19
  FuzzyRuleAntecedent *panas_kering_19 = new FuzzyRuleAntecedent();
  panas_kering_19->joinWithAND(panas, kering);

  FuzzyRuleAntecedent *panas_kering_rendah_19 = new FuzzyRuleAntecedent();
  panas_kering_rendah_19->joinWithAND(panas_kering_19, c_rendah);

  FuzzyRuleConsequent *s_r_19 = new FuzzyRuleConsequent();
  s_r_19->addOutput(sl);
//  s_r_19->addOutput(r);

  FuzzyRule *fuzzyRule19 = new FuzzyRule(19, panas_kering_rendah_19, s_r_19);
  fuzzy->addFuzzyRule(fuzzyRule19);

  // Building FuzzyRule////////////////////////////////////////////////////////////////// 20
  FuzzyRuleAntecedent *panas_kering_20 = new FuzzyRuleAntecedent();
  panas_kering_20->joinWithAND(panas, kering);

  FuzzyRuleAntecedent *panas_kering_normal_kelembabanUdara_20 = new FuzzyRuleAntecedent();
  panas_kering_normal_kelembabanUdara_20->joinWithAND(panas_kering_20, c_normal_kelembabanUdara);

  FuzzyRuleConsequent *s_20 = new FuzzyRuleConsequent();
  s_20->addOutput(sl);
//  s_20->addOutput();

  FuzzyRule *fuzzyRule20 = new FuzzyRule(20, panas_kering_normal_kelembabanUdara_20, s_20);
  fuzzy->addFuzzyRule(fuzzyRule20);

  // Building FuzzyRule////////////////////////////////////////////////////////////////// 21
  FuzzyRuleAntecedent *panas_kering_21 = new FuzzyRuleAntecedent();
  panas_kering_21->joinWithAND(panas, kering);

  FuzzyRuleAntecedent *panas_kering_tinggi_21 = new FuzzyRuleAntecedent();
  panas_kering_tinggi_21->joinWithAND(panas_kering_21, c_tinggi);

  FuzzyRuleConsequent *s_21 = new FuzzyRuleConsequent();
  s_21->addOutput(sl);
//  s_21->addOutput();

  FuzzyRule *fuzzyRule21 = new FuzzyRule(21, panas_kering_tinggi_21, s_21);
  fuzzy->addFuzzyRule(fuzzyRule21);

  // Building FuzzyRule////////////////////////////////////////////////////////////////// 22
  FuzzyRuleAntecedent *panas_normal_kelembabanTanah_22 = new FuzzyRuleAntecedent();
  panas_normal_kelembabanTanah_22->joinWithAND(panas, normal_kelembabanTanah);

  FuzzyRuleAntecedent *panas_normal_kelembabanTanah_rendah_22 = new FuzzyRuleAntecedent();
  panas_normal_kelembabanTanah_rendah_22->joinWithAND(panas_normal_kelembabanTanah_22, c_rendah);

  FuzzyRuleConsequent *l_22 = new FuzzyRuleConsequent();
  l_22->addOutput(l);
//  _t_22->addOutput(t);

  FuzzyRule *fuzzyRule22 = new FuzzyRule(22, panas_normal_kelembabanTanah_rendah_22, l_22);
  fuzzy->addFuzzyRule(fuzzyRule22);

  // Building FuzzyRule////////////////////////////////////////////////////////////////// 23
  FuzzyRuleAntecedent *panas_normal_kelembabanTanah_23 = new FuzzyRuleAntecedent();
  panas_normal_kelembabanTanah_23->joinWithAND(panas, normal_kelembabanTanah);

  FuzzyRuleAntecedent *panas_normal_kelembabanTanah_normal_kelembabanUdara_23 = new FuzzyRuleAntecedent();
  panas_normal_kelembabanTanah_normal_kelembabanUdara_23->joinWithAND(panas_normal_kelembabanTanah_23, c_normal_kelembabanUdara);

  FuzzyRuleConsequent *l_23 = new FuzzyRuleConsequent();
  l_23->addOutput(l);
//  _r_23->addOutput(r);

  FuzzyRule *fuzzyRule23 = new FuzzyRule(23, panas_normal_kelembabanTanah_normal_kelembabanUdara_23, l_23);
  fuzzy->addFuzzyRule(fuzzyRule23);

  // Building FuzzyRule////////////////////////////////////////////////////////////////// 24
  FuzzyRuleAntecedent *panas_normal_kelembabanTanah_24 = new FuzzyRuleAntecedent();
  panas_normal_kelembabanTanah_24->joinWithAND(panas, normal_kelembabanTanah);

  FuzzyRuleAntecedent *panas_normal_kelembabanTanah_tinggi_24 = new FuzzyRuleAntecedent();
  panas_normal_kelembabanTanah_tinggi_24->joinWithAND(panas_normal_kelembabanTanah_24, c_tinggi);

  FuzzyRuleConsequent *_24 = new FuzzyRuleConsequent();
  _24->addOutput(l);
//  _24->addOutput();

  FuzzyRule *fuzzyRule24 = new FuzzyRule(24, panas_normal_kelembabanTanah_tinggi_24, _24);
  fuzzy->addFuzzyRule(fuzzyRule24);

  // Building FuzzyRule////////////////////////////////////////////////////////////////// 25
  FuzzyRuleAntecedent *panas_basah_25 = new FuzzyRuleAntecedent();
  panas_basah_25->joinWithAND(panas, basah);

  FuzzyRuleAntecedent *panas_basah_rendah_25 = new FuzzyRuleAntecedent();
  panas_basah_rendah_25->joinWithAND(panas_basah_25, c_rendah);

  FuzzyRuleConsequent *n_durasi_25 = new FuzzyRuleConsequent();
  n_durasi_25->addOutput(n_durasi);
//  n_durasi_25->addOutput();

  FuzzyRule *fuzzyRule25 = new FuzzyRule(25, panas_basah_rendah_25, n_durasi_25);
  fuzzy->addFuzzyRule(fuzzyRule25);

  // Building FuzzyRule////////////////////////////////////////////////////////////////// 26
  FuzzyRuleAntecedent *panas_basah_26 = new FuzzyRuleAntecedent();
  panas_basah_26->joinWithAND(panas, basah);

  FuzzyRuleAntecedent *panas_basah_normal_kelembabanUdara_26 = new FuzzyRuleAntecedent();
  panas_basah_normal_kelembabanUdara_26->joinWithAND(panas_basah_26, c_normal_kelembabanUdara);

  FuzzyRuleConsequent *n_durasi_26 = new FuzzyRuleConsequent();
  n_durasi_26->addOutput(n_durasi);
//  n_durasi_t_26->addOutput(t);

  FuzzyRule *fuzzyRule26 = new FuzzyRule(26, panas_basah_normal_kelembabanUdara_26, n_durasi_26);
  fuzzy->addFuzzyRule(fuzzyRule26);

  // Building FuzzyRule////////////////////////////////////////////////////////////////// 27
  FuzzyRuleAntecedent *panas_basah_27 = new FuzzyRuleAntecedent();
  panas_basah_27->joinWithAND(panas, basah);

  FuzzyRuleAntecedent *panas_basah_tinggi_27 = new FuzzyRuleAntecedent();
  panas_basah_tinggi_27->joinWithAND(panas_basah_27, c_tinggi);

  FuzzyRuleConsequent *n_durasi_27 = new FuzzyRuleConsequent();
  n_durasi_27->addOutput(n_durasi);
//  n_durasi_27->addOutput(r);

  FuzzyRule *fuzzyRule27 = new FuzzyRule(27, panas_basah_tinggi_27, n_durasi_27);
  fuzzy->addFuzzyRule(fuzzyRule27);

  }
