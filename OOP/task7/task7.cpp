/**
* @file	task2.cpp
* @brief	C++ source of the app that displays the contents of a text file
*
*
* Copyright 2014 by mnxoid,
*
* This software is the confidential and proprietary information
* of mnxoid ("Confidential Information").  You
* shall not disclose such Confidential Information and shall use
* it only in accordance with the terms of the license agreement
* you entered into with mnxoid.
**/
#pragma warning(disable:4996)
#define _CRT_SECURE_NO_WARNINGS
//------------------Includes------------------------------------
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <memory.h>
#include <string>
#include <sstream>
#include <stack>
#include "util.h"
#include "mystack.h"
#include "StFile.h"
//------------------Definitions---------------------------------
#define null 0
//------------------Namespaces----------------------------------
using namespace std;
//------------------Classes-------------------------------------

// void stack_ctor3(stack<char*>* my_this, fstream* f)
// {
// 	char* s = (char*)calloc(1, 256);
// 	while (!(f->eof()))
// 	{
// 		f->getline(s, 256);
// 		if (string(s) != "")
// 		{
// 			char* s1 = (char*)calloc(1, strlen(s) + 1);
// 			strcpy(s1, s);
// 			my_this->push(s1);
// 		}
// 	}
// 	free(s);
// }

//------------------Disclaimer----------------------------------
/**
* @brief       This function displays license agreement
**/
void Disclaimer()
{
	cout << "This is an app that displays the contents of a text file.\n\n";
	cout << "Copyright 2014 by mnxoid, \n\n";
	cout << "This software is the confidential and proprietary information\n";
	cout << "of mnxoid  (\"Confidential Information\") .  You\n";
	cout << "shall not disclose such Confidential Information and shall use\n";
	cout << "it only in accordance with the terms of the license agreement\n";
	cout << "you entered into with mnxoid.\n\n";
	cout << "By pressing [ENTER] you confirm that you are NOT A GEODESIST\n";
	CleanInput(); //here CleanInput is used as a safe getchar (  ) 
}
//------------------Utility functions---------------------------
/**
* @brief	Creates a dummy mnxoid.txt file
*/
void makeDummyFile()
{
	system("echo line > mnxoid.txt");
	system("echo another line >> mnxoid.txt");
	system("echo yet another line >> mnxoid.txt");
	system("echo not a line >> mnxoid.txt");
	system("echo maybe a line >> mnxoid.txt");
}

int openFile(LFFstream &f)
{
	string fname;
	cout << "Enter file to open: ";
	cin >> fname;
	cin.ignore();
	f.open(fname.c_str(), f.in);
	if (!f.good())
	{
		cout << "File not found!!!" << endl;
		cin.ignore();
		return 0;
	}
	return 1;
}

//------------------Main function-------------------------------
int main()
{
	Disclaimer();
	makeDummyFile();
	PrintTxtFiles();
	StFile f;
	f.Show();
	cin.ignore();
	return 0;
}