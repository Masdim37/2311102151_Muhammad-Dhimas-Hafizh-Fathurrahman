#include <iostream>
#include <map> 

using namespace std;

int main() {
    string Buah_151;

    // Deklarasi map dengan key string dan value integer
    map <string, int> Stok_151;
  
    // Menambahkan jumlah stok untuk setiap jenis buah ke dalam map
    Stok_151["jeruk"] = 27; //jika user menginputkan "jeruk", maka akan ditampilkan 27 kg
    Stok_151["apel"] = 20; //jika user menginputkan "apel", maka akan ditampilkan 20 kg
    Stok_151["pir"] = 31; //jika user menginputkan "pir", maka akan ditampilkan 31 kg
    Stok_151["anggur"] = 17; //jika user menginputkan "anggur", maka akan ditampilkan 17 kg
    Stok_151["semangka"] = 45; //jika user menginputkan "semangka", maka akan ditampilkan 45 kg
    Stok_151["melon"] = 38; //jika user menginputkan "melon", maka akan ditampilkan 38 kg

    cout << "--- Cek Stok Buah ---" << endl;
    cout << "Buah yang tersedia = jeruk, apel, pir, anggur, semangka, melon" << endl;
    cout << endl;
    cout << "Masukkan nama buah untuk mengecek jumlah stok = ";
    cin >> Buah_151;
    cout << endl;
    
    //mengecek stok buah berdasarkan nama buah yang diinput user
    if (Stok_151.find(Buah_151) != Stok_151.end()) { //jika buah yang dicari ada dalam map Stok_151, maka tampilkan output
        cout << "Jumlah stok " << Buah_151 << " adalah " << Stok_151[Buah_151] << " kg" << endl;
    } else { //jika buah yang dicari tidak ada dalam map Stok_151, maka tampilkan output
        cout << "Buah tidak ditemukan dalam katalog." << endl;
    }
    
    return 0;
}