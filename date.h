#ifndef _date_h_
#define _date_h_

#include <sstream>

using namespace std;

class Date {
protected:
  int day;
  int month;
  int year;
  
public:
  Date(int const d, int const m, int const y);
  Date();
  ~Date();
  
  int getDay() const;
  void setDay(int value);
  
  int getMonth() const;
  void setMonth(int value);
  
  int getYear() const;
  void setYear(int value);
  
  string getDate();
  
};


#endif