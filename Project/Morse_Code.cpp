#include <string>
#include <iostream>
#include <iomanip>
#include "Morse_Code.h"

using namespace std;

void MorseCode::build_tree()
{
	//this is the map for encode tree, need binary tree for decode
	encode_map['a'] = ".-";
	encode_map['b'] = "-...";
	encode_map['c'] = "-.-.";
	encode_map['d'] = "-..";
	encode_map['e'] = ".";
	encode_map['f'] = "..-.";
	encode_map['g'] = "--.";
	encode_map['h'] = "....";
	encode_map['i'] = "..";
	encode_map['j'] = ".-";
	encode_map['k'] = "-.-";
	encode_map['l'] = ".-..";
	encode_map['m'] = "--";
	encode_map['n'] = "-.";
	encode_map['o'] = "----";
	encode_map['p'] = ".-.";
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

void MorseCode::encode(string input)
{
	string result;
	for (int i = 1; i <= input.size(); i++)
		result += encode_map[input[i - 1]] + ' ';
	cout << result << endl;
}