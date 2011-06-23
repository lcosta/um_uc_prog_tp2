#include "syrup.h"

Syrup::Syrup() : Drug() {
  
  // configure specific unit of product
  setMeasureUnit("ml");
}

Syrup::Syrup(int _id,
           string _name,
           string _laboratory,
           Date _date,
           float _price,
           float _pooling,
           int _quantity,
           int _stock,

           int _dose,
           string _type_of_casing) : Drug() {
  
  setMeasureUnit("ml");
  
  setId(_id);
  setName(_name);
  setLaboratory(_laboratory);
  setExpirationDate(_date);
  setPrice(_price);
  setPooling(_pooling);
  setQuantity(_quantity);
  setStock(_stock);
  
  setDose(_dose);
  setTypeOfCasing(_type_of_casing);
  
}


Syrup::~Syrup() {
}

int Syrup::getDose() const {
  return dose;
}

void Syrup::setDose(int value) {
  dose = value;
}

string Syrup::getTypeOfCasing() const {
  return type_of_casing;
}

void Syrup::setTypeOfCasing(string value) {
  type_of_casing = value;
}

void Syrup::print() {
  Drug::print();
  cout << "\t" << getQuantity() << " x " << getDose() << getMeasureUnit() 
    << " | " << getTypeOfCasing() << "\n";
}

void Syrup::write(std::ostream &out){
  out << "syrup\n";
  Drug::write(out);
  out << getDose() << "\n";
  out << getTypeOfCasing() << "\n";
}