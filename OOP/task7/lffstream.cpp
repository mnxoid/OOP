#include "lffstream.h"
#include <iostream>
using namespace std;

LFFstream::LFFstream()
{
	string fname;
	cout << "Enter file to open: ";
	cin >> fname;
	cin.ignore();
	this->open(fname.c_str(), this->in);
	if (!this->good())
	{
		cout << "File not found!!!" << endl;
		cin.ignore();
	}
}


LFFstream::~LFFstream()
{
}
