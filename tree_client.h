/*
 *  tree_client.h
 */

#ifndef _TREE_CLIENT_H_
#define _TREE_CLIENT_H_

#include <string>
#include <iostream>
#include <fstream>



#include "tree.h"
#include "client.h"

using namespace std;


class TreeClient : public Tree {
  
private:
	int size;
	TreeNode * root;
  
public:
	TreeClient();
	~TreeClient(){};
	
	virtual void add(Client * elem){
    Tree::add(elem);
  };
	
protected:
  
};

TreeClient::TreeClient(){
};


#endif