#include "lexer.h"
#include <vector>
#include <iostream>
#include <string>
using namespace std;

int* scanLine(string inputLine)
{
	vector<int> inputVec;
	for (char& c : inputLine)
	{
		inputVec.push(c);
	}

	for (std::vector<int>::iterator i = inoutVec.begin(); i != in.end(); ++i)
	{
		cout << *i << endl;
	}
}
