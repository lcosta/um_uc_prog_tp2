#ifndef _client_h_
#define _client_h_

#include <string>
#include <iostream>
#include <fstream>

#include "generic_data.h"

using namespace std;

class Client {
protected:
  int _age;
  
public:
  Client();	
  
  Client(int age);  
  ~Client();

  // START: gets and sets
  int getAge() const{
    return _age;
  };
  void setAge(int value){
    _age = value;
  };
  // END: gets and sets  
  
  
  // START: methods
  void print();
  void write(std::ostream &out);
  // END: methods
  

};

#endif