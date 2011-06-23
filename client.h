#ifndef _client_h_
#define _client_h_

#include <string>
#include <iostream>
#include <fstream>

using namespace std;

class Client {
protected:
  int id;
  string name;
  int age;
  
public:
  Client();	
  
  Client(int const _id,
         string const  _name,
         int const _age); 
  
  ~Client();

  // START: gets and sets
  int getId() const;
  void setId(int value);
  string getName() const;
  void setName(string value);
  int getAge() const;
  void setAge(int value);
  // END: gets and sets  
  
  
  // START: methods
  void print();
  void write(std::ostream &out);
  // END: methods
  

};

#endif