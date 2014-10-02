#include "taxi.h"
#include <iostream>
using namespace std;
#define null NULL

Taxi::Taxi()
{
	cout << "a taxi has been created!" << endl;
	driver = getNextId();
	passenger = null;
	address = null;
}

void Taxi::processOrder()
{
	cout << "Driver " << this->getID() << " : ";
	if (this->address && this->passenger)
	{
		cout << "Client " << this->passenger << " has been delivered to " << this->address << endl;
		free(this->address);
		free(this->passenger);
		this->passenger = null;
		this->address = null;
	}
	else {
		cout << "No client." << endl;
	}
}

void Taxi::setAddress(char* addr)
{
	address = _strdup(addr);
}

int Taxi::getID()
{
	return driver;
}

Taxi::~Taxi()
{
	if (this->passenger) free(this->passenger);
	if(this->address) free(this->address);
	cout << "a taxi died!" << endl;
}

int TaxiPool::order(char* address)
{
	if (this->order() > 0)
	{
		for (auto i = v.begin(); i != v.end(); ++i)
		{
			if (!((*i)->passenger)) {
				(*i)->passenger = _strdup(passenger);
				(*i)->setAddress(address);
				return (*i)->getID();
			}
		}
		return 0;
	}
	else return 0;
}

bool TaxiPool::order(int driver, char* address)
{
	if (this->order() > 0)
	{
		for (auto i = v.begin(); i != v.end(); ++i)
		{
			if ((!((*i)->passenger)) && ((*i)->getID() == driver)) {
				(*i)->passenger = _strdup(passenger);
				(*i)->setAddress(address);
				return true;
			}
			cout << "Driver with id = " << (*i)->getID() << " is ";
			cout << boolalpha << !((*i)->passenger) << endl;
		}
		return false;
	}
	else return false;
}

double TaxiPool::order()
{
	if (Taxi::getCount() == 0) return 0;
	double count=0;
	for (auto i = v.begin(); i != v.end(); ++i)
	{
		if (!(*i)->passenger)
		{
			count++;
			//cout << "A free taxi" << endl;
		}
	}
	return count / Taxi::getCount();
}

void TaxiPool::addTaxi()
{
	Taxi *t = new Taxi;
	v.push_back(t);
}

void TaxiPool::fire(int driver)
{
	for (auto i = v.begin(); i != v.end(); ++i)
	{
		if ((*i)->getID() == driver)
		{
			v.erase(i);
		}
	}
}

void TaxiPool::processAll()
{
	for (auto i = v.begin(); i != v.end(); ++i)
	{
		(*i)->processOrder();
	}
}

void TaxiPool::clear()
{
	for (auto i = v.begin(); i != v.end(); ++i)
	{
		delete *i;
	}
	v.clear();
}