# <h1 align="center">Laporan Praktikum Modul 6 - Stack</h1>
<p align="center">Muhammad Dhimas Hafizh Fathurrahman - 2311102151</p>

## Dasar Teori

### A. Stack
Tumpukan (Stack) adalah daftar terurut di mana penyisipan dan penghapusan dilakukan di satu ujung, yang disebut atas (Top)[1]. Stack menggunakan konsep LIFO (Last In First Out) yang artinya data atau elemen terakhir yang ditambahkan adalah data atau elemen pertama yang dikeluarkan. Contoh penerapan stack dalam kehidupan sehari-hari adalah tumpukan keranjang belanja di supermarket. Pegawai supermarket akan menumpuk keranjang belanja yang baru atau yang selesai digunakan oleh pelanggan di atas tumpukan yang sudah ada dan pembeli akan mengambil keranjang belanja yang ditumpuk paling akhir oleh pegawai (pembeli mengambil keranjang belanja yang paling atas (top)). Stack biasanya diimplementasikan dengan array. Berikut merupakan gambar penjelasan konsep LIFO pada stack dengan pengimplementasian array.
![Dhimas_Konsep-LIFO-Stack](https://github.com/Masdim37/2311102151_Muhammad-Dhimas-Hafizh-Fathurrahman/blob/main/Pertemuan6_Modul6-Stack/Laprak/Dhimas_Konsep-LIFO-Stack.png)
<br>Pada gambar tersebut Top (data paling akhir yang ditambahkan) akan bernilai -1 ketika stack kosong dan akan bertambah 1 setiap data baru ditambahkan. Indeks penempatan data dimulai dari 0 seperti halnya indeks pada array dan nilai indeks tersebut akan bertambah 1 setiap data baru ditambahkan.

### B. Operasi Pada Stack
Seperti halnya struktur data yang lain, pada stack juga dapat dilakukan beberapa operasi. Berikut Terdapat beberapa istilah dan operasi yang bisa dilakukan pada stack, antara lain[2] :
- Top = Istilah yang merujuk pada elemen teratas atau elemen yang terakhir kali ditambahkan kedalam stack
- isEmpty = Fungsi yang digunakan untuk mengecek apakah stack masih kosong atau tidak
- IsFull = Fungsi yang digunakan untuk mengecek apakah stack sudah penuh atau belum
- Size = Fungsi untuk menghitung jumlah data yang tersimpan didalam stack
- Push = Operasi untuk memasukkan data ke dalam tumpukan pada posisi paling atas. Operasi ini biasa dinyatakan dengan push(T,d). T menyatakan tumpukan dan d menyatakan item data yang disisipkan ke dalam tumpukan T.
- Pop = Operasi untuk mengambil data teratas dari tumpukan. Operasi ini biasa dinyatakan dengan pop (T). Dalam hal ini data teratas dari tumpukan T akan dikeluarkan dan menjadi nilai balik pop. Itulah sebabnya, penggunaan pop sering dituangkan dalam bentuk pernyataan : data = pop (T);
- Peek = Operasi untuk melihat data yang tersimpan didalam stack pada urutan tertentu. 
- Clear = Operasi untuk mengosongkan atau menghapus semua data yang tersimpan pada stack

## Guided 

### 1. Latihan Stack Sederhana 
```C++
#include<iostream>

using namespace std;

//Deklarasi array bernama arrayBuku dengan ukuran 5
string arrayBuku[5];
int maksimal = 5, top = 0;

//Fungsi isFull untuk memeriksa apakah stack full atau tidak
bool isFull(){
    return (top == maksimal);
}

//Fungsi isEmpty untuk memeriksa apakah stack kosong atau tidak
bool isEmpty(){
    return (top == 0);
}

//Prosedur push untuk menambahkan elemen pada stack posisi paling atas
void pushArrayBuku(string data){
    if(isFull()){
        cout << "Data telah penuh" << endl;
    } else {
        arrayBuku[top] = data;
        top++;
    }
}

//Prosedur pop untuk menghapus elemen pada stack posisi paling atas
void popArrayBuku(){
    if(isEmpty()){
        cout << "tidak ada data yang dihapus" << endl;
    } else {
        arrayBuku[top - 1] = "";
        top--;
    }
}

//Prosedur peek untuk melihat elemen pada stack posisi tertentu 
void peekArrayBuku(int posisi){
    if(isEmpty()){
        cout << "tidak ada data yang bisa dilihat" << endl;
    } else {
        int index = top;
        for(int i = 1; i <= posisi; i++){
            index--;
        }
        cout << "Posisi ke-" << posisi << " adalah " << arrayBuku[index] << endl;
    }
}

//Fungsi Count untuk menghitung jumlah elemen pada stack
int countStack(){
    return top;
}

//Prosedur change untuk mengubah elemen posisi tertentu pada stack
void changeArrayBuku(int posisi, string data){
    if(posisi > top){
        cout << "Posisi melebihi data yang ada" << endl;
    } else {
        int index = top;
        for(int i = 1; i <= posisi; i++){
            index--;
        }
        arrayBuku[index] = data;
    }
}

//Prosedur destroy atau clear untuk menghapus semua elemen pada stack
void destroyArrayBuku(){
    for(int i = top; i >= 0; i--){
        arrayBuku[i] = "";
    }
    top = 0;
}

//Prosedur cetak untuk menampilkan semua elemen pada stack
void cetakArrayBuku(){
    if(isEmpty()){
        cout << "tidak ada data yang bisa dicetak" << endl;
    } else {
        for (int i = top - 1; i >= 0; i--){
            cout << arrayBuku[i] << endl;
        }
    }
}

int main(){
    //Menambahkan elemen pada stack menggunakan prosedur push
    pushArrayBuku("Kalkulus");
    pushArrayBuku("Struktur Data");
    pushArrayBuku("Matematika Diskrit");
    pushArrayBuku("Dasar Multimedia");
    pushArrayBuku("Inggris");

    //mencetak semua elemen pada stack menggunakan prosedur cetak
    cetakArrayBuku();
    cout << "\n";

    //Memeriksa apakah stack penuh atau tidak menggunakan fungsi isFull
    cout << "Apakah data stack penuh? " << isFull() << endl;

    //Memeriksa apakah stack kosong atau tidak menggunakan fungsi isEmpty
    cout << "Apakah data stack kosong? " << isEmpty() << endl;
    cout << "\n";

    //Melihat elemen pada stack posisi ke 2 menggunakan prosedur peek
    peekArrayBuku(2);

    //Menghapus elemen stack posisi paling atas menggunakan prosedur pop
    popArrayBuku();
    cout << "\n";

    //Menghitung jumlah elemen pada stack menggunakan fungsi count
    cout << "Banyaknya data = " << countStack() << endl;

    //Mengubah elemen stack posisi ke 2 menjadi "Bahasa Jerman" menggunakan prosedur change
    changeArrayBuku(2, "Bahasa Jerman");

    //mencetak semua elemen pada stack menggunakan prosedur cetak
    cetakArrayBuku();
    cout << "\n";

    //Menghapus semua elemen pada stack menggunakan prosedur destroy atau clear
    destroyArrayBuku();

    //Menghitung jumlah elemen pada stack menggunakan fungsi count
    cout << "Jumlah data setelah dihapus = " << countStack() << endl;

    //mencetak semua elemen pada stack menggunakan prosedur cetak
    cetakArrayBuku();

    return 0;
}
```

### Deskripsi Program
Kode diatas merupakan program latihan stack sederhana. Implementasi stack pada program ini menggunakan array yang bernama `arrayBuku` dengan ukuran 5. Pada awal program dideklarasikan array bertipe data string dengan nama `arrayBuku` berukuran 5, variabel bertipe data integer bernama 'maksimal' dengan nilai 5, serta variabel bertipe data integer bernama 'top' dengan nilai 0. Variabel 'top' akan digunakan sebagai indeks dari elemen teratas yang tersimpan pada stack. Pada program ini juga terdapat beberapa fungsi dan prosedur yang digunakan untuk memanipulasi stack, fungsi dan prosedur tersebut antara lain :
- bool isFull(); digunakan untuk memeriksa apakah stack kosong atau tidak
- bool isEmpty(); digunakan untuk memeriksa apakah stack penuh atau tidak
- void pushArrayBuku(string data); digunakan untuk menambahkan data atau elemen pada posisi teratas atau elemen paling akhir pada stack
- void popArrayBuku(); digunakan untuk menghapus dan mengembalikan elemen paling atas pada stack
- void peekArrayBuku(int posisi); digunakan untuk melihat data atau elemen pada posisi tertentu pada stack
- int countStack(); digunakan untuk mengetahui jumlah data yang tersimpan pada stack
- void changeArrayBuku(int posisi, string data); digunakan untuk mengubah data atau elemen pada posisi tertentu pada stack
- void destroyArrayBuku(); digunakan untuk menghapus semua data atau elemen yang tersimpan pada stack
- void cetakArrayBuku(); digunakan untuk mencetak atau menampilkan semua data yang tersimpan pada stack
<br>Kemudian pada int main(), dilakukan beberapa operasi seperti push data, cetak data, memerika penuh atau tidaknya stack, memerika kosong atau tidaknya stack, melihat data posisi ke-2, menghapus data teratas, menghitung jumlah data pada stack, mengubah data kedua, mencetak data kembali, menghapus semua data, menghitung jumlah data setelah dihapus, serta mencetak data kembali.

## Unguided 

### 1. Buatlah program untuk menentukan apakah kalimat yang diinputkan dalam program stack adalah palindrom atau tidak.
Palindrom adalah kalimat yang dibaca dari depan dan belakang sama. Jelaskan bagaimana cara kerja programnya.

contoh = 

Kalimat = ini
<br>Kalimat tersebut adalah palindrom

Kalimat = telkom
<br>Kalimat tersebut adalah bukan palindrom

![Dhimas_Soal-Unguided1](https://github.com/Masdim37/2311102151_Muhammad-Dhimas-Hafizh-Fathurrahman/blob/main/Pertemuan6_Modul6-Stack/Laprak/Dhimas_Soal-Unguided1.png)

```C++
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
    cout << "--- CEK KATA PALIDROME ---" << endl;
    cout << "Masukkan kata yang ingin di cek = ";
    cin.getline(InputKata_151, Max_151); //memasukkan setiap karakter/huruf yang diinputkan user kedalam array InputKata_151

    //menghitung panjang string input
    int PanjangKata_151 = 0;
    while(InputKata_151[PanjangKata_151] != '\0'){
        PanjangKata_151++;
    }

    //mengecek kata yang diinputkan palindrom atau tidak menggunakan fungsi CekPalindrom_151
    if(CekPalindrom_151(InputKata_151, PanjangKata_151)){
        cout << "Kata " << InputKata_151 << " adalah palindrom" << endl;  
    } else {
        cout << "Kata " << InputKata_151 << " adalah bukan palindrom" << endl;
    }
    
    return 0;
}
```

#### Output:
![Dhimas_Output-Unguided1](https://github.com/Masdim37/2311102151_Muhammad-Dhimas-Hafizh-Fathurrahman/blob/main/Pertemuan6_Modul6-Stack/Laprak/Dhimas_Output-Unguided1.png)

### Deskripsi Program
Kode diatas merupakan program untuk menentukan kalimat yang diinputkan user merupakan kalimat palindrom atau bukan. Kalimat palindrom adalah kalimat yang pembacaannya sama jika dibaca dari depan maupun belakang. Program ini menggunakan stack yang diimplementasikan menggunakan array bertipe data char yang bernama 'Kata_151' yang ukurannya diambil dari integer konstanta 'Max_151' bernilai 100. Pada awal program dideklarasikan variabel integer konstanta 'Max_151' bernilai 100, array bertipe data char bernama 'Kata_151', serta variabel 'Top_151' bernilai -1. Pada program ini juga terdapat beberapa fungsi dan prosedur yang digunakan untuk mencapai tujuan program, fungsi dan prosedur tersebut antara lain :
- void PushHuruf_151(char Huruf_151); digunakan untuk menambahkan Huruf yang tersimpan pada variabel 'Huruf_151' pada stack
- char PeekHurufPertama_151(); digunakan untuk melihat huruf pertama yang tersimpan pada stack
- bool isEmpty_151(); digunakan untuk memeriksa apakah stack kosong atau tidak
- bool CekPalindrom_151(const char* InputKata_151, int Panjang_151); digunakan untuk mengecek apakah kata yang diinputkan user merupakan kata palindrom atau tidak
<br>Berikut merupakan cara kerja dari program diatas :
- User memasukkan kata yang akan dicek apakah kata tersebut palindrom atau bukan. Kata tersebut akan dipecah menjadi huruf-huruf penyusunnya dan huruf-huruf tersebut akan disimpan pada array 'InputKata_151' 
- Program akan menghitung panjang karakter dari kata yang diinputkan dengan mengiterasi setiap huruf yang ada. Apabila ditemukan spasi atau terminator, maka perhitungan selesai
- Program memanggil prosedur 'CekPalindrom_151' untuk mengecek kata tersebut palindrom atau bukan. Parameter yang digunakan adalah kata yang diinputkan user (const char* InputKata_151), dan panjang kata tersebut (int Panjang_151). 
- Program akan membagi kata tersebut menjadi 2 bagian, yaitu setengah karakter pertama dan setengah karakter kedua. Bagian setengah karakter pertama akan dimasukkan kedalam stack
- Setelah itu, program akan mengeluarkan setengah karakter pertama yang disimpan pada stack secara terbalik (LIFO (Last In First Out)) kemudian membandingkannya dengan setengah karakter kedua
- Apabila hasil perbandingannya sama, maka tampilkan "Kata <InputKata_151> adalah palindrom"
- Apabila hasil perbandingannya berbeda, maka tampilka "Kata <InputKata_151> adalah bukan palindrom"

### 2. Buatlah program untuk melakukan pembalikan terhadap kalimat menggunakan stack dengan minimal 3 kata.
Jelaskan output program dan source codenya beserta operasi/fungsi yang dibuat?

contoh = 

Kalimat = Telkom Purwokerto
<br>Hasil = otrekowruP mokleT

![Dhimas_Soal-Unguided2](https://github.com/Masdim37/2311102151_Muhammad-Dhimas-Hafizh-Fathurrahman/blob/main/Pertemuan6_Modul6-Stack/Laprak/Dhimas_Soal-Unguided2.png)

```C++
#include<iostream>

using namespace std;

const int Max_151 = 100;
string ArrayKalimat_151[Max_151]; //deklarasi array bernama ArrayKalimat sebagai stack
int Top_151 = 0;

//fungsi isEmpty untuk mengecek apakah stack kosong atau tidak
bool isEmpty(){
    return (Top_151 == 0);
}

//prosedur PushKata_151 untuk menambahkan kata pada stack
void PushKata_151(string InputKata_151){
    if(!InputKata_151.empty()){  // Periksa apakah input kata tidak kosong
        ArrayKalimat_151[Top_151] = InputKata_151;
        Top_151++;
    }
}

//prosedur PopKata_151 untuk mengeluarkan elemen pertama pada stack
void PopKata_151(){
    if(Top_151 > 0){
        ArrayKalimat_151[Top_151 - 1] = "";
        Top_151--;
    }
}

//fungsi HitungKata_151 untuk menghitung jumlah kata yang diinputkan user
int HitungKata_151(const char* InputKata_151){
    int JumlahKata_151 = 0;
    int i = 0;
    while (InputKata_151[i] != '\0') {
        // Jika karakter saat ini bukan spasi dan karakter selanjutnya adalah spasi atau null terminator,
        // itu menandakan bahwa kata baru dimulai.
        if (InputKata_151[i] != ' ' && (InputKata_151[i + 1] == ' ' || InputKata_151[i + 1] == '\0')) {
            JumlahKata_151++;
        }
        i++;
    }
    return JumlahKata_151;
}

//Fungsi BalikKata_151 untuk membalikkan urutan huruf pada kata di kalimat yang diinputkan user
string BalikKata_151(const char* InputKata_151){
    string KalimatTerbalik_151; //variabel untuk menampung kata yang sudah terbalik secara keseluruhan
    string KataBelumTerbalik_151;  // variabel untuk menampung kata sementara yang belum dibalik
    string KataSudahTerbalik_151; //variabel untuk menampung kata sementara yang sudah dibalik
    int i = 0;
    //perulangan while
    while (InputKata_151[i] != '\0') { //jika setiap elemen pada InputKata_151 bukan spasi, maka lanjutkan
        char Huruf_151 = InputKata_151[i]; //masukkan setiap elemen pada InputKata_151 pada variabel Huruf_151
        //percabangan if-else
        if (Huruf_151 != ' ') { //jika karakter yang sedang diproses bukan spasi, maka lanjutkan
            KataBelumTerbalik_151 += Huruf_151; //tambahkan karakter bukan spasi ke dalam KataBelumTerbalik_151
        } else { //jika karakter yang sedang diproses adalah spasi, maka lanjutkan
            int PanjangKata_151 = KataBelumTerbalik_151.length(); //Hitung panjang kata pada KataBelumTerbalik_151
            for (int j = PanjangKata_151 - 1; j >= 0; --j) {
                KataSudahTerbalik_151 += KataBelumTerbalik_151[j]; //balikkan kata pada KataBelumTerbalik_151 dan masukkan kedalam KataSudahTerbalik_151
            }
            //Tambahkan kata yang sudah terbalik ke dalam stack menggunakan PushKata_151
            if (!KataSudahTerbalik_151.empty()) {
                PushKata_151(KataSudahTerbalik_151);
            }
            KataBelumTerbalik_151 = "";  // Kosongkan KataBelumTerbalik_151 untuk menampung kata baru
            KataSudahTerbalik_151 = "";  // Kosongkan KataBelumTerbalik_151 untuk menampung kata baru
        }
        ++i;
    }
    // Balik kata terakhir jika setelah kata tersebut tidak diikuti oleh spasi
    if(!KataBelumTerbalik_151.empty()) {
        int PanjangKata_151 = KataBelumTerbalik_151.length(); //Hitung panjang kata 
        for (int j = PanjangKata_151 - 1; j >= 0; --j) {
            KataSudahTerbalik_151 += KataBelumTerbalik_151[j]; //balikkan kata dan masukkan kedalam KataSudahTerbalik_151
        }
        if (!KataSudahTerbalik_151.empty()) { //Tambahkan kata yang sudah terbalik ke dalam stack menggunakan PushKata_151
            PushKata_151(KataSudahTerbalik_151);
        }
    }
    
    //keluarkan kata yang sudah dibalik dari stack
    while(!isEmpty()){
        KalimatTerbalik_151 += ArrayKalimat_151[Top_151 - 1]; //masukkan kata yang sudah dibalik kedalam KalimatTerbalik_151
        PopKata_151(); //keluarkan KalimatTerbalik_151 menggunakan PopKata_151
        if (!isEmpty()) { // Jika stack belum kosong, tambahkan spasi di antara kata yang sudah dibalik
            KalimatTerbalik_151 += " ";
        }
    }
    return KalimatTerbalik_151; //kembalikan nilai KalimatTerbalik_151
}

int main(){
    char InputKata_151[Max_151];
    string KalimatTerbalik_151, hasil_151;
    cout << "--- PEMBALIK KALIMAT ---" << endl;
    cout << "Anda bisa memasukkan minimal 3 kata untuk dibalik" << endl;
    MasukkanKalimat:
    cout << "Masukkan kalimat (minimal 3 kata) = ";
    cin.getline(InputKata_151, Max_151);  //Kalimat yang diinputkan user dimasukkan kedalam array InputKata_151

    //Pengecekan apakah kata yang diinputkan user lebih dari 3 atau tidak
    if(HitungKata_151(InputKata_151) < 3){ //Jika kata yang dimasukkan user kurang dari 3 maka user harus memasukkan kalimat lagi 
        cout << "Jumlah kata = " << HitungKata_151(InputKata_151) << endl;
        cout << "Kata yang anda masukkan kurang dari 3, silahkan masukkan ulang kalimat anda" << endl;
        cout << endl;
        goto MasukkanKalimat;
    } else { //jika kata yang diinputkan user lebih dari sama dengan 3 maka tampilkan urutan huruf setiap kata pada kalimat secara terbalik
        cout << "Jumlah kata = " << HitungKata_151(InputKata_151) << endl;
        hasil_151 = BalikKata_151(InputKata_151);
        cout << "Kalimat yang dibalik menjadi " << hasil_151 << endl;
    }
    
    return 0;
}
```
#### Output:
![Dhimas_Output-Unguided2](https://github.com/Masdim37/2311102151_Muhammad-Dhimas-Hafizh-Fathurrahman/blob/main/Pertemuan6_Modul6-Stack/Laprak/Dhimas_Output-Unguided2.png)

### Deskripsi Program
Kode diatas merupakan program untuk membalik urutan kata dan huruf dari kalimat yang diinputkan oleh user. Program ini menggunakan stack yang diimplementasikan menggunakan array bertipe data string yang bernama 'ArrayKalimat_151' yang ukurannya diambil dari integer konstanta 'Max_151' bernilai 100. Pada awal program dideklarasikan variabel integer konstanta 'Max_151' bernilai 100, array bertipe data string bernama 'ArrayKalimat_151' serta variabel 'Top_151' bernilai 0. Pada program ini juga terdapat beberapa fungsi dan prosedur yang digunakan untuk mencapai tujuan program, fungsi dan prosedur tersebut antara lain :
- bool isEmpty(); digunakan untuk memeriksa apakah stack kosong atau tidak
- void PushKata_151(string InputKata_151); digunakan untuk menambahkan kata yang sudah dibalik kedalam stack
- void PopKata_151(); digunakan untuk menghapus kata yang sudah terbalik pada stack urutan teratas
- int HitungKata_151(const char* InputKata_151); digunakan untuk menghitung jumlah kata yang diinputkan oleh user
- string BalikKata_151(const char* InputKata_151); digunakan untuk membalik huruf dan kata pada kalimat yangg diinputkan oleh user
<br>Berikut merupakan cara kerja dari program diatas :
- User menginputkan kalimat yang terdiri dari minimal 3 kata untuk dibalik penulisannya. Kalimat tersebut akan dipecah menjadi huruf dan spasi penyusunnya dan akan disimpan pada array 'InputKata_151'. Jika kalimat yang diinputkan user kurang dari 3 kata, maka user akan diminta memasukkan kalimat kembali
- Program akan menghitung panjang karakter dari setiap kata yang diinputkan dengan mengiterasi setiap elemen yang ada. Apabila karakter saat ini bukan spasi dan karakter selanjutnya adalah spasi atau null terminator, maka menandakan bahwa kata baru dimulai dan perhitungan panjang karakter akan dimulai kembali dari awal
- Program memanggil prosedur 'BalikKata_151' untuk membalikkan urutan huruf dan kata dari kalimat yang diinputkan user. Parameter yang digunakan adalah pointer ke kata dalam kalimat yang diinputkan user (const char* InputKata_151)
- Program akan melakukan perulangan untuk mengiterasi setiap karakter pada kalimat yang diinputkan user ('InputKata_151'). Jika karakter yang diproses saat ini bukan spasi, maka masukkan karakter tersebut pada variabel 'KataBelumTerbalik_151'. Jika karakter yang diproses saat ini adalah spasi, maka balikkan karakter yang tersimpan pada 'KataBelumTerbalik_151' dan masukkan hasilnya ke variabel 'KataSudahTerbalik_151'. Kemudian karakter-karakter yang disimpan pada 'KataSudahTerbalik_151' dimasukkan ke stack menggunakan prosedur 'PushKata_151'. Proses ini akan berulang hingga kata sebelum kata terakhir
- Khusus untuk kata terakhir dimana setelah kata tersebut merupakan terminator, maka pembalikkan urutan huruf tersebut dilakukan diluar perulangan while. Sama seperti pemrosesan pembalikkan kata sebelumnya, jika karakter yang diproses saat ini bukan spasi, maka masukkan karakter tersebut pada variabel 'KataBelumTerbalik_151'. Kemudian dilakukan pengecekan apakah variabel 'KataBelumTerbalik_151' sudah kosong atau belum. Jika variabel 'KataBelumTerbalik_151' belum kosong (masih ada isinya), maka balikkan karakter yang tersimpan dan masukkan hasilnya ke variabel 'KataSudahTerbalik_151'. Kemudian karakter-karakter yang disimpan pada 'KataSudahTerbalik_151' dimasukkan ke stack menggunakan prosedur 'PushKata_151'
- Terakhir, keluarkan semua karakter yang tersimpan pada stack dan masukkan pada variabel 'KalimatTerbalik_151' dengan penambahan spasi diantara kata-kata yang sudah dibalik. Kemudian tampilkan semua kata yang sudah dibalik

## Kesimpulan
Tumpukan (Stack) adalah daftar terurut di mana penyisipan dan penghapusan dilakukan di satu ujung, yang disebut atas (Top). Elemen terakhir yang dimasukkan adalah yang pertama dihapus. Oleh karena itu, stack disebut daftar Last In First Out (LIFO). Pada stack terdapat beberapa istilah dan fungsi yang dapat digunakan antara lain top, isEmpty, isFull, push, pop, size, peek, serta clear. 

## Referensi
[1] Joseph Teguh Santoso. (2021). "STRUKTUR DATA dan ALGORITMA (Bagian 1)". Penerbit Yayasan Prima Agus Teknik, 7(1), 1-333. Retrieved from https://penerbit.stekom.ac.id/index.php/yayasanpat/article/view/288.
<br>[2] Sindar, Anita. (2019). "STRUKTUR DATA DAN ALGORITMA DENGAN C++". Serang: CV. AA. RIZKY.