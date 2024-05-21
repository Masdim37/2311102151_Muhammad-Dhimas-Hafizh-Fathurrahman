#include<iostream>
#include<conio.h>
#include<iomanip>

using namespace std;

int dataArray[7] = {1, 8, 2, 5, 4, 9, 7}; //deklarasi array dataArray beserta isinya
int cari; //deklarasi variabel cari

//prosedur Selection_Sort untuk mengurutkan data secara ascending
void Selection_Sort(){
    int temp, min, i, j; 
    for(i = 0; i < 7; i++){ //perulangan for untuk memeriksa setiap data 
        min = i; //nilai min adalah 0
        for(j = i + 1; j < 7; j++){ //nilai j adalah 1
            if(dataArray[j] < dataArray[min]){ //jika nilai pada dataArray index ke j (1) kurang dari nilai pada dataArray index ke i (0), maka 
                min = j; //nilai min adalah j
            }
        }
        temp = dataArray[i]; //masukkan nilai pada dataArray index ke i kedalam temp
        dataArray[i] = dataArray[min]; //isi dataArray index ke i dengan dataArray index min (j)
        dataArray[min] = temp; //isi dataArray index min (j) dengan nilai temp
    }
}

//prosedur BinarySearch untuk mencari data
void BinarySearch(){
    int awal, akhir, tengah; //deklarasi variabel awal, akhir, tengah
    bool b_flag = false; //deklarasi variabel boolean b_flag dengan nilai false 
    awal = 0; //nilai awal adalah 0
    akhir = 6; //nilai akhir adalah 6
    while(!b_flag && awal <= akhir){
        tengah = (awal + akhir)/2; //menghitung nilai tengah
        if(dataArray[tengah] == cari){ //jika data yang dicari berada di tengah, maka
            b_flag = true; //ubah b_flag menjadi true
        } else if(dataArray[tengah] < cari){  //jika data yang dicari lebih besar dari data yang ditengah (data berada di kanan), maka
            awal = tengah + 1; //nilai awal adalah tengah + 1
        } else { //jika data yang dicari lebih kecil dari data yang ditengah (data berada di kiri), maka
            akhir = tengah - 1; //nilai akhir adalah tengah - 1
        }
    }
    if(b_flag){ //jika data ditemukan, maka tampilkan 
        cout << "\nData ditemukan pada index ke-" << tengah << endl;
    } else { //jika data tidak ditemukan, maka tampilkan
        cout << "\nData tidak ditemukan" << endl;
    }
}

int main(){
    cout << "BINARY SEARCH" << endl;
    cout << "\nData : ";
    //Perulangan untuk menampilkan data
    for(int x = 0; x < 7; x++){
        cout << setw(3) << dataArray[x];
    }
    cout << endl;

    //user menginputkan data yang ingin dicari
    cout << "Masukkan data yang ingin dicari : ";
    cin >> cari;
    
    cout << "\nData diurutkan : ";
    Selection_Sort(); //pemanggilan prosedur Selection_Sort() untuk mengurutkan data secara ascending

    //Perulangan untuk menampilkan data setelah diurutkan
    for(int x = 0; x < 7; x++){
        cout << setw(3) << dataArray[x];
    }
    cout << endl;

    BinarySearch(); //pemanggilan prosedur BinarySearch() untuk mencari data yang ingin dicari
    _getche();
    return 0;
}