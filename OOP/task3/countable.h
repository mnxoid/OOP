#ifndef _countable_header_
#define _countable_header_
//--------------------------
class Countable
{
private:
	static int count;
public:
	Countable();
	~Countable();
	static int getCount();
};
//--------------------------
#endif