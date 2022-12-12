#include <iostream>
#include <fstream>
#include <string>
#include <map>

using namespace std;

ifstream infile("input.txt");


map<string,int> pts_map = {
	{ "A X", 3 },
	{ "A Y", 4 },
	{ "A Z", 8 },
	{ "B X", 1 },
	{ "B Y", 5 },
	{ "B Z", 9 },
	{ "C X", 2 },
	{ "C Y", 6 },
	{ "C Z", 7 } };

string line; 
int main()
{
	int total = 0;
        while( !infile.eof() )
        {
                getline(infile,line);
		total += pts_map[line];
	}
	cout << "Total score using strategy sheet: " << total << endl;
	return 0;
}
	



