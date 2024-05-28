#include <iostream>
#include <iomanip>

using namespace std;

//Fungsi untuk menampilkan graph dalam format matriks
void TampilGraph_151(int JumlahSimpul_2311102151, string* NamaSimpul_2311102151, int** BobotSimpul_151) {
    //menampilkan baris pertama berupa simpul nama kota
    cout << setw(10) << " ";
    for (int i = 0; i < JumlahSimpul_2311102151; i++) {
        cout << setw(10) << NamaSimpul_2311102151[i];
    }
    cout << endl;

    // Menampilkan bobot kota secara matriks
    for (int baris_151 = 0; baris_151 < JumlahSimpul_2311102151; baris_151++) {
        cout << setw(10) << NamaSimpul_2311102151[baris_151];
        for (int kolom_151 = 0; kolom_151 < JumlahSimpul_2311102151; kolom_151++) {
            cout << setw(10) << BobotSimpul_151[baris_151][kolom_151];
        }
        cout << endl;
    }
}

int main() {
    int JumlahSimpul_2311102151;
    int Nomor_151 = 1;
    int Bobot_151;

    cout << "--- PROGRAM GRAPH SEDERHANA ---" << endl;

    //User menginputkan jumlah simpul (jumlah kota)
    cout << "Masukkan jumlah simpul = ";
    cin >> JumlahSimpul_2311102151;

    //membuat array NamaSimpul_2311102151 yang dialokasikan secara dinamis berdasarkan input jumlah simpul
    string* NamaSimpul_2311102151 = new string[JumlahSimpul_2311102151];

    //user memasukkan nama simpul (nama kota)
    cout << "--- Masukkan nama simpul ---" << endl; 
    for (int i = 0; i < JumlahSimpul_2311102151; i++) {
        cout << "Masukkan nama simpul " << Nomor_151++ << " = ";
        cin >> NamaSimpul_2311102151[i];
    }
    cout << endl;

    //membuat array BobotSimpul_151 yang dialokasikan secara dinamis berdasarkan input jumlah simpul
    int** BobotSimpul_151 = new int*[JumlahSimpul_2311102151];
    for (int i = 0; i < JumlahSimpul_2311102151; i++) {
        BobotSimpul_151[i] = new int[JumlahSimpul_2311102151]();
    }

    //user emasukkan bobot antar simpul
    cout << "--- Masukkan Bobot Antar Simpul ---" << endl;
    for (int i = 0; i < JumlahSimpul_2311102151; i++) {
        for (int j = 0; j < JumlahSimpul_2311102151; j++) {
            if (i != j) {
                cout << "Bobot " << NamaSimpul_2311102151[i] << " --> " << NamaSimpul_2311102151[j] << " = ";
                cin >> Bobot_151;
                BobotSimpul_151[i][j] = Bobot_151;
            }
        }
    }
    cout << endl;

    //memanggil fungsi TampilGraph_151
    TampilGraph_151(JumlahSimpul_2311102151, NamaSimpul_2311102151, BobotSimpul_151);

    return 0;
}