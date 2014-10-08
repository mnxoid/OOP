#pragma once
#include "ticket.h"
#include <vector>
#include <ctime>
using namespace std;
class Composter
{
public:
	Ticket* t;
	//tm currentDate();
	//tm timeFromLastCheck();
	Composter();
	~Composter();
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

