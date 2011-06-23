#include "tablet.h"

Tablet::Tablet() : Drug() {
  
  // configure specific unit of product
  setMeasureUnit("comprimidos(s)");
}

Tablet::Tablet(int const _id,
               string const  _name,
               string const  _laboratory,
               Date const  _date,
               float const  _price,
               float const  _pooling,
               int const  _quantity,
               int const  _stock) : Drug() {
  
  setMeasureUnit("comprimidos(s)");
  
  setId(_id);
  setName(_name);
  setLaboratory(_laboratory);
  setExpirationDate(_date);
  setPrice(_price);
  setPooling(_pooling);
  setQuantity(_quantity);
  setStock(_stock);
  
}

Tablet::~Tablet() {
}

void Tablet::print() {
  Drug::print();
  cout << "\t" << getQuantity() << " " <<  getMeasureUnit() << "\n";
}

void Tablet::write(std::ostream &out){
  out << "tablet\n";
  Drug::write(out);
}