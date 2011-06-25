
#include <iostream>
#include <fstream>
#include <string>

#include "tree.h"

#include "client.h"

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

void test_basics_structures (bool run, string _test_name="") {
  if (run && !_run_none_test) {
    app_print(_test_name);
    
    app_print("test - GenericData class...");

    app_print("");
    
    GenericData * db = new GenericData(1, "Leonardo Costa");
    
    int id_from_db = db->getId(); app_print(id_from_db, false);
    
    app_print(db->getName());
    

    app_print("");
    
    app_print("test - TreeNode class...");
    
    app_print("maker - root node");
    
    GenericData * left__generic_data = new GenericData(1, "nome 1");
    GenericData * root__generic_data = new GenericData(2, "nome 2");
    GenericData * right_generic_data = new GenericData(3, "nome 3");
    
    // tree = new TreeNode(elem, NULL, NULL)
    // TreeNode(GenericData * elem, TreeNode* left, TreeNode* right)
    
    TreeNode * left__node = new TreeNode(left__generic_data, NULL, NULL);
    TreeNode * root__node = new TreeNode(root__generic_data, NULL, NULL);
    TreeNode * right_node = new TreeNode(right_generic_data, NULL, NULL);    
    
    app_print("maker - tree");
    
    
    Tree * b_tree = new Tree();
    
    b_tree->add(left__generic_data);
    b_tree->add(root__generic_data);
    b_tree->add(right_generic_data);
    
    b_tree->add(new GenericData(4, "new"));
    
    
    //Client * client1 = new Client(22);
    
    
    //b_tree->add();
    
    b_tree->print(std::cout);
    
    
    app_print("");
    app_print("");
    app_print("");
    app_print("");
    app_print("");
    app_print("");
    
  }
}

void test_x (bool run, string _test_name="") {
  if (run && !_run_none_test) {
    app_print(_test_name);
    
  }
}

int main (int argc, char * const argv[]) {
  
  _run_none_test = false;
  
  app_print("start app...", true);
  app_print("");
  
  test_basics_structures(true, "* Teste - Estruturas Basicas...\n");
  
  test_x(true, "* Teste -  X");
  
  return 0;
}


