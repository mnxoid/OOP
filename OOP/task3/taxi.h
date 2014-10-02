#ifndef _taxi_header_
#define _taxi_header_
#include "countable.h"
#include <vector>
using namespace std;
//--------------------------
class Taxi : public Countable
{
public:
	char* passenger;
private:
	int driver;
	int drvN;
protected:
	char* address;
};
class TaxiPool
{
public:
	int order(char*address);
private:
	vector<Taxi> v;

};
//--------------------------
#endif