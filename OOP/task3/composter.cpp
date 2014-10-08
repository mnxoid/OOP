#include "composter.h"
#define null 0
int Composter::nextSerial = 0;

Composter::Composter() : t(null)
{
	serialNumber = nextSerial;
	nextSerial++;

}


Composter::~Composter()
{
}
