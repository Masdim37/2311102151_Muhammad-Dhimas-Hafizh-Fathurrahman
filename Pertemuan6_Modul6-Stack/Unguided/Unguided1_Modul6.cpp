#include<iostream>

using namespace std;

const int Max_151 = 100;
char Kata_151[Max_151]; //Deklarasi array bernama Kata_151 sebagai stack
int Top_151 = -1;

//Prosedur PushHuruf_151 untuk menambahkan huruf pada stack
void PushHuruf_151(char Huruf_151){
    if(Top_151 < Max_151 - 1){
        Kata_151[++Top_151] = Huruf_151;
    }
}

//Fungsi PeekHurufPertama_151 untuk melihat huruf atau elemen pertama yang disimpan pada stack
char PeekHurufPertama_151(){
    if(Top_151 >= 0){
        return Kata_151[Top_151];
    }
    return '\0';
}

//Fungsi isEmpty_151 untuk memeriksa stack kosong atau tidak
bool isEmpty_151(){
    return (Top_151 == -1);
}

//Fungsi CekPalindrom_151 untuk memeriksa kata yang diinputkan user merupakan kata palindrom atau tidak
bool CekPalindrom_151(const char* InputKata_151, int Panjang_151){
    //Memasukkan setengah huruf dari total huruf pada kata yang diinputkan user kedalam stack
    for(int i = 0; i < Panjang_151 / 2; i++){
        PushHuruf_151(InputKata_151[i]);
    }

    //menentukan jumlah dari setengah karakter kedua dari kata yang diinputkan user 
    int Kedua_151;
    if(Panjang_151 % 2 == 0){
        Kedua_151 = Panjang_151 / 2;
    } else if(Panjang_151 % 2 == 1){
        Kedua_151 = Panjang_151 / 2 + 1;
    }

    //membandingkan setengah karakter kedua dengan setengah karakter pertama menggunakan fungsi PeekHurufPertama_151
    for(int i = Kedua_151; i < Panjang_151; i++){ 
        if(PeekHurufPertama_151() != InputKata_151[Kedua_151]){
            return false; 
        } 
    }
    return true;
}

int main(){
    char InputKata_151[Max_151]; 
    char CekLagi_151;
    cout << "--- CEK KATA PALINDROM ---" << endl;
    cout << "Palindrom adalah kata yang pembacaannya dari depan maupun belakang adalah sama" << endl;
    CekKata:
    cout << "Masukkan kata yang ingin dicek = ";
    cin.getline(InputKata_151, Max_151); //memasukkan setiap karakter/huruf yang diinputkan user kedalam array InputKata_151

    //menghitung panjang string input
    int PanjangKata_151 = 0;
    while(InputKata_151[PanjangKata_151] != '\0'){
        PanjangKata_151++;
    }

    //mengecek kata yang diinputkan palindrom atau tidak menggunakan fungsi CekPalindrom_151
    if(CekPalindrom_151(InputKata_151, PanjangKata_151)){
        cout << "Kata " << InputKata_151 << " adalah palindrom" << endl;
        cout << endl;  
    } else {
        cout << "Kata " << InputKata_151 << " adalah bukan palindrom" << endl;
        cout << endl;
    }
    cout << "Apakah anda ingin mengecek kata lagi? [y/n] = ";
    cin >> CekLagi_151;
    cin.ignore();
    cout << endl;
    if(CekLagi_151 == 'y' || CekLagi_151 == 'Y'){
        goto CekKata;
    } else if (CekLagi_151 == 'n' || CekLagi_151 == 'N'){
        cout << "Terimakasih telah menggunakan program ini :)" << endl;
        return 0;
    }
}
