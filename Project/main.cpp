#include <string>
#include <sstream>
#include "Morse_Code.h"
#include<iostream>

using namespace std;
int main()
{	
	MorseCode obj;	
	obj.build_encode_tree();
	obj.buildDecodingTree();
	

	string in, str;
	
	int choice;
	bool started = true;
	cout << "Welcom to Morse Code Translation " << endl << endl;
	while (started)
	{
		cout << "Select one of the following:" << endl << "1. From morse code to a word." << endl << "2. From word to morse code." << endl << "3. exit" << endl;

		cin >> choice;
		if (choice == 1)
		{
			cin.ignore();
			cout << "Type the morse code " << endl;
			getline(cin, in);

			istringstream str(in);
			cout << endl;
			cout << "The word is: ";
			while (str >> in)
			{
				obj.decode(in);
			}
			cout << endl;
			cout << endl;
		}
		else if (choice == 2)
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
			cout << endl;
			cout << endl;
		}

		else if (choice == 3)
		{
			cout << "Thank you for using our system, hope to see you soon!" << endl;
			system("pause");
			exit(1);
			
		}
		else
		{
			cout << "You must select 1, 2, or 3" << endl;
			cout << endl;
		}
	}
	



	
}