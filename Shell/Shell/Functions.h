
#include <string>
#include <iostream>
#include <filesystem>
#include <windows.h>
#include <tchar.h>
#include <stdio.h>
#include <filesystem>
#include <dirent.h>
#include <stdlib.h>
#include <io.h>
using namespace std;
enum funct {
	help,
	mkdirfils,
	ls,
	dir
};
vector<string> operators = { ";","&","|","&&","||" };
funct hashit(string const& inString) {
	if (inString == "help") return help;
	if (inString == "ls") return ls;
	if (inString == "dir") return dir;
	if (inString == "mkdirfils") return mkdirfils;
}

void lsh_mkdir(string name) {

	string newFolder= ".\\"+name;
	
	_mkdir(newFolder.c_str());
	cout << "new folder created:" << newFolder << endl;
}
bool lsh_dir(DIR *d) {
	
	struct dirent *dir;
	d = opendir(".");
	if (d)
	{
		while ((dir = readdir(d)) != NULL)
		{
			printf("%s\n", dir->d_name);
		}
		closedir(d);
	}
	return(0);
}
void lsh_ls_back(DIR *d, DIR *newDir) {

}
void analyzer(vector<string> * elements, DIR *currentDir) {
	for (int i = 0; i < elements->size(); ++i) {
		//cout << (elements[i]) << endl;
		switch (hashit((*elements)[i]))
		{
		case dir:
		{
			lsh_dir(currentDir);
			break;
		}
		case mkdirfils: 
			if (i + 1 < elements->size())
			{
				
				lsh_mkdir((*elements)[i + 1]);
				break;

			}
			else {
				cout << "you didn't introduce a name" << endl;
				break;
			}
			/*	Do the navigation later
			case ls:
			if (i + 1 == elements.size())
			//lsh_ls_back();
			break;
			else
			{
			const char* new_elem = elements[i + 1].c_str();
			const char* final_file = strcat(dirInitial,new_elem);
			chdir(final_file);
			cout << "new dir" << dirInitial << elements[i + 1] ;
			}
			*/
		}

		/*
		for (vector<string>::iterator it = elements.begin(); it != elements.end(); it++) {
		cout << *it ;


		}
		*/
	}
}

