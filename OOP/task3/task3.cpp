/**
* @file		task3.cpp
* @brief	C++ source of the app that simulates a taxi
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
#include "util.h"
#include "taxi.h"
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
	printf("my_this software is the confidential and proprietary information\n");
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
	TaxiPool tp;
	tp.addTaxi();
	tp.addTaxi();
	tp.addTaxi();
	cout << "There are " << Taxi::getCount() << " taxis" << endl;
	cout << 100 * tp.order() << "% of the taxis are free" << endl;
	tp.passenger = "Mnxoid";
	cout <<  tp.order("Ny, Park lane") << endl;
	cout << "There are " << Taxi::getCount() << " taxis" << endl;
	cout << 100 * tp.order() << "% of the taxis are free" << endl;
	tp.passenger = "Nick";
	cout << boolalpha << tp.order(2, "London, Baker str.") << endl;
	cout << "There are " << Taxi::getCount() << " taxis" << endl;
	cout << 100 * tp.order() << "% of the taxis are free" << endl;
	tp.processAll();
	tp.clear();
	CleanInput();
	return 0;
}