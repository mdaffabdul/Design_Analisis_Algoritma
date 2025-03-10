#include <iostream>
#include <string>

using namespace std;

void bubblesort (string arr[],int n)
{
	int i, j;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n - i -1; j++)
		{
			if (arr[j] > arr[j+1])
			{
				swap(arr[j], arr[j+1]);
			}
		}
	}
}

int main()
{
	int n;
	
	cout << "Masukkan Jumlah Buku: ";
	cin >> n;
	cin.ignore();
	
	string words[n];
	
	cout << endl;
	
	for (int i = 0; i < n; i++)
	{
	cout << "Masukkan Judul Buku ke - " << i+1 << " :";
	getline(cin, words[i]);
	}
	
	cout << endl;
	
	bubblesort(words, n);
	
	cout << "Hasil Pengurutan Judul Buku:\n";
	for (int i = 0; i < n; i++)
	{
		cout << words[i] << "\n";
	}
	
	return 0;
}
