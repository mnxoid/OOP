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
	void Cypher(int);
	int Cypher();
	bool good();
	friend ostream& operator<<(ostream& os, SingleTicket& t);
};

