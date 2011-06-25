#ifndef _client_h_
#define _client_h_

#include <string>
#include <iostream>
#include <fstream>

#include "generic_data.h"

using namespace std;


class Client : public GenericData {
  
protected:
  int _age;
  
  
public:
  Client(int id, string name, int age);
  
  ~Client();
  
  
  /* atributos genericos */
  
  virtual int getAge() const{ return _age; };
  virtual void setAge(int value){ _age = value; };
  
  
  
  
  /* --- */
  
  
};


Client::Client(int id, string name, int age) : GenericData(id, name){
  Client::_age = age;
};



#endif