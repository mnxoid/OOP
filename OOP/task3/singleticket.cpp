#include "singleticket.h"
#include <iostream>
using namespace std;

SingleTicket::SingleTicket() //: cypher(0), id(getNextId())
{
	cout << "Ticket with ID=" << id << " was created." << endl;
}


SingleTicket::~SingleTicket()
{
	cout << "Ticket with ID=" << id << " was thrown away." << endl;
}

void SingleTicket::Cypher(int c)
{
	cypher |= c;
}

int SingleTicket::Cypher()
{
	return cypher;
}

bool SingleTicket::good()
{
	return (cypher) ? false : true;
}

ostream& operator<<(ostream& os, SingleTicket& t)
{
	return os << "Ticket: ID=" << t.getID() << " Cypher=" << t.Cypher() << endl;
}