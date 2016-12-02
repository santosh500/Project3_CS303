#pragma once

#ifndef HUFFMAN
#define HUFFMAN
#include <string>
#include <map>
using namespace std;
class MorseCode
{

public:
	void build_tree(); //build the map tree for encode
	void encode(string input); //taking string input and cout the morse code tranlated from letters


private:
	map<char, string> encode_map;
	


};


#endif
