#include <iostream>

using namespace std;

// Fungsi untuk menggabungkan dua bagian array yang sudah diurutkan
void merge(int arr[], int l, int m, int r) 
{
    int x, y, z;
    int n1 = m - l + 1; // Panjang subarray kiri
    int n2 = r - m;     // Panjang subarray kanan

    int L[n1], R[n2];   // Buat array sementara untuk menyimpan subarray kiri dan kanan

    // Copy data ke subarray kiri L[] dan subarray kanan R[]
    for (x = 0; x < n1; x++)
        L[x] = arr[l + x]; 
    for (y = 0; y < n2; y++)
        R[y] = arr[m + 1 + y]; 

    x = 0; // Indeks awal subarray kiri
    y = 0; // Indeks awal subarray kanan
    z = l; // Indeks awal array utama yang akan diisi hasil merge

    // Bandingkan elemen dari kedua subarray dan masukkan yang lebih kecil ke dalam array utama
    while (x < n1 && y < n2)
    {
        if (L[x] <= R[y]) // Jika elemen kiri lebih kecil atau sama dengan elemen kanan
        {
            arr[z] = L[x]; // Masukkan elemen dari subarray kiri ke array utama
            x++; // Geser indeks kiri ke elemen berikutnya
        }
        else
        {
            arr[z] = R[y]; // Masukkan elemen dari subarray kanan ke array utama
            y++; // Geser indeks kanan ke elemen berikutnya
        }
        z++; // Geser indeks array utama
    }

    // Jika masih ada elemen yang tersisa di subarray kiri, masukkan ke array utama
    while (x < n1)
    {
        arr[z] = L[x];
        x++;
        z++;
    }

    // Jika masih ada elemen yang tersisa di subarray kanan, masukkan ke array utama
    while (y < n2)
    {
        arr[z] = R[y];
        y++;
        z++;
    }
}

// Fungsi rekursif untuk membagi array menjadi subarray dan mengurutkannya
void mergeSort(int arr[], int l, int r)
{
    if (l < r) // Jika masih ada lebih dari satu elemen dalam array
    {
        int m = l + (r - l) / 2; // Tentukan titik tengah array

        // Panggil mergeSort untuk bagian kiri
        mergeSort(arr, l, m);

        // Panggil mergeSort untuk bagian kanan
        mergeSort(arr, m + 1, r);

        // Gabungkan dua bagian yang sudah diurutkan
        merge(arr, l, m, r);
    }
}

// Fungsi untuk menampilkan isi array
void show(int A[], int size)
{
    for (int i = 0; i < size; i++)
        cout << A[i] << " ";
    cout << endl;
}

// Fungsi utama (main)
int main()
{
    int size;
    cout << "\nMasukkan Banyak Data : "; // Meminta input jumlah elemen array
    cin >> size;

    int arr[size];

    // Input elemen array dari pengguna
    for (int i = 0; i < size; ++i)
    {
        cout << "\nMasukkan Data array ke-" << i << " : ";
        cin >> arr[i];
    }

    // Memanggil fungsi mergeSort untuk mengurutkan array
    mergeSort(arr, 0, size - 1);

    cout << "\nHasil setelah sorting:\n";
    show(arr, size); // Menampilkan hasil array yang sudah diurutkan

    return 0;
}

