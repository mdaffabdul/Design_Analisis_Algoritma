#include <iostream>

using namespace std;

int main()
{
	int angka[5];
	
	cout << "Isi array:" << endl;
	
	for(int a = 0; a < 5; a++ )
	{
		cout << "angka[" << a << "]" << " = ";
		cin >> angka[a];
	}
	
	return 0;
}
