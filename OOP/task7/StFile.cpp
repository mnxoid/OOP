#include "StFile.h"


StFile::StFile() : MyStack(this), LFFstream()
{
}

StFile::~StFile()
{
	this->close();
}

void StFile::Show()
{
	this->reverseRenumber()->purge();
}

