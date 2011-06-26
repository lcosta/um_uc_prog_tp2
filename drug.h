#ifndef _drug_h_
#define _drug_h_

#include <string>
#include <iostream>
#include <fstream>

#include "generic_data.h"

using namespace std;


class Drug : public GenericData {
  
protected:
  string _laboratory;
  float _price;
  float _pooling;
  string _measure_unit;
  int _quantity;
  int _stock;
  
  
public:
  Drug(int id, string name, 
       string laboratory, 
       float price, float pooling,
       int quantity, int stock);
  
  ~Drug();
  
  
  /* atributos drug */
  
  
  virtual string getLaboratory() const{ return _laboratory; };
  virtual void setLaboratory(string value){ _laboratory = value; };


  virtual float getPrice() const{ return _price; };
  virtual void setPrice(float value){ _price = value; };

  virtual float getPooling() const{ return _pooling; };
  virtual void setPooling(float value){ _pooling = value; };

  virtual string getMeasure_unit() const{ return _measure_unit; };
  virtual void setMeasure_unit(string value){ _measure_unit = value; };

  virtual int getQuantity() const{ return _quantity; };
  virtual void setQuantity(int value){ _quantity = value; };

  virtual int getStock() const{ return _stock; };
  virtual void setStock(int value){ _stock = value; };


  
  
  /* --- */
  
  
};


Drug::Drug(int id, string name, 
            string laboratory,
            float price, float pooling,
            int quantity, int stock
          ) : GenericData(id, name){
            
  _laboratory = laboratory;
  _price = price;
  _pooling = pooling;
  _quantity = quantity;
  _stock = stock;
  
  setMeasure_unit("unidade(s)");
};



#endif