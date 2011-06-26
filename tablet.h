#ifndef _tablet_h_
#define _tablet_h_

#include "drug.h"


class Tablet : public Drug {
protected:

  
public:

  
  Tablet(int const id,
         string const  name,
         string const  laboratory,
         float const  price,
         float const  pooling,
         int const  quantity,
         int const  stock
         );
  
  ~Tablet();

  // START: gets and sets
  // END: gets and sets  
  
  
  // START: methods
  //void print();
  //void write(std::ostream &out);
  // END: methods
  

};






Tablet::Tablet(int const id,
               string const  name,
               string const  laboratory,
               float const  price,
               float const  pooling,
               int const  quantity,
               int const  stock) : Drug(id, name, laboratory, price,
                                        pooling,
                                        quantity, stock) {
  


  // ToDo -> ERROR -> Drug::setMeasure_unit("comprimido(s)");
  
  //Drug::_measure_unit = "comprimido(s)";
}


#endif