#include "composter.h"
#define __CPLUSPLUS
#include "util.h"
#include <iostream>
#define null 0
int Composter::nextSerial = 0;

Composter::Composter() : t(null), busNumber(0), reisNumber(0), compostedQuantity(0), cypher(0)
{
	cout << "Default composter created!" << endl;
	serialNumber = nextSerial;
	nextSerial++;
	Check();
	startTime = currentDate();
}

Composter::Composter(int bN, int rN, int cQ, int cy, tm startTime, tm lastCheckTime) : Composter()
{
	cout << "Full-parameter composter created!" << endl;
	busNumber = bN;
	reisNumber = rN;
	compostedQuantity = cQ;
	this->startTime = startTime;
	this->lastCheckTime = lastCheckTime;
	cypher = cy;
}

Composter::Composter(int bN, int rN, int cQ, int cy) : Composter()
{
	cout << "Partial-parameter composter created!" << endl;
	busNumber = bN;
	reisNumber = rN;
	compostedQuantity = cQ;
	this->startTime = startTime;
	this->lastCheckTime = lastCheckTime;
	cypher = cy;
}

Composter::Composter(Composter& c) : Composter(c.busNumber,c.reisNumber,c.compostedQuantity,c.cypher,c.startTime,c.lastCheckTime)
{
	cout << "Composter copied!" << endl;
	compostedIDs = c.compostedIDs;
}


Composter::~Composter()
{
	compostedIDs.clear();
	cout << "Composter destroyed!" << endl;
}

tm Composter::currentDate()
{
	time_t seconds = time(NULL);
	return  *(localtime(&seconds));
}

time_t Composter::timeFromLastCheck()
{
	time_t seconds = time(NULL);
	time_t start = mktime(&lastCheckTime);
	seconds -= start;
	return seconds;
}

void Composter::Check()
{
	cout << "Composter checked!" << endl;
	time_t seconds = time(NULL);
	lastCheckTime = *(localtime(&seconds));
}

void Composter::Compost()
{
	bool fnd=false;
	if (t)
	{
		if (t->good())
		{
			t->Cypher(cypher);
			for each (int i in compostedIDs)
			{
				if (t->getID() == i) {
					fnd = true;
					break;
				}
			}
			if (!fnd)
			{
				compostedIDs.push_back(t->getID());
				compostedQuantity++;
			}
			cout << "Ticket composted successfully!" << endl;
		}
		else
		{
			cout << "Bad ticket!" << endl;
		}
	}
	else
	{
		cout << "No ticket!" << endl;
	}
}

void Composter::Control()
{
	cout << "Composter has been working for ";
	time_t wt = time(NULL);
	wt -= mktime(&startTime);
	print_time(wt);
	cout << endl;
}

bool Composter::Control(Ticket& tick)
{
	return tick.good();
}

void Composter::setTicket(Ticket& tick)
{
	t = &tick;
}

ostream& operator<<(ostream& os, Composter& c)
{
	os << "Composter:\n\tSerialNumber: " << c.serialNumber << endl;
	os << "\tBus: " << c.busNumber << endl;
	os << "\tRace: " << c.reisNumber << endl;
	os << "\tComposted (" << c.compostedQuantity << "): ";
	os << "{ ";
	for each (int i in c.compostedIDs)
	{
		os << i << " ";
	}
	os << "}\n\tStarted: " << c.startTime;
	os << "\tLast check: " << c.lastCheckTime;
	return os;
}