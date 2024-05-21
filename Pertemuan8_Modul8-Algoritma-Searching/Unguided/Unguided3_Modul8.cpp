#include<iostream>

using namespace std;

int main(){
    int ArrayData_151[10] = {9, 4, 1, 4, 7, 10, 5, 4, 12, 4}; //Deklarasi array bernama ArrayData_151 dengan ukuran 10 
    int CariAngka_151; //Deklarasi variabel CariAngka_151 yang menampung angka yang ingin dicari
    int JumlahAngka_151 = 0; //Deklarasi variabel JumlahAngka_151 dengan nilai 0 untuk menghitung jumlah angka yang ingin dicari yang ada pada array
    int IndexAngka_151[10]; //Deklarasi array IndexAngka_151 dengan ukuran 10 untuk menyimpan index dari angka yang dicari didalam array ArrayData_151
    int j = 0; //Deklarasi variabel j
    cout << "--- PROGRAM PENGHITUNG ANGKA DALAM ARRAY ---" << endl;
    cout << "Diketahui sebuah array berisi data = {9, 4, 1, 4, 7, 10, 5, 4, 12, 4}" << endl;
    cout << "Masukkan angka yang ingin dihitung jumlahnya = "; //User memasukkan angka yang ingin dihitung jumlahnya
    cin >> CariAngka_151;
    cout << endl;

    //Sequential Search
    for(int i = 0; i < 10; i++){
        if(ArrayData_151[i] == CariAngka_151){ //Jika setiap data yang tersimpan pada array ArrayData_151 sama dengan angka yang diinputkan user yang ingin dihitung jumlahnya, maka lanjutkan
            JumlahAngka_151++; //variabel JumlahAngka_151 bertambah nilainya
            IndexAngka_151[j++] = i; //nilai i dimasukkan ke array IndexAngka_151 indeks ke j++ (0)
        }
    }

    if(JumlahAngka_151 != 0){ //jika variabel JumlahAngka_151 nilainya tidak sama dengan 0, maka lanjutkan
        cout << "Array tersebut memiliki angka " << CariAngka_151 << " sebanyak " << JumlahAngka_151 << endl;
        cout << "Ditemukan pada index ke-";
        //perulangan untuk menampilkan index dari angka yang dicari
        for(int i = 0; i < JumlahAngka_151; i++){
            cout << IndexAngka_151[i];
            if(i < j - 1){
                cout << ", ";
            }
        }
    } else { //jika variabel JumlahAngka_151 nilainya sama dengan 0, maka lanjutkan
        cout << "Array tersebut tidak berisi angka " << CariAngka_151 << endl;
    }
    
    return 0; 
}