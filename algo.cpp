// Algorithm is placed here
// Author: Vasily Petrov
// Date: 11.07.2016
#include "algo.h"

#include <list>
#include <iostream>

using namespace std;

//
// Calculate count of different characters. The method assumes equal count of characters in words
// Return value: count of different symbols in two words
//               -1 if size of words are different
int CalculateDistance(const string& x, const string& y)
{
	if (x.size() != y.size())
		return -1;

	unsigned ret = 0;
	for (size_t i = 0; i < x.size(); ++i)
		if (x.at(i)!=y.at(i))
			++ret;

	return ret;	
}

//
// This is an internal method that searches path from words from 'in' to 'out' using dictionary 'dict'.
// chain contains words already used
// Return value: true - if path is found
//               false - if path isn't found
bool SearchForPath(const string& in, const string& out, const set<string>& dict, const list<string>& chain)
{
	if (0==in.compare(out))
	{
		cout << "Path:" << endl;
		for (list<string>::const_iterator i = chain.begin(); chain.end() != i; ++i)
			cout << "\t" << *i << endl;
		cout << endl;
		return true;
	}

	// search for the nearest words
	for (set<string>::iterator it = dict.begin(); dict.end() != it; ++it)
		// check if this transormation already exists in the chain
		if (1==CalculateDistance(in, *it)) // if not exist in chain yet after in then exten chain and recusively call SearchForPath
		{
			bool alreadyUsed = false;
			for (list<string>::const_iterator chainItem = chain.begin(); chain.end() != chainItem; ++chainItem)
				if (0==it->compare(*chainItem))
				{
					alreadyUsed = true;
					break;
				}

			if (alreadyUsed) // if we already have *it after 'in' prevously then break
				continue;

			// otherwise go futher
			list<string> chain2(chain);
			chain2.push_back(*it);
			return SearchForPath(*it, out, dict, chain2);
		}

	return false;	
}

//
// The method to search path from words from 'in' to 'out' using dictionary 'dict'.
// Return value: true - if path is found
//               false - if path isn't found
bool SearchForPath(const string& in, const string& out, const set<string>& dict)
{
	// break if dict doesn't contain in
	if (dict.end() == dict.find(in))
		return false;

	list<string> initChain;
	initChain.push_back(in);
	return SearchForPath(in, out, dict, initChain);
}
