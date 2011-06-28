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
	
	virtual void add(Client * elem);
  
	
protected:
  virtual TreeNode * insert(GenericData * elem, TreeNode * tree);
};

TreeClient::TreeClient(){
};


void TreeClient::add(Client * elem){
  Tree::add(elem);
};


TreeNode * TreeClient::insert(GenericData * elem, TreeNode *tree) {
  if(tree == NULL) {
    tree = new TreeNode(elem, NULL, NULL);
  }
  else {
    if(elem->getName() < tree->getElem()->getName()) {
      tree->setLeft(insert(elem, tree->getLeft()));
      if(height(tree->getLeft()) - height(tree->getRight()) > 1) {
        if(elem->getName() < tree->getLeft()->getElem()->getName()) {
          tree = singleRotateLeft(tree);
        }
        else {
          tree = doubleRotateLeft(tree);
        }
      }
    }
    else if(elem->getName() > tree->getElem()->getName()) {
      tree->setRight(insert(elem, tree->getRight()));
      if(height(tree->getRight()) - height(tree->getLeft()) > 1) {
        if(elem->getName() > tree->getRight()->getElem()->getName()) {
          tree = singleRotateRight(tree);
        }
        else {
          tree = doubleRotateRight(tree);
        }
      }
    }
  }
  return tree;
}



#endif