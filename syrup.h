#ifndef _syrup_h_
#define _syrup_h_

#include "drug.h"


class Syrup : public Drug {
protected:
  int dose;
  string type_of_casing;
  
public:
  Syrup();	
  Syrup( int _id,
         string const _name,
         string const _laboratory,
         Date _date,
         float const _price,
         float const _pooling,
         int const _quantity,
         int const _stock,

         int const _dose,
         string const _type_of_casing);	
  ~Syrup();

  // START: gets and sets
  int getDose() const;
  void setDose(int value);
  string getTypeOfCasing() const;
  void setTypeOfCasing(string value);
  // END: gets and sets  
  
  
  // START: methods
  void print();
  void write(std::ostream &out);
  // END: methods
  

};

#endif