#ifndef _taxi_header_
#define _taxi_header_
#include "countable.h"
#include <vector>
using namespace std;
//--------------------------
class Taxi : public Countable
{
public:
	Taxi();
	char* passenger;
	void processOrder();
	void setAddress(char* addr);
	int getID();
	~Taxi();
private:
	int driver;
protected:
	char* address;
};
class TaxiPool
{
public:
	char* passenger;
	int order(char* address);
	bool order(int driver, char* address);
	double order();
	void addTaxi();
	void fire(int driver);
	void processAll();
	void clear();
private:
	vector<Taxi*> v;
};
//--------------------------
#endif