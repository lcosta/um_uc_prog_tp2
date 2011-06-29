#ifndef _pharmacy_h_
#define _pharmacy_h_

#include <string>
#include <iostream>
#include <fstream>
#include "generic_data.h"

using namespace std;


class Pharmacy : public GenericData {
  
private:
  Tree * drug_db;

public:
  Pharmacy(int id, string name);
  
  ~Pharmacy();
  
  
  /* metodos */
  void addDrug(Drug * drug);
  void listDrugs(std::ostream &out);
  Drug * getDrug(int id);
  /* --- */
};

//-----cpp
Pharmacy::Pharmacy(int id, string name) : GenericData(id, name){
  drug_db = new Tree(); // criar arvore binaria
};

void Pharmacy::addDrug(Drug * drug){
  drug_db->add(drug);
};

Drug * Pharmacy::getDrug(int id){
  return ((Drug *)drug_db->get(id));
};

void Pharmacy::listDrugs(std::ostream &out){
  drug_db->list(out);
}

#endif


