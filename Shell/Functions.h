
#include <string>
#include <iostream>
#include <filesystem>
#include <windows.h>
#include <tchar.h>
#include <stdio.h>
#include <filesystem>
#include <dirent.h>
using namespace std;
enum funct {
	help,
	ls,
	dir
};

funct hashit(string const& inString) {
	if (inString == "help") return help;
	if (inString == "ls") return ls;
	if (inString == "dir") return dir;
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
void analyze(string const& stringValue, DIR *currentDir) {
	switch (hashit(stringValue))
	{
	case dir:
		lsh_dir(currentDir);
		break;
	
	}
}
