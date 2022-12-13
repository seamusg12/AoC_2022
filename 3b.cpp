#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <vector>

using namespace std;

ifstream infile("3_input.txt");

int main()
{
	string alphabet = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
	vector<char> char_alphabet(alphabet.begin(),alphabet.end());
	
	map<char,int> priority_map;
	for (int i=0; i < char_alphabet.size(); i++)
	{
		priority_map.insert( pair<char,int>(char_alphabet[i],i+1) );
	}
	

	string line1,line2,line3;
        int total = 0;
	int counter= 0;
        while( !infile.eof() )
        {
                getline(infile,line1);
		getline(infile,line2);
		getline(infile,line3);
		
		vector<char> sack1(line1.begin(),line1.end());

		for(char a: sack1)
		{
			bool found2 = ( find(line2.begin(),line2.end(),a) != line2.end());
			bool found3 = ( find(line3.begin(),line3.end(),a) != line3.end());

			if( (found2 == true) && (found3 == true) )
			{
				total += priority_map[a];
				cout << a << endl;
				break;
			}
			else
			{
				cout << "ah" << endl;
				continue;
			}
		}
        }
	cout << "Sum of priorities: " << total << endl;
        return 0;
}



