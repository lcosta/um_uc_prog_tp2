#include "drug.h"

Drug::Drug() {

}

Drug::~Drug() {
}

// START: gets and sets

int Drug::getId() const {
  return id;
}

void Drug::setId(int value) {
  id = value;
}

string Drug::getName() const {
  return name;
}

void Drug::setName(string value) {
  name = value;
}

string Drug::getLaboratory() const {
  return laboratory;
}

void Drug::setLaboratory(string value) {
  laboratory = value;
}

Date Drug::getExpirationDate() const {
  return expiration_date;
}

void Drug::setExpirationDate(Date value) {
  expiration_date = value;
}

float Drug::getPrice() const {
  return price;
}

float Drug::getPrice(bool w_pooling) {
  
  float p;
  if (w_pooling) {
    p = getPrice() * (1-getPooling());
  }
  else {
    p = getPrice();
  }
  
  return p;
}

void Drug::setPrice(float value) {
  price = value;
}

float Drug::getPooling() const {
  return pooling;
}

void Drug::setPooling(float value) {
  pooling = value;
}

string Drug::getMeasureUnit() const {
  return measure_unit;
}

void Drug::setMeasureUnit(string value) {
  measure_unit = value;
}

int Drug::getQuantity() const {
  return quantity;
}

void Drug::setQuantity(int value) {
  quantity = value;
}

int Drug::getStock() const {
  return stock;
}

void Drug::setStock(int value) {
  stock = value;
}

// END: gets and sets


// START: methods
void Drug::print() {
  cout << "[ID:" << getId() << "] " << getName() << " | lad:" << getLaboratory();
  cout << " | ex. date: " << getExpirationDate().getDate() << "\n";
  cout << "\t" << getPrice() << "€ | " << getPooling() * 100 << "% | stock:" << getStock() << "\n";
}

void Drug::write(std::ostream &out){
  out << getId() << "\n" << getName() << "\n" << getLaboratory() << "\n";
  out << getExpirationDate().getDay() << "\n" << getExpirationDate().getMonth() << "\n";
  out << getExpirationDate().getYear() << "\n";
  out << getPrice() << "\n" << getPooling() << "\n" << getQuantity() << "\n" << getStock() << "\n";
}
// END: methods
