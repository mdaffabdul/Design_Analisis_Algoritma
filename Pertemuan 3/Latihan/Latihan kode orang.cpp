#include <iostream>
#include <string>
using namespace std;

int main ()
{
	int n;
	
	cout << "Masukkan total barang belanja (angka): ";
	cin >> n;
	
	string barang[n];
	
	for(int a = 0; a < n; a++)
	{
		cout << "Barang ke- " << a+1 << " : ";
		cin >> barang[a];
		cin.ignore();
	}
	
	cout << "\n";
	
	cout << "Daftar Barang Belanja\n";
	cout << "---------------------------\n";
	
	for(int a = 0; a < n; a++)
	{
		cout << a+1 << ". " << barang[a] << endl;
	}
	
	cout << "---------------------------";
}
