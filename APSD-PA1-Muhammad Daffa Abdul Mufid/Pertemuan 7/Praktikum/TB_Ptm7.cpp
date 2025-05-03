#include <iostream>
using namespace std;

int main() 
{
    int input[] = {0, 6, 12, 18, 24};
    int size = sizeof(input) / sizeof(input[0]);
    
    int data_dicari;
    cout << "Masukkan data yang dicari: ";
    cin >> data_dicari;
    
    int L = 0;
    int R = size - 1;
	bool tm = false;

    while (R >= L)
	{
        int mid = (L + R) / 2;

        if (input[mid] == data_dicari) {
            tm = true;
            break;
        } else if (input[mid] < data_dicari) {
            L = mid + 1;
        } else {
            R = mid - 1;
        }
    }
    
    if (tm)
	{
        cout << "Bilangan ditemukan" << endl;
    } else {
        cout << "Bilangan tidak ditemukan" << endl;
    }

    return 0;
}
