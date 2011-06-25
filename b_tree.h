/*
 *  b_tree.h
 *
 */

#ifndef _TREE_H_
#define _TREE_H_

#include <iostream>
#include "tree_node.h"

class Tree  {
private:
	int size;
	TreeNode * root;
public:
	Tree();
	~Tree();
	
	virtual void add(GenericData * elem);
	virtual bool remove(GenericData * elem);
	
	virtual bool contains(int id) const;
	virtual GenericData * get(int id) const;
	
	virtual int getSize() const;
	
	virtual void print(std::ostream &out) const;
	
protected:
	virtual int height(TreeNode * node) const;
	virtual TreeNode * singleRotateLeft(TreeNode* node);
	virtual TreeNode * doubleRotateLeft(TreeNode* node);
	virtual TreeNode * singleRotateRight(TreeNode* node);
	virtual TreeNode * doubleRotateRight(TreeNode* node);
  
	virtual TreeNode * insert(GenericData * elem, TreeNode * tree);
	virtual TreeNode * remove(GenericData * elem, TreeNode * tree);
	virtual GenericData * get(TreeNode * tree, int id) const;
	virtual void printTree(TreeNode* tree, std::ostream &out) const;
};
#endif
