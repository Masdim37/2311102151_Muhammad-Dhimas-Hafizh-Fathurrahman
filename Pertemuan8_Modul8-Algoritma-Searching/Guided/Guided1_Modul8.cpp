#include <iostream>

using namespace std;

int main(){
    int n = 10; //deklarasi variabel n sebagai ukuran array
    int data[10] = {9, 4, 1, 7, 5, 12, 4, 13, 3, 10}; //deklarasi array data 
    int cari = 10; //deklarasi variabel cari dengan nilai 10 (angka yang dicari adalah 10)
    bool ketemu = false; //deklarasi variabel boolean ketemu dengan nilai false
    int i; //deklarasi variabel i

    //Sequential Search untuk mencari angka 10
    for(i=0; i < n; i++){
        if(data[i] == cari){ //jika nilai pada array data index ke i adalah 10, maka 
            ketemu = true; //ubah variabel boolean ketemu menjadi true
            break; //perulangan berhenti
        }
    }

    cout << "Program Sequential Search" << endl;
    cout << "Data = {9, 4, 1, 7, 5, 12, 4, 13, 3, 10}" << endl; //menampilkan isi array data

    if(ketemu){ //jika angka 10 ditemukan, maka tampilkan
        cout << "\nAngka " << cari << " ditemukan pada indeks ke " << i << endl; 
    } else { //jika angka 10 tidak ditemukan, maka tampilkan
        cout << "Data tidak ditemukan!" << endl;
    }

    return 0;
}