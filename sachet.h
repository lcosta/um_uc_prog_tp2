#ifndef _sachet_h_
#define _sachet_h_

#include "drug.h"


class Sachet : public Drug {
protected:
  int _dose;
  
public:
  
  
  Sachet(int const id,
         string const  name,
         string const  laboratory,
         float const  price,
         float const  pooling,
         int const  quantity,
         int const  stock,
         int dose
         );
  
  ~Sachet();
  
  // START: gets and sets
  
  virtual int getDose() const{ return _dose; };
  virtual void setDose(int value){ _dose = value; };

  
  // END: gets and sets  
  
  
  // START: methods
  //void print();
  //void write(std::ostream &out);
  // END: methods
  
  
};






Sachet::Sachet(int const id,
               string const  name,
               string const  laboratory,
               float const  price,
               float const  pooling,
               int const  quantity,
               int const  stock,
               int dose) : Drug(id, name, laboratory, price,
                                        pooling,
                                        quantity, stock) {
  
  
  setDose(dose);
// ToDo -> ERROR -> Drug::setMeasure_unit("comprimido(s)");
  
  //Drug::_measure_unit = "comprimido(s)";
}


#endif