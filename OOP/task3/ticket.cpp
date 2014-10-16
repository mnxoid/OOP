#include "ticket.h"
#include <iostream>
using namespace std;

vector<int> Ticket::multIDs;

Ticket::Ticket() : cypher(0), id(getNextId())
{
	cout << "Ticket with ID=" << id << " was created." << endl;
}


Ticket::~Ticket()
{
	cout << "Ticket with ID=" << id << " was thrown away." << endl;
}

void Ticket::Cypher(int c)
{
	cypher |= c;
}

int Ticket::Cypher()
{
	return cypher;
}

int Ticket::getID()
{
	return id;
}

bool Ticket::good()
{
	return (cypher) ? false : true;
}

ostream& operator<<(ostream& os, Ticket& t)
{
	return os << "Ticket: ID=" << t.getID() << " Cypher=" << t.Cypher() << endl;
}