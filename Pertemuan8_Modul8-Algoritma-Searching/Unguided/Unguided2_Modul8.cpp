#include<iostream>

using namespace std;

//Prosedur sequential search untuk mencari huruf vokal 
void SequentialSearch_151(char ArrayKalimat_151[], int PanjangKalimat_151){
    int JumlahHurufVokal_151 = 0; //deklarasi variabel JumlahHurufVokal dengan nilai 0
    char HurufVokal_151[PanjangKalimat_151]; //deklarasi array HurufVokal dengan ukuran PanjangKalimat_151 untuk menyimpan huruf vokal yang ditemukan dalam kalimat
    for(int i = 0; i < PanjangKalimat_151; i++){ //perulangan untuk memeriksa setiap huruf didalm kalimat
        //jika dalam ArrayKalimat_151[] index ke i ditemukan huruf vokal (a, A, i, I, u, U, e, E, o, O), maka 
        if(ArrayKalimat_151[i] == 'a' || ArrayKalimat_151[i] == 'A' || ArrayKalimat_151[i] == 'i' || ArrayKalimat_151[i] == 'I' || ArrayKalimat_151[i] == 'u' || ArrayKalimat_151[i] == 'U' || ArrayKalimat_151[i] == 'e' || ArrayKalimat_151[i] == 'E' || ArrayKalimat_151[i] == 'o' || ArrayKalimat_151[i] == 'O'){
            HurufVokal_151[JumlahHurufVokal_151] = ArrayKalimat_151[i]; //masukkan huruf vokal tersebut kedalam array HurufVokal[] 
            JumlahHurufVokal_151++; //variabel JumlahHurufVokal bertambah nilainya
        }
    }
    if(JumlahHurufVokal_151 != 0){ //jika nilai variabel JumlahHurufVokal bukan sama dengan 0 (ditemukan huruf vokal), maka tampilkan jumlah huruf vokal yang ditemukan beserta huruf-hurufnya
        cout << "Kalimat ini memiliki " << JumlahHurufVokal_151 << " huruf vokal, yaitu : ";
        for(int i = 0; i < JumlahHurufVokal_151; i++){
            cout << HurufVokal_151[i];
            if(i < JumlahHurufVokal_151 - 1){
                cout << ", ";
            }
        }
    } else { //jika nilai variabel JumlahHurufVokal sama dengan 0 (tidak ditemukan huruf vokal), maka tampilkan "Kalimat ini tidak memiliki huruf vokal"
        cout << "Kalimat ini tidak memiliki huruf vokal" << endl;
    }
}

int main(){
    string InputKalimat_151; //deklarasi variabel string InputKalimat_151
    int PanjangKalimat_151; //deklarasi variabel integer PanjangKalimat_151
    cout << "--- PROGRAM PENGHITUNG HURUF VOKAL ---" << endl;
    cout << "Masukkan kalimat = ";
    getline(cin, InputKalimat_151); //user memasukkan kalimat kemudian disimpan pada variabel InputKalimat_151
    cout << endl;

    //Menghitung panjang karakter dalam kalimat
    PanjangKalimat_151 = InputKalimat_151.length();

    //memasukkan karakter dalam kalimat kedalam array
    char ArrayKalimat_151[PanjangKalimat_151]; //deklarasi array char ArrayKalimat[] dengan ukuran PanjangKalimat_151
    //perulangan for-each yang memecah kalimat dalam InputKalimat_151 mejadi huruf-huruf penyusunnya, kemudian masukkan huruf-huruf tersebut kedalam ArrayKalimat[]
    for(int i = 0; i < PanjangKalimat_151; i++){
        ArrayKalimat_151[i] = InputKalimat_151[i];
    }

    //pemanggilan prosedur SequentialSearch_151() untuk mencari huruf vokal, menghitung jumlahnya, dan menampilkan huruf-hurufnya
    SequentialSearch_151(ArrayKalimat_151, PanjangKalimat_151);

    return 0;
}