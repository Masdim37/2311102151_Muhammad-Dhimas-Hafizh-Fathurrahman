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
Kode diatas digunakan untuk menampilkan biodata mahasiswa antara lain nama, alamat, dan umur. Data biodata mahasiswa tersebut disimpan dalam struct mahasiswa. Terdapat 2 variabel mhs1 dan mhs2 yang masing-masing menyimpan informasi tentang dua mahasiswa. Setiap mahasiswa memiliki tiga atribut, yaitu name (nama) yang disimpan dalam array Name[50], address (alamat) yang disimpan pada array Address[50], dan age (umur) yang dismpan pada variabel age.  Kemudian biodata tersebut dicetak menggunakan fungsi printf.

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

Kode diatas digunakan untuk mencetak nilai yang terdapat dalam array nilai dengan ukuran 5. Pada awal program, nilai dari masing-masing indeks array tersebut telah dideklarasikan, antara lain 23 pada indeks ke-0, 50 pada indeks ke-1, 34 pada indeks ke-2, 78 pada indeks ke-3, dan 90 pada indeks ke-4. kemudian nilai-nilai tersebut dicetak satu persatu.

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
### Output Unguided 1 :

##### Output 1
![Screenshot Output Unguided 1_1](https://github.com/Masdim37/2311102151_Muhammad-Dhimas-Hafizh-Fathurrahman/blob/main/Pertemuan-1/Laprak/Dhimas_Output-Unguided1-1.png)

##### Output 2
![Screenshot Output Unguided 1_2](https://github.com/Masdim37/2311102151_Muhammad-Dhimas-Hafizh-Fathurrahman/blob/main/Pertemuan-1/Laprak/Dhimas_Output-Unguided1-2.png)

##### Output 3
![Screenshot Output Unguided 1_3](https://github.com/Masdim37/2311102151_Muhammad-Dhimas-Hafizh-Fathurrahman/blob/main/Pertemuan-1/Laprak/Dhimas_Output-Unguided1-3.png)

Kode di atas merupakan program kalkulator lingkaran. Program ini dapat digunakan untuk menghitung luas, keliling, dan jari-jari lingkaran. Program ini menggunakan 3 fungsi dan 2 prosedur yang masing-masing menangani operasi terkait lingkaran. Program ini juga dilengkapi percabangan switch-case dan if-else yang membantu user dalam memilih menu yang diinginkan. Program ini menggunakan beberapa tipe data primitif, antara lain integer dan float yang digunakan untuk menyimpan nilai-nilai yang digunakan dalam perhitungan terkait lingkaran. 

##### Kesimpulan materi tipe data primitif =
<br> Tipe data primitif adalah tipe data dasar yang tersedia dalam banyak bahasa pemrograman (sudah ditentukan oleh sistem) yang digunakan untuk menyimpan nilai sederhana seperti bilangan bulat, bilangan desimal, karakter, dan nilai boolean.

### 2. Jelaskan fungsi dari class dan struct secara detail dan berikan contoh programnya!

```C++
#include <iostream>

using namespace std;

//Struct Student_151 yang berisi data nama string, data kelas char, dan data NIS integer
struct Student_151 {
    string Name_151;
    char Class_151;
    int NIS_151;
};

//Class Subject_151 yang berisi data integer nilai matematika, IPA, dan Bahasa Indonesia
class Subject_151 {
    public:
        int Math_151;
        int Science_151;
        int Indonesian_151;
};

//fungsi RataRataNilai_151 yang digunakan untuk menghitung nilai rata-rata
float RataRataNilai_151 (float Rata_151, int MTK_151, int IPA_151, int INDO_151){
    Rata_151 = (MTK_151 + IPA_151 + INDO_151) / 3;
    return Rata_151;
}

int main(){
    int JumlahMurid_151 = 2; 
    float RataRata_151;

    //Menggunakan struct
    Student_151 Murid[JumlahMurid_151];

    //menggunakan class
    Subject_151 Nilai[JumlahMurid_151];

    //Pengisian data ke struct dan class menggunakan perulangan for
    for(int i = 0; i < JumlahMurid_151; i++){
        cout << "Masukkan data murid ke "<< i+1 << endl;
        cout << "Nama = "; 
        cin >> Murid[i].Name_151; //menginput nama murid kedalam array Murid indeks ke i pada atribut Name_151 yang ada pada struct Student_151
        cout << "Kelas = ";
        cin >> Murid[i].Class_151; //menginput kelas murid kedalam array Murid indeks ke i pada atribut Class_151 yang ada pada struct Student_151
        cout << "Nomor Induk Siswa = ";
        cin >> Murid[i].NIS_151; //menginput NIS murid kedalam array Murid indeks ke i pada atribut NIS_151 yang ada pada struct Student_151
        cout << "Masukkan nilai mata pelajaran matematika = ";
        cin >> Nilai[i].Math_151; //menginput nilai matematika kedalam array Nilai indeks ke i pada atribut Math_151 yang ada pada class Subject_151
        cout << "Masukkan nilai mata pelajaran IPA = ";
        cin >> Nilai[i].Science_151; //menginput nilai IPA kedalam array Nilai indeks ke i pada atribut Science_151 yang ada pada class Subject_151
        cout << "Masukkan nilai mata pelajaran Bahasa Indonesia = ";
        cin >> Nilai[i].Indonesian_151; //menginput nilai Bahasa Indonesia kedalam array Nilai indeks ke i pada atribut Indonesian_151 yang ada pada class Subject_151
        cout << endl;
    }

    cout << "--- REKAPITULASI NILAI MURID ---" << endl;
    //Menampilkan data yang ada pada struct & class
    for(int i = 0; i < JumlahMurid_151; i++){
        cout << "Murid ke " << i+1 << endl;
        cout << "Nama = " << Murid[i].Name_151 << endl; //menampilkan nama murid yang ada pada array Murid indeks ke i pada atribut Name_151 yang ada pada struct Student_151
        cout << "Kelas = " << Murid[i].Class_151 << endl; //menampilkan kelas murid yang ada pada array Murid indeks ke i pada atribut Class_151 yang ada pada struct Student_151
        cout << "Nomor Induk Siswa (NIS) = " << Murid[i].NIS_151 << endl;  //menampilkan NIS murid yang ada pada array Murid indeks ke i pada atribut NIS_151 yang ada pada struct Student_151
        cout << "Nilai mata pelajaran Matematika = " << Nilai[i].Math_151 << endl; //menampilkan nilai matematika murid yang ada pada array Nilai indeks ke i pada atribut Math_151 yang ada pada class Subject_151
        cout << "Nilai mata pelajaran IPA = " << Nilai[i].Science_151 << endl;//menampilkan nilai IPA murid yang ada pada array Nilai indeks ke i pada atribut Science_151 yang ada pada class Subject_151
        cout << "Nilai mata pelajaran Bahasa Indonesia = " << Nilai[i].Indonesian_151 << endl; //menampilkan nilai Bahasa Indonesia murid yang ada pada array Nilai indeks ke i pada atribut Indonesian_151 yang ada pada class Subject_151
        cout << "Rata - rata nilai = " << RataRataNilai_151(RataRata_151, Nilai[i].Math_151, Nilai[i].Science_151, Nilai[i].Indonesian_151) << endl; //memanggil fungsi RataRataNilai_151 untuk menghitung nilai rata-rata
        cout << endl;
    }

    return 0;
}
```
### Output Unguided 2 :  

##### Output 1
![Screenshot Output Unguided 2_1](https://github.com/Masdim37/2311102151_Muhammad-Dhimas-Hafizh-Fathurrahman/blob/main/Pertemuan-1/Laprak/Dhimas_Output-Unguided2-1.png)

##### Output 2
![Screenshot Output Unguided 2_2](https://github.com/Masdim37/2311102151_Muhammad-Dhimas-Hafizh-Fathurrahman/blob/main/Pertemuan-1/Laprak/Dhimas_Output-Unguided2-2.png)

Kode di atas merupakan program yang digunakan untuk merekap nilai siswa. Program ini menggunakan struct Student_151 untuk menyimpan biodata siswa berupa nama (Name_151), kelas (Class_151), dan NIS (NIS_151); serta menggunakan class Subject_151 dengan akses publik untuk menyimpan nilai matematika (Math_151), IPA (Science_151), dan bahasa indonesia (Indonesian_151). Program ini juga menggunakan fungsi RataRataNilai_151 untuk menghitung nilai rata-rata setip murid. User diminta untuk menginputkan biodata serta nilai masing-masing siswa, kemudian program akan menghasilkan output berupa rekapitulasi nilai siswa.

##### A. Struct 
<br> Struct atau struktur data dalam bahasa pemrograman C++ adalah sekumpulan data yang terdiri dari lebih dari satu variabel bertipe data sama maupun berbeda. Struct merupakan tipe data yang dapat dibentuk sendiri atau didefinisikan sendiri sesuai kebutuhan pemrogram (user defined data type)[1]. Struct digunakan apabila data yang ingin dikelompokkan memiliki tipe data yang berbeda. Selain itu, penggunaan struct dapat memudahkan pengelolaan dan manipulasi data dengan mengakses atribut secara individu.

##### B. Class
<br> Class adalah kumpulan dari objek-objek dengan karakterstik yang sama. Fitur class merupakan fitur Object Oriented Program(OOP) pada bahasa C++. Sebuah class memiliki sifat (atribut), kelakuan (operasi/method), hubungan (relationship), dan arti[2]. Sama seperti struct, class  digunakan untuk membungkus tipe data di dalamnya sebagai anggota.

### 3. Buat dan jelaskan program menggunakan fungsi map dan jelaskan perbedaan dari array dengan map

```C++
#include <iostream>
#include <map> 

using namespace std;

int main() {
    string Buah_151;

    // Deklarasi map dengan key string dan value integer
    map <string, int> Stok_151;
  
    // Menambahkan jumlah stok untuk setiap jenis buah ke dalam map
    Stok_151["jeruk"] = 27; //jika user menginputkan "jeruk", maka akan ditampilkan 27 kg
    Stok_151["apel"] = 20; //jika user menginputkan "apel", maka akan ditampilkan 20 kg
    Stok_151["pir"] = 31; //jika user menginputkan "pir", maka akan ditampilkan 31 kg
    Stok_151["anggur"] = 17; //jika user menginputkan "anggur", maka akan ditampilkan 17 kg
    Stok_151["semangka"] = 45; //jika user menginputkan "semangka", maka akan ditampilkan 45 kg
    Stok_151["melon"] = 38; //jika user menginputkan "melon", maka akan ditampilkan 38 kg

    cout << "--- Cek Stok Buah ---" << endl;
    cout << "Buah yang tersedia = jeruk, apel, pir, anggur, semangka, melon" << endl;
    cout << endl;
    cout << "Masukkan nama buah untuk mengecek jumlah stok = ";
    cin >> Buah_151;
    cout << endl;
    
    //mengecek stok buah berdasarkan nama buah yang diinput user
    if (Stok_151.find(Buah_151) != Stok_151.end()) { //jika buah yang dicari ada dalam map Stok_151, maka tampilkan output
        cout << "Jumlah stok " << Buah_151 << " adalah " << Stok_151[Buah_151] << " kg" << endl;
    } else { //jika buah yang dicari tidak ada dalam map Stok_151, maka tampilkan output
        cout << "Buah yang anda cari tidak ditemukan." << endl;
    }
    
    return 0;
}
```
### Output Unguided 3 :  
![Screenshot Output Unguided 3_1](https://github.com/Masdim37/2311102151_Muhammad-Dhimas-Hafizh-Fathurrahman/blob/main/Pertemuan-1/Laprak/Dhimas_Output-Unguided3.png)

Kode diatas merupakan program yang dapat digunakan mengecek stok buah. Program ini menggunakan map Stok_151 untuk menyimpan nilai stok setiap buahnya. Key dalam map Stok_151 adalah nama buah (string), sedangkan valuenya adalah jumlah stok buah (integer). User diminta untuk memasukkan nama buah untuk dicek stoknya, kemudian program akan menampilkan stok dari buah tersebut dalam satuan kg. Apabila buah yang diinputkan tidak ada didalam map Stok_151, maka program akan menampilkan "Buah yang anda cari tidak ditemukan".

Perbedaan antara array dan map antara lain :
1. Array menggunakan tipe data integer (bilangan) sebagai indeksnya, sedangkan map dapat menggunakan tipe data selain integer sebagai indeksnya.
2. Indeks dalam array harus berurutan dan dimulai dari 0, sedangkan indeks dalam map bersifat flexibel dan tidak harus berurutan.
3. Ukuran array biasanya tetap dan harus ditentukan saat deklarasi, sedangkan ukuran map bisa berubah sesuai dengan jumlah elemen yang dimasukkan atau dihapus.

## Kesimpulan
Ringkasan dan interpretasi pandangan kalia dari hasil praktikum dan pembelajaran yang didapat[1].

## Referensi
[1] Indahyati, Uce., Rahmawati Yunianita. 2020. BUKU AJAR ALGORITMA DAN PEMROGRAMAN DALAM BAHASA C++. Sidoarjo: Umsida Press. 
<br>[2] Ahmad, Nazaruddin, et al. Analisa & Perancangan Sistem Informasi Berorientasi Objek. Penerbit Widina, 2022.