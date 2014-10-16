#include "countable.h"

int Countable::count = 0;

Countable::Countable()
{
	count++;
}

Countable::~Countable()
{
	count--;
}

int Countable::getCount()
{
	return count;
}