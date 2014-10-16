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
#include "multiticket.h"
#include <ctime>
//------------------Definitions---------------------------------
#define null 0
//------------------Namespaces----------------------------------
using namespace std;
//------------------Classes-------------------------------------
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

//------------------Main function-------------------------------
int main()
{
	Disclaimer();
	Composter c(1, 1, 0, 1);
	cout << "Current Date and time: " << c.currentDate();
	for (long long i = 0; i < 10000000; i++)
	{
		for (long long j = 0; j < 100; j++)
		{
			//Just for time wasting
		}
	}
	Ticket t;
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
	for (int i = 0; i < 80; i++)
	{
		Ticket tick;
		if (i % 5) continue;
		c.setTicket(t);
		c.Compost();
	}
	cout << c;
	cout << "Time since check: "; print_time(c.timeFromLastCheck()); cout << endl;
	c.Control();
	for (int i = 0; i < 80; i++)
	{
		MultiTicket tick(5);
		if (i % 5) continue;
		c.setTicket(t);
		c.Compost();
		c.Compost();
		c.Compost();
		cout << tick;
		c.Compost();
		c.Compost();
		cout << tick;
	}
	cout << c;
	CleanInput();
	return 0;
}