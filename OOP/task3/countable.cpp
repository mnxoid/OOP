#include "countable.h"

int Countable::count = 0;
int Countable::id = 0;

Countable::Countable()
{
	count++;
	id++;
}

Countable::~Countable()
{
	count--;
}

int Countable::getCount()
{
	return count;
}

int Countable::getNextId()
{
	return id;
}