#pragma once
#include "countable.h"
#include "ticket.h"
#include <vector>
using namespace std;
class SingleTicket :
	public Ticket
{
public:
	SingleTicket();
	~SingleTicket();
	virtual void Cypher(int);
	virtual int Cypher();
	virtual bool good();
	friend ostream& operator<<(ostream& os, SingleTicket& t);
};

