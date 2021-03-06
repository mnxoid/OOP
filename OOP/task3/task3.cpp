/**
* @file		task3.cpp
* @brief	C++ source of the app that simulates a composter
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
//------------------Includes------------------------------------
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#define __CPLUSPLUS
#include "util.h"
#include "composter.h"
#include "singleticket.h"
#include "multiticket.h"
#include <ctime>
#include <fstream>
#include "afterlife.h"
//------------------Definitions---------------------------------
#define null 0
//------------------Namespaces----------------------------------
using namespace std;
//------------------Classes-------------------------------------
AfterLife exists;
//------------------Disclaimer----------------------------------
/**
* @brief       my_this function displays license agreement
**/
void Disclaimer()
{
	printf("This is an app that simulates a taxi.\n\n");
	printf("Copyright 2014 by mnxoid, \n\n");
	printf("This software is the confidential and proprietary information\n");
	printf("of mnxoid  (\"Confidential Information\") .  You\n");
	printf("shall not disclose such Confidential Information and shall use\n");
	printf("it only in accordance with the terms of the license agreement\n");
	printf("you entered into with mnxoid.\n\n");
	printf("By pressing [ENTER] you confirm that you are NOT A GEODESIST\n");
	CleanInput(); //here CleanInput is used as a safe getchar (  ) 
}

//------------------Utility functions---------------------------

void BubbleSortC(Composter** cArr)
{
	bool und = true;
	while (und)
	{
		und = false;
		for (int i = 0; i < 4; i++)
		{
			if (*cArr[i]>*cArr[i + 1])
			{
				Composter* T = cArr[i];
				cArr[i] = cArr[i + 1];
				cArr[i + 1] = T;
				und = true;
			}
		}
	}
}

void CArrayOut(Composter** cArr)
{
	cout << "--------------SORTED:--------------" << endl;
	for (int i = 0; i < 5; i++)
	{
		cout << *cArr[i];
	}
}

void CompostMTtest(Composter &c)
{
	for (int i = 0; i < 80; i++)
	{
		MultiTicket tick(5);
		if (i % 5) continue;
		c.setTicket(tick);
		c.Compost();
		c.Compost();
		c.Compost();
		cout << tick;
		c.Compost();
		c.Compost();
		cout << tick;
	}
}

void longWait()
{
	for (long long i = 0; i < 10000000; i++)
	{
		for (long long j = 0; j < 100; j++)
		{
			//Just for time wasting
		}
	}
}

void CompostTtest(Composter &c)
{
	for (int i = 0; i < 80; i++)
	{
		SingleTicket tick;
		if (i % 5) continue;
		c.setTicket(tick);
		c.Compost();
	}
}

void CArrayCreate(Composter** cArr)
{
	for (int i = 0; i < 5; i++)
	{
		cArr[i] = new Composter(5 * i, 4 * i, 3 * (6 - i), i);
		cout << *cArr[i];
	}
}

void CFileReadTest()
{
	cout << "Reading from file:" << endl;
	ifstream inf;
	inf.open("1.dat", ios_base::binary);
	Composter ci;
	inf >> ci;
	cout << ci;
	inf.close();
}



//------------------Main function-------------------------------
int main()
{
	Disclaimer();
	Composter c(1, 1, 0, 1);
	cin >> c;
	cout << c;
	cout << "Current Date and time: " << c.currentDate();
	longWait();

	system("echo. > 1.dat");//dummy file
	ofstream outf;
	outf.open("1.dat",ios_base::binary);
	if (!outf.good()) cout << "Bad file!" << endl;
	SingleTicket t;
	c.setTicket(t);
	cout << t;
	c.Compost();
	c.Compost();
	cout << t;
	cout << "Current Date and time: " << c.currentDate();
	cout << "Last time checked: " << c.currentDate();
	cout << "Time since check: "; print_time(c.timeFromLastCheck()); cout << endl;
	c.Check();
	cout << "Last time checked: " << c.currentDate();
	cout << "Time since check: "; print_time(c.timeFromLastCheck()); cout << endl;
	cout << c;
	CompostTtest(c);

	outf << c;
	outf.close();
	cout << c;
	cout << "Time since check: "; print_time(c.timeFromLastCheck()); cout << endl;
	c.Control();
	CleanInput();
	system("cls");
	CompostMTtest(c);

	cout << c;
	CleanInput();
	system("cls");
	cout << "Now we will create an array of composters and sort it" << endl;
	Composter** cArr = new Composter*[5];
	CArrayCreate(cArr);

	BubbleSortC(cArr);
	CArrayOut(cArr);

	CleanInput();
	CFileReadTest();

	CleanInput();
	//---------Valid access examples-------------
	MultiTicket mt;
	SingleTicket st;
	st.getCount();
	st.getID();
	mt.getID();
	mt.getCount();
	//-------Invalid access examples-------------
	/*mt.getNextId();
	mt.multIDs;
	mt.id;
	mt.cypher;
	mt.usesleft;*/
	string s = c.Serialize();
	cout << s << endl;
	Composter c1;
	c1.Deserialize(s);
	cout << c1;
	//CleanInput();
	return 0;
}