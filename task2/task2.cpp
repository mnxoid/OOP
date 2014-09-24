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
	void setStr(const char* s)
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
 	stack(fstream *f)
 	 {
 	 	top=null;
 	 	count=0;
 	 	char* s = (char*) calloc(1,256);
 	 	while (!(f->eof()))
		 {
			f->getline(s,256);
			if(string(s)!="")
			 {
				elem* curr = new elem(s);
				stringstream ss;
				ss << getCount()+1 << " : " << curr->getStr();
				curr->setStr(ss.str().c_str());
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
 	 		string temp(curr->getStr());
 	 		temp.erase(0,temp.find(':')+2);
 	 		stringstream ss;
 	 		ss << curN << " : " << temp;
 	 		//char* pureStr = strchr(curr->getStr(),':')+2;
 	 		//sprintf(s,"%i : %s",curN,pureStr);
 	 		curr->setStr(ss.str().c_str());
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
	fstream f;
	f.open("mnxoid.txt", f.in);
	if (!f.good()) cout << "File not found!!!" << endl;
	cout << "Do you want to store the data in a stack? (1 - yes, 0 - no) ";
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
	 	stack st(&f);
		st.purge();
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