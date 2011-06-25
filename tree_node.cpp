/*
 *  tree_node.cpp
 *
 */

#include "tree_node.h"

TreeNode::TreeNode(GenericData * elem, TreeNode* left, TreeNode* right) {
	TreeNode::elem = elem;
	TreeNode::left = left;
	TreeNode::right = right;
}

TreeNode::~TreeNode() {
}

TreeNode* TreeNode::getLeft() const {
	return TreeNode::left;
}

TreeNode* TreeNode::getRight() const {
	return TreeNode::right;
}

GenericData * TreeNode::getElem() const {
	return elem;
}

void TreeNode::setElem(GenericData * elem) {
	TreeNode::elem = elem;
}

void TreeNode::setLeft(TreeNode* left) {
	TreeNode::left = left;
}

void TreeNode::setRight(TreeNode* right) {
	TreeNode::right = right;
}

