/*
 *  b_tree.cpp
 *
 */

#include <stdlib.h>
#include <string>
#include <iostream>
#include <fstream>

#include "tree.h"





/**/

 Tree::Tree() {
 size = 0;
 root = NULL;
 }

Tree::~Tree(){  }

void Tree::add(GenericData * elem) {
	root = insert(elem, root);
	size ++;
}

TreeNode * Tree::insert(GenericData * elem, TreeNode *tree) {
	if(tree == NULL) {
		tree = new TreeNode(elem, NULL, NULL);
	}
	else {
		if(elem->getId() < tree->getElem()->getId()) {
			tree->setLeft(insert(elem, tree->getLeft()));
			if(height(tree->getLeft()) - height(tree->getRight()) > 1) {
				if(elem->getId() < tree->getLeft()->getElem()->getId()) {
          tree = singleRotateLeft(tree);
				}
				else {
					tree = doubleRotateLeft(tree);
				}
			}
		}
		else if(elem->getId() > tree->getElem()->getId()) {
			tree->setRight(insert(elem, tree->getRight()));
			if(height(tree->getRight()) - height(tree->getLeft()) > 1) {
				if(elem->getId() > tree->getRight()->getElem()->getId()) {
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

int Tree::height(TreeNode *node) const{
	int left, right;
	
	if(node==NULL)
		return 0;
	left = height(node->getLeft());
	right = height(node->getRight());
	
	if(left > right)
		return left+1;
	else
		return right+1;
}

TreeNode * Tree::singleRotateLeft(TreeNode* node){
	TreeNode *otherNode;
	
	otherNode = node->getLeft();
	node->setLeft(otherNode->getRight());
	otherNode->setRight(node);
	
	return otherNode;
}

TreeNode * Tree::singleRotateRight(TreeNode* node){
	TreeNode *otherNode;
	
	otherNode = node->getRight();
	node->setRight(otherNode->getLeft());
	otherNode->setLeft(node);
	
	return otherNode;
}

TreeNode * Tree::doubleRotateLeft(TreeNode* node){
	node->setLeft(singleRotateRight(node->getLeft()));
	return singleRotateLeft(node);
}

TreeNode * Tree::doubleRotateRight(TreeNode* node){
	node->setRight(singleRotateLeft(node->getRight()));
	return singleRotateRight(node);
}


//bool Tree::remove(GenericData * elem) {
	// TODO: remove elem
//}



bool Tree::contains(int id) const {
	return get(root, id) != NULL;
}

GenericData * Tree::get(int id) const {
	return get(root, id);
}

GenericData * Tree::get(TreeNode * tree, int id) const {
	GenericData * res = NULL;
	if(tree != NULL) {
		if (tree->getElem()->getId() == id)
			res = tree->getElem();
		else if (id > tree->getElem()->getId())
			res = get(tree->getRight(), id);
		else
			res = get(tree->getLeft(), id);
	}
	return res;
}

int Tree::getSize() const {
	return size;
}

void Tree::print(std::ostream &out) const {
	if (root != NULL) {
		printTree(root, out);
		out << std::endl;
	}
}

void Tree::printTree(TreeNode* tree, std::ostream &out) const {
	if(tree != NULL) {
		out << "[";
		printTree(tree->getLeft(), out);
		out << tree->getElem()->getId();
		printTree(tree->getRight(), out);
		out << "]";
	}
	
}

