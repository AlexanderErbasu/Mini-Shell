
#include "stdafx.h"
#include <iostream>
#include <string>
#include <stdio.h>
#include <ctype.h>
#include <sstream>
#include <vector>
#include <dirent.h>

#include "Functions.h"
using namespace std;


vector<string> split(string text) {
	vector<string> strings;
	istringstream f(text);
	string s;

	while (getline(f, s, ' ')) 
		strings.push_back(s);
	return strings;
}
int main() {
	DIR *currentDir = NULL;
	currentDir = opendir(".");

	string sequence;

	vector<string> elements;
	//loop:
	while (sequence != "exit")
	{
		cout << ">";
		cin >> sequence;
		for (int i = 0; i < sequence.size(); i++) {
			sequence.at(i) = tolower(sequence.at(i));
		}
		//parser
		elements = split(sequence);

		//transform vectors into stirings
		string *scr;
		scr = new string[elements.size()];
		for (int i = 0; i < elements.size(); i++) {
			scr[i] = elements[i];//Copy the vector to the string
		}

		for (int i = 0; i < elements.size(); i++) {
			switch (hashit(elements[i]))
			{
			case dir:
				lsh_dir(currentDir);
				break;
			
			}

			/*
			for (vector<string>::iterator it = elements.begin(); it != elements.end(); it++) {
				//cout << *it ;

				analyze(it, currentDir)
			}
			*/

		}

	}
}
