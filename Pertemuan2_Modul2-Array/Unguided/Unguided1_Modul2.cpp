#include <iostream>

using namespace std;

int main(){
    int PanjangArray_151;

    //input panjang array
    cout << "Masukkan panjang array = ";
    cin >> PanjangArray_151;

    //Input elemen-elemen array
    int Data_151[PanjangArray_151];
    for(int i = 0; i < PanjangArray_151; i++){
        cout << "Masukkan nilai array indeks ke-" << i << " = ";
        cin >> Data_151[i];
    }
    cout << endl;

    //output data array
    cout << "Data array = ";
    for(int i = 0; i < PanjangArray_151; i++){
        cout << Data_151[i] << " " << ends;
    }
    cout << endl;

    //otput elemen array bilangan genap
    cout << "Nomor genap = ";
    for(int i = 0; i < PanjangArray_151; i++){
        if(Data_151[i] % 2 == 0){ //jika nilai array Data_151 indeks ke i dibagi 2 memiliki sisa 0, maka tampilkan output
            cout << Data_151[i] << ", " << ends;
        }
    }
    cout << endl;

    //otput elemen array bilangan ganjil
    cout << "Nomor ganjil = ";
    for(int i = 0; i < PanjangArray_151; i++){ 
        if(Data_151[i] % 2 == 1){ //jika nilai array Data_151 indeks ke i dibagi 2 memiliki sisa 1, maka tampilkan output
            cout << Data_151[i] << ", " << ends;
        }
    }
    cout << endl;

    return 0;
}