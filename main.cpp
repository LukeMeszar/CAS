#include <iostream>
#include <string>
#include "lexer.h"
using namespace std;

int main()
{
	cout << "Input function you want to evaluate: " << endl;
	string funtionInput; 
	getline(cin, funtionInput);
	cout << funtionInput << endl;
	scanLine(funtionInput);
}