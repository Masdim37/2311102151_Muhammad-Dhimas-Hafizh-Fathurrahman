# <h1 align="center">Laporan Praktikum Modul 5 - Hash Table</h1>
<p align="center">Muhammad Dhimas Hafizh Fathurrahman - 2311102151</p>

## Dasar Teori

### A. Teknik Hashing
Sebelum memahami apa itu tabel hash atau hash table, kita perlu mengetahui apa itu teknik hashing. Teknik hashing adalah proses penggunaan fungsi hash untuk mengonversi kunci (key) menjadi hash value berupa indeks dalam array (tabel hash), di mana nilai tersebut akan disimpan. Proses ini memungkinkan akses cepat ke nilai yang terkait dengan kunci tertentu. Teknik hashing memiliki empat komponen utama, antara lain sebagai berikut.

#### 1. Tabel Hash 
Tabel hash atau peta hash adalah struktur data yang digunakan untuk menyimpan kunci (key) dan nilai (value) terkaitnya[1]. Tabel Hash terdiri dari sebuah array di mana setiap elemen dalam array tersebut disebut sebagai "bucket". Setiap bucket dapat menampung satu atau lebih item data yang memiliki nilai hash yang sama (setelah diterapkan teknik resolusi collision). Untuk memetakan key dan value pada tabel hash, diperlukan sebuah fungsi yang disebut sebagai fungsi hash.

Berikut merupakan ilustrasi dari hash table.
![Dhimas_Ilustrasi-HashTable](https://github.com/Masdim37/2311102151_Muhammad-Dhimas-Hafizh-Fathurrahman/blob/main/Pertemuan5_Modul5-HashTable/Laprak/Dhimas_Ilustrasi-HashTable.png)

Pada tabel hash dapat dilakukan beberapa operasi antara lain insertion (menambahkan data baru kedalam hash table), deletion (menghapus data tertentu pada hash table), searching (mencari data tertentu berdasarkan inputan key), update (memperbarui data yang tersimpan didalam hash table), dan transversal (menelusuri seluruh hash table untuk memproses semua data yang ada dalam tabel).

#### 2. Fungsi Hash
Fungsi hash adalah sebuah function yang digunakan untuk mengubah suatu key yang diinputkan user menjadi nilai indeks array yang ada pada tabel hash sehingga memungkinkan akses cepat dan efisien ke data yang terkait dengan key tersebut. Fungsi hash yang baik akan menghasilkan nilai hash yang berbeda untuk setiap kunci yang berbeda, sehingga data dapat tersimpan secara merata di seluruh ruang penyimpanan (tabel hash). Fungsi hash merupakan komponen kunci dalam teknik hashing sehingga perlu dirancang dengan baik. Jika tidak, maka data tidak dapat disimpan pada index yang sesuai, sehingga memungkinkan terjadinya tabrakan data (collision).

#### 3. Tabrakan Data (Collision)
Tabrakan data atau collision adalah suatu kondisi dimana dua atau lebih key menghasilkan nilai hash yang sama, sehingga data yang ingin disimpan dimuat dalam 1 bucket yang sama. Collision bisa terjadi karena fungsi hash yang telah dibuat tidak efisien sehingga tidak dapat menghasilkan nilai hash yang unik untuk setiap key yang berbeda. Hal ini merupakan masalah yang umum terjadi dalam implementasi tabel hash sehingga diperlukan teknik resolusi tabrakan

#### 4. Teknik Resolusi Tabrakan
Untuk mengatasi collision, diperlukan teknik resolusi tabrakan, antara lain sebagai berikut[2].
- Open Hashing (Separate Chaining)
<br>Open hashing atau separate chaining dilakukan dengan membuat tabel hash menjadi sebuah array of pointer yang masing-masing pointernya diikuti oleh sebuah linked list. Dalam pendekatan ini, setiap elemen array (bucket) mengandung sebuah linked list. Chain atau rantai pertama terletak pada array of pointer itu sendiri, sedangkan chain-chain berikutnya berhubungan dengan chain pertama secara memanjang. Kelemahan metode ini yaitu terjadi linked list yang panjang apabila data menumpuk pada satu atau sedikit indeks.
- Closed Hashing (Open Addressing)
<br>Closed Hashing dilakukan dengan menggunakan memori yang masih ada tanpa menggunakan memori di luar array yang dipakai. Dalam closed hashing, ketika terjadi tabrakan atau collision di suatu indeks dalam array, algoritma akan mencari alamat lain untuk menyimpan data yang bertabrakan tanpa meninggalkan array yang sudah ada. Terdapat tiga metode dalam closed hashing, antara lain :
  - Linear Probing (Metode Pembagian); dilakukan dengan mencari posisi yang kosong dengan bergeser satu indeks dari indeks sebelumnya hingga ditemukan alamat yang belum terisi data.
  - Quadratic Probing (Metode Midsquare/Nilai Tengah); dilakukan dengan mencari alamat baru untuk ditempati dengan proses perhitungan kuadratik yang lebih kompleks. 
  - Double Hashing (Metode Penjumlahan Digit); dilakukan dengan melakukan hashing ulang sehingga tercipta hash value yang baru.

Metode closed hashing memiliki kelemahan yaitu ukuran array yang disediakan harus lebih besar dari jumlah data. Selain itu, dibutuhkan memori yang lebih besar untuk meminimalkan collision.

### B. Kelebihan dan Kekurangan Hash Table
#### 1. Kelebihan hash table antara lain :
   - Dapat mengakses data dengan cepat; hal ini dikarenakan penggunaan fungsi hash untuk memetakan kunci ke indeks dalam array, yang memungkinkan pencarian, penyisipan, dan penghapusan data dengan waktu eksekusi yang konstan atau mendekati konstan (O(1)).
   - Hash table dapat menyimpan data dengan efisien; hal ini karena hash table hanya menggunakan memori yang diperlukan untuk menyimpan data, tanpa memerlukan alokasi memori tambahan untuk mengakomodasi pertumbuhan data.
   - fleksibel; sehingga cocok untuk diterapkan dalam berbagai macam aplikasi dan struktur data, seperti basis data, kamus, caching, dan lainnya.
#### 2. Kekurangan hash table antara lain :
   - Dapat terjadi tabrakan data (collision); sehingga diperlukan implementasi teknik resolusi collision yang baik.
   - Memerlukan fungsi hash yang tepat dan efisien; sehingga k dapat menghasilkan nilai hash yang berbeda untuk setiap key yang berbeda.
   - pengimplementasian hash table cukup kompleks, apalagi jika diperlukan penanganan collision.

## Guided 

### 1. Program Hash Table Sederhana

```C++
#include <iostream>

using namespace std;

const int MAX_SIZE = 10;

//Fungsi Hash Sederhana
int hash_func(int key){
    return key % MAX_SIZE;
}

//Struktur data untuk setiap node
struct Node{
    int key;
    int value;
    Node* next;
    Node(int key, int value) : key(key), value(value), next(nullptr) {}
};

//Class hash table
class HashTable{
    private:
        Node** table;
    public:
        HashTable(){
            table = new Node*[MAX_SIZE]();
        }
        ~HashTable(){
            for(int i = 0; i < MAX_SIZE; i++){
                Node* current = table[i];
                while(current != nullptr){
                    Node* temp = current;
                    current = current->next;
                    delete temp;
                }
            }
            delete[] table;
        }

        //Insertion
        void insert(int key, int value){
            int index = hash_func(key);
            Node* current = table[index];
            while(current != nullptr){
                if(current->key == key){
                    current->value = value;
                    return;
                }
                current = current->next;
            }
            Node* node = new Node(key, value);
            node->next = table[index];
            table[index] = node;
        }

        //Searching
        int get(int key){
            int index = hash_func(key);
            Node* current = table[index];
            while(current != nullptr){
                if(current->key == key){
                    return current->value;
                }
                current = current->next;
            }
            return -1;
        }

        //Deletion
        void remove(int key){
            int index = hash_func(key);
            Node* current = table[index];
            Node* prev = nullptr;
            while(current != nullptr){
                if(current->key == key){
                    if(prev == nullptr){
                        table[index] = current->next;
                    } else {
                        prev->next = current->next;
                    }
                    delete current;
                    return;
                }
                prev = current;
                current = current->next;    
            }           
        }

        //Transversal
        void transverse(){
            for(int i = 0; i < MAX_SIZE; i++){
                Node* current = table[i];
                while(current != nullptr){
                    cout << current->key << ": " << current->value << endl;
                    current = current->next;
                }
            }
        }
};

int main(){
    HashTable ht;
    //Insertion
    ht.insert(1, 10);
    ht.insert(2, 20);
    ht.insert(3, 30);

    //searhing
    cout << "Get key 1 : " << ht.get(1) << endl;
    cout << "Get key 4 : " << ht.get(4) << endl;

    //deletion
    ht.remove(4);

    //transversal
    ht.transverse();

    return 0;
}
```

#### Deskripsi Program
Program diatas merupakan implementasi dari hash table sederhana. Pada program ini terdapat pasangan kunci-nilai (key-value) yang di mana setiap key dipetakan ke value tertentu menggunakan fungsi hash. Pada awal program ini, dideklarasikan ukuran table sebanyak 10, kemudian terdapat fungsi hash_func, struct node, dan class HashTable. Berikut merupakan penjelasan setiap bagiannya.
1. int hash_func(int key); berfungsi sebagai fungsi hash sederhana yang menggunakan operasi key modulus MAX_SIZE untuk memastikan nilai hash tetap dalam rentang yang sesuai dengan ukuran tabel hash.
2. struct Node; berfungsi untuk mendeklarasikan node yang terdiri dari key, value, dan pointer next.
3. class HashTable; berfungsi sebagai implementasi dari hash table yang teridir dari :
   - kontruktor HashTable(); berfungsi untuk menginisialisasi tabel hash dengan ukuran MAX_SIZE.
   - destruktor ~HashTable(); berfungsi untuk membersihkan atau menghapus memori yang dialokasikan secara dinamis untuk tabel hash.
   - void insert(int key, int value); digunakan untuk menambahkan node baru kedalam tabel hash. Jika kunci sudah ada, maka nilai yang terkait diperbarui.
   - int get(int key); digunakan untuk mencari nilai yang terkait dengan suatu kunci dalam tabel hash.
   - void remove(int key); digunakan untuk menghapus elemen yang terkait dengan kunci tertentu dari tabel hash.
   - void transverse(); digunakan untuk menampilkan semua pasangan key-value yang disimpan.

Kemudian pada int main(), dideklarasikan objek ht dari kelas HashTable, kemudian dilakukan operasi menambah dengan pasangan key-value antara lain 1-10, 2-20, 3-30. Kemudian dilakukan pencarian key 1 dan key 4 menggunakan ht.get(). Kemudian dilakukan penghapusan key 4 menggunakan ht.remove(). Kemudian menampilkan semua data yang disimpan menggunakan ht.transverse().

### 2. Implementasi Hash Table Untuk Penyimpanan dan Pencarian Data Nama dan Nomor Telepon

```C++
#include <iostream>
#include <string>
#include <vector>

using namespace std;

//Deklarasi isi tabel sebanyak 11
const int TABLE_SIZE = 11;

string name;
string phone_number;

//Deklarasi class HashNode
class HashNode{
    public:
    string name;
    string phone_number;

    //deklarasi konstruktor HashNode yang digunakan untuk membuat objek HashNode dengan parameter nama dan nomor telepon
    HashNode(string name, string phone_number){
        this->name = name;
        this->phone_number = phone_number;
    }
};

//Deklarasi class HashMap
class HashMap{
    private:
    //inisialisasi array table dengan ukuran TABLE_SIZE yang setiap elemen dari array tersebut merupakan sebuah vektor yang menyimpan pointer ke HashNode.
    vector<HashNode*> table[TABLE_SIZE];

    public:
    //fungsi hashFunc untuk menghitung nilai hash dari sebuah string key_151
    int hashFunc(string key){
        int hash_val = 0;
        for(char c : key){
            hash_val += c;
        }
    return hash_val % TABLE_SIZE;
    }

    //Prosedur insert untuk menambahkan data 
    void insert(string name, string phone_number){
        int hash_val = hashFunc(name);

        for(auto node : table[hash_val]){
            if(node->name == name){
                node->phone_number = phone_number;
                return;
            }
        }
        table[hash_val].push_back(new HashNode(name, phone_number));
    }

    //Prosedur remove untuk menghapus data tertentu berdasarkan key nama yang diinputkan user.
    void remove(string name){
        int hash_val = hashFunc(name);

        for(auto it = table[hash_val].begin(); it != table[hash_val].end(); it++){
            if((*it)->name == name){
                table[hash_val].erase(it);
                return;
            }
        }
    }

    //fungsi searchByName untuk mencari data nomor telepon berdasarkan key nama yang diinputkan user.
    string searchByName(string name){
        int hash_val = hashFunc(name);
        for(auto node : table[hash_val]){
            if(node->name == name){
                return node->phone_number;
            }
        }
        return "";
    }

    //prosedur print() untuk menampilkan data yang tersimpan dalam tabel 
    void print(){
        for(int i = 0; i < TABLE_SIZE; i++){
            cout << i << ": ";
            for(auto pair : table[i]){
                if(pair != nullptr){
                    cout << "[" << pair->name << ", " << pair->phone_number << "]";
                }
            }
            cout << endl;
        }
    }
};

int main(){
    //deklarasik objek employee_map dari kelas HashMap
    HashMap employee_map;

    //insertion
    employee_map.insert("Mistah", "1234");
    employee_map.insert("Pastah", "5678");
    employee_map.insert("Ghana", "91011");

    //Search by name
    cout << "Nomor HP Mistah : " << employee_map.searchByName("Mistah") << endl;
    cout << "Nomor HP Pastah : " << employee_map.searchByName("Pastah") << endl;

    //remove
    employee_map.remove("Mistah");

    //search by name
    cout << "Nomor HP Mistah setelah dihapus : " << employee_map.searchByName("Mistah") << endl << endl;

    //print
    employee_map.print();

    return 0;
}
```

#### Deksripsi Program
Program diatas merupakan program implementasi hash table untuk penyimpanan dan pencarian data nama dan nomor telepon. Pada program ini key yang digunakan adalah nama sedangkan valuenya adalah nomor telepon sehingga pasangan key-value yang digunakan adalah nama-nomor telepon. Pada awal program ini, dideklarasikan ukuran table sebanyak 11, kemudian terdapat class HashNode dan class HashMap yang terdiri dari int hashFunc(), void insert(), void remove(), string searchByName(), dan void print(). Berikut merupakan penjelasan masing-masing bagian tersebut
1. class HashNode; digunakan untuk mendeklarasikan node yang terdiri dari name dan phone_number
2. class HashMap; berfungsi sebagai implementasi dari hash table yang teridir dari :
   - vector<HashNode*> table[TABLE_SIZE]; digunakan untuk menginisialisasi array table dengan ukuran TABLE_SIZE yang setiap elemen dari array tersebut merupakan sebuah vektor yang menyimpan pointer ke HashNode.
   - int hashFunc(string key); digunakan untuk menghitung nilai hash dari string key yang diinputkan user.
   - void insert(string name, string phone_number); digunakan untuk menambahkan data kedalam hash table. Jika ditemukan node dengan nama yang sama, nomor teleponnya diperbarui. Jika tidak ada node dengan nama yang sama, sebuah node baru dibuat menggunakan konstruktor HashNode dan ditambahkan ke vektor di indeks hash_val.
   - void remove(string name); digunakan untuk menghapus data tertentu berdasarkan key nama yang diinputkan user.
   - string searchByName(string name); digunakan untuk mencari data nomor telepon berdasarkan key nama yang diinputkan user.
   - void print(); digunakan untuk menampilkan atau mencetak isi dari tabel hash.

Kemudian pada int main(), dideklarasikan objek employee_map dari kelas HashMap, kemudian dilakukan operasi penambahan data key-value antara lain Mistah-1234, Pastah-5678, Ghana-91011. Kemudian dilakukan pencarian data nomor telepon Mistah dan Pastah menggunakan employee_map.searchByName(). Kemudian menghapus data nomor telepon Mistah menggunakan employee_map.remove(). Kemudian menampilkan data nomor telepon Mistah setelah dihapus menggunakan employee_map.searchByName(). Kemudian menampilkan semua data yang tersimpan dalan tabel hash menggunakan employee_map.print().

## Unguided 

### 1. Implementasikan Hash Table Untuk Menyimpan Data Mahasiswa. 
Setiap mahasiswa memiliki NIM dan nilai. Implementasikan fungsi untuk menambahkan data baru, menghapus data, mencari data berdasarkan NIM, dan mencari data berdasarkan nilai. Dengan ketentuan :
- a. Setiap mahasiswa memiliki NIM dan nilai.
- b. Program memiliki tampilan pilihan menu berisi poin C.
- c. Implementasikan fungsi untuk menambahkan data baru, menghapus data, mencari data berdasarkan NIM, dan mencari data berdasarkan rentang nilai (80 – 90).

```C++
#include<iostream>
#include<vector> 
#include<iomanip>

using namespace std;

//Deklarasi isi tabel sebanyak 100
const int TableSize_151 = 100;

//Deklarasi class HashNode_151
class HashNode_151{
    public:
    string nama_151;
    string NIM_151;
    int nilai_151;

    //deklarasi konstruktor HashNode_151 yang digunakan untuk membuat objek HashNode_151 dengan parameter nama, nim, dan nilai
    HashNode_151(string name_151, string NIM_151, int grade_151){
        this->nama_151 = name_151;
        this->NIM_151 = NIM_151;
        this->nilai_151 = grade_151;
    }
};

//Deklarasi class HashMap_151
class HashMap_151{
    private:
    //array table yang berisi vektor dari pointer ke HashNode_151, 
    //yang digunakan sebagai wadah untuk menyimpan data secara terorganisir berdasarkan hasil hashing dari kunci (key).
    vector<HashNode_151*> table[TableSize_151];

    public:
    //menghitung nilai hash dari sebuah string key_151
    int hashFunc_151(string key_151){
        int hashValue_151 = 0;
        for(char c : key_151){
            hashValue_151 += c;
        }
        return hashValue_151 % TableSize_151;
    }

    //prosedur Tambah_151 untuk menambah data baru kedalam tabel
    void Tambah_151(string name_151, string NIM_151, int grade_151){
        int hashValue_151 = hashFunc_151(name_151); //inisialisasi nilai hash

        //perulangan for-each yang memeriksa setiap node atau isi tabel
        for(auto node : table[hashValue_151]){
            if(node->nama_151 == name_151){ //jika nama_151 dari node saat ini sama dengan inputan name_151, maka
                node->NIM_151 = NIM_151; //ubah nim node saat ini dengan inputan nim baru
                node->nilai_151 = grade_151; //ubah nilai saat ini dengan inputan nilai baru
                return;
            }
        }
        //jika tidak terdapat node dengan nama yang sama, maka buat node baru
        table[hashValue_151].push_back(new HashNode_151(name_151, NIM_151, grade_151));
    }

    //fungsi CekData_151 untuk mengecek data tertentu dalam tabel apakah ada atau tidak
    bool CekData_151(string name_151){
        int hashValue_151 = hashFunc_151(name_151); //inisialisasi nilai hash

        //perulangan for-each yang memeriksa setiap node atau isi tabel
        for(auto node = table[hashValue_151].begin(); node != table[hashValue_151].end(); node++){
            if((*node)->nama_151 == name_151){  //jika nama dari node saat ini sama dengan inputan name_151, maka
                return true; //kembalikan true
            } 
        }
        return false; //kembalikan false jika nama dari node saat ini tidak sama dengan inputan name_151
    }

    //fungsi IsEmpty_151 untuk mengecek apakah tabel kosong atau tidak 
    bool IsEmpty_151() {
        for (int i = 0; i < TableSize_151; i++) {
            if (!table[i].empty()) {
                return false; // Jika ditemukan tabel tidak kosong, kembalikan false
            }
        }
        return true; // Jika tabel kosong, kembalikan true
    }

    //prosedur Hapus_151 untuk menghapus data tertentu yang ada didalam tabel
    void Hapus_151(string name_151){
        int hashValue_151 = hashFunc_151(name_151); //inisialisasi nilai hash

        //perulangan for-each yang memeriksa setiap node atau isi tabel
        for(auto node = table[hashValue_151].begin(); node != table[hashValue_151].end(); node++){
            if((*node)->nama_151 == name_151){ //jika nama dari node saat ini sama dengan inputan name_151, maka
                table[hashValue_151].erase(node); //hapus node saat ini
                return;
            } else { //jika nama dari node saat ini tidak sama dengan inputan name_151, maka tampilkan output
                cout << "Data mahasiswa " << name_151 << " tidak ditemukan" << endl;
            }
        }
    }

    //prosedur SearchByNIM_151 untuk mencari data tertentu berdasarkan NIM
    void SearchByNIM_151(string NIM_151){
        bool ketemu = false; //deklarasi variable bool ketemu sebagai false
        cout << "-------------- HASIL PENCARIAN --------------" << endl;
        cout << "---------------------------------------------" << endl;
        cout << "|" << left << setw(14) << "Nama" << "|" << left << setw(14) << "NIM" << "|" << left << setw(13) << "Nilai" << "|" << endl;
        cout << "---------------------------------------------" << endl;
        for(int i=0; i < TableSize_151; i++){
            //perulangan for-each yang memeriksa setiap node atau isi tabel
            for(auto node : table[i]){
                if(node->NIM_151 == NIM_151){ //jika nim dari node saat ini sama dengan inputan NIM_151, maka tampilkan data
                    cout << "|" << left << setw(14) << node->nama_151 << "|" << left << setw(14) << node->NIM_151 << "|" << left << setw(13) << node->nilai_151 << "|" << endl;
                    ketemu = true; //ubah bool ketemu menjadi true
                }
            }
        }
        if(!ketemu){ //jika nim dari node saat ini tidak sama dengan inputan NIM_151, maka tampilkan output
            cout << "Data mahasiswa dengan NIM " << NIM_151 << " tidak ditemukan" << endl;
        }
        cout << "---------------------------------------------" << endl;
    }

    //prosedur SearchByGrade_151 untuk mencari data tertentu berdasarkan rentang nilai
    void SearchByGrade_151(int min_151, int max_151){
        bool ketemu = false; //deklarasi variable bool ketemu sebagai false
        cout << "-------------- HASIL PENCARIAN --------------" << endl;
        cout << "---------------------------------------------" << endl;
        cout << "|" << left << setw(14) << "Nama" << "|" << left << setw(14) << "NIM" << "|" << left << setw(13) << "Nilai" << "|" << endl;
        cout << "---------------------------------------------" << endl;
        for (int i=0; i < TableSize_151; i++){
            //perulangan for-each yang memeriksa setiap node atau isi tabel
            for(auto node : table[i]){
                if(node->nilai_151 >= min_151 && node->nilai_151 <= max_151){ //jika nilai dari node saat ini lebih dari sama dengan inputan min_151 dan kurang dari sama degan max_151, maka tampilkan data  
                    cout << "|" << left << setw(14) << node->nama_151 << "|" << left << setw(14) << node->NIM_151 << "|" << left << setw(13) << node->nilai_151 << "|" << endl;
                    ketemu = true; //ubah bool ketemu menjadi true
                }
            }
        }
        if(!ketemu){ //jika nilai dari node saat ini tidak lebih dari sama dengan inputan min_151 dan tidak kurang dari sama degan max_151, maka tampilkan output
            cout << "Data mahasiswa dengan rentang nilai " << min_151 << " - " << max_151 << " tidak ditemukan" << endl;
        }
        cout << "---------------------------------------------" << endl;
    }

    //prosedur TampilData_151 untuk menampilkan tabel
    void TampilData_151(){
        for(int i=0; i < TableSize_151; i++){
            //perulangan for-each yang memeriksa setiap node atau isi tabel
            for(auto node : table[i]){ //tampilkan data setiap node 
            cout << "|" << left << setw(14) << node->nama_151 << "|" << left << setw(14) << node->NIM_151 << "|" << left << setw(13) << node->nilai_151 << "|" << endl;
            }
        }
        cout << "---------------------------------------------" << endl;
    }
};

int main(){
    //menggunakan class
    HashMap_151 StudentMap;
    //deklarasi variablel yang diperlukan
    int choose_151, grade_151, GradeMin_151, GradeMax_151;
    string name_151, NIM_151;
    char yakin_151;
    //tag Menu Utama
    MenuUtama:
    cout << "--------------- DATA MAHASISWA --------------" << endl;
    cout << "| 1. Tambah Data                            |" << endl;
    cout << "| 2. Hapus Data                             |" << endl;
    cout << "| 3. Cari Data Berdasarkan NIM              |" << endl;
    cout << "| 4. Cari Data Berdasarkan Nilai            |" << endl;
    cout << "| 5. Tampilkan Data                         |" << endl;
    cout << "| 6. Keluar                                 |" << endl;
    cout << "---------------------------------------------" << endl;
    cout << "Masukkan pilihan anda = ";
    cin >> choose_151;
    cout << endl;

    switch(choose_151){ //percabangan switchcase berdasarkan inputan variabel choose_151
        case 1: //jika memilih 1, maka tambah data
            cout << "---------------- TAMBAH DATA ----------------" << endl;
            cout << "Masukkan nama mahasiswa = "; cin >> name_151;
            cout << "Masukkan NIM = "; cin >> NIM_151;
            cout << "Masukkan nilai mahasiswa = "; cin >> grade_151;
            StudentMap.Tambah_151(name_151, NIM_151, grade_151); //pemanggilan metode Tambah_151 pada objek StudentMap dari kelas HashMap_151
            cout << "Data mahasiswa " << name_151 << " berhasil ditambahkan" << endl;
            cout << endl;
            goto MenuUtama; //kembali ke Menu Utama
            break;
        case 2: //jika memilih 2, maka hapus data
            cout << "----------------- HAPUS DATA ----------------" << endl;
            if(StudentMap.IsEmpty_151() == false){ //jika metode IsEmpty_151 pada objek StudentMap dari kelas HashMap_151 bernilai false, maka lanjutkan
                cout << "Masukkan nama mahasiswa yang ingin dihapus = "; cin >> name_151;
                StudentMap.CekData_151(name_151); //pemanggilan metode CekData_151 pada objek StudentMap dari kelas HashMap_151
                if(StudentMap.CekData_151(name_151) == true){ //jika metode CekData_151 bernilai true, maka lanjutkan
                    cout << "Apakah anda yakin unuk menghapus data mahasiswa " << name_151 << "? [y/n] = "; cin >> yakin_151;
                    if(yakin_151 == 'y' || yakin_151 == 'Y'){
                        StudentMap.Hapus_151(name_151); //pemanggilan metode Hapus_151 pada objek StudentMap dari kelas HashMap_151
                        cout << "Data mahasiswa " << name_151 << " berhasil dihapus" << endl;
                    } else if(yakin_151 == 'n' || yakin_151 == 'N'){
                        cout << "Aksi dibatalkan" << endl;
                    }
                } else { //jika data name_151 tidak ditemukan pada tabel, maka tampilkan output
                    cout << "Data mahasiswa " << name_151 << " tidak ditemukan" << endl;
                }
            } else { //jika metode IsEmpty bernilai true, maka tabel masih kosong
                cout << "Tabel masih kosong!" << endl;
            }
            cout << endl;
            goto MenuUtama; //kembali ke Menu Utama
            break;
        case 3: //jika memilih 3, maka cari data berdasarkan NIM
            cout << "--------- CARI DATA BERDASARKAN NIM ---------" << endl;
            if(StudentMap.IsEmpty_151() == false){ //jika metode IsEmpty_151 pada objek StudentMap dari kelas HashMap_151 bernilai false, maka lanjutkan
                cout << "Masukkan NIM = "; cin >> NIM_151;
                cout << endl;
                StudentMap.SearchByNIM_151(NIM_151); //pemanggilan metode SearchByNIM_151 pada objek StudentMap dari kelas HashMap_151
            } else { //jika metode IsEmpty bernilai true, maka tabel masih kosong
                cout << "Tabel masih kosong!" << endl;
            }
            cout << endl;
            goto MenuUtama; //kembali ke Menu Utama
            break;
        case 4: //jika memilih 4, maka cari data berdasarkan nilai
            cout << "-------- CARI DATA BERDASARKAN NILAI --------" << endl;
            if(StudentMap.IsEmpty_151() == false){ //jika metode IsEmpty_151 pada objek StudentMap dari kelas HashMap_151 bernilai false, maka lanjutkan
                cout << "Masukkan rentang nilai minimum = "; cin >> GradeMin_151;
                cout << "Masukkan rentang nilai maksimum = "; cin >> GradeMax_151;
                cout << endl;
                StudentMap.SearchByGrade_151(GradeMin_151,GradeMax_151); //pemanggilan metode SearchByGrade_151 pada objek StudentMap dari kelas HashMap_151
            } else { //jika metode IsEmpty bernilai true, maka tabel masih kosong
                cout << "Tabel masih kosong!" << endl;
            }
            cout << endl;
            goto MenuUtama; //kembali ke Menu Utama
            break;
        case 5: //jika memilih 5, maka tampilkan data
            cout << "---------------- TAMPIL DATA ----------------" << endl;
            if(StudentMap.IsEmpty_151() == false){ //jika metode IsEmpty_151 pada objek StudentMap dari kelas HashMap_151 bernilai false, maka lanjutkan
                cout << "---------------------------------------------" << endl;
                cout << "|" << left << setw(14) << "Nama" << "|" << left << setw(14) << "NIM" << "|" << left << setw(13) << "Nilai" << "|" << endl;
                cout << "---------------------------------------------" << endl;
                StudentMap.TampilData_151(); //pemanggilan metode TampilData_151 pada objek StudentMap dari kelas HashMap_151
            } else { //jika metode IsEmpty bernilai true, maka tabel masih kosong
                cout << "Tabel masih kosong!" << endl;
            }
            cout << endl;
            goto MenuUtama; //kembali ke Menu Utama
            break;
        case 6: //jika memilih 6, maka keluar dari program
            cout << "Anda keluar dari program" << endl;
            return 0;
        default: //opsi jika inputan pilihan tidak tersedia
            cout << "Pilihan anda tidak tersedia" << endl;
            cout << endl;
            goto MenuUtama; //kembali ke Menu Utama
            break;
    }
}
```
#### Output:

##### Output 1-1 (Tambah Data Dhimas)
![Dhimas_Output-Unguided1-1-1](https://github.com/Masdim37/2311102151_Muhammad-Dhimas-Hafizh-Fathurrahman/blob/main/Pertemuan5_Modul5-HashTable/Laprak/Dhimas_Output-Unguided1-1-1.png)

##### Output 1-2 (Tambah Data Hafizh)
![Dhimas_Output-Unguided1-1-2](https://github.com/Masdim37/2311102151_Muhammad-Dhimas-Hafizh-Fathurrahman/blob/main/Pertemuan5_Modul5-HashTable/Laprak/Dhimas_Output-Unguided1-1-2.png)

##### Output 1-3 (Tambah Data Fathur)
![Dhimas_Output-Unguided1-1-3](https://github.com/Masdim37/2311102151_Muhammad-Dhimas-Hafizh-Fathurrahman/blob/main/Pertemuan5_Modul5-HashTable/Laprak/Dhimas_Output-Unguided1-1-3.png)

##### Output 1-4 (Tambah Data Rahman)
![Dhimas_Output-Unguided1-1-4](https://github.com/Masdim37/2311102151_Muhammad-Dhimas-Hafizh-Fathurrahman/blob/main/Pertemuan5_Modul5-HashTable/Laprak/Dhimas_Output-Unguided1-1-4.png)

##### Output 1-5 (Tambah Data zmihd)
![Dhimas_Output-Unguided1-1-5](https://github.com/Masdim37/2311102151_Muhammad-Dhimas-Hafizh-Fathurrahman/blob/main/Pertemuan5_Modul5-HashTable/Laprak/Dhimas_Output-Unguided1-1-5.png)

##### Output 1-6 (Tampilkan Data Setelah Ditambahkan)
![Dhimas_Output-Unguided1-1-6](https://github.com/Masdim37/2311102151_Muhammad-Dhimas-Hafizh-Fathurrahman/blob/main/Pertemuan5_Modul5-HashTable/Laprak/Dhimas_Output-Unguided1-1-6.png)

##### Output 2-1 (Hapus Data Rahman)
![Dhimas_Output-Unguided1-2-1](https://github.com/Masdim37/2311102151_Muhammad-Dhimas-Hafizh-Fathurrahman/blob/main/Pertemuan5_Modul5-HashTable/Laprak/Dhimas_Output-Unguided1-2-1.png)

##### Output 2-1 (Tampilkan Data Setelah Menghapus Data Rahman)
![Dhimas_Output-Unguided1-2-2](https://github.com/Masdim37/2311102151_Muhammad-Dhimas-Hafizh-Fathurrahman/blob/main/Pertemuan5_Modul5-HashTable/Laprak/Dhimas_Output-Unguided1-2-2.png)

##### Output 3-1 (Cari Data Berdasarkan NIM (2311102151))
![Dhimas_Output-Unguided1-3-1](https://github.com/Masdim37/2311102151_Muhammad-Dhimas-Hafizh-Fathurrahman/blob/main/Pertemuan5_Modul5-HashTable/Laprak/Dhimas_Output-Unguided1-3-1.png)

##### Output 3-2 (Cari Data Berdasarkan NIM (2311102121))
![Dhimas_Output-Unguided1-3-2](https://github.com/Masdim37/2311102151_Muhammad-Dhimas-Hafizh-Fathurrahman/blob/main/Pertemuan5_Modul5-HashTable/Laprak/Dhimas_Output-Unguided1-3-2.png)

##### Output 4 (Cari Data Berdasarkan Rentang Nilai (80-90))
![Dhimas_Output-Unguided1-4](https://github.com/Masdim37/2311102151_Muhammad-Dhimas-Hafizh-Fathurrahman/blob/main/Pertemuan5_Modul5-HashTable/Laprak/Dhimas_Output-Unguided1-4.png)

##### Output 5 (Tampilkan Seluruh Data)
![Dhimas_Output-Unguided1-5](https://github.com/Masdim37/2311102151_Muhammad-Dhimas-Hafizh-Fathurrahman/blob/main/Pertemuan5_Modul5-HashTable/Laprak/Dhimas_Output-Unguided1-5.png)

##### Output 6 (Keluar Dari Program)
![Dhimas_Output-Unguided1-6](https://github.com/Masdim37/2311102151_Muhammad-Dhimas-Hafizh-Fathurrahman/blob/main/Pertemuan5_Modul5-HashTable/Laprak/Dhimas_Output-Unguided1-6.png)

#### Deskripsi Program
Program diatas merupakan implementasi dari struktur data hash table yang digunakan untuk menyimpan data mahasiswa, yang terdiri dari nama, NIM, dan nilai. Tabel yang digunakan memiliki ukuran 100. Pada program ini, terdapat 2 tipe data class, berikut penjelasannya :
- class HashNode_151; merepresentasikan setiap node dalam tabel hash. Setiap node memiliki atribut nama, NIM, dan nilai.
- class HashMap_151; digunakan untuk mengelola tabel hash. tabel ini berupa array yang berisi vektor dari pointer ke HashNode_151 yang digunakan sebagai wadah untuk menyimpan data secara terorganisir berdasarkan hasil hashing dari kunci (key). Pada class HashMap_151 ini terdapat beberapa operasi yang digunakan untuk mengelola tabel hash, antara lain sebagai berikut.
  - int hashFunc_151(string key_151); digunakan untuk menghitung nilai hash dari sebuah string key_151
  - void Tambah_151(string name_151, string NIM_151, int grade_151); digunakan untuk Menambahkan data mahasiswa baru ke dalam tabel hash
  - bool CekData_151(string name_151); digunakan untuk mengecek ada atau tidaknya data mahasiswa tertentu didalam tabel
  - bool IsEmpty_151(); digunakan untuk mengecek kosong atau tidaknya isi tabel
  - void Hapus_151(string name_151); digunakan untuk menghapus data tertentu yang ada didalam tabel
  - void SearchByNIM_151(string NIM_151); digunakan untuk mencari data mahasiswa berdasarkan NIM
  - void SearchByGrade_151(int min_151, int max_151); digunakan untuk mencari data mahasiswa berdasarkan rentang nilai
  - void TampilData_151(); digunakan untuk menampilkan data yang tersimpan didalam tabel
  
Kemudian pada int main(), terdapat menu DATA MAHASISWA yang dibuat menggunakan perulangan switchcase. Jika user memilih 1, maka masuk ke menu Tambah Data; jika user memilih 2, maka masuk ke menu Hapus Data; jika user memilih 3, maka masuk ke menu Cari Data Berdasarkan NIM; jika user memilih 4, maka masuk ke menu Cari Data Berdasarkan Nilai; jika user memilih 5, maka masuk ke menu Tampilkan Data; dan jika user memilih 6, maka keluar dari program.

## Kesimpulan
Tabel Hash atau hash table adalah sebuah struktur data yang digunakan untuk menyimpan pasangan key-value, di mana key digunakan sebagai indeks atau alamat untuk mengakses nilai terkait (value). Hash table terdiri dari sebuah array di mana setiap elemen dalam array tersebut disebut sebagai bucket. Untuk memetakan suatu key pada sebuah value, diperlukan sebuah teknik hashing. Teknik hashing ini melibatkan penggunaan fungsi hash yang mengonversi key menjadi sebuah hash value, yang kemudian digunakan sebagai indeks dalam array untuk menentukan lokasi penyimpanan data (value) tersebut dalam hash table.
<br>Pada implementasi hash table, dapat terjadi collision atau tabrakan data, yaitu kondisi dimana terdapat 2 atau lebih key yang menghasilkan hash value yang sama, sehingga data-data tersebut tersimpan dalam 1 bucket yang sama. Untuk mengatasi hal tersebut, diperlukan teknik resolusi collision antara lain open hashing (separate chaining) dan closed hashing (open addressing) yang terdiri dari linear probing (metode pembagian), quadratic probing (metode midsquare atau nilai tengah), dan double hashing (metode penjumlahan digit).

## Referensi
[1] Joseph Teguh Santoso. (2021). "STRUKTUR DATA dan ALGORITMA (Bagian 2)". Penerbit Yayasan Prima Agus Teknik, 7(1), 1-352. Retrieved from https://penerbit.stekom.ac.id/index.php/yayasanpat/article/view/284. 
<br>[2] Mulyana, Ade. (2023). "E-Books Cara Mudah Mempelajari Algoritma dan Struktur Data". Ade Mulyana. Diakses pada 8 April 2024 melalui https://repository.mercubuana.ac.id/id/eprint/80729. 
