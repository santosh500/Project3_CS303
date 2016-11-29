#pragma once

#ifndef BINARYTREE
#define BINARYTREE
#include "Node.h"
#include "SearchString.h"
#include <string>
#include <map>
using namespace std;
class BinaryTree
{
	public:
		BinaryTree();
		void add(Node* traverseNode, char charValue, string codeValue, int level);
		void printTree();
		bool isEmpty();
		Node* getTreeRoot();
		void addNode(Node* traverseNode, Node* newNode);
		void displayTree(Node* subtree);
		void searchTree(Node* traverseNode, SearchString* mainString);
	private:
		Node* treeRoot;
		int treeSize;
};


#endif
