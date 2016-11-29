#include <string>
#include <iostream>
#include <iomanip>
#include "SearchString.h"

SearchString::SearchString()
{
	iterationParameter = 0;
	code = "";
	value = ' ';
}

void SearchString::setValue(char val)
{
	value = val;
}

char SearchString::getValue()
{
	return value;
}

void SearchString::setCode(string mainCode)
{
	code = mainCode;
}

string SearchString::getCode()
{
	return code;
}

void SearchString::setIP(int ip)
{
	iterationParameter = ip;
}

int SearchString::getIP()
{
	return iterationParameter;
}
