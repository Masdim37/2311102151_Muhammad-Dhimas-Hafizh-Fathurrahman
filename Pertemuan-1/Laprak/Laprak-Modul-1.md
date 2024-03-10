# <h1 align="center">Laporan Praktikum Modul Tipe Data</h1>
<p align="center">Muhammad Dhimas Hafizh Fathurrahman - 2311102151</p>

## Dasar Teori

Berikan penjelasan teori terkait materi modul ini dengan bahasa anda sendiri serta susunan yang terstruktur per topiknya.

## Guided 

### 1. [Tipe Data Primitif]

```C++
#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    char op;
    float num1, num2;

    cout << "Enter operator (+, -, *, /) = ";
    cin >> op;

    cout << "Enter two operands = ";
    cin >> num1 >> num2;

    switch (op)
    {
    case '+':
        cout << "Result = " << num1 + num2;
        break;
    case '-':
        cout << "Result = " << num1 - num2;
        break;
    case '*':
        cout << "Result = " << num1 * num2;
        break;
    case '/':
        if (num2 != 0)
        {
            cout << "Result = " << fixed << setprecision(2) << num1 / num2;
        }
        else
        {
            cout << "Error! Division by zero is not allowed.";
        }
        break;
    default:
        cout << "Error! operator is not correct.";
        break;
    }
    return 0;
}
```
Kode di atas digunakan untuk melakukan operasi aritmetika berdasarkan operator yang dipilih oleh user (penjumlahan(+), pengurangan(-), perkalian(*), dan pembagian(/)). Pada program ini terdapat dua tipe data primitif yaitu tipe data char yang digunakan untuk menyimpan operator aritmetika yang dipilih oleh user, dan tipe data float yang digunakan untuk menyimpan bilangan atau operand yang diinputkan oleh user serta untuk menyimpan hasil dari operasi aritmetika. Tipe data char digunakan pada saat pemilihan switch case dan tipe data float digunakan pada saat menginputkan bilangan.

### 2. [Tipe Data Abstrak]

```C++
#include <stdio.h>
#include <string.h>

//struct
struct Mahasiswa{
    char name[50];
    char address[100];
    int age;
};

int main(){
    //menggunakan struct
    struct Mahasiswa mhs1, mhs2;
    //mengisi nilai ke struct
    strcpy(mhs1.name, "Dian");
    strcpy(mhs1.address, "Mataram");
    mhs1.age = 22;
    strcpy(mhs2.name, "Bambang");
    strcpy(mhs2.address, "Surabaya");
    mhs2.age = 23;

    //mencetak isi struct
    printf("## Mahasiswa 1 ##\n");
    printf("Nama : %s\n", mhs1.name);
    printf("Alamat : %s\n", mhs1.address);
    printf("Umur : %d\n", mhs1.age);
    printf("\n");
    printf("## Mahasiswa 2 ##\n");
    printf("Nama : %s\n", mhs2.name);
    printf("Alamat : %s\n", mhs2.address);
    printf("Umur : %d\n", mhs2.age);
    return 0;
}
```
Kode diatas digunakan untuk menampilkan biodata mahasiswa. 

### 3. [Tipe Data Koleksi]

```C++
#include <iostream>
#include <array>

using namespace std;

int main() {
// Deklarasi dan inisialisasi array
int nilai[5];
nilai[0] = 23;
nilai[1] = 50;
nilai[2] = 34;
nilai[3] = 78;
nilai[4] = 90;

// Mencetak array dengan tab
cout << "Isi array pertama : " << nilai[0] << endl;
cout << "Isi array kedua : " << nilai[1] << endl;
cout << "Isi array ketiga : " << nilai[2] << endl;
cout << "Isi array keempat : " << nilai[3] << endl;
cout << "Isi array kelima : " << nilai[4] << endl;

return 0;
}
```
deksripsi

## Unguided 

### 1. [Buatlah program menggunakan tipe data primitif minimal dua fungsi dan bebas. Menampilkan program, jelaskan program tersebut dan ambil kesimpulan dari materi tipe data primitif!]

```C++
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
    cout << "Masukkan keliling lingkaran = ";
    cin >> Keliling_151;
    Jari_151 = Keliling_151 / (2 * 3.14);
    cout << "Jari - jari lingkaran tersebut adalah = " << Jari_151 << endl;
    cout << endl;
}

//Prosedur menghitung jari-jari jika diketahui luasnya
void JariJari3_151(){
    float Jari_151, Luas_151;
    cout << "Masukkan luas lingkaran = ";
    cin >> Luas_151;
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
        if (PilihanJari_151 == 1){ //Percabangan if 1, untuk menghitung jari-jari lingkaran jika diketahui diameternya
            cout << "Masukkan diameter lingkaran = ";
            cin >> Diameter_151;
            cout << "Jari - jari lingkaran tersebut adalah = " << JariJari1_151(Jari_151, Diameter_151) << endl; //Baris pemanggilan fungsi JariJari1_151
            cout << endl;
        } else if (PilihanJari_151 == 2){ //Percabangan if 2, untuk menghitung jari-jari lingkaran jika diketahui kelilingnya
            JariJari2_151(); //Baris pemanggilan prosedur JariJari2_151
        } else if (PilihanJari_151 == 3){ //Percabangan if 3, untuk menghitung jari-jari lingkaran jika diketahui luasnya
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
```
#### Output:

#### Output 1
![Screenshot Output Unguided 1_1](https://github.com/Masdim37/2311102151_Muhammad-Dhimas-Hafizh-Fathurrahman/blob/main/Pertemuan-1/Laprak/Dhimas_Output-Unguided1-1.png)

#### Output 2
![Screenshot Output Unguided 1_2](https://github.com/Masdim37/2311102151_Muhammad-Dhimas-Hafizh-Fathurrahman/blob/main/Pertemuan-1/Laprak/Dhimas_Output-Unguided1-2.png)

#### Output 3
![Screenshot Output Unguided 1_3](https://github.com/Masdim37/2311102151_Muhammad-Dhimas-Hafizh-Fathurrahman/blob/main/Pertemuan-1/Laprak/Dhimas_Output-Unguided1-3.png)
Kode di atas digunakan untuk mencetak teks "ini adalah file code guided praktikan" ke layar menggunakan function cout untuk mengeksekusi nya.

## Kesimpulan
Ringkasan dan interpretasi pandangan kalia dari hasil praktikum dan pembelajaran yang didapat[1].

## Referensi
[1] I. Holm, Narrator, and J. Fullerton-Smith, Producer, How to Build a Human [DVD]. London: BBC; 2002.