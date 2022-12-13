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
	

	string line;
        int total = 0;

        while( !infile.eof() )
        {
                LOOP:getline(infile,line);
                vector<char> comp1(line.begin(),line.begin() + line.size()/2);
		vector<char> comp2(line.begin() + line.size()/2,line.end());

		for(char a: comp1)
		{
			for(char b: comp2)
			{
				if( a == b )
				{
					total += priority_map[b];
					goto LOOP;
				}
			}
		}
        }
	cout << "Sum of priorities: " << total << endl;
        return 0;
}



