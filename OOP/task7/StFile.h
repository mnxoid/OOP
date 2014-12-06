#pragma once
#include "mystack.h"
#include "lffstream.h"
class StFile :
	public LFFstream, public MyStack
{
public:
	StFile();
	void Show();
	~StFile();
};

