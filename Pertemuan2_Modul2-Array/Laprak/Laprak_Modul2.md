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
#include <iostream>

using namespace std;

int main(){
    int X_151, Y_151, Z_151;
    cout << "--- Program Input Array 3 Dimensi ---" << endl;
    //Input ukuran dimensi array
    cout << "Masukkan ukuran dimensi x (lapisan) = "; cin >> X_151;
    cout << "Masukkan ukuran dimensi y (baris) = "; cin >> Y_151;
    cout << "Masukkan ukuran dimensi z (kolom) = "; cin >> Z_151;
    cout << endl;

    //Deklarasi array 3 dimensi
    int Array_151[X_151][Y_151][Z_151];

    //Input elemen array
    cout << "- Inputkan nilai masing-masing elemen array -" << endl;
    for(int i=0; i<X_151; i++){
        for(int j=0; j<Y_151; j++){
            for(int k=0; k<Z_151; k++){
                cout << "Input array[" << i << "][" << j << "][" << k << "] = ";
                cin >> Array_151[i][j][k];
            }
        }
        cout << endl;
    }

    //Output data array
    cout << "- Data Array Yang Diinputkan -" << endl;
    for(int i=0; i<X_151; i++){
        cout << "Data array lapisan ke-" << i+1 << endl;
        for(int j=0; j<Y_151; j++){
            for(int k=0; k<Z_151; k++){
                cout << "Data array[" << i << "][" << j << "][" << k << "] = " << Array_151[i][j][k] << endl;
            }
        }
        cout << endl;
    }

    //Tampilan Array dalam bentuk matriks
    cout << "- Tampilan array 3 dimensi dalam bentuk matriks -" << endl;
    for(int i=0; i<X_151; i++){
        cout << "Matriks lapisan ke-" << i+1 << endl;
        for(int j=0; j<Y_151; j++){
            for(int k=0; k<Z_151; k++){
                cout << Array_151[i][j][k] << " " << ends;
            }
            cout << endl;
        }
        cout << endl;
    }

    return 0;
}
```
#### Output :

##### Output 1 :
![Dhimas_Output-Unguided2-1_Modul2](https://github.com/Masdim37/2311102151_Muhammad-Dhimas-Hafizh-Fathurrahman/blob/main/Pertemuan2_Modul2-Array/Laprak/Dhimas_Output-Unguided2-1_Modul2.png)

##### Output 2 :
![Dhimas_Output-Unguided2-2_Modul2](https://github.com/Masdim37/2311102151_Muhammad-Dhimas-Hafizh-Fathurrahman/blob/main/Pertemuan2_Modul2-Array/Laprak/Dhimas_Output-Unguided2-2_Modul2.png)

Kode diatas merupakan program input dan output array 3 dimensi. Pada awal program, user diminta untuk memasukkan ukuran dimensi x (lapisan), y (baris), dan z (kolom) array 3 dimensi tersebut. Terdapat 3 pengulangan for pada program tersebut yang digunakan untuk user menginput nilai masing-masing elemen array, menampilkan data array yang telah diinput user, dan menampilkan array dalam bentuks matriks.

### 3. Buatlah program menu untuk mencari nilai Maksimum, Minimum dan Nilai rata – rata dari suatu array dengan input yang dimasukan oleh user!

```C++
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
```
#### Output:

##### Output 1 :
![Dhimas_Output-Unguided3-1_Modul2](https://github.com/Masdim37/2311102151_Muhammad-Dhimas-Hafizh-Fathurrahman/blob/main/Pertemuan-1/Laprak/Dhimas_Output-Unguided3-1_Modul2.png)

##### Output 2 :
![Dhimas_Output-Unguided3-2_Modul2](https://github.com/Masdim37/2311102151_Muhammad-Dhimas-Hafizh-Fathurrahman/blob/main/Pertemuan2_Modul2-Array/Laprak/Dhimas_Output-Unguided3-2_Modul2.png)

##### Output 3 :
![Dhimas_Output-Unguided3-3_Modul2](https://github.com/Masdim37/2311102151_Muhammad-Dhimas-Hafizh-Fathurrahman/blob/main/Pertemuan2_Modul2-Array/Laprak/Dhimas_Output-Unguided3-3_Modul2.png)

Kode diatas merupakan program array 1 dimensi yang dapat digunakan untuk mencari nilai maksimum, nilai minimum, dan menghitung nilai rata-rata dari elemen-elemen array. Pada awal program, user diminta untuk memasukkan panjang array serta elemen-elemen array tersebut. Kemudian program akan menampilkan pilihan menu yang bisa dipilih oleh user untuk mencari nilai maksimum, nilai minimum, atau menghitung nilai rata-rata dari elemen-elemen array yang telah diinputkan. Program ini juga menggunakan prosedur (void) untuk menampilkan data array yang telah tersimpan pada setiap menu-menu tersebut. Sebagai contoh jika user memilih menu 1 (mencari nilai maksimum), maka program akan menampilkan data array yang telah tersimpan, kemudian program akan menggunakan perulangan for untuk mencari nilai maksimum dari elemen-elemen array yang sebelumnya telah diinputkan oleh user.

## Kesimpulan

## Referensi
