#include <iostream>

using namespace std;

class buku 
{
	private:
		string judul;
		
	public: 
	buku (string judulbuku) { 
		judul = judulbuku;
		cout << "Buku " << judul << " ditambahkan";
	}
	
	~buku () { 
		cout << "\nBuku " << judul << " dihapus";
	}	
};

int main ()
{
	string judul;
	cout << "Masukkan judul buku: ";
	getline(cin, judul);
	
	buku buku1(judul);
}
