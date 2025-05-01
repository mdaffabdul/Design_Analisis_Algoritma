#include <iostream>
#include <string>
using namespace std;

class mahasiswa {
	private:
		string nama [100];
		int nim [100];
		int ipk [100];
	public:
		void setnama(string nm [100]){
			nama [100]= nm [100];
		}
		void setnim(int npm [100]){
			nim [100]= npm [100];
		}
		void setipk(int pk [100]){
			ipk [100]= pk [100];
		}
		
		string getnama(){
			return nama [100];
		}
		int getnim(){
			return nim [100];
		}
		int getipk(){
			return ipk [100];
		}
};

int main()
{
	string nama [100];
	int nim [100];
	int ipk [100];
	int a;
	
	mahasiswa mhs;
	
	cout << "masukkan jumlah data yang ingin di input: ";
	cin >> a;
	
	for(int b=1; b<=a; b++)
	{
		cout << "masukkan nama: ";
		cin >> nama [b];
		mhs.setnama(nama [b]);
		
	}
	
	for(int c=1; c<=a; c++)
	{
	cout << mhs.getnama();
	}
}
