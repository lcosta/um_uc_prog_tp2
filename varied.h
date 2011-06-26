#ifndef _varied_h_
#define _varied_h_

#include "drug.h"


class Varied : public Drug {
protected:

  
public:

  
  Varied(int const id,
         string const  name,
         string const  laboratory,
         float const  price,
         float const  pooling,
         int const  quantity,
         int const  stock
         );
  
  ~Varied();

  // START: gets and sets
  // END: gets and sets  
  
  
  // START: methods
  //void print();
  //void write(std::ostream &out);
  // END: methods
  

};






Varied::Varied(int const id,
               string const  name,
               string const  laboratory,
               float const  price,
               float const  pooling,
               int const  quantity,
               int const  stock) : Drug(id, name, laboratory, price,
                                        pooling,
                                        quantity, stock) {
  

  /*
  setId(id);
  setName(name);
  setLaboratory(laboratory);
  setPrice(price);
  setPooling(pooling);
  setQuantity(quantity);
  setStock(_stock);
   */
  
}


#endif