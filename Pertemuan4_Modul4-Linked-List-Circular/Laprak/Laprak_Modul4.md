# <h1 align="center">Laporan Praktikum Modul 4 - Linked List Circular & Non-Circular</h1>
<p align="center">Muhammad Dhimas Hafizh Fathurrahman - 2311102151</p>

## Dasar Teori
Linked list atau yang disebut juga senarai berantai adalah Salah satu bentuk struktur data yang berisi kumpulan data yang tersusun secara sekuensial, saling bersambungan, dinamis, dan terbatas[1]. Linked list terdiri dari sejumlah node atau simpul yang dihubungkan secara linier dengan bantuan pointer. Suatu simpul atau node harus mempunyai satu atau lebih elemen struktur atau class yang berisi data. Pada suatu linked list, terdiri dari 2 elemen yaitu elemen pada awal list (head) dan elemen pada akhir list (tail). Berdasarkan cara hubungan antar elemennya, linked list terbagi menjadi 2 yaitu linked list circular dan linked list non-circular. 

### A. Linked List Non-Circular
Linked List Non-Circular merupakan linked list yang terdiri dari sejumlah node di mana setiap node memiliki pointer berikutnya ke elemen berikut. Node berikutnya dari node terakhir atau tail suatu linked list non-circular adalah NULL, yang menunjukkan akhir list[2]. Pada linked list non-circular tidak ada siklus atau lingkaran dalam struktur linked list. Dengan kata lain, tidak ada elemen yang menunjuk kembali ke elemen sebelumnya. Proses traversal dari awal hingga akhir linked list akan mencapai elemen terakhir dan kemudian berakhir. Operasi yang bisa dilakukan untuk memanipulasi linked list non-circular antara lain deklarasi node, inisialisasi node head dan tail, mengecek isi node, menambah node (depan, belakang, tengah), mengubah isi node (depan, belakang, tengah), menghapus node (depan, belakang, tengah), menghapus list, dan menampilkan list.
Berikut merupakan ilustrasi dari linked list non-circular.

- Ilustrasi Single Linked List Non-Circular (SLLNC)

![Dhimas_Ilustrasi-SLLNC](https://github.com/Masdim37/2311102151_Muhammad-Dhimas-Hafizh-Fathurrahman/blob/main/Pertemuan4_Modul4-Linked-List-Circular/Laprak/Dhimas_Ilustrasi-SLLNC.png)

Pada single linked list non-circular, suatu node terdiri dari data yang disimpan dan pointer next yang merujuk pada node selanjutnya. Proses ini berlanjut hingga node terakhir atau tail. Pointer next dari tail merujuk pada NULL atau kosong. 

- Ilustrasi Double Linked List Non-Circular (DLLNC)

![Dhimas_Ilustrasi-DLLNC](https://github.com/Masdim37/2311102151_Muhammad-Dhimas-Hafizh-Fathurrahman/blob/main/Pertemuan4_Modul4-Linked-List-Circular/Laprak/Dhimas_Ilustrasi-DLLNC.png)

Pada double linked list non-circular, suatu node terdiri dari data yang disimpan, pointer next yang merujuk pada node selanjutnya, dan pointer prev yang merujuk pada node sebelumnya. Pointer prev dari node pertama atau head merujuk pada NULL atau kosong dan pointer next dari node terakhir atau tail merujuk pada NULL atau kosong.

### B. Linked List Circular
Berbeda dengan linked list non-circular, linked list circular merupakan variasi dari linked list di mana elemen terakhir ditautkan ke elemen pertama, sehingga membentuk lingkaran melingkar[3]. Pada linked list circular, terdapat siklus dalam struktur linked list, di mana elemen terakhir menunjuk kembali ke elemen pertama, dan iterasi melalui linked list akan terus berputar mengelilingi siklus.
Pada linked list circular juga tidak ada elemen yang menunjuk ke null, karena seluruh linked list membentuk siklus tertutup. Sama seperti linked list non-circular, operasi yang bisa dilakukan untuk memanipulasi linked list circular antara lain deklarasi node, inisialisasi node head dan tail, mengecek isi node, menambah node (depan, belakang, tengah), mengubah isi node (depan, belakang, tengah), menghapus node (depan, belakang, tengah), menghapus list, dan menampilkan list.
Berikut merupakan ilustrasi dari linked list non-circular.

- Ilustrasi Single Linked List Circular (SLLC)

![Dhimas_Ilustrasi-SLLC](https://github.com/Masdim37/2311102151_Muhammad-Dhimas-Hafizh-Fathurrahman/blob/main/Pertemuan4_Modul4-Linked-List-Circular/Laprak/Dhimas_Ilustrasi-SLLC.png)

Pada single linked list circular, suatu node terdiri dari data yang disimpan dan pointer next yang merujuk pada node selanjutnya. Proses ini berlanjut hingga node terakhir atau tail. Pointer next dari tail merujuk pada node pertama atau head.

- Ilustrasi Double Linked List Circular (DLLC)

![Dhimas_Ilustrasi-DLLC](https://github.com/Masdim37/2311102151_Muhammad-Dhimas-Hafizh-Fathurrahman/blob/main/Pertemuan4_Modul4-Linked-List-Circular/Laprak/Dhimas_Ilustrasi-DLLC.png)

Pada double linked list circular, suatu node terdiri dari data yang disimpan, pointer next yang merujuk pada node selanjutnya, dan pointer prev yang merujuk pada node sebelumnya. Pointer prev dari node pertama atau head merujuk node terakhir atau tail dan pointer next dari node terakhir atau tail merujuk pada node pertama atau head.

## Guided 

### 1. Linked List Non Circular
```C++
#include<iostream>

using namespace std;

//PROGRAM SINGLE LINKED LIST NON-CIRCULAR

//Deklarasi Struct node
struct node{
    int data;
    node *next;
};
    node *head;
    node *tail;

//inisialisasi node head & tail
void init(){
    head = NULL;
    tail = NULL;
}

//Pengecekan isi list
bool isEmpty(){
    if(head == NULL){
        return true;
    } else {
        return false;
    }
}

//Prosedur tambah depan
void TambahDepan(int nilai){
    node *baru = new node;
    baru->data = nilai;
    baru->next = NULL;
    if(isEmpty() == true){
        head = tail = baru;
        tail->next = NULL;
    } else {
        baru->next = head;
        head = baru;
    }
}

//Prosedur tambah belakang
void TambahBelakang(int nilai){
    node *baru = new node;
    baru->data = nilai;
    baru->next = NULL;
    if(isEmpty() == true){
        head = tail = baru;
        tail->next = NULL;
    } else {
        tail->next = baru;
        tail = baru;
    }
}

//Prosedur hitung list
int HitungList(){
    node *hitung;
    hitung = head;
    int jumlah = 0;
    while(hitung != NULL){
        hitung = hitung->next;
        jumlah++;
    }
    return jumlah;
}

//Prosedur tambah tengah
void TambahTengah(int nilai, int posisi){
    if(posisi < 1 || posisi > HitungList()){
        cout << "Node yang ingin ditambahkan diluar jangkauan" << endl;
    } else if(posisi == 1){
        cout << "Node yang ingin ditambahkan bukan di tengah" << endl;
    } else {
        node *bantu;
        node *baru = new node;
        baru->data = nilai;
        //transvering
        bantu = head;
        int nomor = 1;
        while (nomor < posisi - 1){
            bantu = bantu->next;
            nomor++;
        }
        baru->next = bantu->next;
        bantu->next = baru;
    }
}

//Prosedur hapus depan
void HapusDepan(){
    node *hapus;
    if(isEmpty() == false){
        if(head->next != NULL){
            hapus = head;
            head = head->next;
            delete hapus;
        } else {
            head = tail = NULL;
        }
    } else {
        cout << "List kosong!" << endl;
    }
}

//Prosedur hapus belakang
void HapusBelakang(){
    node *hapus, *bantu;
    if(isEmpty() == false){
        if(head != tail){
            hapus = tail;
            bantu = head;
            while(bantu->next != tail){
                bantu = bantu->next;
            }
            tail = bantu;
            tail->next = NULL;
            delete hapus;
        } else {
            head = tail = NULL;
        }
    } else {
        cout << "List kosong!" << endl;
    }
}

//Prosedur Hapus tengah
void HapusTengah(int posisi){
    node *bantu, *hapus, *sebelum;
    if (posisi < 1 || posisi > HitungList()){
        cout << "Posisi diluar jangkauan" << endl;
    } else if(posisi == 1){
        cout << "Posisi bukan posisi tengah" << endl;
    } else {
        int nomor = 1;
        bantu = head;
        while(nomor <= posisi){
            if(nomor == posisi - 1){
                sebelum = bantu;
            } else if(nomor == posisi){
                hapus = bantu;
            }
            bantu = bantu->next;
            nomor++;
        }
        sebelum->next = bantu;
        delete hapus;
    }
}

//Prosedur ubah depan
void UbahDepan(int nilai){
    if(isEmpty() == 0){
        head->data = nilai;
    } else {
        cout << "List masih kosong!" << endl;
    }
}

//Prosedur ubah tengah
void UbahTengah(int nilai, int posisi){
    node *bantu;
    if(isEmpty() == false){
        if(posisi < 1 || posisi > HitungList()){
            cout << "Posisi diluar jangkauan" << endl;
        } else if(posisi == 1){
            cout << "node bukan node tengah" << endl;
        } else {
            bantu = head;
            int nomor = 1;
            while (nomor < posisi){
                bantu = bantu->next;
                nomor++;
            }
            bantu->data = nilai;
        }
    } else {
        cout << "List masih kosong!" << endl;
    }
}

//Prosedur ubah belakang
void UbahBelakang(int nilai){
    if(isEmpty() == false){
        tail->data = nilai;
    } else {
        cout << "List masih kosong!" << endl;
    }
}

//Prosedur hapus list
void Clearlist(){
    node *bantu, *hapus;
    bantu = head;
    while (bantu != NULL){
        hapus = bantu;
        bantu = bantu->next;
        delete hapus;
    }
    head = tail = NULL;
    cout << "List berhasil terhapus!" << endl;
}

//Prosedur tampilka list
void TampilList(){
    node *bantu;
    bantu = head;
    if(isEmpty() == false){
        while (bantu != NULL){
            cout << bantu->data << ends;
            bantu = bantu->next;
        }
        cout << endl;
    } else {
        cout << "List masih kosong!" << endl;
    }
}

int main(){
    init();
    TambahDepan(3);
    TampilList();
    TambahBelakang(5);
    TampilList();
    TambahDepan(2);
    TampilList();
    TambahDepan(1);
    TampilList();
    HapusDepan();
    TampilList;
    HapusBelakang();
    TampilList();
    TambahTengah(7, 2);
    TampilList();
    HapusTengah(2);
    TampilList();
    UbahDepan(1);
    TampilList();
    UbahBelakang(8);
    TampilList();
    UbahTengah(11, 2);
    TampilList();

    return 0;
}
```
#### Deskripsi Program
Deskripsi guided 1

### 2. Linked List Circular

```C++
#include <iostream>
using namespace std;

// Deklarasi Struct Node
struct Node{
    string data;
    Node* next;
};

Node* head, * tail, * baru, * bantu, * hapus;

//Inisialisasi node head & tail
void init(){
    head = NULL;
    tail = head;
}

//Pengecekan isi list
int isEmpty(){
    if (head == NULL){
        return 1; // true
    } else {
        return 0; // false
    }
}

//Buat Node Baru
void buatNode(string data){
    baru = new Node;
    baru->data = data;
    baru->next = NULL;
}

//Hitung List
int hitungList(){
    bantu = head;
    int jumlah = 0;
    while (bantu != NULL) {
        jumlah++;
        bantu = bantu->next;
    }
    return jumlah;
}

//Tambah Depan
void insertDepan(string data){
    // Buat Node baru
    buatNode(data);

    if (isEmpty() == 1){
        head = baru;
        tail = head;
        baru->next = head;
    } else {
        while (tail->next != head){
            tail = tail->next;
        }
        baru->next = head;
        head = baru;
        tail->next = head;
    }
}

//Tambah Belakang
void insertBelakang(string data){
    // Buat Node baru
    buatNode(data);

    if (isEmpty() == 1){
        head = baru;
        tail = head;
        baru->next = head;
    } else {
        while (tail->next != head){
            tail = tail->next;
        }
        tail->next = baru;
        baru->next = head;
    }
}

//Tambah Tengah
void insertTengah(string data, int posisi){
    if (isEmpty() == 1){
        head = baru;
        tail = head;
        baru->next = head;
    } else {
        baru->data = data;
        // transversing
        int nomor = 1;
        bantu = head;
        while (nomor < posisi - 1){
            bantu = bantu->next;
            nomor++;
        }
        baru->next = bantu->next;
        bantu->next = baru;
    }
}

//Hapus Depan
void hapusDepan(){
    if (isEmpty() == 0){
        hapus = head;
        tail = head;
        if (hapus->next == head){
            head = NULL;
            tail = NULL;
            delete hapus;
        } else {
            while (tail->next != hapus){
                tail = tail->next;
            }
            head = head->next;
            tail->next = head;
            hapus->next = NULL;
            delete hapus;
        }
    } else {
        cout << "List masih kosong!" << endl;
    }
}

//Hapus Belakang
void hapusBelakang(){
    if (isEmpty() == 0){
        hapus = head;
        tail = head;
        if (hapus->next == head){
            head = NULL;
            tail = NULL;
            delete hapus;
        } else {
            while (hapus->next != head){
                hapus = hapus->next;
            }
            while (tail->next != hapus){
                tail = tail->next;
            }
            tail->next = head;
            hapus->next = NULL;
            delete hapus;
        }
    } else {
        cout << "List masih kosong!" << endl;
    }
}

// Hapus Tengah
void hapusTengah(int posisi){
    if (isEmpty() == 0){
        // transversing
        int nomor = 1;
        bantu = head;
        while (nomor < posisi - 1){
            bantu = bantu->next;
            nomor++;
        }
        hapus = bantu->next;
        bantu->next = hapus->next;
        delete hapus;
    } else {
        cout << "List masih kosong!" << endl;
    }
}

//Hapus List
void clearList(){
    if (head != NULL){
        hapus = head->next;
        while (hapus != head){
            bantu = hapus->next;
            delete hapus;
            hapus = bantu;
        }
        delete head;
        head = NULL;
    }
    cout << "List berhasil terhapus!" << endl;
}

//Tampilkan List
void tampil(){
    if (isEmpty() == 0){
        tail = head;
        do {
            cout << tail->data << ends;
            tail = tail->next;
        } while (tail != head);
        cout << endl;
    } else {
        cout << "List masih kosong!" << endl;
    }
}

int main(){
    init();
    insertDepan("Ayam");
    tampil();
    insertDepan("Bebek");
    tampil();
    insertBelakang("Cicak");
    tampil();
    insertBelakang("Domba");
    tampil();
    hapusBelakang();
    tampil();
    hapusDepan();
    tampil();
    insertTengah("Sapi", 2);
    tampil();
    hapusTengah(2);
    tampil();
    
    return 0;
}
```
#### Deskripsi Program
Deskripsi guided 2

## Unguided 
Buatlah program menu Linked List Non Circular untuk menyimpan Nama dan NIM mahasiswa, dengan menggunakan input dari user.

### 1. Buatlah menu untuk menambahkan, mengubah, menghapus, dan melihat Nama dan NIM mahasiswa! 
berikut contoh tampilan output dari nomor 1:

![Dhimas_Soal-Unguided1-1](https://github.com/Masdim37/2311102151_Muhammad-Dhimas-Hafizh-Fathurrahman/blob/main/Pertemuan4_Modul4-Linked-List-Circular/Laprak/Dhimas_Soal-Unguided1-1.png)
![Dhimas_Soal-Unguided1-2](https://github.com/Masdim37/2311102151_Muhammad-Dhimas-Hafizh-Fathurrahman/blob/main/Pertemuan4_Modul4-Linked-List-Circular/Laprak/Dhimas_Soal-Unguided1-2.png)

```C++
#include<iostream>
#include<iomanip>

using namespace std;

//deklarasi struct node
struct node{
    string Nama_151;
    string NIM_151;
    node *next;
};
    node *head;
    node *tail;

//Inisialisasi node head & tail
void Inisialisasi_151(){
    head = NULL;
    tail = NULL;
}

//fungsi pengecekan
bool isEmpty_151(){
    if(head == NULL){
        return true;
    } else {
        return false;
    }
}

//prosedur hitung node
int HitungNode_151(){
    node *hitung = head;
    int jumlah_151 = 0;
    while (hitung != NULL){
        hitung = hitung->next;
        jumlah_151++;
    }
    return jumlah_151;
}

//prosedur tambah depan
void TambahDepan_151(string Name_151, string NIM_151){
    node *baru = new node;
    baru->Nama_151 = Name_151;
    baru->NIM_151 = NIM_151;
    baru->next = NULL;
    if(isEmpty_151() == true){
        head = tail = baru;
        tail->next = NULL;
    } else {
        baru->next = head;
        head = baru;
    }
}

//prosedur tambah belakang
void TambahBelakang_151(string Name_151, string NIM_151){
    node *baru = new node;
    baru->Nama_151 = Name_151;
    baru->NIM_151 = NIM_151;
    baru->next = NULL;
    if(isEmpty_151() == true){
        head = tail = baru;
        tail->next = NULL;
    } else {
        tail->next = baru;
        tail = baru;
    }
}

//prosedur tambah tengah
void TambahTengah_151(string Name_151, string NIM_151, int Position_151){
    if(Position_151 < 1 || Position_151 > HitungNode_151()){
        cout << "Node yang ingin ditambah diluar jangkauan!" << endl;
    } else if(Position_151 == 1){
        cout << "Node yang ingin ditambah bukan ditengah!"<< endl;
    } else {
        node *bantu = head;
        node *baru = new node;
        baru->Nama_151 = Name_151;
        baru->NIM_151 = NIM_151;
        int hitung_151 = 1;
        while(hitung_151 < Position_151 - 1){
            bantu = bantu->next;
            hitung_151++;
        }
        baru->next = bantu->next;
        bantu->next = baru;
    }
}

//prosedur hapus depan
void HapusDepan_151(){
    node *hapus;
    if(isEmpty_151() == true){
        cout << "List masih kosong!" << endl;
    } else {
        if(head->next != NULL){
            hapus = head;
            head = head->next;
            delete hapus;
        } else {
            head = tail = NULL;
        }
    }
}

//fungsi tampil data depan
string TampilDepan_151(){
    string NamaYangDihapus_151 = "";
    if(isEmpty_151() == false){
        NamaYangDihapus_151 = head->Nama_151;
    } else {
        cout << "List masih kosong" << endl;
    }
    return NamaYangDihapus_151;
}

//prosedur hapus belakang
void HapusBelakang_151(){
    node *hapus, *bantu;
    if(isEmpty_151() == true){
        cout << "List masih kosong!" << endl;
    } else {
        if(head != tail){
            hapus = tail;
            bantu = head;
            while(bantu->next != tail){
                bantu = bantu->next;
            }
            tail = bantu;
            tail->next = NULL;
            delete hapus;
        } else {
            head = tail = NULL;
        }
    }
}

//fungsi tampil data belakang
string TampilBelakang_151(){
    string NamaYangDihapus_151 = "";
    if(isEmpty_151() == false){
        NamaYangDihapus_151 = tail->Nama_151;
    } else {
        cout << "List masih kosong" << endl;
    }
    return NamaYangDihapus_151;
}


//prosedur hapus tengah
void HapusTengah_151(int posisi_151){
    if(posisi_151 < 1 || posisi_151 > HitungNode_151()){ 
        cout << "Posisi node yang akan dihapus offside" << endl;
    } else if(posisi_151 == 1){
        cout << "Node yang ingin dihapus bukan node tengah" << endl;
    } else {
        node *hapus, *bantu, *bantu2;
        bantu = head;
        int nomor_151 = 1;
        while(nomor_151 <= posisi_151){
            if(nomor_151 == posisi_151 - 1){
                bantu2 = bantu;
            } else if(nomor_151 == posisi_151){
                hapus = bantu;
            }
            bantu = bantu->next;
            nomor_151++; 
        }
        bantu2->next = bantu;
        delete hapus;
    }
}

//fungsi tampil data tengah
string TampilTengah_151(int Position_151){
    string NamaYangDihapus_151 = "";
    node *tampil = head;
    node *bantu;
    if(isEmpty_151() == false){
        int nomor_151 = 1;
        while (nomor_151 <= Position_151 - 1){
            if(nomor_151 == Position_151 - 1){
                bantu = tampil;
            }
            tampil = tampil->next;
            nomor_151++;
        }
        bantu->next = tampil;
        NamaYangDihapus_151 = tampil->Nama_151;       
    } else {
        cout << "List masih kosong" << endl;
    }
    return NamaYangDihapus_151;
}

//prosedur Ubah depan
void UbahDepan_151(string NewName_151, string NewNIM_151){
    if(isEmpty_151() == true){
        cout << "List masih kosong!" << endl;
    } else {
        head->Nama_151 = NewName_151;
        head->NIM_151 = NewNIM_151;
    }
}

//prosedur ubah belakang
void UbahBelakang_151(string NewName_151, string NewNIM_151){
    if(isEmpty_151() == true){
        cout << "List masih kosong!" << endl;
    } else {
        tail->Nama_151 = NewName_151;
        tail->NIM_151 = NewNIM_151;
    }
}

//prosedur ubah tengah
void UbahTengah_151(string NewName_151, string NewNIM_151, int Position_151){
    if(isEmpty_151() == true){
        cout << "List masih kosong!" << endl;
    } else {
        if(Position_151 < 1 || Position_151 > HitungNode_151()){
            cout << "Node yang ingin diubah diluar jangkauan!" << endl;
        } else if(Position_151 == 1){
            cout << "Node yang ingin diubah bukan ditengah!" << endl;
        } else {
            node *bantu;
            bantu = head;
            int nomor_151 = 1;
            while(nomor_151 < Position_151){
                bantu = bantu->next;
                nomor_151++;
            }
           bantu->Nama_151 = NewName_151;
           bantu->NIM_151 = NewNIM_151;
        }
    }
}

//prosedur hapus list
void HapusList_151(){
    node *hapus;
    node *bantu = head;
    if(isEmpty_151() == true){
        cout << "List masih kosong!" << endl;
    } else {
        while(bantu != NULL){
            hapus = bantu;
            bantu = bantu->next;
            delete hapus;   
        }
        head = tail = NULL;
    }
}

//prosedur tampil list
void TampilList_151(){
    node *bantu = head;
    if(isEmpty_151() == true){
        cout << "List masih kosong!" << endl;
    } else {
        cout << "------------------------------------------" << endl;
        cout << "|         NAMA         |       NIM       |" << endl;
        cout << "------------------------------------------" << endl;
        while(bantu != NULL){
            cout << "|" << setw(22) << left << bantu->Nama_151 << "|" << setw(17) << left << bantu->NIM_151 << "|" << endl;
            bantu = bantu->next;
        }
        cout << "------------------------------------------" << endl;
    }
}

int main(){
    int Position_151, Choose_151;
    string Name_151, OldName_151, NIM_151, OldNIM_151;
    char Yakin_151;
    Inisialisasi_151();
    MenuUtama:
    cout << "------- PROGRAM SINGLE LINKED LIST -------" << endl;
    cout << "-------------- NON-CIRCULAR --------------" << endl; 
    cout << "| 1. TAMBAH DEPAN                        |" << endl;
    cout << "| Menambahkan data pada awal list        |" << endl;
    cout << "| 2. TAMBAH BELAKANG                     |" << endl;
    cout << "| Menambahkan data pada akhir list       |" << endl;
    cout << "| 3. TAMBAH TENGAH                       |" << endl;
    cout << "| Menambahkan data pada urutan tertentu  |" << endl;
    cout << "| 4. UBAH DEPAN                          |" << endl;
    cout << "| Mengubah data pada urutan pertama      |" << endl;
    cout << "| 5. UBAH BELAKANG                       |" << endl;
    cout << "| Mengubah data pada urutan terakhir     |" << endl;
    cout << "| 6. UBAH TENGAH                         |" << endl;
    cout << "| Mengubah data pada urutan tertentu     |" << endl;
    cout << "| 7. HAPUS DEPAN                         |" << endl;
    cout << "| Menghapus data urutan pertama          |" << endl;
    cout << "| 8. HAPUS BELAKANG                      |" << endl;
    cout << "| Menghapus data urutan terakhir         |" << endl;
    cout << "| 9. HAPUS TENGAH                        |" << endl;
    cout << "| Menghapus data urutan tertentu         |" << endl;
    cout << "| 10. HAPUS LIST                         |" << endl;
    cout << "| Menghapus seluruh data                 |" << endl;
    cout << "| 11. TAMPILKAN                          |" << endl;
    cout << "| Menampilkan list data yang tersimpan   |" << endl;
    cout << "| 0. KELUAR                              |" << endl;
    cout << "| Keluar dari program                    |" << endl;
    cout << "------------------------------------------" << endl;
    cout << "Masukkan pilihan anda = ";
    cin >> Choose_151;
    cout << endl;
    switch(Choose_151){
        case 1:
            cout << "-------------- TAMBAH DEPAN --------------" << endl;
            cout << "-- Masukkan data yang ingin ditambahkan --" << endl;
            cout << "Nama Mahasiswa = ";
            cin >> Name_151;
            cout << "NIM Mahasiswa = ";
            cin >> NIM_151;
            TambahDepan_151(Name_151, NIM_151);
            cout << "Data berhasil ditambahkan" << endl;
            cout << endl;
            goto MenuUtama;
            break;
        case 2:
            cout << "------------ TAMBAH BELAKANG -------------" << endl;
            cout << "-- Masukkan data yang ingin ditambahkan --" << endl;
            cout << "Nama Mahasiswa = ";
            cin >> Name_151;
            cout << "NIM Mahasiswa = ";
            cin >> NIM_151;
            TambahBelakang_151(Name_151, NIM_151);
            cout << "Data berhasil ditambahkan" << endl;
            cout << endl;
            goto MenuUtama;
            break;
        case 3:
            cout << "------------- TAMBAH TENGAH --------------" << endl;
            cout << "-- Masukkan data yang ingin ditambahkan --" << endl;
            cout << "Nama Mahasiswa = ";
            cin >> Name_151;
            cout << "NIM Mahasiswa = ";
            cin >> NIM_151;
            cout << "Posisi data = ";
            cin >> Position_151;
            TambahTengah_151(Name_151, NIM_151, Position_151);
            cout << "Data berhasil ditambahkan" << endl;
            cout << endl;
            goto MenuUtama;
            break;
        case 4:
            cout << "----------------- UBAH DEPAN -----------------" << endl;
            cout << "------- Masukkan data yang akan diubah -------" << endl;
            cout << "--- Data Lama ---" << endl;
            cout << "Nama Mahasiswa lama = ";
            cin >> OldName_151;
            cout << "NIM Mahasiswa lama = ";
            cin >> OldNIM_151;
            cout << "--- Data Baru ---" << endl;
            cout << "Nama mahasiswa baru = "; 
            cin >> Name_151;
            cout << "NIM mahasiswa baru = ";
            cin >> NIM_151;
            UbahDepan_151(Name_151, NIM_151);
            cout << "Data mahasiswa " << OldName_151 << " (" << OldNIM_151 << ") telah diganti dengan data mahasiswa baru " << Name_151 << " (" << NIM_151 << ")" << endl;
            cout << endl;
            goto MenuUtama;
            break;
        case 5:
            cout << "--------------- UBAH BELAKANG ----------------" << endl;
            cout << "------- Masukkan data yang akan diubah -------" << endl;
            cout << "--- Data Lama ---" << endl;
            cout << "Nama Mahasiswa lama = ";
            cin >> OldName_151;
            cout << "NIM Mahasiswa lama = ";
            cin >> OldNIM_151;
            cout << "--- Data Baru ---" << endl;
            cout << "Nama mahasiswa baru = "; 
            cin >> Name_151;
            cout << "NIM mahasiswa baru = ";
            cin >> NIM_151;
            UbahBelakang_151(Name_151, NIM_151);
            cout << "Data mahasiswa " << OldName_151 << " (" << OldNIM_151 << ") telah diganti dengan data mahasiswa baru " << Name_151 << " (" << NIM_151 << ")" << endl;
            cout << endl;
            goto MenuUtama;
            break;
        case 6:
            cout << "---------------- UBAH TENGAH -----------------" << endl;
            cout << "------- Masukkan data yang akan diubah -------" << endl;
            cout << "--- Data Lama ---" << endl;
            cout << "Nama Mahasiswa lama = ";
            cin >> OldName_151;
            cout << "NIM Mahasiswa lama = ";
            cin >> OldNIM_151;
            cout << "Posisi data lama pada list = ";
            cin >> Position_151;
            cout << "--- Data Baru ---" << endl;
            cout << "Nama mahasiswa baru = "; 
            cin >> Name_151;
            cout << "NIM mahasiswa baru = ";
            cin >> NIM_151;
            UbahTengah_151(Name_151, NIM_151, Position_151);
            cout << "Data mahasiswa " << OldName_151 << " (" << OldNIM_151 << ") pada posisi ke-" << Position_151 << " telah diganti dengan data mahasiswa baru " << Name_151 << " (" << NIM_151 << ")" << endl;
            cout << endl;
            goto MenuUtama;
            break;
        case 7:
            cout << "---------------- HAPUS DEPAN -----------------" << endl;
            cout << "Apakah anda yakin untuk menghapus data mahasiswa " << TampilDepan_151() << "? [y/n] = ";
            cin >> Yakin_151;
            if(Yakin_151 == 'y' || Yakin_151 == 'Y'){
                HapusDepan_151();
                cout << "Data telah dihapus" << endl;
            } else if(Yakin_151 == 'n' || Yakin_151 == 'N'){
                cout << "Aksi dibatalkan" << endl;
            }
            cout << endl;
            goto MenuUtama;
            break;
        case 8:
            cout << "--------------- HAPUS BELAKANG ---------------" << endl;
            cout << "Apakah anda yakin untuk menghapus data mahasiswa " << TampilBelakang_151() << "? [y/n] = ";
            cin >> Yakin_151;
            if(Yakin_151 == 'y' || Yakin_151 == 'Y'){
                HapusBelakang_151();
                cout << "Data telah dihapus" << endl;
            } else if(Yakin_151 == 'n' || Yakin_151 == 'N'){
                cout << "Aksi dibatalkan" << endl;
            }
            cout << endl;
            goto MenuUtama;
            break;
        case 9:
            cout << "---------------- HAPUS TENGAH ----------------" << endl;
            cout << "Masukkan posisi data yang ingin dihapus = ";
            cin >> Position_151;
            cout << "Apakah anda yakin untuk menghapus data mahasiswa " << TampilTengah_151(Position_151) << "? [y/n] = ";
            cin >> Yakin_151;
            if(Yakin_151 == 'y' || Yakin_151 == 'Y'){
                HapusTengah_151(Position_151);
                cout << "Data telah dihapus" << endl;
            } else if(Yakin_151 == 'n' || Yakin_151 == 'N'){
                cout << "Aksi dibatalkan" << endl;
            }
            cout << endl;
            goto MenuUtama;
            break;
        case 10:
            cout << "----------------- HAPUS LIST -----------------" << endl;
            cout << "Apakah anda yakin untuk menghapus semua data? [y/n] = ";
            cin >> Yakin_151;
            if(Yakin_151 == 'y' || Yakin_151 == 'Y'){
                HapusList_151();
                cout << "List telah terhapus" << endl; 
            } else if(Yakin_151 == 'n' || Yakin_151 == 'N'){
                cout << "Aksi dibatalkan" << endl;
            }
            cout << endl;
            goto MenuUtama;
            break;
        case 11:
            cout << "-------------- TAMPIL LIST ---------------" << endl;
            TampilList_151();
            cout << endl;
            goto MenuUtama;
            break;
        case 0:
            cout << "Anda keluar dari program" << endl;
            return 0;
            break;
        default:
            cout << "Pilihan anda tidak tersedia" << endl;
            cout << endl;
            goto MenuUtama;
            break;
    }
}
```
#### Output:

##### Output 1 (Tampilan Menu Utama)
![Dhimas_Output-Unguided1-1](https://github.com/Masdim37/2311102151_Muhammad-Dhimas-Hafizh-Fathurrahman/blob/main/Pertemuan4_Modul4-Linked-List-Circular/Laprak/Dhimas_Output-Unguided1-1.png)

##### Output 2 (Tampilan Menu Tambah Depan)
![Dhimas_Output-Unguided1-2](https://github.com/Masdim37/2311102151_Muhammad-Dhimas-Hafizh-Fathurrahman/blob/main/Pertemuan4_Modul4-Linked-List-Circular/Laprak/Dhimas_Output-Unguided1-2.png)

##### Output 3 (Tampilan Menu Tambah Belakang)
![Dhimas_Output-Unguided1-3](https://github.com/Masdim37/2311102151_Muhammad-Dhimas-Hafizh-Fathurrahman/blob/main/Pertemuan4_Modul4-Linked-List-Circular/Laprak/Dhimas_Output-Unguided1-3.png)

##### Output 4 (Tampilan Menu Tambah Tengah)
![Dhimas_Output-Unguided1-4](https://github.com/Masdim37/2311102151_Muhammad-Dhimas-Hafizh-Fathurrahman/blob/main/Pertemuan4_Modul4-Linked-List-Circular/Laprak/Dhimas_Output-Unguided1-4.png)

##### Output 5 (Tampilan Menu Ubah Depan)
![Dhimas_Output-Unguided1-5](https://github.com/Masdim37/2311102151_Muhammad-Dhimas-Hafizh-Fathurrahman/blob/main/Pertemuan4_Modul4-Linked-List-Circular/Laprak/Dhimas_Output-Unguided1-5.png)

##### Output 6 (Tampilan Menu Ubah Belakang)
![Dhimas_Output-Unguided1-6](https://github.com/Masdim37/2311102151_Muhammad-Dhimas-Hafizh-Fathurrahman/blob/main/Pertemuan4_Modul4-Linked-List-Circular/Laprak/Dhimas_Output-Unguided1-6.png)

##### Output 7 (Tampilan Menu Ubah Tengah)
![Dhimas_Output-Unguided1-7](https://github.com/Masdim37/2311102151_Muhammad-Dhimas-Hafizh-Fathurrahman/blob/main/Pertemuan4_Modul4-Linked-List-Circular/Laprak/Dhimas_Output-Unguided1-7.png)

##### Output 8 (Tampilan Menu Hapus Depan)
![Dhimas_Output-Unguided1-8](https://github.com/Masdim37/2311102151_Muhammad-Dhimas-Hafizh-Fathurrahman/blob/main/Pertemuan4_Modul4-Linked-List-Circular/Laprak/Dhimas_Output-Unguided1-8.png)

##### Output 9 (Tampilan Menu Hapus Belakang)
![Dhimas_Output-Unguided1-9](https://github.com/Masdim37/2311102151_Muhammad-Dhimas-Hafizh-Fathurrahman/blob/main/Pertemuan4_Modul4-Linked-List-Circular/Laprak/Dhimas_Output-Unguided1-9.png)

##### Output 10 (Tampilan Menu Hapus Tengah)
![Dhimas_Output-Unguided1-10](https://github.com/Masdim37/2311102151_Muhammad-Dhimas-Hafizh-Fathurrahman/blob/main/Pertemuan4_Modul4-Linked-List-Circular/Laprak/Dhimas_Output-Unguided1-10.png)

##### Output 11 (Tampilan Menu Hapus List)
![Dhimas_Output-Unguided1-11](https://github.com/Masdim37/2311102151_Muhammad-Dhimas-Hafizh-Fathurrahman/blob/main/Pertemuan4_Modul4-Linked-List-Circular/Laprak/Dhimas_Output-Unguided1-11.png)

##### Output 12 (Tampilan Menu Tampil List)
![Dhimas_Output-Unguided1-12](https://github.com/Masdim37/2311102151_Muhammad-Dhimas-Hafizh-Fathurrahman/blob/main/Pertemuan4_Modul4-Linked-List-Circular/Laprak/Dhimas_Output-Unguided1-12.png)

##### Output 13 (Tampilan Menu Keluar)
![Dhimas_Output-Unguided1-13](https://github.com/Masdim37/2311102151_Muhammad-Dhimas-Hafizh-Fathurrahman/blob/main/Pertemuan4_Modul4-Linked-List-Circular/Laprak/Dhimas_Output-Unguided1-13.png)

### Deskripsi Program
Deskripsi program unguided 1

### 2. Setelah membuat menu tersebut, masukkan data sesuai urutan berikut, lalu tampilkan data yang telah dimasukkan! (Gunakan insert depan, belakang atau tengah)

![Dhimas_Soal-Unguided2](https://github.com/Masdim37/2311102151_Muhammad-Dhimas-Hafizh-Fathurrahman/blob/main/Pertemuan4_Modul4-Linked-List-Circular/Laprak/Dhimas_Soal-Unguided2.png)

```C++
#include<iostream>
#include<iomanip>

using namespace std;

//deklarasi struct node
struct node{
    string Nama_151;
    string NIM_151;
    node *next;
};
    node *head;
    node *tail;

//Inisialisasi node head & tail
void Inisialisasi_151(){
    head = NULL;
    tail = NULL;
}

//fungsi pengecekan
bool isEmpty_151(){
    if(head == NULL){
        return true;
    } else {
        return false;
    }
}

//prosedur hitung node
int HitungNode_151(){
    node *hitung = head;
    int jumlah_151 = 0;
    while (hitung != NULL){
        hitung = hitung->next;
        jumlah_151++;
    }
    return jumlah_151;
}

//prosedur tambah depan
void TambahDepan_151(string Name_151, string NIM_151){
    node *baru = new node;
    baru->Nama_151 = Name_151;
    baru->NIM_151 = NIM_151;
    baru->next = NULL;
    if(isEmpty_151() == true){
        head = tail = baru;
        tail->next = NULL;
    } else {
        baru->next = head;
        head = baru;
    }
}

//prosedur tambah belakang
void TambahBelakang_151(string Name_151, string NIM_151){
    node *baru = new node;
    baru->Nama_151 = Name_151;
    baru->NIM_151 = NIM_151;
    baru->next = NULL;
    if(isEmpty_151() == true){
        head = tail = baru;
        tail->next = NULL;
    } else {
        tail->next = baru;
        tail = baru;
    }
}

//prosedur tambah tengah
void TambahTengah_151(string Name_151, string NIM_151, int Position_151){
    if(Position_151 < 1 || Position_151 > HitungNode_151()){
        cout << "Node yang ingin ditambah diluar jangkauan!" << endl;
    } else if(Position_151 == 1){
        cout << "Node yang ingin ditambah bukan ditengah!"<< endl;
    } else {
        node *bantu = head;
        node *baru = new node;
        baru->Nama_151 = Name_151;
        baru->NIM_151 = NIM_151;
        int hitung_151 = 1;
        while(hitung_151 < Position_151 - 1){
            bantu = bantu->next;
            hitung_151++;
        }
        baru->next = bantu->next;
        bantu->next = baru;
    }
}

//prosedur hapus depan
void HapusDepan_151(){
    node *hapus;
    if(isEmpty_151() == true){
        cout << "List masih kosong!" << endl;
    } else {
        if(head->next != NULL){
            hapus = head;
            head = head->next;
            delete hapus;
        } else {
            head = tail = NULL;
        }
    }
}

//fungsi tampil data depan
string TampilDepan_151(){
    string NamaYangDihapus_151 = "";
    if(isEmpty_151() == false){
        NamaYangDihapus_151 = head->Nama_151;
    } else {
        cout << "List masih kosong" << endl;
    }
    return NamaYangDihapus_151;
}

//prosedur hapus belakang
void HapusBelakang_151(){
    node *hapus, *bantu;
    if(isEmpty_151() == true){
        cout << "List masih kosong!" << endl;
    } else {
        if(head != tail){
            hapus = tail;
            bantu = head;
            while(bantu->next != tail){
                bantu = bantu->next;
            }
            tail = bantu;
            tail->next = NULL;
            delete hapus;
        } else {
            head = tail = NULL;
        }
    }
}

//fungsi tampil data belakang
string TampilBelakang_151(){
    string NamaYangDihapus_151 = "";
    if(isEmpty_151() == false){
        NamaYangDihapus_151 = tail->Nama_151;
    } else {
        cout << "List masih kosong" << endl;
    }
    return NamaYangDihapus_151;
}


//prosedur hapus tengah
void HapusTengah_151(int posisi_151){
    if(posisi_151 < 1 || posisi_151 > HitungNode_151()){ 
        cout << "Posisi node yang akan dihapus offside" << endl;
    } else if(posisi_151 == 1){
        cout << "Node yang ingin dihapus bukan node tengah" << endl;
    } else {
        node *hapus, *bantu, *bantu2;
        bantu = head;
        int nomor_151 = 1;
        while(nomor_151 <= posisi_151){
            if(nomor_151 == posisi_151 - 1){
                bantu2 = bantu;
            } else if(nomor_151 == posisi_151){
                hapus = bantu;
            }
            bantu = bantu->next;
            nomor_151++; 
        }
        bantu2->next = bantu;
        delete hapus;
    }
}

//fungsi tampil data tengah
string TampilTengah_151(int Position_151){
    string NamaYangDihapus_151 = "";
    node *tampil = head;
    node *bantu;
    if(isEmpty_151() == false){
        int nomor_151 = 1;
        while (nomor_151 <= Position_151 - 1){
            if(nomor_151 == Position_151 - 1){
                bantu = tampil;
            }
            tampil = tampil->next;
            nomor_151++;
        }
        bantu->next = tampil;
        NamaYangDihapus_151 = tampil->Nama_151;       
    } else {
        cout << "List masih kosong" << endl;
    }
    return NamaYangDihapus_151;
}

//prosedur Ubah depan
void UbahDepan_151(string NewName_151, string NewNIM_151){
    if(isEmpty_151() == true){
        cout << "List masih kosong!" << endl;
    } else {
        head->Nama_151 = NewName_151;
        head->NIM_151 = NewNIM_151;
    }
}

//prosedur ubah belakang
void UbahBelakang_151(string NewName_151, string NewNIM_151){
    if(isEmpty_151() == true){
        cout << "List masih kosong!" << endl;
    } else {
        tail->Nama_151 = NewName_151;
        tail->NIM_151 = NewNIM_151;
    }
}

//prosedur ubah tengah
void UbahTengah_151(string NewName_151, string NewNIM_151, int Position_151){
    if(isEmpty_151() == true){
        cout << "List masih kosong!" << endl;
    } else {
        if(Position_151 < 1 || Position_151 > HitungNode_151()){
            cout << "Node yang ingin diubah diluar jangkauan!" << endl;
        } else if(Position_151 == 1){
            cout << "Node yang ingin diubah bukan ditengah!" << endl;
        } else {
            node *bantu;
            bantu = head;
            int nomor_151 = 1;
            while(nomor_151 < Position_151){
                bantu = bantu->next;
                nomor_151++;
            }
           bantu->Nama_151 = NewName_151;
           bantu->NIM_151 = NewNIM_151;
        }
    }
}

//prosedur hapus list
void HapusList_151(){
    node *hapus;
    node *bantu = head;
    if(isEmpty_151() == true){
        cout << "List masih kosong!" << endl;
    } else {
        while(bantu != NULL){
            hapus = bantu;
            bantu = bantu->next;
            delete hapus;   
        }
        head = tail = NULL;
    }
}

//prosedur tampil list
void TampilList_151(){
    node *bantu = head;
    if(isEmpty_151() == true){
        cout << "List masih kosong!" << endl;
    } else {
        cout << "------------------------------------------" << endl;
        cout << "|         NAMA         |       NIM       |" << endl;
        cout << "------------------------------------------" << endl;
        while(bantu != NULL){
            cout << "|" << setw(22) << left << bantu->Nama_151 << "|" << setw(17) << left << bantu->NIM_151 << "|" << endl;
            bantu = bantu->next;
        }
        cout << "------------------------------------------" << endl;
    }
}

int main(){
    int Position_151, Choose_151;
    string Name_151, OldName_151, NIM_151, OldNIM_151;
    char Yakin_151;
    Inisialisasi_151();
    MenuUtama:
    cout << "------- PROGRAM SINGLE LINKED LIST -------" << endl;
    cout << "-------------- NON-CIRCULAR --------------" << endl; 
    cout << "| 1. TAMBAH DEPAN                        |" << endl;
    cout << "| Menambahkan data pada awal list        |" << endl;
    cout << "| 2. TAMBAH BELAKANG                     |" << endl;
    cout << "| Menambahkan data pada akhir list       |" << endl;
    cout << "| 3. TAMBAH TENGAH                       |" << endl;
    cout << "| Menambahkan data pada urutan tertentu  |" << endl;
    cout << "| 4. UBAH DEPAN                          |" << endl;
    cout << "| Mengubah data pada urutan pertama      |" << endl;
    cout << "| 5. UBAH BELAKANG                       |" << endl;
    cout << "| Mengubah data pada urutan terakhir     |" << endl;
    cout << "| 6. UBAH TENGAH                         |" << endl;
    cout << "| Mengubah data pada urutan tertentu     |" << endl;
    cout << "| 7. HAPUS DEPAN                         |" << endl;
    cout << "| Menghapus data urutan pertama          |" << endl;
    cout << "| 8. HAPUS BELAKANG                      |" << endl;
    cout << "| Menghapus data urutan terakhir         |" << endl;
    cout << "| 9. HAPUS TENGAH                        |" << endl;
    cout << "| Menghapus data urutan tertentu         |" << endl;
    cout << "| 10. HAPUS LIST                         |" << endl;
    cout << "| Menghapus seluruh data                 |" << endl;
    cout << "| 11. TAMPILKAN                          |" << endl;
    cout << "| Menampilkan list data yang tersimpan   |" << endl;
    cout << "| 0. KELUAR                              |" << endl;
    cout << "| Keluar dari program                    |" << endl;
    cout << "------------------------------------------" << endl;
    cout << "Masukkan pilihan anda = ";
    cin >> Choose_151;
    cout << endl;
    switch(Choose_151){
        case 1:
            cout << "-------------- TAMBAH DEPAN --------------" << endl;
            cout << "-- Masukkan data yang ingin ditambahkan --" << endl;
            cout << "Nama Mahasiswa = ";
            cin >> Name_151;
            cout << "NIM Mahasiswa = ";
            cin >> NIM_151;
            TambahDepan_151(Name_151, NIM_151);
            cout << "Data berhasil ditambahkan" << endl;
            cout << endl;
            goto MenuUtama;
            break;
        case 2:
            cout << "------------ TAMBAH BELAKANG -------------" << endl;
            cout << "-- Masukkan data yang ingin ditambahkan --" << endl;
            cout << "Nama Mahasiswa = ";
            cin >> Name_151;
            cout << "NIM Mahasiswa = ";
            cin >> NIM_151;
            TambahBelakang_151(Name_151, NIM_151);
            cout << "Data berhasil ditambahkan" << endl;
            cout << endl;
            goto MenuUtama;
            break;
        case 3:
            cout << "------------- TAMBAH TENGAH --------------" << endl;
            cout << "-- Masukkan data yang ingin ditambahkan --" << endl;
            cout << "Nama Mahasiswa = ";
            cin >> Name_151;
            cout << "NIM Mahasiswa = ";
            cin >> NIM_151;
            cout << "Posisi data = ";
            cin >> Position_151;
            TambahTengah_151(Name_151, NIM_151, Position_151);
            cout << "Data berhasil ditambahkan" << endl;
            cout << endl;
            goto MenuUtama;
            break;
        case 4:
            cout << "----------------- UBAH DEPAN -----------------" << endl;
            cout << "------- Masukkan data yang akan diubah -------" << endl;
            cout << "--- Data Lama ---" << endl;
            cout << "Nama Mahasiswa lama = ";
            cin >> OldName_151;
            cout << "NIM Mahasiswa lama = ";
            cin >> OldNIM_151;
            cout << "--- Data Baru ---" << endl;
            cout << "Nama mahasiswa baru = "; 
            cin >> Name_151;
            cout << "NIM mahasiswa baru = ";
            cin >> NIM_151;
            UbahDepan_151(Name_151, NIM_151);
            cout << "Data mahasiswa " << OldName_151 << " (" << OldNIM_151 << ") telah diganti dengan data mahasiswa baru " << Name_151 << " (" << NIM_151 << ")" << endl;
            cout << endl;
            goto MenuUtama;
            break;
        case 5:
            cout << "--------------- UBAH BELAKANG ----------------" << endl;
            cout << "------- Masukkan data yang akan diubah -------" << endl;
            cout << "--- Data Lama ---" << endl;
            cout << "Nama Mahasiswa lama = ";
            cin >> OldName_151;
            cout << "NIM Mahasiswa lama = ";
            cin >> OldNIM_151;
            cout << "--- Data Baru ---" << endl;
            cout << "Nama mahasiswa baru = "; 
            cin >> Name_151;
            cout << "NIM mahasiswa baru = ";
            cin >> NIM_151;
            UbahBelakang_151(Name_151, NIM_151);
            cout << "Data mahasiswa " << OldName_151 << " (" << OldNIM_151 << ") telah diganti dengan data mahasiswa baru " << Name_151 << " (" << NIM_151 << ")" << endl;
            cout << endl;
            goto MenuUtama;
            break;
        case 6:
            cout << "---------------- UBAH TENGAH -----------------" << endl;
            cout << "------- Masukkan data yang akan diubah -------" << endl;
            cout << "--- Data Lama ---" << endl;
            cout << "Nama Mahasiswa lama = ";
            cin >> OldName_151;
            cout << "NIM Mahasiswa lama = ";
            cin >> OldNIM_151;
            cout << "Posisi data lama pada list = ";
            cin >> Position_151;
            cout << "--- Data Baru ---" << endl;
            cout << "Nama mahasiswa baru = "; 
            cin >> Name_151;
            cout << "NIM mahasiswa baru = ";
            cin >> NIM_151;
            UbahTengah_151(Name_151, NIM_151, Position_151);
            cout << "Data mahasiswa " << OldName_151 << " (" << OldNIM_151 << ") pada posisi ke-" << Position_151 << " telah diganti dengan data mahasiswa baru " << Name_151 << " (" << NIM_151 << ")" << endl;
            cout << endl;
            goto MenuUtama;
            break;
        case 7:
            cout << "---------------- HAPUS DEPAN -----------------" << endl;
            cout << "Apakah anda yakin untuk menghapus data mahasiswa " << TampilDepan_151() << "? [y/n] = ";
            cin >> Yakin_151;
            if(Yakin_151 == 'y' || Yakin_151 == 'Y'){
                HapusDepan_151();
                cout << "Data telah dihapus" << endl;
            } else if(Yakin_151 == 'n' || Yakin_151 == 'N'){
                cout << "Aksi dibatalkan" << endl;
            }
            cout << endl;
            goto MenuUtama;
            break;
        case 8:
            cout << "--------------- HAPUS BELAKANG ---------------" << endl;
            cout << "Apakah anda yakin untuk menghapus data mahasiswa " << TampilBelakang_151() << "? [y/n] = ";
            cin >> Yakin_151;
            if(Yakin_151 == 'y' || Yakin_151 == 'Y'){
                HapusBelakang_151();
                cout << "Data telah dihapus" << endl;
            } else if(Yakin_151 == 'n' || Yakin_151 == 'N'){
                cout << "Aksi dibatalkan" << endl;
            }
            cout << endl;
            goto MenuUtama;
            break;
        case 9:
            cout << "---------------- HAPUS TENGAH ----------------" << endl;
            cout << "Masukkan posisi data yang ingin dihapus = ";
            cin >> Position_151;
            cout << "Apakah anda yakin untuk menghapus data mahasiswa " << TampilTengah_151(Position_151) << "? [y/n] = ";
            cin >> Yakin_151;
            if(Yakin_151 == 'y' || Yakin_151 == 'Y'){
                HapusTengah_151(Position_151);
                cout << "Data telah dihapus" << endl;
            } else if(Yakin_151 == 'n' || Yakin_151 == 'N'){
                cout << "Aksi dibatalkan" << endl;
            }
            cout << endl;
            goto MenuUtama;
            break;
        case 10:
            cout << "----------------- HAPUS LIST -----------------" << endl;
            cout << "Apakah anda yakin untuk menghapus semua data? [y/n] = ";
            cin >> Yakin_151;
            if(Yakin_151 == 'y' || Yakin_151 == 'Y'){
                HapusList_151();
                cout << "List telah terhapus" << endl; 
            } else if(Yakin_151 == 'n' || Yakin_151 == 'N'){
                cout << "Aksi dibatalkan" << endl;
            }
            cout << endl;
            goto MenuUtama;
            break;
        case 11:
            cout << "-------------- TAMPIL LIST ---------------" << endl;
            TampilList_151();
            cout << endl;
            goto MenuUtama;
            break;
        case 0:
            cout << "Anda keluar dari program" << endl;
            return 0;
            break;
        default:
            cout << "Pilihan anda tidak tersedia" << endl;
            cout << endl;
            goto MenuUtama;
            break;
    }
}
```
#### Output:

##### Output 1 (Tambah Data Jawad)
![Dhimas_Output-Unguided2-1](https://github.com/Masdim37/2311102151_Muhammad-Dhimas-Hafizh-Fathurrahman/blob/main/Pertemuan4_Modul4-Linked-List-Circular/Laprak/Dhimas_Output-Unguided2-1.png)

##### Output 2 (Tambah Data Nama Sendiri (Dhimas))
![Dhimas_Output-Unguided2-2](https://github.com/Masdim37/2311102151_Muhammad-Dhimas-Hafizh-Fathurrahman/blob/main/Pertemuan4_Modul4-Linked-List-Circular/Laprak/Dhimas_Output-Unguided2-2.png)

##### Output 3 (Tambah Data Farrel)
![Dhimas_Output-Unguided2-3](https://github.com/Masdim37/2311102151_Muhammad-Dhimas-Hafizh-Fathurrahman/blob/main/Pertemuan4_Modul4-Linked-List-Circular/Laprak/Dhimas_Output-Unguided2-3.png)

##### Output 4 (Tambah Data Denis)
![Dhimas_Output-Unguided2-4](https://github.com/Masdim37/2311102151_Muhammad-Dhimas-Hafizh-Fathurrahman/blob/main/Pertemuan4_Modul4-Linked-List-Circular/Laprak/Dhimas_Output-Unguided2-4.png)

##### Output 5 (Tambah Data Anis)
![Dhimas_Output-Unguided2-5](https://github.com/Masdim37/2311102151_Muhammad-Dhimas-Hafizh-Fathurrahman/blob/main/Pertemuan4_Modul4-Linked-List-Circular/Laprak/Dhimas_Output-Unguided2-5.png)

##### Output 6 (Tambah Data Bowo)
![Dhimas_Output-Unguided2-6](https://github.com/Masdim37/2311102151_Muhammad-Dhimas-Hafizh-Fathurrahman/blob/main/Pertemuan4_Modul4-Linked-List-Circular/Laprak/Dhimas_Output-Unguided2-6.png)

##### Output 7 (Tambah Data Gahar)
![Dhimas_Output-Unguided2-7](https://github.com/Masdim37/2311102151_Muhammad-Dhimas-Hafizh-Fathurrahman/blob/main/Pertemuan4_Modul4-Linked-List-Circular/Laprak/Dhimas_Output-Unguided2-7.png)

##### Output 8 (Tambah Data Udin)
![Dhimas_Output-Unguided2-8](https://github.com/Masdim37/2311102151_Muhammad-Dhimas-Hafizh-Fathurrahman/blob/main/Pertemuan4_Modul4-Linked-List-Circular/Laprak/Dhimas_Output-Unguided2-8.png)

##### Output 9 (Tambah Data Ucok)
![Dhimas_Output-Unguided2-9](https://github.com/Masdim37/2311102151_Muhammad-Dhimas-Hafizh-Fathurrahman/blob/main/Pertemuan4_Modul4-Linked-List-Circular/Laprak/Dhimas_Output-Unguided2-9.png)

##### Output 10 (Tambah Data Budi)
![Dhimas_Output-Unguided2-10](https://github.com/Masdim37/2311102151_Muhammad-Dhimas-Hafizh-Fathurrahman/blob/main/Pertemuan4_Modul4-Linked-List-Circular/Laprak/Dhimas_Output-Unguided2-10.png)

##### Output 11 (Tampilkan Semua Data)
![Dhimas_Output-Unguided2-11](https://github.com/Masdim37/2311102151_Muhammad-Dhimas-Hafizh-Fathurrahman/blob/main/Pertemuan4_Modul4-Linked-List-Circular/Laprak/Dhimas_Output-Unguided2-11.png)

#### Deskripsi Program
Deskripsi program unguided 2

### 3. Lakukan perintah berikut!

![Dhimas_Soal-Unguided3](https://github.com/Masdim37/2311102151_Muhammad-Dhimas-Hafizh-Fathurrahman/blob/main/Pertemuan4_Modul4-Linked-List-Circular/Laprak/Dhimas_Soal-Unguided3.png)

```C++
#include<iostream>
#include<iomanip>

using namespace std;

//deklarasi struct node
struct node{
    string Nama_151;
    string NIM_151;
    node *next;
};
    node *head;
    node *tail;

//Inisialisasi node head & tail
void Inisialisasi_151(){
    head = NULL;
    tail = NULL;
}

//fungsi pengecekan
bool isEmpty_151(){
    if(head == NULL){
        return true;
    } else {
        return false;
    }
}

//prosedur hitung node
int HitungNode_151(){
    node *hitung = head;
    int jumlah_151 = 0;
    while (hitung != NULL){
        hitung = hitung->next;
        jumlah_151++;
    }
    return jumlah_151;
}

//prosedur tambah depan
void TambahDepan_151(string Name_151, string NIM_151){
    node *baru = new node;
    baru->Nama_151 = Name_151;
    baru->NIM_151 = NIM_151;
    baru->next = NULL;
    if(isEmpty_151() == true){
        head = tail = baru;
        tail->next = NULL;
    } else {
        baru->next = head;
        head = baru;
    }
}

//prosedur tambah belakang
void TambahBelakang_151(string Name_151, string NIM_151){
    node *baru = new node;
    baru->Nama_151 = Name_151;
    baru->NIM_151 = NIM_151;
    baru->next = NULL;
    if(isEmpty_151() == true){
        head = tail = baru;
        tail->next = NULL;
    } else {
        tail->next = baru;
        tail = baru;
    }
}

//prosedur tambah tengah
void TambahTengah_151(string Name_151, string NIM_151, int Position_151){
    if(Position_151 < 1 || Position_151 > HitungNode_151()){
        cout << "Node yang ingin ditambah diluar jangkauan!" << endl;
    } else if(Position_151 == 1){
        cout << "Node yang ingin ditambah bukan ditengah!"<< endl;
    } else {
        node *bantu = head;
        node *baru = new node;
        baru->Nama_151 = Name_151;
        baru->NIM_151 = NIM_151;
        int hitung_151 = 1;
        while(hitung_151 < Position_151 - 1){
            bantu = bantu->next;
            hitung_151++;
        }
        baru->next = bantu->next;
        bantu->next = baru;
    }
}

//prosedur hapus depan
void HapusDepan_151(){
    node *hapus;
    if(isEmpty_151() == true){
        cout << "List masih kosong!" << endl;
    } else {
        if(head->next != NULL){
            hapus = head;
            head = head->next;
            delete hapus;
        } else {
            head = tail = NULL;
        }
    }
}

//fungsi tampil data depan
string TampilDepan_151(){
    string NamaYangDihapus_151 = "";
    if(isEmpty_151() == false){
        NamaYangDihapus_151 = head->Nama_151;
    } else {
        cout << "List masih kosong" << endl;
    }
    return NamaYangDihapus_151;
}

//prosedur hapus belakang
void HapusBelakang_151(){
    node *hapus, *bantu;
    if(isEmpty_151() == true){
        cout << "List masih kosong!" << endl;
    } else {
        if(head != tail){
            hapus = tail;
            bantu = head;
            while(bantu->next != tail){
                bantu = bantu->next;
            }
            tail = bantu;
            tail->next = NULL;
            delete hapus;
        } else {
            head = tail = NULL;
        }
    }
}

//fungsi tampil data belakang
string TampilBelakang_151(){
    string NamaYangDihapus_151 = "";
    if(isEmpty_151() == false){
        NamaYangDihapus_151 = tail->Nama_151;
    } else {
        cout << "List masih kosong" << endl;
    }
    return NamaYangDihapus_151;
}


//prosedur hapus tengah
void HapusTengah_151(int posisi_151){
    if(posisi_151 < 1 || posisi_151 > HitungNode_151()){ 
        cout << "Posisi node yang akan dihapus offside" << endl;
    } else if(posisi_151 == 1){
        cout << "Node yang ingin dihapus bukan node tengah" << endl;
    } else {
        node *hapus, *bantu, *bantu2;
        bantu = head;
        int nomor_151 = 1;
        while(nomor_151 <= posisi_151){
            if(nomor_151 == posisi_151 - 1){
                bantu2 = bantu;
            } else if(nomor_151 == posisi_151){
                hapus = bantu;
            }
            bantu = bantu->next;
            nomor_151++; 
        }
        bantu2->next = bantu;
        delete hapus;
    }
}

//fungsi tampil data tengah
string TampilTengah_151(int Position_151){
    string NamaYangDihapus_151 = "";
    node *tampil = head;
    node *bantu;
    if(isEmpty_151() == false){
        int nomor_151 = 1;
        while (nomor_151 <= Position_151 - 1){
            if(nomor_151 == Position_151 - 1){
                bantu = tampil;
            }
            tampil = tampil->next;
            nomor_151++;
        }
        bantu->next = tampil;
        NamaYangDihapus_151 = tampil->Nama_151;       
    } else {
        cout << "List masih kosong" << endl;
    }
    return NamaYangDihapus_151;
}

//prosedur Ubah depan
void UbahDepan_151(string NewName_151, string NewNIM_151){
    if(isEmpty_151() == true){
        cout << "List masih kosong!" << endl;
    } else {
        head->Nama_151 = NewName_151;
        head->NIM_151 = NewNIM_151;
    }
}

//prosedur ubah belakang
void UbahBelakang_151(string NewName_151, string NewNIM_151){
    if(isEmpty_151() == true){
        cout << "List masih kosong!" << endl;
    } else {
        tail->Nama_151 = NewName_151;
        tail->NIM_151 = NewNIM_151;
    }
}

//prosedur ubah tengah
void UbahTengah_151(string NewName_151, string NewNIM_151, int Position_151){
    if(isEmpty_151() == true){
        cout << "List masih kosong!" << endl;
    } else {
        if(Position_151 < 1 || Position_151 > HitungNode_151()){
            cout << "Node yang ingin diubah diluar jangkauan!" << endl;
        } else if(Position_151 == 1){
            cout << "Node yang ingin diubah bukan ditengah!" << endl;
        } else {
            node *bantu;
            bantu = head;
            int nomor_151 = 1;
            while(nomor_151 < Position_151){
                bantu = bantu->next;
                nomor_151++;
            }
           bantu->Nama_151 = NewName_151;
           bantu->NIM_151 = NewNIM_151;
        }
    }
}

//prosedur hapus list
void HapusList_151(){
    node *hapus;
    node *bantu = head;
    if(isEmpty_151() == true){
        cout << "List masih kosong!" << endl;
    } else {
        while(bantu != NULL){
            hapus = bantu;
            bantu = bantu->next;
            delete hapus;   
        }
        head = tail = NULL;
    }
}

//prosedur tampil list
void TampilList_151(){
    node *bantu = head;
    if(isEmpty_151() == true){
        cout << "List masih kosong!" << endl;
    } else {
        cout << "------------------------------------------" << endl;
        cout << "|         NAMA         |       NIM       |" << endl;
        cout << "------------------------------------------" << endl;
        while(bantu != NULL){
            cout << "|" << setw(22) << left << bantu->Nama_151 << "|" << setw(17) << left << bantu->NIM_151 << "|" << endl;
            bantu = bantu->next;
        }
        cout << "------------------------------------------" << endl;
    }
}

int main(){
    int Position_151, Choose_151;
    string Name_151, OldName_151, NIM_151, OldNIM_151;
    char Yakin_151;
    Inisialisasi_151();
    MenuUtama:
    cout << "------- PROGRAM SINGLE LINKED LIST -------" << endl;
    cout << "-------------- NON-CIRCULAR --------------" << endl; 
    cout << "| 1. TAMBAH DEPAN                        |" << endl;
    cout << "| Menambahkan data pada awal list        |" << endl;
    cout << "| 2. TAMBAH BELAKANG                     |" << endl;
    cout << "| Menambahkan data pada akhir list       |" << endl;
    cout << "| 3. TAMBAH TENGAH                       |" << endl;
    cout << "| Menambahkan data pada urutan tertentu  |" << endl;
    cout << "| 4. UBAH DEPAN                          |" << endl;
    cout << "| Mengubah data pada urutan pertama      |" << endl;
    cout << "| 5. UBAH BELAKANG                       |" << endl;
    cout << "| Mengubah data pada urutan terakhir     |" << endl;
    cout << "| 6. UBAH TENGAH                         |" << endl;
    cout << "| Mengubah data pada urutan tertentu     |" << endl;
    cout << "| 7. HAPUS DEPAN                         |" << endl;
    cout << "| Menghapus data urutan pertama          |" << endl;
    cout << "| 8. HAPUS BELAKANG                      |" << endl;
    cout << "| Menghapus data urutan terakhir         |" << endl;
    cout << "| 9. HAPUS TENGAH                        |" << endl;
    cout << "| Menghapus data urutan tertentu         |" << endl;
    cout << "| 10. HAPUS LIST                         |" << endl;
    cout << "| Menghapus seluruh data                 |" << endl;
    cout << "| 11. TAMPILKAN                          |" << endl;
    cout << "| Menampilkan list data yang tersimpan   |" << endl;
    cout << "| 0. KELUAR                              |" << endl;
    cout << "| Keluar dari program                    |" << endl;
    cout << "------------------------------------------" << endl;
    cout << "Masukkan pilihan anda = ";
    cin >> Choose_151;
    cout << endl;
    switch(Choose_151){
        case 1:
            cout << "-------------- TAMBAH DEPAN --------------" << endl;
            cout << "-- Masukkan data yang ingin ditambahkan --" << endl;
            cout << "Nama Mahasiswa = ";
            cin >> Name_151;
            cout << "NIM Mahasiswa = ";
            cin >> NIM_151;
            TambahDepan_151(Name_151, NIM_151);
            cout << "Data berhasil ditambahkan" << endl;
            cout << endl;
            goto MenuUtama;
            break;
        case 2:
            cout << "------------ TAMBAH BELAKANG -------------" << endl;
            cout << "-- Masukkan data yang ingin ditambahkan --" << endl;
            cout << "Nama Mahasiswa = ";
            cin >> Name_151;
            cout << "NIM Mahasiswa = ";
            cin >> NIM_151;
            TambahBelakang_151(Name_151, NIM_151);
            cout << "Data berhasil ditambahkan" << endl;
            cout << endl;
            goto MenuUtama;
            break;
        case 3:
            cout << "------------- TAMBAH TENGAH --------------" << endl;
            cout << "-- Masukkan data yang ingin ditambahkan --" << endl;
            cout << "Nama Mahasiswa = ";
            cin >> Name_151;
            cout << "NIM Mahasiswa = ";
            cin >> NIM_151;
            cout << "Posisi data = ";
            cin >> Position_151;
            TambahTengah_151(Name_151, NIM_151, Position_151);
            cout << "Data berhasil ditambahkan" << endl;
            cout << endl;
            goto MenuUtama;
            break;
        case 4:
            cout << "----------------- UBAH DEPAN -----------------" << endl;
            cout << "------- Masukkan data yang akan diubah -------" << endl;
            cout << "--- Data Lama ---" << endl;
            cout << "Nama Mahasiswa lama = ";
            cin >> OldName_151;
            cout << "NIM Mahasiswa lama = ";
            cin >> OldNIM_151;
            cout << "--- Data Baru ---" << endl;
            cout << "Nama mahasiswa baru = "; 
            cin >> Name_151;
            cout << "NIM mahasiswa baru = ";
            cin >> NIM_151;
            UbahDepan_151(Name_151, NIM_151);
            cout << "Data mahasiswa " << OldName_151 << " (" << OldNIM_151 << ") telah diganti dengan data mahasiswa baru " << Name_151 << " (" << NIM_151 << ")" << endl;
            cout << endl;
            goto MenuUtama;
            break;
        case 5:
            cout << "--------------- UBAH BELAKANG ----------------" << endl;
            cout << "------- Masukkan data yang akan diubah -------" << endl;
            cout << "--- Data Lama ---" << endl;
            cout << "Nama Mahasiswa lama = ";
            cin >> OldName_151;
            cout << "NIM Mahasiswa lama = ";
            cin >> OldNIM_151;
            cout << "--- Data Baru ---" << endl;
            cout << "Nama mahasiswa baru = "; 
            cin >> Name_151;
            cout << "NIM mahasiswa baru = ";
            cin >> NIM_151;
            UbahBelakang_151(Name_151, NIM_151);
            cout << "Data mahasiswa " << OldName_151 << " (" << OldNIM_151 << ") telah diganti dengan data mahasiswa baru " << Name_151 << " (" << NIM_151 << ")" << endl;
            cout << endl;
            goto MenuUtama;
            break;
        case 6:
            cout << "---------------- UBAH TENGAH -----------------" << endl;
            cout << "------- Masukkan data yang akan diubah -------" << endl;
            cout << "--- Data Lama ---" << endl;
            cout << "Nama Mahasiswa lama = ";
            cin >> OldName_151;
            cout << "NIM Mahasiswa lama = ";
            cin >> OldNIM_151;
            cout << "Posisi data lama pada list = ";
            cin >> Position_151;
            cout << "--- Data Baru ---" << endl;
            cout << "Nama mahasiswa baru = "; 
            cin >> Name_151;
            cout << "NIM mahasiswa baru = ";
            cin >> NIM_151;
            UbahTengah_151(Name_151, NIM_151, Position_151);
            cout << "Data mahasiswa " << OldName_151 << " (" << OldNIM_151 << ") pada posisi ke-" << Position_151 << " telah diganti dengan data mahasiswa baru " << Name_151 << " (" << NIM_151 << ")" << endl;
            cout << endl;
            goto MenuUtama;
            break;
        case 7:
            cout << "---------------- HAPUS DEPAN -----------------" << endl;
            cout << "Apakah anda yakin untuk menghapus data mahasiswa " << TampilDepan_151() << "? [y/n] = ";
            cin >> Yakin_151;
            if(Yakin_151 == 'y' || Yakin_151 == 'Y'){
                HapusDepan_151();
                cout << "Data telah dihapus" << endl;
            } else if(Yakin_151 == 'n' || Yakin_151 == 'N'){
                cout << "Aksi dibatalkan" << endl;
            }
            cout << endl;
            goto MenuUtama;
            break;
        case 8:
            cout << "--------------- HAPUS BELAKANG ---------------" << endl;
            cout << "Apakah anda yakin untuk menghapus data mahasiswa " << TampilBelakang_151() << "? [y/n] = ";
            cin >> Yakin_151;
            if(Yakin_151 == 'y' || Yakin_151 == 'Y'){
                HapusBelakang_151();
                cout << "Data telah dihapus" << endl;
            } else if(Yakin_151 == 'n' || Yakin_151 == 'N'){
                cout << "Aksi dibatalkan" << endl;
            }
            cout << endl;
            goto MenuUtama;
            break;
        case 9:
            cout << "---------------- HAPUS TENGAH ----------------" << endl;
            cout << "Masukkan posisi data yang ingin dihapus = ";
            cin >> Position_151;
            cout << "Apakah anda yakin untuk menghapus data mahasiswa " << TampilTengah_151(Position_151) << "? [y/n] = ";
            cin >> Yakin_151;
            if(Yakin_151 == 'y' || Yakin_151 == 'Y'){
                HapusTengah_151(Position_151);
                cout << "Data telah dihapus" << endl;
            } else if(Yakin_151 == 'n' || Yakin_151 == 'N'){
                cout << "Aksi dibatalkan" << endl;
            }
            cout << endl;
            goto MenuUtama;
            break;
        case 10:
            cout << "----------------- HAPUS LIST -----------------" << endl;
            cout << "Apakah anda yakin untuk menghapus semua data? [y/n] = ";
            cin >> Yakin_151;
            if(Yakin_151 == 'y' || Yakin_151 == 'Y'){
                HapusList_151();
                cout << "List telah terhapus" << endl; 
            } else if(Yakin_151 == 'n' || Yakin_151 == 'N'){
                cout << "Aksi dibatalkan" << endl;
            }
            cout << endl;
            goto MenuUtama;
            break;
        case 11:
            cout << "-------------- TAMPIL LIST ---------------" << endl;
            TampilList_151();
            cout << endl;
            goto MenuUtama;
            break;
        case 0:
            cout << "Anda keluar dari program" << endl;
            return 0;
            break;
        default:
            cout << "Pilihan anda tidak tersedia" << endl;
            cout << endl;
            goto MenuUtama;
            break;
    }
}
```
#### Output:

##### Output 1 (Tambah Data Wati Diantara Farrel dan Denis)
![Dhimas_Output-Unguided3-1](https://github.com/Masdim37/2311102151_Muhammad-Dhimas-Hafizh-Fathurrahman/blob/main/Pertemuan4_Modul4-Linked-List-Circular/Laprak/Dhimas_Output-Unguided3-1.png)

##### Output 2 (Hapus Data Denis)
![Dhimas_Output-Unguided3-2](https://github.com/Masdim37/2311102151_Muhammad-Dhimas-Hafizh-Fathurrahman/blob/main/Pertemuan4_Modul4-Linked-List-Circular/Laprak/Dhimas_Output-Unguided3-2.png)

##### Output 3 (Tambah Data Owi Diawal)
![Dhimas_Output-Unguided3-3](https://github.com/Masdim37/2311102151_Muhammad-Dhimas-Hafizh-Fathurrahman/blob/main/Pertemuan4_Modul4-Linked-List-Circular/Laprak/Dhimas_Output-Unguided3-3.png)

##### Output 4 (Tambah Data David Diakhir)
![Dhimas_Output-Unguided3-4](https://github.com/Masdim37/2311102151_Muhammad-Dhimas-Hafizh-Fathurrahman/blob/main/Pertemuan4_Modul4-Linked-List-Circular/Laprak/Dhimas_Output-Unguided3-4.png)

##### Output 5 (Ubah Data Udin Menjadi Idin)
![Dhimas_Output-Unguided3-5](https://github.com/Masdim37/2311102151_Muhammad-Dhimas-Hafizh-Fathurrahman/blob/main/Pertemuan4_Modul4-Linked-List-Circular/Laprak/Dhimas_Output-Unguided3-5.png)

##### Output 6 (Ubah Data Terakhir Mnejadi Lucy)
![Dhimas_Output-Unguided3-6](https://github.com/Masdim37/2311102151_Muhammad-Dhimas-Hafizh-Fathurrahman/blob/main/Pertemuan4_Modul4-Linked-List-Circular/Laprak/Dhimas_Output-Unguided3-6.png)

##### Output 7 (Hapus Data Awal)
![Dhimas_Output-Unguided3-7](https://github.com/Masdim37/2311102151_Muhammad-Dhimas-Hafizh-Fathurrahman/blob/main/Pertemuan4_Modul4-Linked-List-Circular/Laprak/Dhimas_Output-Unguided3-7.png)

##### Output 8 (Ubah Data Awal Menjadi Bagas)
![Dhimas_Output-Unguided3-8](https://github.com/Masdim37/2311102151_Muhammad-Dhimas-Hafizh-Fathurrahman/blob/main/Pertemuan4_Modul4-Linked-List-Circular/Laprak/Dhimas_Output-Unguided3-8.png)

##### Output 9 (Hapus Data Akhir)
![Dhimas_Output-Unguided3-9](https://github.com/Masdim37/2311102151_Muhammad-Dhimas-Hafizh-Fathurrahman/blob/main/Pertemuan4_Modul4-Linked-List-Circular/Laprak/Dhimas_Output-Unguided3-9.png)

##### Output 10 (Tampilkan Seluruh Data)
![Dhimas_Output-Unguided3-10](https://github.com/Masdim37/2311102151_Muhammad-Dhimas-Hafizh-Fathurrahman/blob/main/Pertemuan4_Modul4-Linked-List-Circular/Laprak/Dhimas_Output-Unguided3-10.png)

#### Deskripsi Program
Deskripsi program unguided 3

## Kesimpulan

## Referensi
[1] Triase. 2020. "Diktat Edisi Revisi : STRUKTUR DATA". Medan: UNIVERSTAS ISLAM NEGERI SUMATERA UTARA MEDAN. 
<br>[2] Santoso, Joseph Teguh. 2021. "Struktur Data dan Algoritma : Bagian 1". Semarang : Yayasan Prima Agus Teknik.
<br>[3] Musiafa, Zayid. 2022. "Struktur Data dan Implementasi Algoritma (SDIA): Pemrograman Python C C++ Java". (n.p.): ZAYID MUSIAFA.