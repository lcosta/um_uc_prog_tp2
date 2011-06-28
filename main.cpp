#include <iostream>
#include <fstream>
#include <string>

#include "tree.h"
#include "tree_client.h"




#include "drug.h"
#include "varied.h"
#include "tablet.h"
#include "sachet.h"
#include "syrup.h"

#include "pharmacy.h"

#include "shop.h"
#include "client.h"


bool _run_none_test = false;

TreeClient * tree_client_db = new TreeClient();
Tree * tree_pharmacy_db = new Tree();

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

/* funcoes auxiliares */
void test_basics_structures (bool run, std::string _test_name="") {
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
      
      Client * current_client = ((Client*)get_client1);// cast
      
      int id_client = current_client->getId();
      app_print(id_client);
      
      string name_client = current_client->getName();
      app_print(name_client);
      
      int age = current_client->getAge();
      
      app_print(age);
    }
    b_tree_client_db->print(std::cout);
    
    
    
    app_print("maker - tree_drug_db...");
    
    Tree * tree_drug_db = new Tree(); // criar arvore binaria
    
    // adicionar elementos a Tree
    tree_drug_db->add(new Drug(1, "drug1", "laboratory1", 1.1, 0.15,  10, 1000) );
    tree_drug_db->add(new Drug(2, "drug2", "laboratory2", 2.2, 0.16,  20, 2000) );
    
    tree_drug_db->add(new Varied(3, "varied_drug3", "laboratory3", 3.3, 0.17, 30, 3000) );
    tree_drug_db->add(new Tablet(4, "tablet_drug4", "laboratory4", 4.4, 0.18, 40, 4000) );
    tree_drug_db->add(new Sachet(5, "sachet_drug5", "laboratory5", 4.4, 0.18, 50, 5000, 12) );
    tree_drug_db->add(new Syrup(6, "syrup_drug5", "laboratory6", 4.4, 0.18, 50, 6000, 24, 1) ); // ultimo parametro o tipo de envolucro ex. 1 = Vidro
    
    
    tree_drug_db->print(std::cout);
    
    
    
    app_print("get id, name, laboratory and stock from drug...");
    
    Drug * get_drug = (Drug*)tree_drug_db->get(6); // cast GenericData to Drug
    
    // propriedades do GenericData
    app_print(get_drug->getId());
    app_print(get_drug->getName());
    
    // propriedades do Drug
    app_print(get_drug->getLaboratory());
    app_print(get_drug->getStock());
    app_print(get_drug->getMeasure_unit());
    
    // propriedades do Sachet
    if (typeid(*get_drug) == typeid(Sachet)) { // verifica o typeid para pegar propriedade especifica.
      Sachet * current_drug = ((Sachet*)get_drug); //cast
      app_print("propriedades do Sachet - getDose");
      app_print(current_drug->getDose());
    }
    
    // propriedades do Syrup
    if (typeid(*get_drug) == typeid(Syrup)) { // verifica o typeid para pegar propriedade especifica.
      Syrup * current_drug = ((Syrup*)get_drug); //cast
      app_print("propriedades do Syrup - getDose and getTypeOfCasing");
      app_print(current_drug->getDose());
      app_print(current_drug->getTypeOfCasing(), false); app_print(" <-- tipyOfCasing");
    }
    
    /*
     if (typeid(*get_drug) == typeid(Drug)) { // verifica o typeid para pegar propriedade especifica.
     Drug * current_drug = ((Drug*)get_drug); //cast
     
     app_print(current_drug->getId());
     app_print(current_drug->getName());
     
     app_print(current_drug->getLaboratory());
     
     }
     */  
    
    //app_print(typeid(*get_drug).name);
    
    
    
    
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
      
      Shop * current_shop = ((Shop*)get_shop);  // cast para aceder aos atributos q nao s�generic data
      
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
      
      Pharmacy * current_pharm = ((Pharmacy*)get_pharm);  // cast
      
      int id_pharm		= current_pharm->getId();
      string name_pharm	= current_pharm->getName();
      
      app_print(id_pharm);
      app_print(name_pharm);
      pharm_tree->print(std::cout);//print tree [[]]
      //------------------------------------------------------------------------
      
    }
    
    
    app_print("");
    app_print("");
    
    
  }
}


void test_app_structures (bool run, std::string _test_name="") {
  if (run && !_run_none_test)
  {
    app_print(_test_name);
    app_print("");
    
    
    // pharmacy
    tree_pharmacy_db->add(new Pharmacy(1, "Farmacia Brito"));
    tree_pharmacy_db->add(new Pharmacy(2, "Farmacia Cristal"));
    tree_pharmacy_db->add(new Pharmacy(3, "Farmacia Charopinho"));
    
    app_print("show tree pharmacy");
    tree_pharmacy_db->print(std::cout);
    
    app_print("");
    app_print("get and show pharmacy with id=1");
    Pharmacy * current_pharm = ((Pharmacy*)tree_pharmacy_db->get(1));
    
    current_pharm->list(std::cout);
    
    app_print("");
    app_print("add Drugs in pharmacy tree and list tree of drugs");
    current_pharm->addDrug(new Varied(3, "varied_drug3", "laboratory3", 3.3, 0.17, 30, 3000) );
    current_pharm->addDrug(new Tablet(4, "tablet_drug4", "laboratory4", 4.4, 0.18, 40, 4000) );
    current_pharm->addDrug(new Sachet(5, "sachet_drug5", "laboratory5", 4.4, 0.18, 50, 5000, 12) );
    current_pharm->addDrug(new Syrup(6, "syrup_drug5", "laboratory6", 4.4, 0.18, 50, 6000, 24, 1) );
    
    current_pharm->listDrugs(std::cout);
    
    app_print("");
    
    // client
    
    tree_client_db->add(new Client(1, "X client 1", 10));
    tree_client_db->add(new Client(2, "C client 2", 20));
    tree_client_db->add(new Client(3, "A client 3", 30));
    
    app_print("show tree client order by name");
    tree_client_db->list(std::cout);
    
    app_print("get and show client with id=2");
    Client * current_client = ((Client*)tree_client_db->get(2));
    current_client->list(std::cout);
    
    app_print("");
    
    app_print("add shop in client with id=2 and list shops");
    current_client->addShop(new Shop(1, 1, 3, "varied_drug3", 0.15, true, 33));//(id,idPhar,idDrug,name,quantity, compart, totalValue)
    current_client->addShop(new Shop(2, 1, 4, "tablet_drug4", 0.15, true, 33));
    current_client->listShops(std::cout);
    
  }
}


int main (int argc, char * const argv[]) {
  
  _run_none_test = false;
  
  app_print("start app...", true);
  app_print("");
  
  // para activar os teste, colocar o primeiro pararametro a true
  test_basics_structures(false, "* Teste - Estruturas Basicas...\n");
  test_app_structures(true, "* Teste - Estrutura da Aplicacao...\n");
  
  
  //system("pause");
  return 0;
}








