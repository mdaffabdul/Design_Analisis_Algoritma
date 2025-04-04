#include <iostream>
#include <string>

using namespace std;
class pelajaran //class name
{
	public: //access specifier
	pelajaran () { //constructor
		cout << "Ini adalah materi C++ tentang Constructors!";
	}	
};

int main ()
{
	pelajaran obj; //membuat object dari sebuah class
	
	return 0;
}
