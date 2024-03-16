#include <iostream>

using namespace std;

int main(){
    int maks, a, i = 1, lokasi; //deklarasi variabel bertipe data integer

    //menginputkan panjang array 
    cout << "Masukkan panjang array = ";
    cin >> a;

    //menginputkan elemen array
    int array[a];
    cout << "Masukkan " << a << "angka" << endl;
    for(i=0; i<a; i++){
        cout << "Array ke-" << i << " = ";
        cin >> array[i];
    }

    //Sorting elemen-elemen array menggunakan algoritma bubble sort
    maks = array[0];
    for(i=0; i<a; i++){
        if(array[i] > maks){
            maks = array[i];
            lokasi = i;
        }
    }

    //cetak nilai maksimum diatara elemen-elemen array
    cout << "Nilai maksimum adalah " << maks << " berada di array ke " << lokasi << endl;

    return 0;
}