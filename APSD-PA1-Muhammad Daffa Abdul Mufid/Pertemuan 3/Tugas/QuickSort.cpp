#include <iostream>
using namespace std;

void swap (int arr [], int pos1, int pos2) // Fungsi untuk menukar dua elemen dalam array
{
	int temp; // Int temp sebagai tempat penyimpanan sementara pada saat penukaran
	temp = arr[pos1]; // Simpan nilai posisi pertama di temp
	arr[pos1] = arr [pos2]; // Pindahkan nilai posisi kedua ke posisi pertama
	arr[pos2] = temp; // Masukkan nilai yang disimpan di temp ke posisi kedua
}

int partition (int arr[], int low, int high, int pivot) // Fungsi untuk membagi array berdasarkan pivot
{
	int i = low;  // Penunjuk elemen yang sedang dibandingkan
    int j = low;  // Penunjuk tempat elemen kecil akan dipindahkan

	while ( i <= high) // Merupakan pengulangn dari low sampai high
	{
		if(arr[i] > pivot) // Jika elemen pada indeks i lebih besar dari pivot
		{
			i++; // Lewati elemen yang lebih besar dari pivot
		}
		else
		{
			swap (arr,i,j); // Menukar elemen lebih kecil ke posisi kiri (j) dan maju ke elemen berikutnya
			i++;
			j++;
		}
	}
	return j-1; return j-1; // Mengembalikan indeks akhir dari elemen yang lebih kecil atau sama dengan pivot
}

void quicksort (int arr[], int low, int high) // Fungsi untuk menjalankan quicksort
{
	if(low < high) 
	{
		int pivot = arr [high]; // pivot diletakan di akhir index pada array
		int pos = partition (arr, low, high, pivot); // Melempar nilai ke fungsi partisi untuk disusun yang dimana pos merupakan posisi pivot setelah fungsi 
		
		// Rekursi untuk mengurutkan bagian kiri dan kanan pivot
		quicksort (arr, low, pos-1); // Mensortir array pada kiri pivot
		quicksort (arr, pos+1, high); // Mensortir array pada kanan pivot
	}
}

int main()
{
	int n;
	cout << "Tentukan panjang array : "; // Input panjang array
	cin >> n;
	int arr[n];
	for (int i = 0; i < n; i++) // Looping untuk mengisi nilai array
	{
		cin >> arr[i];	
	}
	quicksort (arr, 0, n-1); // Nilai dilempar untuk sorting
	cout << "Berikut adalah array yang telah di sortir: "; // Output hasil input
	for ( int i = 0; i < n; i++) // Looping untuk output hasil sorting
	{
		cout << arr[i] << "\t";
	}
}
