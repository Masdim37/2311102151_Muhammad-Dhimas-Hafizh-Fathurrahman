#include <iostream>

using namespace std;

//Prosedur untuk menampilkan elemen array yang telah tersimpan
void OutputArray_151(int PanjangArray, int Array[]){
    cout << "Array[" << PanjangArray << "] = ";
    for(int i=0; i<PanjangArray; i++){
        cout << Array[i] << ", " << ends;
    }
    cout << endl;
}

int main(){
    int PanjangArray_151, Pilihan_151, maks_151, min_151, lokasi_151, jumlah_151;
    double RataRata_151;
    cout << "--- PROGRAM ARRAY ---" << endl;
    cout << "Silahkan masukkan data array 1 dimensi" << endl;
    cout << "Masukkan panjang array = ";  cin >> PanjangArray_151;
    
    //Deklarasi array
    int Array_151[PanjangArray_151];
    //Input elemen array
    for(int i=0; i<PanjangArray_151; i++){
        cout << "Masukkan nilai indeks ke-" << i << " = ";
        cin >> Array_151[i];
    }
    cout << "Data array telah disimpan" << endl;
    cout << endl;

    MenuUtama: //Label MenuUtama
    cout << "- Menu Program array -" << endl;
    cout << "1. Mencari nilai maksimum" << endl;
    cout << "2. Mencari nilai minimum" << endl;
    cout << "3. Mencari nilai rata-rata" << endl;
    cout << "4. Keluar" << endl;
    cout << "Pilihan anda [1-4] = "; cin >> Pilihan_151;

    switch (Pilihan_151) { //Switchcase menu program array
    case 1 : //Jika memilih 1, maka mencari nilai maksimum
        OutputArray_151(PanjangArray_151, Array_151); //Tampilkan prosedur OutputArray_151
        //Searching untuk mencari nilai maksimum
        maks_151 = Array_151[0];
        for(int i=0; i<PanjangArray_151; i++){
            if(Array_151[i] > maks_151){
                maks_151 = Array_151[i];
                lokasi_151 = i;
            }
        }
        //cetak nilai maksimum diatara elemen-elemen array
        cout << "Nilai maksimum dalam array tersebut adalah " << maks_151 << " berada di indeks ke-" << lokasi_151 << endl;
        break;
    case 2 : //Jika memilih 2, maka mencari nilai minimum
        OutputArray_151(PanjangArray_151, Array_151); //Tampilkan prosedur OutputArray_151
        //Searching untuk mencari nilai maksimum
        min_151 = Array_151[0];
        for(int i=0; i<PanjangArray_151; i++){
            if(Array_151[i] < min_151){
                min_151 = Array_151[i];
                lokasi_151 = i;
            }
        }
        //cetak nilai minimum diatara elemen-elemen array
        cout << "Nilai minimum dalam array tersebut adalah " << min_151 << " berada di indeks ke-" << lokasi_151 << endl;
        break;
    case 3 : //Jika memilih 3, maka menghitung nilai rata-rata elemen array
        OutputArray_151(PanjangArray_151, Array_151); //Tampilkan prosedur OutputArray_151
        //Perulangan for untuk menjumlahkan elemen array
        for(int i=0; i<PanjangArray_151; i++){
            jumlah_151 += Array_151[i];
        }
        //Variabel RataRata_151 menyimpan nilai rata-rata elemen array
        RataRata_151 = jumlah_151 / PanjangArray_151;
        cout << "Rata-rata = " << jumlah_151 << " / " << PanjangArray_151 << endl;
        //cetak nilai rata-rata elemen array
        cout << "Rata-rata elemen array tersebut adalah " << RataRata_151 << endl;
        break;
    case 4 : //Jika memilih 4, maka keluar dari program
        cout << "Anda keluar dari program" << endl;
        break;
    default: //Output jika menginputkan selain 1-4
        cout << "Pilihan menu anda tidak tersedia" << endl;
        goto MenuUtama; //Pernyataan goto untuk kembali ke menu utama
        break;
    }

    return 0;
}