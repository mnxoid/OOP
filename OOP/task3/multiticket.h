#pragma once
#include "ticket.h"
class MultiTicket :
	public Ticket
{
public:
	MultiTicket();
	MultiTicket(int n);
	bool good();
	void Cypher(int);
	int Cypher();
	~MultiTicket();
private:
	int usesleft;
	friend ostream& operator<<(ostream& os, MultiTicket& t);
};

