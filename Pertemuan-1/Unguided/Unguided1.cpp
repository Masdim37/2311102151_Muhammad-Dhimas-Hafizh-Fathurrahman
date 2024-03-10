#include <iostream>
#include <cmath>

using namespace std;

//Fungsi menghitung luas lingkaran 
float LuasLingkaran_151(float Luas_151, int Jari_151){
    Luas_151 = 3.14 * Jari_151 * Jari_151;
    return Luas_151;
}

//Fungsi menghitung kelulung lingkaran
float KelilingLingkaran_151(float Keliling_151, int Jari_151){
    Keliling_151 = 2 * 3.14 * Jari_151;
    return Keliling_151;
}

//Fungsi menghitung jari-jari lingkaran jika diketahui diameternya
int JariJari1_151(int Jari_151, int Diameter_151){
    Jari_151 = Diameter_151 / 2;
    return Jari_151;
}

//Prosedur menghitung jari-jari lingkaran jika diketahui kelilingnya
void JariJari2_151(){
    float Jari_151, Keliling_151;
    Jari_151 = Keliling_151 / (2 * 3.14);
    cout << "Jari - jari lingkaran tersebut adalah = " << Jari_151 << endl;
    cout << endl;
}

//Prosedur menghitung jari-jari jika diketahui luasnya
void JariJari3_151(){
    float Jari_151, Luas_151;
    Jari_151 = sqrt(Luas_151/3.14);
    cout << "Jari - jari lingkaran tersebut adalah = " << Jari_151 << endl;
    cout << endl;
}

int main(){
    int Pilihan_151, Jari_151, PilihanJari_151, Diameter_151; //Deklarasi variabel bertipe data integer
    float Keliling_151, Luas_151; //Deklarasi variabel bertipe data float
    MenuUtama_151: //Label menu utama
    cout << "--- KALKULATOR LINGKARAN ---" << endl;
    cout << "1. Luas Lingkaran" << endl;
    cout << "2. Keliling Lingkaran" << endl;
    cout << "3. Menghitung jari-jari lingkaran" << endl;
    cout << "4. Keluar" << endl;
    cout << "Silahkan pilih operasi yang diinginkan : ";
    cin >> Pilihan_151;
    cout << endl;

    switch (Pilihan_151) { //Switch case berdasarkan pilihan user
    case 1 : //Jika memilih 1, maka menghitung luas lingkaran
        cout << "Masukkan jari - jari lingkaran = ";
        cin >> Jari_151;
        cout << "Luas lingkaran tersebut adalah = " << LuasLingkaran_151(Luas_151, Jari_151) << endl; //Baris pemanggilan fungsi LuasLingkaran_151
        cout << endl;
        break;
    case 2 : //Jika memilih 2, maka menghitung keliling lingkaran
        cout << "Masukkan jari - jari lingkaran = ";
        cin >> Jari_151;
        cout << "Keliling lingkaran tersebut adalah = " << KelilingLingkaran_151(Keliling_151, Jari_151) << endl; //Baris pemanggilan fungsi KelilingLingkaran_151
        cout << endl;
        break;
    case 3 : //Jika memilih 3, masuk ke sub-menu menghitung jari-jari lingkaran
        MenuJariJari_151: //Label menu menghitung jari-jari lingkaran
        cout << "--- Menghitung jari-jari lingkaran ---" << endl;
        cout << "1. Menghitung jari-jari lingkaran jika diketahui diameternya" << endl;
        cout << "2. Menghitung jari-jari lingkaran jika diketahui kelilingnya" << endl;
        cout << "3. Menghitung jari-jari lingkaran jika diketahui luasnya" << endl;
        cout << "Masukkan pilihan anda = ";
        cin >> PilihanJari_151;
        cout << endl;
        if (PilihanJari_151 = 1){ //Percabangan if 1, untuk menghitung jari-jari lingkaran jika diketahui diameternya
            cout << "Masukkan diameter lingkaran = ";
            cin >> Diameter_151;
            cout << "Jari - jari lingkaran tersebut adalah = " << JariJari1_151(Jari_151, Diameter_151) << endl; //Baris pemanggilan fungsi JariJari1_151
            cout << endl;
        } else if (PilihanJari_151 = 2){ //Percabangan if 2, untuk menghitung jari-jari lingkaran jika diketahui kelilingnya
            cout << "Masukkan keliling lingkaran = ";
            cin >> Keliling_151;
            JariJari2_151(); //Baris pemanggilan prosedur JariJari2_151
        } else if (PilihanJari_151 = 3){ //Percabangan if 3, untuk menghitung jari-jari lingkaran jika diketahui luasnya
            cout << "Masukkan luas lingkaran = ";
            cin >> Luas_151;
            JariJari3_151(); //Baris pemanggilan prosedur JariJari3_151
        } else { //Output jika menginputkan pilihan selain 1 - 3
            cout << "Silahkan pilih menu yang tersedia" << endl;
            goto MenuJariJari_151; //Pernyataan goto untuk kembali ke menu menghitung jari-jari lingkaran
        }
        break;
    case 4 : //Jika memilih 4, maka keluar dari program
        cout << "Anda keluar dari program" << endl;
    default: //Output jika menginputkan selain 1 - 4
        cout << "Silahkan pilih menu yang tersedia" << endl;
        goto MenuUtama_151; //Pernyataan goto untuk kembali ke menu utama
        break;
    }

    return 0;
}