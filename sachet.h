#ifndef _sachet_h_
#define _sachet_h_

#include "drug.h"


class Sachet : public Drug {
protected:
  int dose;
  
public:
  Sachet();
  
  Sachet(int const _id,
         string const  _name,
         string const  _laboratory,
         Date const  _date,
         float const  _price,
         float const  _pooling,
         int const  _quantity,
         int const  _stock,

         int const  _dose
         );	
  ~Sachet();

  // START: gets and sets
  int getDose() const;
  void setDose(int value);
  // END: gets and sets  
  
  // START: methods
  void print();
  void write(std::ostream &out);
  // END: methods

};

#endif