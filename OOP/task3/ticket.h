#pragma once
#include "countable.h"
#include <vector>
using namespace std;
class Ticket :
	public Countable
{
	friend class MultiTicket;
public:
	Ticket();
	~Ticket();
	virtual void Cypher(int);
	virtual int Cypher();
	int getID();
	virtual bool good();
	friend ostream& operator<<(ostream& os, Ticket& t);
private:
	int cypher;
	int id;
	static vector<int> multIDs;
};

