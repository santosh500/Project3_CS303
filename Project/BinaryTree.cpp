#include <string>
#include <cstring>
#include <iostream>
#include <iomanip>
#include "BinaryTree.h"
#include "SearchString.h"

BinaryTree::BinaryTree()
{
	treeRoot = nullptr;
	treeSize = 0;
}

bool BinaryTree::isEmpty()

{
	bool empt = true;
	if (treeSize > 0)
	{
		empt = false;
	}
	return empt;
}

void BinaryTree::searchTree(Node* traverseNode, SearchString* mainString)
{
	string q = mainString->getCode();
	char* superString = (char*)q.c_str();

	if ((mainString->getCode().length() == mainString->getIP()))
	{
		mainString->setValue(traverseNode->getAlphabet());
	}
	else
	{
		if (superString[mainString->getIP()] == '.')
		{
			if (traverseNode->getLeft() != nullptr && (mainString->getCode().length() - 1 >= mainString->getIP()))
			{
				mainString->setIP(mainString->getIP() + 1);
				searchTree(traverseNode->getLeft(), mainString);
			}
		}
		else if (superString[mainString->getIP()] == '-')
		{
			if (traverseNode->getRight() != nullptr && (mainString->getCode().length() - 1 >= mainString->getIP()))
			{
				mainString->setIP(mainString->getIP() + 1);
				searchTree(traverseNode->getRight(), mainString);
			}
		}
	}

	
}


Node* BinaryTree::getTreeRoot()
{
	return treeRoot;
}

void BinaryTree::displayTree(Node* subtree)
{
	if (subtree->getLeft() == nullptr && subtree->getRight() == nullptr)
	{
		cout << "Value: " << subtree->getAlphabet() << ",String: " << subtree->getCode() << ", Left Node: null, Right Node: null" <<endl;

	}
	else if (subtree->getLeft() != nullptr && subtree->getRight() == nullptr)
	{
		cout << "Value: " << subtree->getAlphabet() << ",String: " << subtree->getCode() << ", Left Node: " << subtree->getLeft()->getAlphabet() << ", Right node: null" << endl;
	}
	else
	{
		cout << "Value: " << subtree->getAlphabet() << ",String: " << subtree->getCode() << ", Left Node: " << subtree->getLeft()->getAlphabet() << ", Right node: " << subtree->getRight()->getAlphabet() << endl;
	}

	if (subtree->getLeft() != nullptr)
	{
		displayTree(subtree->getLeft());
	}
	if (subtree->getRight() != nullptr)
	{
		displayTree(subtree->getRight());
	}
}

void BinaryTree::addNode(Node* traverseNode, Node* newNode)
{
	if (isEmpty())
	{
		treeRoot = new Node();
		traverseNode = treeRoot;
		treeRoot->setNode(' ', "");
	}
	string v = newNode->getCode();
	char* superString =(char*)v.c_str();
	
	if (superString[newNode->getIterationParameter()] == '.')
	{
		if (traverseNode->getLeft() != nullptr)
		{
			newNode->setIterationParameter(newNode->getIterationParameter() + 1);
			addNode(traverseNode->getLeft(), newNode);
		}
		else
		{
			treeSize++;
			traverseNode->setLeft(newNode);
		}

	}
	else if (superString[newNode->getIterationParameter()] == '-')
	{
		if (traverseNode->getRight() != nullptr)
		{
			newNode->setIterationParameter(newNode->getIterationParameter() + 1);
			addNode(traverseNode->getRight(), newNode);
		}
		else
		{
			treeSize++;
			traverseNode->setRight(newNode);
		}
	}
}

void BinaryTree::add(Node* traverseNode,char charValue, string codeValue, int level)
{
	const char *superString = codeValue.c_str();
	if (isEmpty())
	{
		Node* newNode = new Node();
		newNode->setCode(codeValue);
		newNode->setAlphabet(charValue);
		newNode->setLeft(nullptr);
		newNode->setRight(nullptr);
		treeRoot = newNode;
	}
	else
	{
		if (superString[level] == '.' && traverseNode->getRight()!= nullptr)
		{
			level++;
			add(traverseNode->getRight(),charValue, codeValue, level);
		}
		if (superString[level] == '-' && traverseNode->getLeft() != nullptr)
		{	level++;
			add(traverseNode->getLeft(), charValue, codeValue, level);
		}
		
	
		Node* newNode = new Node();
		newNode->setCode(codeValue);
		newNode->setAlphabet(charValue);
		newNode->setLeft(nullptr);
		newNode->setRight(nullptr);
		treeRoot = newNode;
	}


	treeSize++;
}

void BinaryTree::printTree()
{
	cout << treeRoot->getAlphabet() << endl;
	cout << treeRoot->getCode() << endl;
}