#include <iostream>

using namespace std;

int PanjangArray_151;

void OutputArray151(){
    int array[PanjangArray_151];
    cout << "Array[" << PanjangArray_151 << "] = ";
    for(int i=0; i<PanjangArray_151; i++){
        cout << array[i] << ", " << ends;
    }
    cout << endl;
}

int main(){
    int Pilihan_151, maks_151, min_151, lokasi_151, jumlah_151;
    float RataRata_151;
    cout << "--- SEPUTAR ARRAY ---" << endl;
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

    MenuUtama:
    cout << "- Menu seputar array -" << endl;
    cout << "1. Mencari nilai maksimum" << endl;
    cout << "2. Mencari nilai minimum" << endl;
    cout << "3. Mencari nilai rata-rata" << endl;
    cout << "4. Keluar" << endl;
    cout << "Pilihan anda [1-4] = "; cin >> Pilihan_151;

    switch (Pilihan_151) {
    case 1 :
        OutputArray151();
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
    case 2 :
        OutputArray151();
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
    case 3 :
        OutputArray151();
        for(int i=0; i<PanjangArray_151; i++){
            jumlah_151 += Array_151[i];
        }
        RataRata_151 = jumlah_151 / PanjangArray_151;
        //cetak nilai rata-rata elemen array
        cout << "Rata-rata elemen array tersebut adalah " << RataRata_151 << endl;
        break;
    case 4 :
        cout << "Anda keluar dari program" << endl;
        break;
    default:
        cout << "Pilihan menu anda tidak tersedia" << endl;
        goto MenuUtama;
        break;
    }

    return 0;
}