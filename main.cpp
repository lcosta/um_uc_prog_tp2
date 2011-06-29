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
Pharmacy * current_pharm;
Client * current_client;
Drug * current_drug;


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


void printMenuMain();
void printMenuOptions();
void printMenuDrugs();

string getString(string msg){
  string s;
  
  cout << msg;
  getline (cin,s);
  
  if (s.length() == 0) {
    cout << "\nintroduza um nome valido.\n";
    return getString(msg);
  }
  
  return s;
}

int getInt(string msg){
  int i;
  
  cout << msg;
  cin >> i;
  
  if (i <= 0) {
    cout << "\nintroduza um valor maior que 0.\n";
    return getInt(msg);
  }
  
  return i;
}

float getFloat(string msg){
  float i;
  
  cout << msg;
  cin >> i;
  
  if (i <= 0) {
    cout << "\nintroduza um valor maior que 0.\n";
    return getInt(msg);
  }
  
  return i;
}



int main (int argc, char * const argv[]) {
  
  _run_none_test = false;
  
  app_print("start app...", true);
  app_print("");
  
  // para activar os teste, colocar o primeiro pararametro a true
  //test_basics_structures(false, "* Teste - Estruturas Basicas...\n");
  //test_app_structures(true, "* Teste - Estrutura da Aplicacao...\n");
  
  
  //system("pause");
  
  // menus
  
  bool run = true;
	int opt;
	int id, age_in;
	string nome;
	int opt_phar, stock_in, quantaty_in, dose_in, type_of_casing_in;
	string name_in;
  string laboratory_in;
  float price_in, pooling_in;
  
  
	int go_to = -1;
  
  while(run) 
	{
    if(go_to != -1)
		{
			opt_phar = go_to;
			go_to = -1;
		}
		else 
		{
			printMenuMain();
			cin >> opt_phar;
		}
    
		switch (opt_phar) 
		{
        
      case 1: // Criar Farmacia
        //opt_phar = getInt("Indique o cÛdigo da farm·cia? ");
        
        
        id = getInt("introduza o ID da farmacia: ");
        cin.ignore();
        name_in = getString("introduza o nome da farmacia: ");
        
        tree_pharmacy_db->add(new Pharmacy(id, name_in));
        app_print("show tree pharmacy");
        tree_pharmacy_db->list(std::cout);
        
        break;
        
      case 2: // Abrir Farmacia
        cout << "Escolha o ID da Farmacia a abrir:\n";
        //cin >> opt_phar;
        opt_phar = getInt("");
        current_pharm = ((Pharmacy*)tree_pharmacy_db->get(opt_phar));
        current_pharm->list(std::cout);
        // cin.ignore();
        go_to = 3;
        break;
        
      case 5: // Listar Farmacia
        tree_pharmacy_db->list(std::cout);
        go_to = 3;
        break;
        
      case 3: // Menu opcoes
        
        printMenuOptions();
        cin >> opt;
        cin.ignore();
        go_to = 3;
        
        switch (opt) 
			{
				case 0:// Editar Farmacia
          
          tree_pharmacy_db->list(std::cout);
          
          id = getInt("Digite o id da farmacia a editar: ");
          
          current_pharm = ((Pharmacy*)tree_pharmacy_db->get(id));
          cin.ignore();
          name_in = getString("introduza o novo nome da farmacia: ");
          
          current_pharm->setName(name_in);
          
          current_pharm->list(std::cout);
          
					break;
          
				case 1:// Inserir medicamento
					printMenuDrugs();

					cin >> opt;

          
          cin.ignore();
          id = getInt("Informe uma ID: ");
          cin.ignore();
          name_in = getString("Introduza um nome: ");
          laboratory_in = getString("Introduza um laboratorio ");
          price_in = getFloat("Introduza o preco: ");
          cin.ignore();
          pooling_in = getFloat("Introduza o valor da comparticipacao: ");
          cin.ignore();
          stock_in = getInt("Introduza o stock: ");
          cin.ignore();
          quantaty_in = getInt("Introduza a quantidade por embalagem: ");
          cin.ignore();
          
          
          switch (opt) 
          {
            case 1:// Comprimido
              current_pharm->addDrug(new Tablet(id, name_in, laboratory_in, price_in, pooling_in, 
                                               quantaty_in, stock_in) );
             break;  
              
            case 2:// Xarope
              dose_in = getInt("Introduza a dozagem: ");
              cin.ignore();
              type_of_casing_in = getInt("Introduza o id do tipo de embalagem");
              current_pharm->addDrug(new Syrup(id, name_in, laboratory_in, price_in, pooling_in, 
                                               quantaty_in, stock_in, dose_in, type_of_casing_in) );
              break;  
              
            case 3:// Saquetas
              dose_in = getInt("Introduza a dozagem: ");
              current_pharm->addDrug(new Sachet(id, name_in, laboratory_in, price_in, pooling_in, 
                                               quantaty_in, stock_in, dose_in) );
              break;  
              
            case 4:// Outros
              current_pharm->addDrug(new Varied(id, name_in, laboratory_in, price_in, pooling_in, 
                                               quantaty_in, stock_in) );
              break;  
          }
            
          
          current_pharm->listDrugs(std::cout);
          
          
					if (go_to == -1) 
						run = false;
					break;
          
				case 2:// Inserir cliente
					cout << endl;
					id = getInt("ID do cliente? ");
          cin.ignore();
          name_in = getString("Nome do cliente? ");
          age_in = getInt("Idade do cliente? ");
          cin.ignore();
          
          tree_client_db->add(new Client(id, name_in, age_in));
          
          tree_client_db->list(cout);
          
					cout << endl;
					break;
          
				case 3:// Listar medicamneto
					cout << endl;
          current_pharm->listDrugs(cout);
          cout << endl;
					break;
          
				case 4:// Listar cliente
					cout << endl;
          tree_client_db->list(cout);
					cout << endl;
					break;
          
				case 5:// Listar medicamentos vendido(s)
          id = getInt("Informe um ID do cliente para consultar suas compras: ");
          cin.ignore();
          cout << endl;
          
          current_client = ((Client*)tree_client_db->get(id));
          current_client->listShops(cout);
          cout << endl;
          
					break;
          
				case 6:// Editar medicamento
					cout << endl;
					cout << endl;
					break;
          
				case 7:// Editar cliente
					cout << endl;
					id = getInt("ID do cliente a editar? ");
          cin.ignore();
          
          current_client = ((Client *)tree_client_db->get(id));
          current_client->list(cout);
          
          name_in = getString("Novo nome do cliente? ");
          age_in = getInt("Nova idade do cliente? ");
          cin.ignore();
      
          current_client->setName(name_in);
          current_client->setAge(age_in);
          
          current_client->list(cout);
          
					cout << endl;
					break;
          
				case 8:// Vender medicamento
					
          current_pharm = ((Pharmacy *)tree_pharmacy_db->get(getInt("Informe o Id da Farmacia: ")));
          
          current_client = ((Client *)tree_client_db->get(getInt("Informe o Id do Cliente: ")));
          
          current_drug = current_pharm->getDrug(getInt("Id do medicamento"));
          
          opt = getInt("Quantos: ");
          
          current_client->addShop(new Shop(getInt("id compra") ,current_pharm->getId(), current_drug->getId() , current_drug->getName(), 
                                           opt, getInt("1 - comparticipado\n0 - nao comparticipado"), current_drug->getPrice() * opt ));

          
          
          
          break;
          
				
          
				case 10:// Menu principal 
					go_to = -1;
					break;
          
				case 11: // Sair
					run = false;
					break;
          
				default:
					cout << endl;
					cout << "Tente novamente..." << endl;
					break;
			}
        break;
        
      case 4:// Sair 
        run = false;
        break;
      default:cout << "Tente novamente..." << endl;
        break;
		}
	}
  
  return 0;
}




void printMenuMain() {
  cout << endl << endl;
  cout << " **** Menu Principal ****" << endl;
  cout << "|----------------------|" << endl;
  cout << "|  1 - Criar Farmacia  |" << endl;
  cout << "|  2 - Abrir Farmacia  |" << endl;
  cout << "|  5 - Lista Farmacia  |" << endl;
  cout << "|  3 - Menu Opcoes     |" << endl;
  cout << "|  4 - Sair            |" << endl;
  cout << " ---------------------- " << endl;
  cout << "digite a opcao? " << endl;
}

void printMenuOptions() {
  cout << endl << endl;
  cout << " ***********  Menu Opcoes  ********** " << endl;
  cout << "|************************************|" << endl;
  cout << "| 0  - Editar farmacia               |" << endl;
  cout << "| 1  - Inserir medicamento           |" << endl;
  cout << "| 2  - Inserir cliente               |" << endl;
  cout << "| 3  - Listar medicamento(s)         |" << endl;
  cout << "| 4  - Listar cliente(s)             |" << endl;
  cout << "| 5  - Listar medicamentos vendido(s)|" << endl;
  cout << "| 6  - Editar medicamento            |" << endl;
  cout << "| 7  - Editar cliente                |" << endl;
  cout << "| 8  - Vender Medicamento            |" << endl;
  cout << "| 10 - Menu Principal                |" << endl;
  cout << "| 11 - Sair                          |" << endl;
  cout << " ************************************ " << endl;
  cout << "digite a opcao? " << endl;
}

void printMenuDrugs() {
  cout << endl << endl;
  cout << "**Menu Tipo de Medicamento***" << endl;
  cout << "|---------------------------|" << endl;
  cout << "|   1 - Comprimido          |" << endl;
  cout << "|   2 - Xarope              |" << endl;
  cout << "|   3 - Saquetas            |" << endl;
  cout << "|   4 - Outros              |" << endl;
  cout << "|   5 - Voltar              |" << endl;
  cout << "|   6 - Sair                |" << endl;
  cout << " --------------------------- " << endl;
  cout << "digite a opcao? " << endl;
}




