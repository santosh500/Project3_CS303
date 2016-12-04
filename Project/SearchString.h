#pragma once
#ifndef SEARCHSTRING_H
#define SEARCHSTRING_H
#include <iostream>
using namespace std;
class SearchString
{
private:
	
	string code;
	int iterationParameter;
	char value;
public:
	SearchString();
	void setValue(char val);
	char getValue();
	void setCode(string mainCode);
	string getCode();
	void setIP(int ip);
	int getIP();
};


#endif