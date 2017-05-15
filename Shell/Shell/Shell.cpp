
#include "stdafx.h"
#include <iostream>
#include <string>
#include <stdio.h>
#include <ctype.h>
#include <sstream>
#include <vector>
#include <dirent.h>
#include <stdlib.h>
#include <iterator>
#include "unistd.h"
#include "Functions.h"
#include <thread>
using namespace std;



struct thread_data {
	int  thread_id;
	char *message;
};


vector<string> * split(string text,char splitter) {
	vector<string> * strings = new vector<string>();
	istringstream f(text);
	string s;

	while (getline(f, s, splitter))
	{
		strings->push_back(s);
	}
	return strings;
}

int main() {
	DIR *currentDir = NULL;
	currentDir = opendir(".");

	string sequence;

	vector<string> * elements;
	
	string oper_available;

	const char* dirInitial = "C://";
	chdir(dirInitial);
	//loop:
	while (sequence != "exit")
	{
		cout << ">";
		std::getline(std::cin, sequence);
		
		//parser
		elements = split(sequence,' ');
		
		//check if we have any operators:
		bool oper = false;
		for (int i = 0; i < elements->size(); ++i) {
			for (int j = 0; j < operators.size(); ++j)
				if ((*elements)[i] == operators[j])
				{
					oper = true;
					oper_available=operators[j];
				}
		}

		//the case where we don't have any operator:
		if (oper == false) {
			analyzer(elements, currentDir);
			continue;
		}
		//ATM: only one operator vailable per command (future improvement: more operands)
		//convert string to char to be used in switch

		char* oper_available_char = new char[oper_available.size() + 1];
		strncpy_s(oper_available_char, oper_available.size() + 1, oper_available.c_str(), oper_available.size() + 1);
		//the case where we have operators:
		
		vector<string> * elements_w_oper;
		
		switch (*oper_available_char) {
			case '&':
			{
				//multithreading of two commands
				elements_w_oper = split(sequence, '&');
				
				vector<string> * elements0 = split((*elements_w_oper)[0], ' ');
				vector<string> * elements1 = split((*elements_w_oper)[1], ' ');

				std::thread t1(analyzer,elements0,currentDir);
				std::thread t2(analyzer, elements1, currentDir);

				t1.join();
				t2.join();
				break;
			}
			case ';':
			{
				
				elements_w_oper = split(sequence, ';');

				vector<string> * elements0 = split((*elements_w_oper)[0], ' ');
				vector<string> * elements1 = split((*elements_w_oper)[1], ' ');

				analyzer(elements0, currentDir);
				analyzer(elements1, currentDir);
				break;
			}
			//conditional execution operators:
			//(NOT IMPLEMENTED YET)
			/*
			case '&&':
			{
				//the first command needs to exist in order for the 2nd command to execute
				elements_w_oper = split(sequence, '&&');

				vector<string> * elements0 = split((*elements_w_oper)[0], ' ');
				vector<string> * elements1 = split((*elements_w_oper)[1], ' ');
				bool correct = false;
				for (int i = 0; i < elements->size(); ++i)
					if (hashit((*elements)[i]) == (*elements0)[0])
						correct = true;
				if (correct)
				{
					analyzer(elements0, currentDir);
					analyzer(elements1, currentDir);
				}
				else
					cout << "first condition is faulty";

				break;
			}
			*/
		}

	}
}
