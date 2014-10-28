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

int Ticket::getID()
{
	return id;
}