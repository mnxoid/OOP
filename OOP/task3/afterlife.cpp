#include "afterlife.h"
#include <iostream>
#include "util.h"
using namespace std;

AfterLife::AfterLife()
{
}


AfterLife::~AfterLife()
{
	cout << "So here we are now, life has come to an end." << endl;
	cout << "No more main(). We are free now, living after the final bracket }..." << endl;
	cout << "Press [ENTER] to kill the last survivor object." << endl;
	CleanInput();
}
