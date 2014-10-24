#include "multiticket.h"
#include "ticket.h"
#include <algorithm>
#include <iostream>

MultiTicket::MultiTicket()
{
	cout << "MultiTicket with ID=" << id << " was created." << endl;
	Ticket::multIDs.push_back(id);
	usesleft = 1;
}

MultiTicket::MultiTicket(int n) : MultiTicket()
{
	usesleft = n;
}

MultiTicket::~MultiTicket()
{
	auto el = find(Ticket::multIDs.begin(), Ticket::multIDs.end(), id);
	if (el != Ticket::multIDs.end())
	{
		Ticket::multIDs.erase(el);
	}
}

bool MultiTicket::good()
{
	if (usesleft < 1) return false;
	else return true;
}

void MultiTicket::Cypher(int c)
{
	cypher |= c;
	usesleft--;
}

int MultiTicket::Cypher()
{
	return cypher;
}

ostream& operator<<(ostream& os, MultiTicket& t)
{
	return os << "Ticket: ID=" << t.getID() << " Cypher=" << t.Cypher() << " Uses left: " << t.usesleft << endl;
}
