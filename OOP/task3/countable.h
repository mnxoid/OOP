#ifndef _countable_header_
#define _countable_header_
//--------------------------
class Countable
{
private:
	static int count;
	static int id;
public:
	Countable();
	~Countable();
	static int getCount();
	static int getNextId();
};
//--------------------------
#endif