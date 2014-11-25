








#include <iostream>
#include <fstream>
#include <iterator>
#include <string>
class line {
	std::string data;
public:
	friend std::istream &operator>>(std::istream &is, line &l) {
		std::getline(is, l.data, '\0');
		return is;
	}
	operator std::string() const { return data; }
};



int main()
{
	system("echo line > mnxoid.txt");
	system("echo another line >> mnxoid.txt");
	system("echo yet another line >> mnxoid.txt");
	system("echo not a line >> mnxoid.txt");
	system("echo maybe a line >> mnxoid.txt");
	std::ifstream in("mnxoid.txt");
	std::istream_iterator<line> it_first(in);
	std::istream_iterator<line> it_last;
	std::ostream_iterator<std::string> it_out(std::cout, "\n");
	std::copy(it_first, it_last, it_out);
	in.close();
	std::cout << std::endl;
	system("pause");
}