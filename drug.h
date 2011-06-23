#ifndef _drug_h_
#define _drug_h_

#include <string>
#include <iostream>
#include <fstream>
#include "date.h"

using namespace std;

class Drug {
protected:
  int id;
  string name;
  string laboratory;
  Date expiration_date;
  float price;
  float pooling;
  string measure_unit;
  int quantity;
  int stock;
  
  // only children accesses
  virtual void setMeasureUnit(string value);
  
public:
  Drug();
  ~Drug();

  // START: gets and sets
  virtual int getId() const;
  virtual void setId(int value);

  virtual string getName() const;
  virtual void setName(string value);
  
  virtual string getLaboratory() const;
  virtual void setLaboratory(string value);
  
  virtual Date getExpirationDate() const;
  virtual void setExpirationDate(Date value);
  
  virtual float getPrice() const;
  virtual float getPrice(bool w_pooling);
  virtual void setPrice(float value);
  
  virtual float getPooling() const;
  virtual void setPooling(float value);
  
  virtual string getMeasureUnit() const;
  
  virtual int getQuantity() const;
  virtual void setQuantity(int value);
  
  virtual int getStock() const;
  virtual void setStock(int value);
  // END: gets and sets  
  
  
  // START: methods
  virtual void print();
  virtual void write(std::ostream &out);
  // END: methods
  
};

#endif