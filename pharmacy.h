#ifndef _pharmacy_h_
#define _pharmacy_h_

#include <string>
#include <iostream>
#include <fstream>
#include "generic_data.h"

using namespace std;


class Pharmacy : public GenericData {
  
protected:

public:
  Pharmacy(int id, string name);
  
  ~Pharmacy();
  
  
  /* atributos genericos */
  
  /* --- */
};

//-----cpp
Pharmacy::Pharmacy(int id, string name) : GenericData(id, name){
  
};



#endif