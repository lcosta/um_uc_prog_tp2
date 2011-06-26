#ifndef _syrup_h_
#define _syrup_h_

#include "drug.h"


#include <fstream>
#include <iostream>

#include <string>

using namespace std;

class Syrup : public Drug {
protected:
  int _dose;
  int _type_of_casing;
  
public:
  
  
  Syrup(int const id,
         string const  name,
         string const  laboratory,
         float const  price,
         float const  pooling,
         int const  quantity,
         int const  stock,
         int dose, int type_of_casing
         );
  
  ~Syrup();
  
  // START: gets and sets
  
  virtual int getDose() const{ return _dose; };
  virtual void setDose(int value){ _dose = value; };
  
  virtual int getTypeOfCasing() const{ return _type_of_casing; };
  virtual void setTypeOfCasing(int value){ _type_of_casing = value; };

  
  // END: gets and sets  
  
  
  // START: methods
  //void print();
  //void write(std::ostream &out);
  // END: methods
  
  
};






Syrup::Syrup(int const id,
               string const  name,
               string const  laboratory,
               float const  price,
               float const  pooling,
               int const  quantity,
               int const  stock,
               int dose,
               int type_of_casing) : Drug(id, name, laboratory, price,
                                pooling,
                                quantity, stock) {
  
  setDose(dose);
  setTypeOfCasing(type_of_casing);
  // ToDo -> ERROR -> Drug::setMeasure_unit("comprimido(s)");
  
  //Drug::_measure_unit = "comprimido(s)";
}


#endif