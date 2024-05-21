# <h1 align="center">Laporan Praktikum Modul 8 - Algoritma Searching</h1>
<p align="center">Muhammad Dhimas Hafizh Fathurrahman - 2311102151</p>

## Dasar Teori

### A. Searching
Searching (pencarian) pada struktur data mengacu pada proses algoritmik untuk memeriksa, menemukan, mengambil posisi elemen tertentu (target) dari kumpulan elemen seperti array, list, linked list, tree, dan lain sebagainya di dalam struktur data[1]. Algoritma searching digunakan untuk melakukan akses cepat ke data terkait, sehingga dapat mengoptimalkan kinerja program dengan mengurangi waktu komputasi dan penggunaan sumber daya. Terdapat 2 algoritma searching yang biasa digunakan, antara lain sebagai berikut.

#### 1. Sequential Seacrh
Sequential search adalah algoritma pencarian yang paling sederhana. Sequential search disebut juga sebagai linear search (pencarian linear). Sequential search bekerja dengan cara membandingkan setiap elemen yang tersimpan dalam suatu struktur data (misal : array) secara berurutan, dimulai dari elemen pertama, sampai elemen yang diinginkan ditemukan atau semua elemen telah dibandingkan[2]. Sequential search dapat dilakukan pada elemen data yang tidak diurutkan maupun pada elemen data yang diurutkan. Proses pencarian sequential akan singkat jika data yang diolah sedikit. Apabila data yang diolah banyak, prosesnya akan memakan waktu yang lama, sehingga algoritma sequential search hanya direkomendasikan untuk struktur data yang memuat jumlah data yang sedikit.

Berikut ilustrasi sequential search pada array =

![Dhimas_Ilustrasi-Sequential-Search-Array](https://github.com/Masdim37/2311102151_Muhammad-Dhimas-Hafizh-Fathurrahman/blob/main/Pertemuan8_Modul8-Algoritma-Searching/Laprak/Dhimas_Ilustrasi-Sequential-Search-Array.png)

#### 2. Binary Search
Binary Search adalah algoritma pencarian data pada suatu struktur data (misal : array) yang telah terurut, metode ini lebih efisien daripada metode pencarian linier (sequential search) karena membutuhkan waktu komputasi yang lebih sedikit[3]. Binary search bekerja dengan membagi separuh dari jumlah data yang dicari (membagi jumlah data keseluruhan menjadi 2 bagian, yaitu bagian kanan dan kiri) sehingga memperkecil lokasi pencarian sampai menjadi satu data. Dengan teknik ini data akan dibuang setengah dari jumlah data seluruhnya. Apabila ditemukan kecocokan data maka program akan mengembalikan output, jika tidak pencarian akan terus berlanjut hingga akhir dari pembagian jumlah data tersebut[4]. Algoritma binary search memerlukan data yang sudah terurut sehingga diperlukan metode sorting data (mengurutkan data) seperti bubble sort, selection sort, insertion sort, dll sebelum mencari data menggunakan metode binary search. Dikarenakan algoritma binary search hanya membutuhkan waktu komputasi yang lebih sedikit, algoritma ini sangat direkomendasikan untuk diimplementasikan pada struktur data dengan jumlah data yang besar. Hal ini karena binary search memiliki kompleksitas waktu O(log n), yang jauh lebih efisien dibandingkan dengan sequential search yang memiliki kompleksitas waktu O(n). Dengan demikian, binary search dapat mengoptimalkan kinerja program secara signifikan, terutama ketika berhadapan dengan dataset yang besar.

Berikut ilustrasi binary search pada array =

![Dhimas_Ilustrasi-Binary-Search-Array](https://github.com/Masdim37/2311102151_Muhammad-Dhimas-Hafizh-Fathurrahman/blob/main/Pertemuan8_Modul8-Algoritma-Searching/Laprak/Dhimas_Ilustrasi-Binary-Search-Array.png)

## Guided 

### 1. Buatlah sebuah project dengan menggunakan sequential search sederhana untuk melakukan pencarian data

```C++
#include <iostream>

using namespace std;

int main(){
    int n = 10; //deklarasi variabel n sebagai ukuran array
    int data[10] = {9, 4, 1, 7, 5, 12, 4, 13, 3, 10}; //deklarasi array data 
    int cari = 10; //deklarasi variabel cari dengan nilai 10 (angka yang dicari adalah 10)
    bool ketemu = false; //deklarasi variabel boolean ketemu dengan nilai false
    int i; //deklarasi variabel i

    //Sequential Search untuk mencari angka 10
    for(i=0; i < n; i++){
        if(data[i] == cari){ //jika nilai pada array data index ke i adalah 10, maka 
            ketemu = true; //ubah variabel boolean ketemu menjadi true
            break; //perulangan berhenti
        }
    }

    cout << "Program Sequential Search" << endl;
    cout << "Data = {9, 4, 1, 7, 5, 12, 4, 13, 3, 10}" << endl; //menampilkan isi array data

    if(ketemu){ //jika angka 10 ditemukan, maka tampilkan
        cout << "\nAngka " << cari << " ditemukan pada indeks ke " << i << endl; 
    } else { //jika angka 10 tidak ditemukan, maka tampilkan
        cout << "Data tidak ditemukan!" << endl;
    }

    return 0;
}
```

#### Deskripsi Program
Kode diatas merupakan program implementasi sequential search sederhana untuk melakukan pencarian data. Pada awal program dideklarasikan array bernama `data` dengan ukuran 10 beserta isinya yaitu 9, 4, 1, 7, 5, 12, 4, 13, 3, 10. Kemudian dideklarasikan variabel `n` dan `cari` dengan nilai 10 (variabel `n` menandakan panjang array sedangkan variabel `cari` menunjukkan angka yang ingin dicari), variabel boolean `ketemu` dengan nilai false, dan variabel `i`. Program ini bertujuan untuk mencari angka 10 didalam array tersebut dan menampilkan indexnya. Sequential search pada program ini diimplementasikan dengan pengulangan for yang membandingkan setiap elemen atau data yang tersimpan didalam array apakah sesuai dengan angka yang ingin dicari (dalam hal ini angka 10). Jika angka yang dicari ditemukan, maka akan menampilkan "angka (10) ditemukan pada index ke (index angka 10 didalam array `data`)". Jika angka yang dicari tidak ditemukan, maka akan menampilkan "Data tidak ditemukan!".

### 2. Buatlah sebuah project untuk melakukan pencarian data dengan menggunakan Binary Search

```C++
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
```

#### Deskripsi Program
Kode diatas merupakan program implementasi binary search untuk mencari data pada array. Syarat untuk mencari suatu data menggunakan algoritma binary search adalah data harus diurutkan terlebih dahulu sehingga pada program ini juga memuat algoritma selection sort untuk mengurutkan data secara ascending. Pada awal program dideklarasikan array bernama `dataArray[]` dengan ukuran 7 beserta isinya yaitu 1, 8, 2, 5, 4, 9, 7; serta dideklarasikan variabel `cari` untuk menyimpan data atau angka yang ingin dicari. Pada program ini juga terdapat 2 prosedur yaitu :
- void Selection_Sort(); merupakan prosedur sorting menggunakan algoritma selection sort yang digunakan untuk mengurutkan data secara ascending (dari terkecil ke terbesar).
- void BinarySearch(); merupakan prosedur searching menggunakan algoritma binary search yang digunakan untuk mencari suatu data yang disimpan pada array `dataArray[]` dan menampilkan indexnya

Berikut cara kerja program :
- Program menampilkan isi dari `dataArray[]` berupa angka-angka
- user memasukkan angka yang ingin dicari kemudian disimpan pada variabel `cari`
- Program memanggil prosedur `Selection_Sort()` untuk mengurutkan data dari terkecil ke terbesar (ascending). Selection sort bekerja dengan membandingkan elemen sekarang dengan elemen selanjutnya, apabila elemen selanjutnya nilainya lebih kecil daripada elemen sekarang, maka tukar posisi keduanya. Proses ini diulang hingga data terakhir dalam array diperiksa
- Program menampilkan data yang telah diurutkan
- Program memanggil prosedur `BinarySearch()` untuk mencari data didalam array `dataArray[]`. Jika data ditemukan maka tampilkan index data tersebut, sedangkan jika data tidak ditemukan maka tampilkan "Data tidak ditemukan". Binary search bekerja dengan membagi array menjadi 2 bagian (kiri dan kanan yang dipisahkan dengan tengah). Apabila data yang dicari nilainya lebih kecil dari data yang ditengah, maka program akan memproses data bagian kiri, sebaliknya Apabila data yang dicari nilainya lebih besar dari data yang ditengah, maka program akan memproses data bagian kanan. Kemudian bagian data tersebut akan dibagi 2 lagi menjadi bagian kiri dan kanan. Proses ini akan berulang hingga bagian kanan dan kiri hanya terdiri dari 1 data saja.

## Unguided 

### 1. Buatlah sebuah program untuk mencari sebuah huruf pada sebuah kalimat yang sudah di input dengan menggunakan Binary Search!

```C++
#include<iostream>

using namespace std;

//Prosedur untuk menampilkan huruf-huruf didalam kalimat
void TampilkanHurufKalimat_151(char ArrayKalimat_151[], int PanjangKalimat_151){
    for(int i = 0; i < PanjangKalimat_151; i++){ //perulangan for untuk menampilkan huruf
        cout << ArrayKalimat_151[i] << '\t';
    }
    cout << endl;
}

//Prosedur untuk mengurutkan huruf sesuai abjad menggunakan bubble sort
void BubbleSort_151(char ArrayKalimat_151[], int PanjangKalimat_151){
    bool Urut_151 = true; //deklarasi variabel boolean Urut_151 dengan nilai true
    int j = 0; //deklarasi variabel j dengan nilai 0 yang digunanakn dalam perulangan
    char temp_151; //deklarasi variabel temp_151 untuk menampung huruf sementara
    while(Urut_151){ //jika variabel boolean Urut_151 bernilai true, maka ulangi
        Urut_151 = false; //variabel Urut_151 menjadi false
        j++; //nilai j bertambah
        for(int i = 0; i < PanjangKalimat_151 - j; i++){ //perulangan untuk mengurutkan huruf
            if(ArrayKalimat_151[i] > ArrayKalimat_151[i + 1]){  //Jika nilai ArrayKalimat_151 index ke i lebih besar dari nilai index selanjutnya, maka lanjutkan
                temp_151 = ArrayKalimat_151[i]; //masukkan nilai ArrayKalimat_151 index ke i kedalam variabel temp_151
                ArrayKalimat_151[i] = ArrayKalimat_151[i + 1]; //masukkan nilai ArrayKalimat_151 index ke i + 1 kedalam ArrayKalimat_151 index ke i
                ArrayKalimat_151[i + 1] = temp_151; //masukkan nilai variabel temp_151 kedalam ArrayKalimat_151 index ke i + 1
                Urut_151 = true; //variabel boolean Urut_151 menjadi true
            }
        }
    }
}

//Prosedur untuk mencari huruf didalam kalimat menggunakan binary search
void BinarySearch_151(char ArrayKalimat_151[], int PanjangKalimat_151, char HurufYangDicari_151){
    int awal_151, tengah_151, akhir_151, Posisi_151; //Deklarasi variabel awal_151, tengah_151, akhir_151, posisi_151
    bool b_flag = false; //deklarasi variabel boolean b_flag dengan nilai false
    awal_151 = 0; //nilai variabel awal_151 adalah 0
    akhir_151 = PanjangKalimat_151; //nilai variabel akhir_151 adalah nilai varaibel PanjangKalimat_151
    while(!b_flag && awal_151 <= akhir_151){ //Jika b_flag false & nilai awal_151 kurang dari sama dengan nilai akhir_151, maka lanjutkan
        tengah_151 = (awal_151 + akhir_151)/2; //hitung nilai tengah_151
        if(HurufYangDicari_151 == ArrayKalimat_151[tengah_151]){ //jika huruf yang dicari berada di tengah, maka
            Posisi_151 = tengah_151; //nilai variabel posisi_151 sama dengan nilai variabel tengah_151
            b_flag = true; //b_flag menjadi true
            break; //perulangan selesai
        } else if(HurufYangDicari_151 < ArrayKalimat_151[tengah_151]){ //jika huruf yang dicari posisinya kurang dari tengah_151 (berada di kiri), maka
            akhir_151 = tengah_151 - 1; //nilai akhir_151 adalah nilai tengah_151 dikurang 1 
        } else if(HurufYangDicari_151 > ArrayKalimat_151[tengah_151]){ //jika huruf yang dicari posisinya lebih dari tengah_151 (berada di kanan), maka
            awal_151 = tengah_151 + 1; //nilai awal_151 adalah nilai tengah_151 ditambah 1
        }
    }
    if(b_flag){ //jika b_flag true (huruf ditemukan), maka 
        //tampilkan huruf ditemukan beserta indexnya
        cout << "Huruf " << HurufYangDicari_151 << " ditemukan pada index ke-";
        for(int i = 0; i < PanjangKalimat_151; i++){
            if(HurufYangDicari_151 == ArrayKalimat_151[i]){
                cout << i;
                if(ArrayKalimat_151[i + 1] == HurufYangDicari_151){
                    cout << ", ";
                }
            }
        }
    } else { //jika b_flag false (huruf tidak ditemukan), maka tampilkan "Huruf tidak ditemukan"
        cout << "Huruf " << HurufYangDicari_151 << " tidak ditemukan" << endl;
    }
}

int main(){
    string InputKalimat_151, KalimatTanpaSpasi_151; //deklarasi variabel string InputKalimat_151 dan KalimatTanpaSpasi_151
    int PanjangKalimat_151; //deklarasi variabel integer PanjangKalimat_151
    char HurufYangDicari_151; //deklarasi variabel char HurufYangDicari_151
    cout << "--- PROGRAM MENCARI HURUF DALAM KALIMAT ---" << endl;
    cout << "Masukkan kalimat = "; 
    getline(cin, InputKalimat_151); //kalimat yang diinputkan user dimasukkan kedalam variabel InputKalimat_151
    cout << endl;

    // Menghapus karakter spasi dari kalimat
    KalimatTanpaSpasi_151 = ""; //variabel KalimatTanpaSpasi_151 dikosongkan
    //perulangan for-each yang mengiterasi setiap karakter atau huru didalam kalimat yang diinputkan user
    for(char c : InputKalimat_151){
        if(c != ' ') { //jika huruf atau karakter yang diperiksa saat ini bukan spasi, maka masukkan kedalam variabel KalimatTanpaSpasi_151
            KalimatTanpaSpasi_151 += c; 
        }
    }

    //menghitung panjang kalimat
    PanjangKalimat_151 = KalimatTanpaSpasi_151.length();

    //memasukkan setiap karakter dalam kalimat kedalam array char ArrayKalimat_151 dengan ukuran PanjangKalimat_151
    char ArrayKalimat_151[PanjangKalimat_151];
    for(int i = 0; i < PanjangKalimat_151; i++){
        ArrayKalimat_151[i] = KalimatTanpaSpasi_151[i]; //masukkan semua huruf yang tersimpan di KalimatTanpaSpasi_151 kedalam array ArrayKalimat_151[]
    }

    //Menampilkan setiap huruf dalam kalimat sebelum di urutkan
    cout << "Urutan huruf dalam kalimat sebelum diurutkan (spasi dihilangkan) = " << endl;
    TampilkanHurufKalimat_151(ArrayKalimat_151, PanjangKalimat_151); //pemanggilan prosedur TampilkanHurufKalimat()
    cout << endl;

    //Menampilkan setiap huruf dalam kalimat setelah di urutkan
    cout << "Urutan huruf dalam kalimat setelah diurutkan (spasi dihilangkan) = " << endl;
    BubbleSort_151(ArrayKalimat_151, PanjangKalimat_151); //pemanggilan prosedur BubbleSort_151()
    TampilkanHurufKalimat_151(ArrayKalimat_151, PanjangKalimat_151); //pemanggilan prosedur TampilkanHurufKalimat() dengan huruf yang sudah diurutkan secara ascending
    cout << endl;

    //User menginputkan huruf yang ingin dicari
    cout << "Masukkan huruf yang ingin dicari = ";
    cin >> HurufYangDicari_151; 

    //Pemanggilan prosedur BinarySearch_151()
    BinarySearch_151(ArrayKalimat_151, PanjangKalimat_151, HurufYangDicari_151);

    return 0;
}
```

#### Output:

##### Output Jika Huruf Ditemukan
![Dhimas_Output-Unguided1-1](https://github.com/Masdim37/2311102151_Muhammad-Dhimas-Hafizh-Fathurrahman/blob/main/Pertemuan8_Modul8-Algoritma-Searching/Laprak/Dhimas_Output-Unguided1-1.png)

##### Output Jika Huruf Tidak Ditemukan
![Dhimas_Output-Unguided1-2](https://github.com/Masdim37/2311102151_Muhammad-Dhimas-Hafizh-Fathurrahman/blob/main/Pertemuan8_Modul8-Algoritma-Searching/Laprak/Dhimas_Output-Unguided1-2.png)

#### Deskripsi Program
Kode diatas merupakan program untuk mencari sebuah huruf pada sebuah kalimat yang diinputkan user kemudian menampilkan indexnya. Program ini menggunakan algoritma binary search untuk mencari huruf yang dimaksud. Dikarenakan syarat untuk menggunakan binary search adalah data atau huruf harus sudah dalam bentuk terurut, maka pada program ini juga disertakan algoritma bubble sort untuk mengurutkan huruf secara ascending (dari terkecil ke terbesar). 

Berikut cara kerja program :
- Pada awal int main(), program mendeklarasikan variabel `InputKalimat_151`, `KalimatTanpaSpasi_151`, `PanjangKalimat_151`, dan `HurufYangDicari_151`.
- user menginputkan kalimat yang ingin dicari hurufnya, kalimat ini dimasukkan kedalam variabel `InputKalimat_151`
- Program melakukan perulangan for-each yang memecah kalimat yang diinputkan menjadi elemen atau huruf-huruf penyusunnya. Kemudian jika elemen yang saat ini diperiksa bukan sama dengan spasi, maka masukkan elemen atau huruf tersebut ke variabel `KalimatTanpaSpasi_151`
- Program menghitung panjang elemen atau huruf yang disimpan pada variabel `KalimatTanpaSpasi_151`. Nilai panjang elemen tersebut disimpan pada variabel `PanjangKalimat_151`
- Program melakukan perulangan untuk memasukkan semua huruf yang tersimpan di variabel `KalimatTanpaSpasi_151` kedalam array `ArrayKalimat_151[]` yang kemudian array tersebut akan digunakan sebagai parameter dalam prosedur `TampilkanHurufKalimat_151()`, `BubbleSort_151()`, dan `BinarySearch_151()`
- Program akan memanggil prosedur `TampilkanHurufKalimat_151()` untuk menampilkan huruf-huruf penyusun kalimat yang diinputkan user dengan karakter spasi yang sudah terhapus
- Kemudian program akan mengurutkan huruf-huruf tersebut secara ascending (dari terkecil dan terbesar) dengan menggunakan prosedur `ubbleSort_151()` dan menampilkannya kembali menggunakan prosedur `TampilkanHurufKalimat_151()`
- Kemudian user diminta memasukkan huruf yang ingin dicari didalam array beserta nomor indexnya. huruf yang diinputkan user akan dimasukkan kedalam variabel `HurufYangDicari_151`.
- Program akan memanggil prosedur `BinarySearch_151()` untuk mencari huruf tersebut dan menampilkan nomor indexnya. Apabila huruf tersebut ditemukan, maka akan menampilkan "Huruf `HurufYangDicari_151` ditemukan pada index ke-(nomor index huruf)". Sedangkan apabila huruf tersebut tidak ditemukan, maka akan menampilkan "Huruf `HurufYangDicari_151` tidak ditemukan".
Binary search bekerja dengan membagi array menjadi 2 bagian (kiri dan kanan yang dipisahkan dengan tengah). Apabila data atau huruf yang dicari nilainya lebih kecil dari data yang ditengah, maka program akan memproses data bagian kiri, sebaliknya Apabila data atau huruf yang dicari nilainya lebih besar dari data yang ditengah, maka program akan memproses data bagian kanan. Kemudian bagian data tersebut akan dibagi 2 lagi menjadi bagian kiri dan kanan. Proses ini akan berulang hingga bagian kanan dan kiri hanya terdiri dari 1 data saja.


### 2. Buatlah sebuah program yang dapat menghitung banyaknya huruf vocal dalam sebuah kalimat!

```C++
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
```

#### Output:

##### Output Jika Kalimat Memiliki Huruf Vokal
![Dhimas_Output-Unguided2-1](https://github.com/Masdim37/2311102151_Muhammad-Dhimas-Hafizh-Fathurrahman/blob/main/Pertemuan8_Modul8-Algoritma-Searching/Laprak/Dhimas_Output-Unguided2-1.png)

##### Output Jika Kalimat Tidak Memiliki Huruf Vokal
![Dhimas_Output-Unguided2-2](https://github.com/Masdim37/2311102151_Muhammad-Dhimas-Hafizh-Fathurrahman/blob/main/Pertemuan8_Modul8-Algoritma-Searching/Laprak/Dhimas_Output-Unguided2-2.png)

#### Deskripsi Program
Kode diatas merupakan program untuk menghitung jumlah huruf vokal yang ada dalam kalimat yang diinputkan user. Program ini menggunakan algoritma sequential search untuk mencari huruf vokal yang ada, menghitung jumlahnya, dan menampilkan huruf-hurufnya. 

Berikut cara kerja program :
- User menginputkan kalimat yang ingin dihitung jumlah huruf vokalnya. Kalimat tersebut akan disimpan dalam variabel `InputKalimat_151`
- Program akan menghitung panjang kalimat tersebut dan menyimpannya dalam variabel `PanjangKalimat_151`
- Program mendeklarasikan array bernama `ArrayKalimat_151` dengan panjang nilai variabel `PanjangKalimat_151`, array ini digunakan untuk menyimpan huruf-huruf penyusun kalimat yang telah diinputkan user
- Program akan memecah kalimat tersebut menjadi huruf-huruf penyusunnya, kemudian huruf-huruf tersebut akan disimpan pada `ArrayKalimat_151[]`
- Program memanggil prosedur `SequentialSearch_151()` untuk mencari huruf vokal diantara huruf-huruf penyusun kalimat tersebut, menghitung jumlahnya, dan menampilkan huruf-hurufnya. Prosedur ini bekerja dengan memeriksa setiap huruf yang tersimpan apabila terdapat huruf vokal (a, A, i, I, u, U, e, E, o, O), maka simpan huruf vokal tersebut dalam array `HurufVokal_151[]` dan jumlah huruf vokal tersebut disimpan pada variabel `JumlahHurufVokal_151`.
- Jika nilai variabel `JumlahHurufVokal_151` bukan sama dengan 0 (ditemukan huruf vokal), maka tampilkan jumlahnya beserta huruf-hurufnya
- Jika nilai variabel `JumlahHurufVokal_151` sama dengan 0 (tidak ditemukan huruf vokal), maka tampilkan "Kalimat ini tidak memiliki huruf vokal".

### 3. Diketahui data = 9, 4, 1, 4, 7, 10, 5, 4, 12, 4. Hitunglah berapa banyak angka 4 dengan menggunakan algoritma Sequential Search!

```C++
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
```

#### Output:

##### Output Jika Angka Yang Dicari Ditemukan 
![Dhimas_Output-Unguided3-1](https://github.com/Masdim37/2311102151_Muhammad-Dhimas-Hafizh-Fathurrahman/blob/main/Pertemuan8_Modul8-Algoritma-Searching/Laprak/Dhimas_Output-Unguided3-1.png)

##### Output Jika Angka Yang Dicari Tidak Ditemukan
![Dhimas_Output-Unguided3-2](https://github.com/Masdim37/2311102151_Muhammad-Dhimas-Hafizh-Fathurrahman/blob/main/Pertemuan8_Modul8-Algoritma-Searching/Laprak/Dhimas_Output-Unguided3-2.png)

#### Deskripsi Program
Kode diatas merupakan program yang dapat menghitung jumlah angka (dalam hal ini angka 4) yang ada didalam suatu array. Program ini memakai algoritma sequential search untuk mencari angka yang ingin dicari kemudian menampilkan jumlah angka tersebut yang tersimpan beserta nomor indexnya. Pada awal program dideklarasikan beberapa variabel dan array, antara lain : 
- array `ArrayData_151[]` dengan ukuran 10 beserta isinya yaitu 9, 4, 1, 4, 7, 10, 5, 4, 12, 4. 
- Variabel `CariAngka_151` untuk menampung angka yang ingin dicari
- Variabel `JumlahAngka_151` dengan nilai 0 untuk menampung jumlah angka yang ingin dicari yang tersimpan didalam array `ArrayData_151[]`
- Array `IndexAngka_151[]` dengan ukuran 10 untuk menyimpan nomor index dari angka yang ingin dicari
- Variabel `j` dengan nilai 0 untuk digunakan dalam perulangan

Berikut cara kerja program :
- Program menampilkan menu "PROGRAM PENGHITUNG ANGKA DALAM ARRAY" kemudian menampilkan array beserta isinya yang sebelumnya telah dideklarasikan (dalam hal ini array `ArrayData_151[]`)
- user menginputkan angka yang ingin dicari apakah ada didalam array yang telah ditampilkan (misal angka 4). Angka tersebut akan dimasukkan kedalam variabel `CariAngka_151`
- Program akan menjalankan squential search, apabila dalam perulangan ditemukan angka yang dicari (angka 4), maka variabel `JumlahAngka_151` akan bertambah nilainya dan nilai index dari angka yang dicari (angka 4) akan dimasukkan kedalam array `IndexAngka_151[]`
- Jika nilai variabel `JumlahAngka_151` bukan sama dengan 0, maka akan menampilkan "Array tersebut memiliki angka `CariAngka_151` sebanyak `JumlahAngka_151`" dan dibawahnya akan menampilkan "Ditemukan pada index ke-(nomor index yang tersimpan di array `IndexAngka_151[]`)"
- Jika nilai variabel `JumlahAngka_151` sama dengan 0, maka akan menampilkan "Array tersebut tidak berisi angka `CariAngka_151`"

## Kesimpulan
Searching (pencarian suatu data) adalah hal yang penting dalam struktur data. Searching memungkinkan akses cepat ke data terkait, sehingga dapat mengoptimalkan kinerja program dengan mengurangi waktu komputasi. Terdapat 2 algoritma searching yang sering digunakan yaitu sequential search dan binary search. Sequential search bekerja dengan membandingkan setiap elemen yang tersimpan pada struktur data apakah sama dengan data yang dicari. Sequential search memiliki kompleksitas waktu O(n), artinya waktu pencarian meningkat secara linear dengan jumlah elemen. Binary search bekerja dengan membagi data keseluruhan menjadi 2 bagian (kanan dan kiri) yang dipisahkan dengan elemen tengah. Apabila elemen tengah nilainya kurang dari data yang dicari, maka pencarian dilakukan di bagian kanan. Sebaliknya apabila elemen tengah nilainya lebih dari data yang dicari, maka pencarian dilakukan di bagian kiri. Proses pembagian data ini terus berlanjut hingga menyisakan elemen tengah saja sebagai data yang dicari  atau ruang pencarian habis. Binary search memiliki kompleksitas waktu O(log n), yang membuatnya jauh lebih efisien untuk data yang jumlahnya lebih besar dibandingkan dengan sequential search.

## Referensi
[1] Putri, M. P., et al. (2022). "Algoritma dan Struktur Data". Bandung: Widina Bhakti Persada Bandung. ISBN 978-623-459-182-8. Retrieved from https://repository.penerbitwidina.com/id/publications/557434/. 
<br>[2] Wahyuni, W. S., Andryana, S., & Rahman, B. (2022). "Penggunaan Algoritma Sequential Searching Pada Aplikasi Perpustakaan Berbasis Web". JIPI (Jurnal Ilmiah Penelitian dan Pembelajaran Informatika), 7(2), 294-302. Retrieved from https://doi.org/10.29100/jipi.v7i2.2646. 
<br>[3] Mone, leonard, & Pekuwali, A. (2023). "Penerapan Algoritma Binary Search Pada Sistem Informasi Perpustakaan Di SMP Negeri 4 Mauliru". SENTIMAS: Seminar Nasional Penelitian Dan Pengabdian Masyarakat, 1(1), 360-367. Retrieved from https://journal.irpi.or.id/index.php/sentimas/article/view/738.
<br>[4] Sitompul, B. J. D., Yusupa, A., & Tuturoong, N. J. (2022). "IMPLEMENTASI ALGORITMA BINARY SEARCH PADA PENCARIAN DATA JEMAAT GEREJA HKBP MANADO". Jurnal Informatika Polinema, 9(1), 17–24. Retrieved from https://doi.org/10.33795/jip.v9i1.1123. 
