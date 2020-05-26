#include <iostream>
#include <fstream>
#include <string>
#include <set>

#include "algo.h"

using namespace std;

int main(int argc, char* argv[])
{
	if (3!=argc)
	{
		cout << "It should be only 2 params: in and dict file names" << endl;
		return -1;
	}

	try
	{
		ifstream inFile(argv[1], ifstream::in);
		ifstream dictFile(argv[2], ifstream::in);

		// read files
		string in, out;
		inFile >> in >> out;
		cout << "in=" << in << endl << "out=" << out << endl << endl;

		// all words should contain the same count of characters
        const size_t len = in.size();
        if (out.size() != len)
        {
                cout << "in and out strings contain different count of characters" << endl;
                return -1;
		}
                
		set<string> dict;
		string word;
		cout << "Dictionary (word of the same length):" << endl;
		while (dictFile >> word)
		{
			if (word.size()==len) // insert only words with given length
			{
				dict.insert(word);
				cout << word << endl;
			}
		}
		cout << endl;
	
		// search for path
		bool ret = SearchForPath(in, out, dict);
		cout << ((ret)?"Path is found":"Path isn't found") << endl;

		inFile.close();
		dictFile.close();
	}
	catch (...)
	{
		cout << "Can't open or process some file" << endl;
	}

	return -1;
}
