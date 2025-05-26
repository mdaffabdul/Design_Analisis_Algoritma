#include <iostream>
#include <cstdlib>  // untuk system("cls")
using namespace std;

class Node {
public:
    int nomorAntrian;
    string nama;
    Node* next;

    Node(int nomor, string nama) {
        this->nomorAntrian = nomor;
        this->nama = nama;
        this->next = NULL;
    }
};

class SistemAntrian {
private:
    Node* head;
    Node* tail;
    int nomorAntrian;

public:
    SistemAntrian() {
        head = tail = NULL;
        nomorAntrian = 1;
    }

    bool isEmpty() {
        return head == NULL;
    }

    void tambahAntrian() {
        system("cls");
        string nama;
        cout << "\nMasukkan Nama : ";
        cin.ignore();
        getline(cin, nama);

        Node* newNode = new Node(nomorAntrian, nama);
        nomorAntrian++;

        if (isEmpty()) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }

        cout << "\n" << nama << " ditambahkan ke dalam antrian.\n";
    }

    void layaniAntrian() {
        system("cls");

        if (isEmpty()) {
            cout << "\nAntrian kosong. Tidak ada yang dapat dilayani.\n";
        } else {
            Node* current = head;
            cout << "\nMelayani: " << current->nama << " (Nomor Antrian: " << current->nomorAntrian << ")\n";
            head = head->next;
            delete current;

            if (head == NULL) {
                tail = NULL;
            }
        }
    }

    void tampilkanAntrian() {
        system("cls");

        if (isEmpty()) {
            cout << "\nAntrian kosong.\n";
        } else {
            Node* current = head;
            cout << "\n========== DAFTAR ANTRIAN ==========\n";
            while (current != NULL) {
                cout << "Nomor " << current->nomorAntrian << " - " << current->nama << endl;
                current = current->next;
            }
            cout << "=====================================\n";
        }
    }

    void hapusSemua() {
        Node* current = head;
        while (current != NULL) {
            Node* temp = current;
            current = current->next;
            delete temp;
        }
        head = tail = NULL;
        cout << "\nSeluruh antrian telah dibersihkan.\n";
    }

    void pause() {
        cout << "\nTekan Enter untuk melanjutkan...";
        cin.get();
    }
};

int main() {
    SistemAntrian antrian;
    char pilihan;
    bool ongoing = true;

    while (ongoing) {
        cout << "\n======================================" << endl;
        cout << "         SISTEM ANTRIAN LOKET         " << endl;
        cout << "======================================" << endl;
        cout << " 1. Tambah Antrian" << endl;
        cout << " 2. Layani Antrian (Keluarkan)" << endl;
        cout << " 3. Tampilkan Seluruh Antrian" << endl;
        cout << " 4. Keluar / Reset Sistem" << endl;
        cout << "======================================" << endl;
        cout << " Pilih opsi [1-4] : ";
        cin >> pilihan;

        switch (pilihan) {
            case '1':
                antrian.tambahAntrian();
                antrian.pause();
                system("cls");
                break;
            case '2':
                antrian.layaniAntrian();
                antrian.pause();
                system("cls");
                break;
            case '3':
                antrian.tampilkanAntrian();
                antrian.pause();
                system("cls");
                break;
            case '4':
                system("cls");
                antrian.hapusSemua();
                cout << "\nSistem dimatikan. Terima kasih.\n" << endl;
                ongoing = false;
                break;
            default:
                system("cls");
                cout << "\nPilihan tidak valid. Silakan pilih antara 1 - 4.\n";
        }
    }

    return 0;
}

