#include <iostream>
#include <vector>
using namespace std;

//Mengonversi angka biner ke bentuk segment
vector<int> BinerKeSegment(int x, int y, int z) {
    static vector<vector<int>> table = {
        {1, 1, 1, 1, 1, 1, 0}, {0, 1, 1, 0, 0, 0, 0},
        {1, 1, 0, 1, 1, 0, 1}, {1, 1, 1, 1, 0, 0, 1},
        {0, 1, 1, 0, 0, 1, 1}, {1, 0, 1, 1, 0, 1, 1},
        {1, 0, 1, 1, 1, 1, 1}, {1, 1, 1, 0, 0, 0, 0}
    };
    return table[x * 4 + y * 2 + z]; //misal input 100, maka 1*4 + 0*2 + 0 = 4, maka yang terdisplay angka 4 atau array ke 4
}

//Menampilkan segment-segment berupa garis-garis
void TampilkanSegment(const vector<int>& s) {
    cout << (s[0] ? " - - - \n" : "       \n");                         //   A
    cout << (s[5] ? "|" : " ") << "     " << (s[1] ? "|\n" : " \n");    //F dan B
    cout << (s[6] ? " - - - \n" : "       \n");                         //   G
    cout << (s[4] ? "|" : " ") << "     " << (s[2] ? "|\n" : " \n");    //E dan C
    cout << (s[3] ? " - - - \n" : "       \n");                         //   D
}

//Fungsi main yang menjadi tempat input angka biner dan eksekusian program
int main() {
    int x, y, z;
    cout << "Masukkan nilai X (0/1): "; cin >> x;
    cout << "Masukkan nilai Y (0/1): "; cin >> y;
    cout << "Masukkan nilai Z (0/1): "; cin >> z;

    if (x < 0 || x > 1 || y < 0 || y > 1 || z < 0 || z > 1) {
        cout << "Input harus berupa 0 atau 1 ya...\n";
        return 1;
    }

    TampilkanSegment(BinerKeSegment(x, y, z));
    return 0;
}
