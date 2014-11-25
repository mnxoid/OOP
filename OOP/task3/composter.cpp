#include "composter.h"
#define __CPLUSPLUS
#include "util.h"
#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;
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

string Composter::Serialize()
{
	string s;
	stringstream  ss(s);
	ss << "{";
		ss << serialNumber << " ";
		ss << busNumber << " ";
		ss << reisNumber << " ";
		ss << compostedQuantity << " ";
		ss << mktime(&startTime) << " ";
		ss << mktime(&lastCheckTime) << " ";
		ss << cypher << " ";
		ss << "{";
			ss << compostedIDs.size() << " ";
			for each(int i in compostedIDs)
			{
				ss << i << " ";
			}
		ss << "{";
	ss << "}";
	return ss.str();
}

void Composter::Deserialize(string s)
{
	stringstream ss(s);
	char junk;
	ss >> junk;
	ss >> serialNumber;
	ss >> busNumber;
	ss >> reisNumber;
	ss >> compostedQuantity;
	time_t temp;
	ss >> temp;
	startTime = *(localtime(&temp));
	ss >> temp;
	lastCheckTime = *(localtime(&temp));
	ss >> cypher;
	junk = 0;
	while (junk != '{') ss >> junk;
	int n;
	ss >> n;
	while (n)
	{
		int t;
		ss >> t;
		compostedIDs.push_back(t);
		n--;
	}
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

istream& operator>>(istream& is, Composter& c)
{
	cout << "Welcome to composter creator!" << endl;
	cout << "\tBus number: "; is >> c.busNumber;
	cout << "\tReis number: "; is >> c.reisNumber;
	cout << "\tCypher: "; is >> c.cypher;
	CleanInput();
	return is;
}

ofstream& operator<<(ofstream& os, Composter& c)
{
	Composter_serial cs{ c.serialNumber, c.busNumber, c.reisNumber, c.compostedQuantity, c.startTime, c.lastCheckTime, c.cypher };
	os.write((char*)&cs, sizeof(cs));
	int s = c.compostedIDs.size();
	os.write((char*)&s,sizeof(int));
	for each (int i in c.compostedIDs)
	{
		os.write((char*)&i, sizeof(int));
	}
	return os;
}

ifstream& operator>>(ifstream& is, Composter& c)
{
	Composter_serial cs;
	is.read((char*)&cs, sizeof(cs));
	c.serialNumber = cs.serialNumber;
	c.busNumber = cs.busNumber;
	c.reisNumber = cs.reisNumber;
	c.compostedQuantity = cs.compostedQuantity;
	c.startTime = cs.startTime;
	c.lastCheckTime = cs.lastCheckTime;
	c.cypher = cs.cypher;
	int s;
	is.read((char*)&s, sizeof(int));
	while (s>0)
	{
		int i;
		is.read((char*)&i, sizeof(int));
		c.compostedIDs.push_back(i);
		s--;
	}
	return is;
}

bool operator>(Composter&a, Composter&b)
{
	return a.compostedQuantity > b.compostedQuantity;
}

bool operator<(Composter&a, Composter&b)
{
	return a.compostedQuantity < b.compostedQuantity;
}

bool operator==(Composter&a, Composter&b)
{
	return a.compostedQuantity == b.compostedQuantity;
}

bool operator>=(Composter&a, Composter&b)
{
	return a.compostedQuantity >= b.compostedQuantity;
}

bool operator<=(Composter&a, Composter&b)
{
	return a.compostedQuantity <= b.compostedQuantity;
}
