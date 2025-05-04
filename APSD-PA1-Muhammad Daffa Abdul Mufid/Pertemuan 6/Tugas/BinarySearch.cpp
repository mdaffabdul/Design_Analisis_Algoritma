#include <iostream>
using namespace std;

struct Buku {
    string judul;
    string rak;
};

void urutkanBuku(Buku buku[], int jumlah) {
    for (int i = 0; i < jumlah - 1; i++) {
        for (int j = 0; j < jumlah - i - 1; j++) {
            if (buku[j].judul > buku[j + 1].judul) {
                Buku temp = buku[j];
                buku[j] = buku[j + 1];
                buku[j + 1] = temp;
            }
        }
    }
}

int binarySearch(Buku buku[], int jumlah, string target) {
    int kiri = 0, kanan = jumlah - 1;
    while (kiri <= kanan) {
        int tengah = (kiri + kanan) / 2;
        string judulTengah = buku[tengah].judul;
        if (judulTengah == target) {
            return tengah;
        } else if (judulTengah < target) {
            kiri = tengah + 1;
        } else {
            kanan = tengah - 1;
        }
    }
    return -1;
}

int main() {
    Buku daftarBuku[] = {
        {"algoritma dan struktur data", "Rak A1"},
        {"basis data", "Rak B3"},
        {"interaksi komputer dan manusia", "Rak C2"},
        {"matematika diskrit", "Rak D1"},
        {"elektronika dasar", "Rak A3"},
        {"sistem operasi", "Rak B1"},
        {"bahasa indonesia", "Rak C1"}
    };

    int jumlahBuku = sizeof(daftarBuku) / sizeof(daftarBuku[0]);

    urutkanBuku(daftarBuku, jumlahBuku);

    string inputJudul;
    cout << "Masukkan judul buku (huruf kecil semua): ";
    getline(cin, inputJudul);

    int indeks = binarySearch(daftarBuku, jumlahBuku, inputJudul);

    if (indeks != -1) {
        cout << "Buku ditemukan di " << daftarBuku[indeks].rak << endl;
    } else {
        cout << "Buku tidak ditemukan di perpustakaan." << endl;
    }

    return 0;
}
