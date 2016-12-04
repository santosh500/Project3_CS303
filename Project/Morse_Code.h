#pragma once

#ifndef HUFFMAN
#define HUFFMAN
#include <string>
#include <map>
#include "BinaryTree.h"
using namespace std;
class MorseCode
{

public:
	MorseCode();
	
	void build_decode_tree();	
	void decode(string str);
	void build_encode_tree();
	void encode(string input);
	void displayBinaryTreeDecode();

private:
	
	map<char, string> encode_map;
	BinaryTree* decode_tree;
	class BinNode
	{
	public:
		char data;
		BinNode * left,
			*right;
		BinNode(char item)
		{
			data = item;
			left = right = 0;
		}
	};

	typedef BinNode * BinNodePointer;
	BinNodePointer root;
	
	
	
	
	
};
inline MorseCode::MorseCode()
{
	root = new BinNode('*');
}

#endif
