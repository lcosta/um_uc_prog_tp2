
#include <iostream>
#include <fstream>
#include <string>

#include "tree.h"
#include "tree_client.h"
#include "client.h"
#include "shop.h"
#include "pharmacy.h"


bool _run_none_test = false;


/* funcoes utilitarias */

void app_print(string str, bool endl=true){
  std::cout << str;
  if (endl == true) cout << "\n";
};

void app_print(int number, bool endl=true){
  std::cout << number;
  if (endl == true) cout << "\n";
};

/* --- */




void test_basics_structures (bool run, string _test_name="") 
{
  if (run && !_run_none_test)
  {
    app_print(_test_name);
    
    app_print("test - GenericData class...");

    app_print("");
    
    GenericData * db = new GenericData(1, "Leonardo Costa");
    
    int id_from_db = db->getId(); 
	app_print(id_from_db, false);
    
    app_print(db->getName());
    

    app_print("");
    
    app_print("test - TreeNode class...");
    
    app_print("maker - root node");
    
    GenericData * left__generic_data = new GenericData(1, "nome 1");
    GenericData * root__generic_data = new GenericData(2, "nome 2");
    GenericData * right_generic_data = new GenericData(3, "nome 3");
    
    // tree = new TreeNode(elem, NULL, NULL)
    // TreeNode(GenericData * elem, TreeNode* left, TreeNode* right)
   /* 
    TreeNode * left__node = new TreeNode(left__generic_data, NULL, NULL);
    TreeNode * root__node = new TreeNode(root__generic_data, NULL, NULL);
    TreeNode * right_node = new TreeNode(right_generic_data, NULL, NULL);    
    */
    app_print("maker - tree");
    

	 //-----------------------------------------client tree---------------------
    
    Tree * b_tree = new Tree();
    b_tree->add(left__generic_data);
    b_tree->add(root__generic_data);
    b_tree->add(right_generic_data);
    b_tree->add(new GenericData(4, "new"));

    Client * client1 = new Client(1000, "leo", 22);
	b_tree->add(client1);    
    b_tree->print(std::cout);    
    
    app_print("\n------------------------------------------maker - tree_client");
    
    
    TreeClient * b_tree_client_db = new TreeClient();
    
    b_tree_client_db->add(new Client(1, "client 1", 10));
    b_tree_client_db->add(new Client(2, "client 2", 20));
    b_tree_client_db->add(new Client(3, "client 3", 30));
    
    GenericData * get_client1 = b_tree_client_db->get(2);
    
    
     if (typeid(*get_client1) == typeid(Client)) {
       app_print("get id, name and age from client...");
       
       Client * current_client = ((Client*)get_client1);// cast para aceder aos atributos q nao são generic data
       
       int id_client = current_client->getId();
       app_print(id_client);
       
       string name_client = current_client->getName();
       app_print(name_client);
       
       int age = current_client->getAge();
       
       app_print(age);
     }
    
    //b_tree_client_db->add(right_generic_data);
    
    b_tree_client_db->print(std::cout);

    //-----------------------------------------shop tree---------------------
	app_print("\n-------------------------------------------maker - shop tree");
	Tree * shop_tree = new Tree();
	
	Shop * shop1 = new Shop(3, 10, 11, "viagra", 100, true, 33);//(id,idPhar,idDrug,name,quantity, compart, totalValue)
	shop_tree->add(shop1);

	Shop * shop2 = new Shop(2, 20, 12, "arldite", 100, true, 34);
	shop_tree->add(shop2);

	shop_tree->add(new Shop(1, 30, 13, "cosmite", 100, true, 35));
	shop_tree->add(new Shop(4, 40, 14, "afrdite", 100, true, 36));
	shop_tree->add(new Shop(5, 50, 15, "tttdite", 100, true, 37));

	GenericData * get_shop = shop_tree->get(1); //poly.  get element with id 1

	if (typeid(* get_shop) == typeid(Shop))	
	{
		app_print("get id, name and totalValue from Shop...");
       
		Shop * current_shop = ((Shop*)get_shop);  // cast para aceder aos atributos q nao são generic data
       
		int id_shop			= current_shop->getId();
		string name_shop	= current_shop->getName();
		int totalVal		= current_shop->getTotalValue();

		app_print(id_shop);
		app_print(name_shop);
		app_print(totalVal);

		shop_tree->print(std::cout);//print tree [[]]
    }
	

	//-----------------------------------------pharmacy tree---------------------
	 
   app_print("\n-------------------------------------------maker - Pharmacy tree");
	Tree * pharm_tree = new Tree();
	
	pharm_tree->add(new Pharmacy(1, "Farmacia Brito"));
	pharm_tree->add(new Pharmacy(2, "Farmacia Cristal"));
	pharm_tree->add(new Pharmacy(3, "Farmacia Charopinho"));

	GenericData * get_pharm = pharm_tree->get(1); //poly.  get element with id 1

	if (typeid(* get_pharm) == typeid(Pharmacy))
	{
		app_print("get id, name");
       
		Pharmacy * current_pharm = ((Pharmacy*)get_pharm);  // cast para aceder aos atributos q nao são generic data
       
		int id_pharm		= current_pharm->getId();
		string name_pharm	= current_pharm->getName();
		
		app_print(id_pharm);
		app_print(name_pharm);
		pharm_tree->print(std::cout);//print tree [[]]
    //------------------------------------------------------------------------
		app_print("");
		app_print("");
		app_print("");
    
   }
  }
}


int main (int argc, char * const argv[]) {
  
  _run_none_test = false;
  
  app_print("start app...", true);
  app_print("");
  
  test_basics_structures(true, "* Teste - Estruturas Basicas...\n");
  

  
  system("pause");
  return 0;
}


