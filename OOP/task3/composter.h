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
	//TODO: File I/O, Keyboard input
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

