#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <stack>
#include <fstream>
#include "lffstream.h"
using namespace std;
class MyStack :
	public stack<char*>
{
public:
	MyStack();
	MyStack(LFFstream* f);
	~MyStack();
	void purge();
	void pop();
	MyStack* reverseRenumber();
};

