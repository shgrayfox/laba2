#include "WORD.h"
#include <iostream>
#include <sstream>
#include <fstream>
#define ERROR_101 101
#define ERROR_102 102
using namespace std;

int main(){
	setlocale(LC_ALL, "RUS");
	stringstream ss;
	string str;
	string temp;
	WORD buff;
	ifstream fin;
	fin.open("test.txt");
	try{
		if (!fin.is_open())
			throw ERROR_101;
	}
	catch (int error){
		cout << "Такого файла не существует" << endl;
		return ERROR_101;
	}
	while (!fin.eof()){
		getline(fin, str);
		ss << str;
		while (ss >> temp){
			buff.setword(temp);
			if (buff.change())
			cout << buff << " ";
		}
		cout << endl;
		ss.clear();
	}
	try{
		if (!fin.is_open())
			throw ERROR_102;
	}
	catch (int error){
		cout << "Файл не закрыт" << endl;
		return ERROR_102;
	}
	fin.close();
	return 0;
}
