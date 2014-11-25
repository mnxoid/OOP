#ifndef _countable_header_
#define _countable_header_
//--------------------------
template<class T>
class Countable
{
private:
	static int count;
	static int id;
public:
	Countable()
	{
		count++;
		id++;
	}
	~Countable()
	{
		count--;
	}
	static int getCount()
	{
		return count;
	}
protected:
	static int getNextId()
	{
		return id;
	}
};
template <class T> int Countable<T>::count = 0;
template <class T> int Countable<T>::id = 0;
//--------------------------
#endif