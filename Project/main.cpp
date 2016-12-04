#include <string>
#include <cstring>
#include <sstream>
#include "Morse_Code.h"
#include "BinaryTree.h"
#include<iostream>
#include<fstream>
#include<vector>

using namespace std;
int main()
{

	
	MorseCode obj;
	string in, str;

	string choice;
	obj.build_encode_tree();
	obj.build_decode_tree();
	
	bool started = true;
	cout << "Welcome to Morse Code Translation " << endl << endl;
	while (started)
	{
		cout << "Select one of the following:" << endl << "1. From morse code to a word." << endl << "2. From word to morse code." << endl << "3. Show Morse code table"<< endl <<"4. exit" << endl;

		cin >> choice;
		if (choice == "1") //decoding
		{
			cin.ignore();
			cout << "Type the morse code " << endl;
			getline(cin, in);

			istringstream str(in);
			obj.decode(in);
			cout << endl;
			cout << endl;
		}
		else if (choice == "2") //encoding
		{
			cin.ignore();
			cout << "Type the words " << endl;
			getline(cin, in);
			istringstream str(in);
			cout << endl;
			cout << "The Morse Code is " << endl;
			while (str >> in)
			{
				obj.encode(in);
			}
			cout << endl;
			cout << endl;
		}
		else if (choice == "3") //Morse code table to check
		{
			obj.displayBinaryTreeDecode();
		}
		else if (choice == "4") //quit
		{
			cout << "Thank you for using our system, hope to see you soon!" << endl;
			system("pause");
			exit(1);

		}
		else
		{
			cout << "You must select 1, 2, 3 or 4" << endl;
			cout << endl;
		}
	}
	system("pause");
}
