#pragma once
#include "countable.h"
#include <vector>
using namespace std;
class Ticket :
	public Countable<Ticket>
{
	friend class MultiTicket;
public:
	Ticket();
	~Ticket();
	virtual void Cypher(int) = 0;
	virtual int Cypher() = 0;
	int getID();
	virtual bool good() = 0;
	friend ostream& operator<<(ostream& os, Ticket& t);
protected:
	int cypher;
	int id;
private:
	static vector<int> multIDs;
};

