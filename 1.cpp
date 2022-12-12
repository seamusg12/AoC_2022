#include <iostream>
#include <fstream>
#include <string>

using namespace std;

ifstream infile("input.txt");

int current = 0;
int top_three[3] = {0,0,0};
string line;

int main()
{
	while( !infile.eof() )
	{
		getline(infile,line);

		if( line.empty() )
		{
			if ( (current > top_three[0]) )
			{

				top_three[0] = current;
				sort(begin(top_three),end(top_three));
				current = 0;
			}
			else
			{
				current = 0;
			}
		}
		else
		{
			current += stoi(line);
		}

	}
	
	int total = 0;
	cout << "The three elves carrying the most calories gathered: " << endl;
	for (int i=0; i<3; i++)
	{
		cout << "	" << top_three[i] << endl;
		total += top_three[i];
	}
	cout << "calories each. Or " << total << " calories all together." << endl;
	return 0;
}


