#pragma once
#include <fstream>
#include <string>
using namespace std;
class line : public string {
public:
	friend std::istream &operator>>(std::istream &is, line &l) {
		std::getline(is, l, '\n');
		return is;
	}
	operator std::string() const { return *this; }
};



class LFFstream :
	public fstream
{
public:
	typedef istream_iterator<line> ii;
	LFFstream();
	~LFFstream();
};

LFFstream& operator>>(LFFstream& is, line &l);
