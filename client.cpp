#include "client.h"

Client::Client() {
  
}

Client::Client(int const _id, string const  _name, int const  _age){
	setId(_id);
	setName(_name);
	setAge(_age);
}

Client::~Client() {
}

int Client::getId() const {
  return id;
}

void Client::setId(int value) {
  id = value;
}

string Client::getName() const {
  return name;
}

void Client::setName(string value) {
  name = value;
}

int Client::getAge() const {
  return age;
}

void Client::setAge(int value) {
  age = value;
}

void Client::print(){
  cout << "[ID:" << getId() << "] " << getName() << " | idade: " << getAge() << "\n"; 
}

void Client::write(std::ostream &out){
  out << getId() << "\n" << getName() << "\n" << getAge() << "\n";
}