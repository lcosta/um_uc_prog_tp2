#ifndef _shop_h_
#define _shop_h_

#include <string>
#include <iostream>
#include <fstream>

#include "generic_data.h"

using namespace std;

class Shop : public GenericData {

protected:  
  int _id_pharmacy;
  int _id_drug;
  int _quantity;
  bool _comp;
  int _total_value;
  
public:

  Shop(int id ,int idPharmacy, int idDrug, string name, int quantity, bool comp, int totalValue);
  ~Shop();
  
   // START: gets and sets
	
  int getIdPharmacy() const{
  return _id_pharmacy;
  }

  int getIdDrug() const{
    return _id_drug;
  };

  int getQuantity() const{
    return _quantity;
  };

  int getTotalValue() const{
    return _total_value;
  };

  bool getComp() const{
    return _comp;
  };

  void setIdPharmacy(int id){
	  _id_pharmacy = id;
  };
  
  void setIdDrug(int id){
   _id_drug = id;
  };

  void setQuantity(int quantity){
  _quantity = quantity;
  };

  void setComp(bool comp){
  _comp = comp;
  };

  void setTotalValue(int totalValue){
  _total_value = totalValue;
  };
  

  // END: gets and sets  
  
  
  // START: methods
  void print();
  void write(std::ostream &out);
  // END: methods
  

};


//----------cpp
Shop::Shop(int id,int idPharmacy, int idDrug, string name, int quantity, bool comp, int totalValue) : GenericData(id, name)
{
	 Shop::_id_pharmacy	= idPharmacy;
	 Shop::_id_drug = idDrug;
	 Shop::_quantity = quantity;
	 Shop::_comp = comp;
	 Shop::_total_value = totalValue;
}
#endif