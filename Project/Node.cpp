#include <string>
#include <iostream>
#include <iomanip>
#include "Node.h"

Node::Node()
{
	left = nullptr;
	right = nullptr;
	alphabet = ' ';
	code = "";
	iterationParameter = 0;
}

void Node::setNode(char valueNode, string codeString)
{
	setAlphabet(valueNode);
	setCode(codeString);
	setLeft(nullptr);
	setRight(nullptr);
	setIterationParameter(0);
}

int Node::getIterationParameter()
{
	return iterationParameter;
}

void Node::setIterationParameter(int parameter)
{
	iterationParameter = parameter;
}

char Node::getAlphabet()
{
	return alphabet;
}

string Node::getCode()
{
	return code;
}

void Node::setCode(string codeNode)
{
	code = codeNode;
}

Node* Node::getLeft()
{
	return left;
}

Node* Node::getRight()
{
	return right;
}

void Node::setAlphabet(char valueNode)
{
	alphabet = valueNode;
}

void Node::setLeft(Node* leftNode)
{
	left = leftNode;
}

void Node::setRight(Node* rightNode)
{
	right = rightNode;
}