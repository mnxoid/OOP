#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include "ticket.h"
#include <vector>
#include <ctime>
using namespace std;
class Composter
{
private:
	Ticket* t;
public:
	void setTicket(Ticket& tick);
	tm currentDate();
	time_t timeFromLastCheck();
	Composter();
	Composter(int bN, int rN, int cQ, int cy, tm startTime, tm lastCheckTime);
	Composter(int bN, int rN, int cQ, int cy);
	Composter(Composter& c);
	~Composter();
	void Check();
	void Compost();
	void Control();
	bool Control(Ticket& tick);
	friend ostream& operator<<(ostream& os, Composter& c);
	friend istream& operator>>(istream& is, Composter& c);
	friend ofstream& operator<<(ofstream& os, Composter& c);
	friend ifstream& operator>>(ifstream& is, Composter& c);
	friend bool operator>(Composter&a, Composter&b);
	friend bool operator<(Composter&a, Composter&b);
	friend bool operator==(Composter&a, Composter&b);
	friend bool operator>=(Composter&a, Composter&b);
	friend bool operator<=(Composter&a, Composter&b);
private:
	int serialNumber;
	static int nextSerial;
	//---------Additional fields-----------
	int busNumber;
	int reisNumber;
	//Current date is a method
	int compostedQuantity;
	vector<int> compostedIDs;
	tm startTime;
	tm lastCheckTime;
	//Time from last check is a method
protected:
	int cypher;
};

struct Composter_serial
{
	int serialNumber;
	int busNumber;
	int reisNumber;
	int compostedQuantity;
	tm startTime;
	tm lastCheckTime;
	int cypher;
};