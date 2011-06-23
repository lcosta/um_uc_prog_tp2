#ifndef _varied_h_
#define _varied_h_

#include "drug.h"


class Varied : public Drug {
protected:

  
public:
  Varied();
  
  Varied(int const _id,
         string const  _name,
         string const  _laboratory,
         Date const  _date,
         float const  _price,
         float const  _pooling,
         int const  _quantity,
         int const  _stock
         );
  
  ~Varied();

  // START: gets and sets
  // END: gets and sets  
  
  
  // START: methods
  void print();
  void write(std::ostream &out);
  // END: methods
  

};

#endif