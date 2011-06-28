#ifndef _client_h_
#define _client_h_

#include <string>
#include <iostream>
#include <fstream>

#include "generic_data.h"
#include "shop.h"

using namespace std;


class Client : public GenericData {
  
protected:
  Tree * shop_db;
  
  int _age;
  
  
public:
  Client(int id, string name, int age);
  
  ~Client();
  
  
  /* atributos genericos */
  
  virtual int getAge() const{ return _age; };
  virtual void setAge(int value){ _age = value; };  
  /* --- */
  
  /* metodos */
  void addShop(Shop * shop);
  void listShops(std::ostream &out);
  /* --- */
  
};


Client::Client(int id, string name, int age) : GenericData(id, name){
  shop_db = new Tree();
  Client::_age = age;
};

void Client::addShop(Shop * shop){
  shop_db->add(shop);
};

void Client::listShops(std::ostream &out){
  shop_db->list(out);
}

#endif