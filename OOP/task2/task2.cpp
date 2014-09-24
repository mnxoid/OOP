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
#include "util.h"
//------------------Definitions---------------------------------
#define null 0
//------------------Namespaces----------------------------------
using namespace std;
//------------------Classes-------------------------------------
/**
 * @brief	Stack element class
 */
struct elem
 {
	char* str; //!< The line (info field)

	elem* prev; //!< Previous element (address field)
 };
	/**
	 * @brief	Default constructor
	 */
	void elem_ctor1(elem* my_this)
	 {
		my_this->str=null;
	 }
	/**
	 * @brief	Constructor with a string parameter
	 * @param	[in] s - the string to put into the info field
	 */
	void elem_ctor2(elem* my_this, const char* s)
	 {
	 	my_this->str = (char*)calloc(1, strlen(s)+1);
		strncpy(my_this->str, s, strlen(s));
	 }
	/**
	 * @brief	Info field getter
	 * @return	Info field value
	 */
	char* getStr(elem* my_this)
	 {
		return my_this->str;
	 }
	/**
	 * @brief	Info field setter
	 * @param 	[in] s - the string to put into the info field
	 */
	void setStr(elem* my_this, const char* s)
	 {
	 	free(my_this->str);
		my_this->str = (char*)calloc(1, strlen(s)+1);
		strncpy(my_this->str, s, strlen(s));
	 }
	/**
	 * @brief	Default deconstructor
	 */
	void elem_dtor(elem* my_this)
	 {
	 	free(my_this->str);
	 	free(my_this);
	 }
/**
 * Stack class
 */
struct stack
 {
 	elem* top; //!< Top element
 	int count; //!< Element quantity
 };
 	/**
 	 * @brief	Default constructor
 	 */
 	void stack_ctor1(stack* my_this)
 	 {
 	 	my_this->top = null;
 	 	my_this->count = 0;
 	 }
 	/**
 	 * @brief	Constructor for using a part of an existing stack
 	 */
 	void stack_ctor2(stack* my_this, elem* e)
 	 {
 	 	my_this->top = e;
 	 	my_this->count = 1;
 	 	elem* curr = my_this->top;
 	 	while (curr->prev)
 	 	 {
 	 	 	curr = curr->prev;
 	 	 	my_this->count++;
 	 	 }
 	 }
 	void push(stack* my_this, elem* e);
 	/**
 	 * @brief	Constructor with input file
 	 * @param	[in] f - file to load the stack from
 	 */
 	void stack_ctor3(stack* my_this, fstream* f)
 	 {
 	 	my_this->top=null;
 	 	my_this->count=0;
 	 	char* s = (char*) calloc(1,256);
 	 	while (!(f->eof()))
		 {
			f->getline(s,256);
			if(string(s)!="")
			 {
				elem* curr = (elem*)calloc(1, sizeof(elem));
				elem_ctor2(curr, s);
				push(my_this,curr);
			 }
		 }
		free(s);
 	 }
 	/**
 	 * @brief	Pushes an element onto the stack
 	 * @param	[in] e - the element to push 
 	 */
 	void push(stack* my_this, elem* e)
 	 {
 	 	if(e)
 	 	 {
 	 	 	e->prev = my_this->top;
 	 	 	my_this->top = e;
 	 	 	my_this->count++;
 	 	 }
 	 }
 	/**
 	 * @brief	Pops an element from the stack
 	 * @return 	elem* - the poped element
 	 */
 	elem* pop(stack* my_this)
 	 {
 	 	if (my_this->count>0)
 	 	 {
 	 	 	elem* r = my_this->top;
 	 	 	my_this->top = my_this->top->prev;
 	 	 	my_this->count--;
 	 	 	return r;
 	 	 } else {
 	 	 	return null;
 	 	 }
 	 }
 	/**
 	 * @brief	Pops an element from the stack without removing it
 	 * @return	elem* - the poped element
 	 */
 	elem* peek(stack* my_this)
 	 {
 	 	return my_this->top;
 	 }
 	/**
 	 * @brief	Element quantity getter
 	 * @return	int - element quantity
 	 */
 	int getCount(stack* my_this)
 	 {
 	 	return my_this->count;
 	 }
 	/**
 	 * @brief	Gets an element from the bottom of the stack
 	 * @return	elem* - the bottom element
 	 */
 	elem* bottom(stack* my_this)
 	 {
 	 	if (my_this->count>0)
 	 	 {
 	 	 	elem* b = my_this->top;
 	 	 	while (b->prev) b = b->prev;
 	 	 	return b;
 	 	 } else {
 	 	 	return null;
 	 	 }
 	 }
 	/**
 	 * @brief	Deletes the bottom of the stack
 	 */
 	void delBottom(stack* my_this)
 	 {
 	 	if (my_this->count>1)
 	 	 {
 	 	 	elem* b = my_this->top;
 	 	 	while (b->prev->prev) b = b->prev;
 	 	 	elem_dtor(b->prev);
 	 	 	b->prev = null;
 	 	 	my_this->count--;
 	 	 } else {
 	 	 	if(my_this->top) elem_dtor(my_this->top);
 	 	 	my_this->top=null;
 	 	 	my_this->count=0;
 	 	 }
 	 }
 	/**
 	 * @brief	Wipes the stack while outputing it in reverse order
 	 */
 	void purge(stack* my_this)
 	 {
 	 	while (getCount(my_this)>0)
		 {
		 	elem* curr = bottom(my_this);
		 	cout << getStr(curr);
		 	delBottom(my_this); 
		 }
 	 }
 	/**
 	 * @brief	Restores stack numeration
 	 */
 	void renumber(stack* my_this)
 	 {
 	 	int curN=my_this->count;
 	 	elem* curr = my_this->top;
 	 	while(curr)
 	 	{
 	 		stringstream ss;
 	 		ss << curN << " : " << getStr(curr) << endl << '\0';
			//cout << "Debuginfo: " << ss.str().c_str();
 	 		//char* pureStr = strchr(curr->getStr(),':')+2;
 	 		//sprintf(s,"%i : %s",curN,pureStr);
 	 		setStr(curr,ss.str().c_str());
 	 		curN--;
 	 		curr = curr->prev;
 	 	}
 	 }
 	/**
 	 * Default destructor
 	 */
 	void stack_dtor(stack* my_this)
 	 {
 	 	while(bottom(my_this)) delBottom(my_this);
 	 	free(my_this);
 	 }
//------------------Disclaimer----------------------------------
/**
 * @brief       This function displays license agreement
 **/
void Disclaimer (  ) 
 {
 	cout << "This is an app that displays the contents of a text file.\n\n" ; 
	cout << "Copyright 2014 by mnxoid, \n\n" ; 
	cout << "This software is the confidential and proprietary information\n" ; 
	cout << "of mnxoid  (\"Confidential Information\") .  You\n" ; 
	cout << "shall not disclose such Confidential Information and shall use\n" ; 
	cout << "it only in accordance with the terms of the license agreement\n" ; 
	cout << "you entered into with mnxoid.\n\n" ; 
	cout << "By pressing [ENTER] you confirm that you are NOT A GEODESIST\n" ; 
	CleanInput (  ) ; //here CleanInput is used as a safe getchar (  ) 
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
//------------------Main function-------------------------------
int main()
 {
	Disclaimer();
	makeDummyFile();
	PrintTxtFiles();
	fstream f;
	string fname;
	cout << "Enter file to open: ";
	cin >> fname;
	f.open(fname.c_str(), f.in);
	if (!f.good()) cout << "File not found!!!" << endl;
	cout << "\nDo you want to store the data in a stack? (1 - yes, 0 - no) ";
	int ch;
	inp:
	cin >> ch;
	cin.ignore();
	if (ch>1 || ch <0)
	 {
	 	cout << "Sorry, try again: ";
	 	goto inp;
	 }
	if (ch==1)
	 {
	 	stack* st = (stack*)calloc(1,sizeof(stack));
	 	stack_ctor3(st,&f);
	 	renumber(st);
		purge(st);
		stack_dtor(st);
	 } else {
	 	char* s = (char*)calloc(1, 256);
		while (!(f.eof()))
		 {
			f.getline(s, 256);
			cout << s << endl;
		 }
		free(s);
	 }
	f.close();
	cin.ignore();
	return 0;
 }