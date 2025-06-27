#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>

using namespace std;

const int MAX_SIZE = 200;
int storage[MAX_SIZE];

int hdt_boundary;
int prime_bawah;

int cari_prima_atas(int n) {
    int calon_prima = (n % 2 == 0) ? n + 1 : n + 2;
    while (true) {
        bool is_prima = true;
        if (calon_prima % 2 == 0) {
            is_prima = false;
        } else {
            for (int i = 3; i <= sqrt(calon_prima); i += 2) {
                if (calon_prima % i == 0) {
                    is_prima = false;
                    break;
                }
            }
        }
        if (is_prima) return calon_prima;
        calon_prima += 2;
    }
}

int cari_prima_bawah(int n) {
    int calon_prima = n - 1;
    if (calon_prima % 2 == 0) calon_prima--;
    while (calon_prima > 1) {
        bool is_prima = true;
        for (int i = 3; i <= sqrt(calon_prima); i += 2) {
            if (calon_prima % i == 0) {
                is_prima = false;
                break;
            }
        }
        if (is_prima) return calon_prima;
        calon_prima -= 2;
    }
    return 2;
}

void tambah_double_hashing(int n) {
    int h1 = n % hdt_boundary;
    int h2_step = prime_bawah - (n % prime_bawah);
    int i = 0;
    bool inserted = false;

    while (!inserted && i < hdt_boundary) {
        int hash_index = (h1 + i * h2_step) % hdt_boundary;

        if (storage[hash_index] == 0) {
            storage[hash_index] = n;
            inserted = true;
            if (i == 0) {
                cout << "Data " << n << " -> Langsung masuk di indeks " << hash_index << endl;
            } else {
                cout << "Data " << n << " -> Masuk di indeks " << hash_index << " setelah " << i << " kali probe." << endl;
            }
        } else {
            cout << "Data " << n << " -> Tabrakan di indeks " << hash_index << ". Mencari slot lain..." << endl;
            i++;
        }
    }

    if (!inserted) {
        cout << "Gagal menyisipkan " << n << ". Tabel mungkin sudah penuh." << endl;
    }
}

void cetak_hashtable() {
    cout << "\n===== ISI HASH TABLE AKHIR =====\n";
    cout << "Ukuran Tabel: " << hdt_boundary << endl;
    cout << "----------------------------------\n";
    for (int a = 0; a < hdt_boundary; ++a) {
        cout << "hash[" << a << "] = ";
        if(storage[a] == 0) {
            cout << "[ KOSONG ]" << endl;
        } else {
            cout << storage[a] << endl;
        }
    }
    cout << "==================================\n";
}

int main() {
    srand((unsigned)time(0));
    int jumlah_data;

    cout << "Masukkan jumlah data yang ingin disisipkan: ";
    cin >> jumlah_data;

    hdt_boundary = cari_prima_atas(jumlah_data);

    if (hdt_boundary > MAX_SIZE) {
        cout << "Error: Jumlah data terlalu besar untuk kapasitas program (Maks: " << MAX_SIZE << ")." << endl;
        return 1;
    }
    
    prime_bawah = cari_prima_bawah(hdt_boundary);
    
    for(int i = 0; i < hdt_boundary; i++) {
        storage[i] = 0;
    }

    cout << "\nProses Pemasukan Data ke Hashtable (Double Hashing)" << endl;
    cout << "Ukuran tabel diatur menjadi: " << hdt_boundary << endl;
    cout << "Bilangan prima untuk h2 diatur menjadi: " << prime_bawah << endl;
    cout << "--------------------------------------------------------" << endl;

    for (int a = 0; a < jumlah_data; ++a) {
        int random_number = 1 + (rand() % 100);
        tambah_double_hashing(random_number);
    }

    cetak_hashtable();

    cout << "\nFormula yang digunakan:\n";
    cout << "h1(k) = k % " << hdt_boundary << endl;
    cout << "h2(k) = " << prime_bawah << " - (k % " << prime_bawah << ")\n";
    cout << "Index = (h1(k) + i * h2(k)) % " << hdt_boundary << endl;

    return 0;
}
