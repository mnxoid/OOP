#pragma once
#include <string>
using namespace std;
class Serializable
{
public:
	Serializable();
	virtual string Serialize() = 0;
	virtual void Deserialize(string s) = 0;
	~Serializable();
};

