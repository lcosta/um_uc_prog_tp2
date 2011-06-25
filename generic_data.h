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
    
  };
  ~GenericData(){};
  
  
  /* atributos genericos */
  
  int getId() const{ return _id; };
  void setId(int value){ _id = value; };
  
  string getName() const{ return _name; };
  void setName(string value){ _name = value; };
  
  /* --- */
  
  
};




#endif