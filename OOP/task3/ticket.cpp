#include "ticket.h"
#include <iostream>
using namespace std;

Ticket::Ticket() : cypher(0), id(getNextId())
{
	cout << "Ticket with ID=" << id << "was created." << endl;
}


Ticket::~Ticket()
{
	cout << "Ticket with ID=" << id << "was thrown away." << endl;
}

void Ticket::Cypher(int c)
{
	cypher |= c;
}

int Ticket::Cypher()
{
	return cypher;
}