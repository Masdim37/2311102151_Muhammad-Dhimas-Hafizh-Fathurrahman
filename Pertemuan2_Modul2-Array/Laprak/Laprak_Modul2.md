# <h1 align="center">Laporan Praktikum Modul 2 - Array</h1>
<p align="center">Muhammad Dhimas Hafizh Fathurrahman - 2311102151</p>

## Dasar Teori

## Guided 

### 1. Program Input Array Tiga Dimensi
```C++
#include <iostream>

using namespace std;

//Program Input Array 3 Dimensi
int main(){
    //Deklarasi Array
    int arr[2][3][3];

    //Input Elemen
    for(int x=0; x<2; x++){
        for(int y=0; y<3; y++){
            for(int z=0; z<3; z++){
                cout << "Input array[" << x << "][" << y << "][" << z << "] = ";
                cin >> arr[x][y][z];
            }
        }
        cout << endl;
    }

    //Output Array
    for(int x=0; x<2; x++){
        for(int y=0; y<3; y++){
            for(int z=0; z<3; z++){
                cout << "Data array[" << x << "][" << y << "][" << z << "] = " << arr[x][y][z] << endl;
            }
        }
    }

    //Tampilan Array
    for(int x=0; x<2; x++){
        for(int y=0; y<3; y++){
            for(int z=0; z<3; z++){
                cout << arr[x][y][z] << " " << ends;
            }
            cout << endl;
        }
        cout << endl;
    }

    return 0;
}
```
Kode di atas adalah program yang mengimplementasikan sebuah array tiga dimensi. Program tersebut meminta pengguna untuk memasukkan nilai ke dalam array tiga dimensi dengan ukuran 2x3x3. Setelah semua nilai dimasukkan, program tersebut kemudian mencetak nilai dari setiap elemen array dengan format matriks.

### 2. Program Mencari Nilai Maksimal pada Array

```C++
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

    //Searching elemen dengan nilai terbesar
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
```
Kode di atas adalah program yang digunakan untuk mencari nilai maksimum dalam sebuah array satu dimensi yang panjangnya serta nilai-nilai setiap indeksnya diinputkan oleh user. Setelah memasukkan nilai-nilai elemen array, program akan mencari nilai maksimum di antara elemen-elemen tersebut. Proses pencarian nilai maksimum dilakukan dengan menggunakan pendekatan linear, yaitu dengan membandingkan setiap elemen array satu per satu. Setelah menemukan nilai maksimum, program mencetak nilai maksimum beserta indeksnya.

## Unguided 

### 1. Buatlah program untuk menampilkan Output seperti berikut dengan data yang diinputkan oleh user!
![Dhimas_Soal-Unguided1_Modul2](https://github.com/Masdim37/2311102151_Muhammad-Dhimas-Hafizh-Fathurrahman/blob/main/Pertemuan2_Modul2-Array/Laprak/Dhimas_Soal-Unguided1_Modul2.png)

```C++
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
```
#### Output:
![Dhimas_Output-Unguided1_Modul2](https://github.com/Masdim37/2311102151_Muhammad-Dhimas-Hafizh-Fathurrahman/blob/main/Pertemuan2_Modul2-Array/Laprak/Dhimas_Output-Unguided1_Modul2.png)

Kode diatas merupakan program yang digunakan untuk menginputkan elemen-elemen array kemudian menampilkannya dan memisahkan bilangan yang merupakan bilangan genap dan bilangan ganjil. Program diatas mengguanakn array Data_151 yang panjang arraynya ditentukan berdasarkan inputan user. Kemudian user diminta untuk menginputkan nilai array Data_151 setiap indeksnya. Kemudian program akan menampilkan bilangan inputan user dan menampilkan bilangan genap dan ganjil berdasarkan bilangan inputan user.

### 2. Buatlah program Input array tiga dimensi (seperti pada guided) tetapi jumlah atau ukuran elemennya diinputkan oleh user!

```C++

```
#### Output:
![Screenshot Output Unguided ...](https://github.com/Masdim37/2311102151_Muhammad-Dhimas-Hafizh-Fathurrahman/blob/main/Pertemuan-1/Laprak/Dhimas_Output-Unguided[nomor].png)

Deskripsi program unguided 2

### 3. [Soal Unguided no 3]

```C++

```
#### Output:
![Screenshot Output Unguided ...](https://github.com/Masdim37/2311102151_Muhammad-Dhimas-Hafizh-Fathurrahman/blob/main/Pertemuan-1/Laprak/Dhimas_Output-Unguided[nomor].png)

Deskripsi program unguided 3

## Kesimpulan

## Referensi
