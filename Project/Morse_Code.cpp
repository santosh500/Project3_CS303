#include <string>
#include <cstring>
#include <sstream>
#include <iomanip>
#include<iostream>
#include<fstream>
#include<vector>
#include "Morse_Code.h"
#include "BinaryTree.h"

using namespace std;



void MorseCode::build_encode_tree() // map for encoding
{
	encode_map['a'] = ".-";
	encode_map['b'] = "-...";
	encode_map['c'] = "-.-.";
	encode_map['d'] = "-..";
	encode_map['e'] = ".";
	encode_map['f'] = "..-.";
	encode_map['g'] = "--.";
	encode_map['h'] = "....";
	encode_map['i'] = "..";
	encode_map['j'] = ".---";
	encode_map['k'] = "-.-";
	encode_map['l'] = ".-..";
	encode_map['m'] = "--";
	encode_map['n'] = "-.";
	encode_map['o'] = "----";
	encode_map['p'] = ".--.";
	encode_map['q'] = "--.-";
	encode_map['r'] = ".-.";
	encode_map['s'] = "...";
	encode_map['t'] = "-";
	encode_map['u'] = "..-";
	encode_map['v'] = "...-";
	encode_map['w'] = ".--";
	encode_map['x'] = "-..-";
	encode_map['y'] = "-.--";
	encode_map['z'] = "--..";

}

void MorseCode::encode(string input) //print out all the result for encoding
{
	string result;
	for (int i = 1; i <= input.size(); i++)
		result += encode_map[input[i - 1]] + ' ';
	cout << result << " ";
}

void MorseCode::build_decode_tree()
{
	decode_tree = new BinaryTree();

	string line;
	ifstream myReadFile("MorseCodeInput.txt");
	int found, i = 0;
	if (myReadFile.is_open())
	{
		while (getline(myReadFile, line))
		{
			istringstream ss(line);
			string token;
			vector<string> mainVec;
			while (getline(ss, token, ','))
			{

				mainVec.push_back(token);
			}
			if (!mainVec.empty())
			{
				string k = mainVec[0];
				const char* l = k.c_str();
				Node* newNode = new Node();
				newNode->setNode(l[0], mainVec[1]);
				decode_tree->addNode(decode_tree->getTreeRoot(), newNode);
			}

		}
		myReadFile.close();

	}
}

void MorseCode::displayBinaryTreeDecode()
{
	if (decode_tree != nullptr)
	{
		decode_tree->displayTree(decode_tree->getTreeRoot());
	}
}


void MorseCode::decode(string str)
{
	vector<string> testString;
	stringstream ss(str);
	string partString;

	while (getline(ss, partString, ' '))
	{
		testString.push_back(partString);
	}

	for (int i = 0; i < testString.size(); i++)
	{
		SearchString* newSS = new SearchString();
		newSS->setCode(testString[i]);
		decode_tree->searchTree(decode_tree->getTreeRoot(), newSS);
		cout << newSS->getValue();
	}
	
}