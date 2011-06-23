#include "date.h"

Date::Date(){
}

Date::Date(int const d, int const m, int const y){
  day = d;
  month = m;
  year = y;
}

Date::~Date(){

}

string Date::getDate() {
  stringstream out;
  out << year << "/" << month << "/" << day;
  return out.str();
}

int Date::getDay() const {
  return day;
}

void Date::setDay(int value) {
  day = value;
}

int Date::getMonth() const {
  return month;
}

void Date::setMonth(int value) {
  month = value;
}

int Date::getYear() const {
  return year;
}

void Date::setYear(int value) {
  year = value;
}