#include <iostream>
#include <string>
using namespace std;

class Mahasiswa {
private:
    string nama;
    int nim;
    float ipk;

public:
    void setnama(string nm) {
        nama = nm;
    }

    void setnim(int npm) {
        nim = npm;
    }

    void setipk(float pk) {
        ipk = pk;
    }

    string getnama() const {
        return nama;
    }

    int getnim() const {
        return nim;
    }

    float getipk() const {
        return ipk;
    }

    void tampilkan() const {
        cout << nama << "\t| " << nim << "\t| IPK: " << ipk << endl;
    }
};


void bubblesort(Mahasiswa arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j].getipk() < arr[j + 1].getipk()) {
                Mahasiswa tmp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = tmp;
            }
        }
    }
}

int main() {
    const int MAX = 100;
    Mahasiswa mhs[MAX];
    int jumlah;
    string nama;
    int nim;
    float ipk;

    cout << "Masukkan jumlah mahasiswa: ";
    cin >> jumlah;
    cin.ignore();

    for (int i = 0; i < jumlah; i++) {
        cout << "\nMahasiswa ke-" << i + 1 << endl;

        cout << "Masukkan Nama: ";
        getline(cin, nama);

        cout << "Masukkan NIM: ";
        cin >> nim;

        cout << "Masukkan IPK: ";
        cin >> ipk;
        cin.ignore();

        mhs[i].setnama(nama);
        mhs[i].setnim(nim);
        mhs[i].setipk(ipk);
    }

    
    bubblesort(mhs, jumlah);

    cout << "\nDaftar Mahasiswa:\n";
    for (int i = 0; i < jumlah; i++) {
        mhs[i].tampilkan();
    }

    return 0;
}

