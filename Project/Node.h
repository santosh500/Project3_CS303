#pragma once
#ifndef NODE_H
#define NODE_H
#include <iostream>
using namespace std;
class Node
{
private:
	Node* left;
	Node* right;
	char alphabet;
	string code;
	int iterationParameter;
public:
	Node();
	void setNode(char valueNode, string codeString);
	char getAlphabet();
	string getCode();
	Node* getLeft();
	Node* getRight();
	int getIterationParameter();
	void setCode(string codeNode);
	void setAlphabet(char valueNode);
	void setLeft(Node* leftNode);
	void setRight(Node* rightNode);
	void setIterationParameter(int parameter);

};
#endif
