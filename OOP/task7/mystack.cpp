#include "mystack.h"
#include <iostream>
#include <sstream>
#include "lffstream.h"
#define _CRT_SECURE_NO_WARNINGS

MyStack::MyStack()
{
}

MyStack::MyStack(LFFstream* f)
{
	line s;
	LFFstream::ii end;
	for (LFFstream::ii i(*f); i != end; i++)
	{
		s = *i;
		if (s != "")
		{
			char* s1 = (char*)calloc(1, s.size() + 1);
			strcpy(s1, s.c_str());
			this->push(s1);
		}
	}
}


MyStack::~MyStack()
{
	while (this->size() > 0)
	{
		free(this->top());
		this->pop();
	}
}

void MyStack::purge()
{
	while (this->size() > 0)
	{
		cout << this->top() << endl;
		this->pop();
	}
}

void MyStack::reverseRenumber(MyStack& newst)
{
	int i = this->size();
	while (this->size() > 0)
	{
		ostringstream oss;
		oss << i << " : " << this->top();
		this->pop();
		newst.push(_strdup(oss.str().c_str()));
		i--;
	}
}

void MyStack::pop()
{
	free(top());
	stack<char*>::pop();
}
