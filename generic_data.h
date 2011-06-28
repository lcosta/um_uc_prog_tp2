/*
 *  GenericData.h
 *
 *  estrutura base para dados genérios,
 *      possibilita polimorfismo nas class. 
 *
 */

#ifndef _GENERIC_DATA_H_
#define _GENERIC_DATA_H_

#include <fstream>
#include <iostream>

#include <string>



using namespace std;

class GenericData {
  
protected:
  int _id;
  string _name;
  
  
public:
  GenericData(int id, string name){
    _id = id;
    _name = name;
  };
  
  ~GenericData(){};
  
  
  /* atributos genericos */
  
  virtual int getId() const{ return _id; };
  virtual void setId(int value){ _id = value; };
  
  virtual string getName() const{ return _name; };
  virtual void setName(string value){ _name = value; };
  
  /* --- */
  
  void list(std::ostream &out){
    out << "id: " << _id << " | " << "name: " << _name << std::endl;
  };
  
};







#endif