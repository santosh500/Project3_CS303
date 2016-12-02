#include <string>
#include <iostream>
#include <iomanip>
#include "Morse_Code.h"

using namespace std;
void MorseCode::build_encode_tree()
{
	//for encode from map, need a tree for decode
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

void MorseCode:: encode(string input)
{
	string result;
	for (int i = 1; i <= input.size(); i++)
		result += encode_map[input[i - 1]] + ' ';
	cout << result <<" ";
}

void MorseCode::buildDecodingTree()
{
	char ch;
	string code;
	for (map<char, string> ::iterator it = encode_map.begin(); it != encode_map.end(); it++) {
		ch = it->first;
		code = it->second;
		MorseCode::BinNodePointer p = root;
		for (int i = 0; i < code.length(); i++)
		{

			switch (code[i])
			{
			case '.':
				if (p->left == NULL)
					p->left = new MorseCode::BinNode('*');
				p = p->left;
				break;
			case '-':
				if (p->right == NULL)
					p->right = new MorseCode::BinNode('*');
				p = p->right;
				break;
			default:
				cerr << "*** Wrong character in code sourc file ***\n";
				exit(1);
			}
		}
		
		p->data = ch;
	}
}


void MorseCode::decode(string str)
{
	char oneBit;
	MorseCode::BinNodePointer p;
	int count = 0;
	while (count < str.size())
	{
		p = root;
		while (p->left != NULL || p->right != NULL)
		{
			if (count == str.size()) { break; }
			oneBit = str[count];
			if (oneBit == '.')
			{
				p = p->left;
				count++;
			}

			else if (oneBit == '-')
			{
				p = p->right;
				count++;
			}
			else
				cerr << "Wrong Morse Code input: " << oneBit << "\n";
		}
		cout << p->data;
	}
	return;
}