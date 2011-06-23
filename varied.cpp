#include "varied.h"

Varied::Varied() : Drug() {
  
  // configure specific unit of product
  setMeasureUnit("unidade(s)");
}

Varied::Varied(int const _id,
               string const  _name,
               string const  _laboratory,
               Date const  _date,
               float const  _price,
               float const  _pooling,
               int const  _quantity,
               int const  _stock) : Drug() {
  
  setMeasureUnit("unidade(s)");
  
  setId(_id);
  setName(_name);
  setLaboratory(_laboratory);
  setExpirationDate(_date);
  setPrice(_price);
  setPooling(_pooling);
  setQuantity(_quantity);
  setStock(_stock);
  
}

Varied::~Varied() {
}

void Varied::print() {
  Drug::print();
  cout << "\t" << getQuantity() << " " <<  getMeasureUnit() << "\n";
}

void Varied::write(std::ostream &out){
  out << "varied\n";
  Drug::write(out);
}