#pragma once
#include "countable.h"
class Ticket :
	public Countable
{
public:
	Ticket();
	~Ticket();
	void Cypher(int);
	int Cypher();
private:
	int cypher;
	int id;
};

