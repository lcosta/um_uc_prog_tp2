/*
 *  tree_node.h
 *
 */


#ifndef _TREENODE_H_
#define _TREENODE_H_


#include <string>
#include <iostream>
#include <fstream>
#include "generic_data.h"

using namespace std;




class TreeNode {
private:
	GenericData *elem;
	TreeNode *left, *right;
public:
	TreeNode(GenericData * elem, TreeNode* left, TreeNode* right);
	~TreeNode();
	
	TreeNode * getLeft() const;
	TreeNode * getRight() const;
	GenericData * getElem() const;
	
	void setElem(GenericData * elem);
	void setLeft(TreeNode* left);
	void setRight(TreeNode* right);
};

#endif

