#include <iostream>
using namespace std;

class contoh
{
    private:
        int nilai; // Atribut private untuk menyimpan nilai

    public:
        contoh (int n) // Constructor yang menerima parameter n
        {
            nilai = n; // Menginisialisasi atribut nilai dengan nilai dari parameter n
        }

        int getNum() // Method untuk mendapatkan nilai dari atribut nilai
        {
            return nilai; // Mengembalikan nilai yang tersimpan
        }
};

int main()
{
    contoh obj(10); // Membuat objek "obj" dari kelas "contoh" dengan nilai 10

    cout << "Nilai yang diinput: " << obj.getNum() << endl; // Menampilkan nilai yang diinput menggunakan method getNum()

    return 0;
}

