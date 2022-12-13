#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <vector>
using namespace std;

ifstream infile("4_input.txt");

int main()
{

        string line;
        int total = 0;
	int no_overlap = 0;

        while( 1 != 0 )
        {
                getline(infile,line);

		if( line.empty() )
		{
			break;
		}

		vector<char> char_line(line.begin(),line.end());
		vector<int> numbers;

		bool check = true; // check if new integer or just concatenating another digit

		string current;

		for( int i=0; i<char_line.size(); i++ )
		{
			if( char_line[i] == '-' || char_line[i] == ',' )
                        {
				check = true;       
                                numbers.push_back(stoi(current));
				current.clear();
                        }
			else if( check == true)
			{
				check = false;
				current = char_line[i];
			}
			else
			{
				current += char_line[i];

			}	
		}
		numbers.push_back(stoi(current));

		if( numbers[0] > numbers[3] || numbers[2] > numbers[1] )
		{
			no_overlap += 1;
			total += 1;
		}
		else 
		{
			total += 1;
		}
	}

	cout << "Total number of pairs with any overlap at all: " << total - no_overlap << endl;
	return 0;
}
