/** 
 * @file	task1.cpp
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
//------------------Includes------------------------------------
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <string.h>
#include "util.h"
//------------------Definitions---------------------------------
#define null 0
//------------------Namespaces----------------------------------
using namespace std;
//------------------Classes-------------------------------------
/**
 * @brief	Stack element class
 */
class elem
 {
private:
	char str[256]; //!< The line (info field)
public:
	elem* prev; //!< Previous element (address field)
	/**
	 * @brief	Default constructor
	 */
	elem()
	 {
		memset(str, 0, 256);
	 }
	/**
	 * @brief	Constructor with a string parameter
	 * @param	[in] s - the string to put into the info field
	 */
	elem(char* s)
	 {
		memset(str, 0, 256);
		strcpy(str, s);
	 }
	/**
	 * @brief	Info field getter
	 * @return	Info field value
	 */
	char* getStr()
	 {
		return str;
	 }
	/**
	 * @brief	Info field setter
	 * @param 	[in] s - the string to put into the info field
	 */
	void setStr(char* s)
	 {
		strcpy(str, s);
	 }
 };
/**
 * Stack class
 */
class stack
 {
 private:
 	elem* top; //!< Top element
 	int count; //!< Element quantity
 public:
 	/**
 	 * @brief	Default constructor
 	 */
 	stack()
 	 {
 	 	top = null;
 	 	count = 0;
 	 }
 	/**
 	 * @brief	Constructor for using a part of an existing stack
 	 */
 	stack(elem* e)
 	 {
 	 	top = e;
 	 	count = 1;
 	 	elem* curr = top;
 	 	while (curr->prev)
 	 	 {
 	 	 	curr = curr->prev;
 	 	 	count++;
 	 	 }
 	 }
 	/**
 	 * @brief	Constructor with input file
 	 * @param	[in] f - file to load the stack from
 	 */
 	stack(FILE* f)
 	 {
 	 	top=null;
 	 	count=0;
 	 	char* s = (char*) calloc(1,256);
 	 	while (!feof(f))
		 {
			if(fgets(s, 256, f))
			 {
				elem* curr = new elem(s);
				//sprintf(s,"%i : %s", getCount()+1, curr->getStr());
				curr->setStr(s);
				push(curr);
			 }
		 }
		free(s);
 	 }
 	/**
 	 * @brief	Pushes an element onto the stack
 	 * @param	[in] e - the element to push 
 	 */
 	void push(elem* e)
 	 {
 	 	if(e)
 	 	 {
 	 	 	e->prev = top;
 	 	 	top = e;
 	 	 	count++;
 	 	 }
 	 }
 	/**
 	 * @brief	Pops an element from the stack
 	 * @return 	elem* - the poped element
 	 */
 	elem* pop()
 	 {
 	 	if (count>0)
 	 	 {
 	 	 	elem* r = top;
 	 	 	top = top->prev;
 	 	 	count--;
 	 	 	return r;
 	 	 } else {
 	 	 	return null;
 	 	 }
 	 }
 	/**
 	 * @brief	Pops an element from the stack without removing it
 	 * @return	elem* - the poped element
 	 */
 	elem* peek()
 	 {
 	 	return top;
 	 }
 	/**
 	 * @brief	Element quantity getter
 	 * @return	int - element quantity
 	 */
 	int getCount()
 	 {
 	 	return count;
 	 }
 	/**
 	 * @brief	Gets an element from the bottom of the stack
 	 * @return	elem* - the bottom element
 	 */
 	elem* bottom()
 	 {
 	 	if (count>0)
 	 	 {
 	 	 	elem* b = top;
 	 	 	while (b->prev) b = b->prev;
 	 	 	return b;
 	 	 } else {
 	 	 	return null;
 	 	 }
 	 }
 	/**
 	 * @brief	Deletes the bottom of the stack
 	 */
 	void delBottom()
 	 {
 	 	if (count>1)
 	 	 {
 	 	 	elem* b = top;
 	 	 	while (b->prev->prev) b = b->prev;
 	 	 	delete b->prev;
 	 	 	b->prev = null;
 	 	 	count--;
 	 	 } else {
 	 	 	if(top) delete top;
 	 	 	top=null;
 	 	 	count=0;
 	 	 }
 	 }
 	/**
 	 * @brief	Wipes the stack while outputing it in reverse order
 	 */
 	void purge()
 	 {
 	 	while (getCount()>0)
		 {
		 	elem* curr = bottom();
		 	printf("%s\n", curr->getStr());
		 	delBottom(); 
		 }
 	 }
 	/**
 	 * @brief	Restores stack numeration
 	 */
 	void renumber()
 	 {
 	 	int curN=count;
 	 	elem* curr = top;
 	 	while(curr)
 	 	{
 	 		char* s = (char*) calloc(1,256);
 	 		char* pureStr = curr->getStr();//(curr->getStr(),':')+2;
 	 		sprintf(s,"%i : %s",curN,pureStr);
 	 		curr->setStr(s);
 	 		free(s);
 	 		curN--;
 	 		curr = curr->prev;
 	 	}
 	 }
 	/**
 	 * Default destructor
 	 */
 	~stack()
 	 {
 	 	while(bottom()) delBottom();
 	 }
 };
//------------------Disclaimer----------------------------------
/**
 * @brief       This function displays license agreement
 **/
void Disclaimer (  ) 
 {
 	printf ( "This is an app that displays the contents of a text file.\n\n" ) ; 
	printf ( "Copyright 2014 by mnxoid, \n\n" ) ; 
	printf ( "This software is the confidential and proprietary information\n" ) ; 
	printf ( "of mnxoid  (\"Confidential Information\") .  You\n" ) ; 
	printf ( "shall not disclose such Confidential Information and shall use\n" ) ; 
	printf ( "it only in accordance with the terms of the license agreement\n" ) ; 
	printf ( "you entered into with mnxoid.\n\n" ) ; 
	printf ( "By pressing [ENTER] you confirm that you are NOT A GEODESIST\n" ) ; 
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
	FILE* f = fopen("mnxoid.txt", "r");
	if (!f) puts("File not found!!!");
	printf("Do you want to store the data in a stack? (1 - yes, 0 - no) ");
	int ch;
	InputInt(&ch,USELIM,-1,2);
	if (ch==1)
	 {
	 	stack st(f);
	 	st.renumber();
		st.purge();
	 } else {
	 	char* s = (char*)calloc(1, 256);
		while (!feof(f))
		 {
			if(fgets(s, 256, f)) printf("%s\n", s);
		 }
		free(s);
	 }
	fclose(f);
	CleanInput();
	return 0;
 }