
#ifndef HUFFMAN
#define HUFFMAN
#include <string>
#include <map>
using namespace std;


class MorseCode
{

public:
	MorseCode();
	
	void buildDecodingTree();	
	void decode(string str);
	void build_encode_tree();
	void encode(string input);

private:
	
	map<char, string> encode_map;

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