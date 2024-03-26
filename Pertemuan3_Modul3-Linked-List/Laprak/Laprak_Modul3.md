# <h1 align="center">Laporan Praktikum Modul 3 - Linked List</h1>
<p align="center">Muhammad Dhimas Hafizh Fathurrahman - 2311102151</p>

## Dasar Teori
Linked list atau yang disebut juga senarai berantai adalah Salah satu bentuk struktur data yang berisi kumpulan data yang tersusun secara sekuensial, saling bersambungan, dinamis, dan terbatas[1]. Linked list terdiri dari sejumlah node atau simpul yang dihubungkan secara linier dengan bantuan pointer. Suatu simpul atau node harus mempunyai satu atau lebih elemen struktur atau class yang berisi data. Pada suatu linked list, terdiri dari 2 elemen yaitu elemen pada awal list (head) dan elemen pada akhir list (tail). Terdapat 2 jenis linked list, diantaranya adalah :

### A. Single Linked list
Umumnya "linked list" berarti single linked list. Single linked list adalah daftar terhubung yang setiap simpul pembentuknya mempunyai satu rantai(link) ke simpul lainnya. Single linked list terdiri dari sejumlah node dimana setiap node memiliki pointer yang merujuk ke elemen berikut (*next). Pointer next pada node terakhir akan menunjuk ke NULL. Ini menandakan akhir dari list. 
Berikut meupakan ilustrasi dari sebuah single linked list.

![Dhimas_Ilustrasi-single-linked-list](https://github.com/Masdim37/2311102151_Muhammad-Dhimas-Hafizh-Fathurrahman/blob/main/Pertemuan3_Modul3-Linked-List/Laprak/Dhimas_Ilustrasi-single-linked-list.png)

### B. Double Linked List
Berbeda dengan single linked list, double linked list adalah linked list yang memiliki dua rantai(link); yaitu satu link atau pointer yang merujuk ke node berikutnya (*next) dan satu link atau pointer yang merujuk ke node sebelumnya (*prev)[2]. Keuntungan dari double linked list adalah bahwa dengan adanya 2 buah pointer, programmer dapat melakukan operasi penghapusan dan penambahan pada simpul mana saja secara efisien. Berikut merupakan ilustrasi dari double linked list.

![Dhimas_Ilustrasi-double-linked-list](https://github.com/Masdim37/2311102151_Muhammad-Dhimas-Hafizh-Fathurrahman/blob/main/Pertemuan3_Modul3-Linked-List/Laprak/Dhimas_Ilustrasi-double-linked-list.png)

Secara garis besar, linked list memiliki kelebihan dan kekurangan. 
Kelebihan dari linked list antara lain :
- Memiliki ukuran yang dinamis, sehingga ukurannya dapat disesuaikan dengan kebutuhan
- Penambahan dan penghapusan elemen di tengah linked list bisa dilakukan dengan mudah dan efisien, tanpa memerlukan penggeseran elemen-elemen lainnya.
- Dapat digunakan sebagai dasar untuk struktur data lainnya seperti stack, queue, dan hash table.

Kekurangan dan linked list antara lain :
- Penggunaan Memori Tambahan untuk Pointer (*next dan *prev)
- Data didalam list tidak terurut

## Guided 

### 1. Latihan Single Linked List

```C++
#include<iostream>

using namespace std;

//Program single linked list non-circular
//Deklarasi struct node
struct node{
    int data;
    node *next;
};
    node *head;
    node *tail;

//inisialisasi node
void init(){
    head = NULL;
    tail = NULL;
}

//pengecekan
bool isEmpty(){
    if (head == NULL){
        return true;
    } else {
        return false;
    }
}

//Tambah depan
void insertdepan(int nilai){
    //buat node baru
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

//tambah belakang
void insertbelakang(int nilai){
    //buat node baru
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

//hitung jumlah list
int hitunglist(){
    node *hitung;
    hitung = head;
    int jumlah = 0;
    while(hitung != NULL){
        jumlah++;
        hitung = hitung->next;
    }
    return jumlah;
}

//tambah tengah
void inserttengah(int data, int posisi){
    if(posisi < 1 || posisi > hitunglist()){
        cout << "posisi diluar jangkauan" << endl;
    } else if(posisi == 1){
        cout << "posisi bukan posisi tengah" << endl;
    } else {
        node *baru, *bantu;
        baru = new node();
        baru->data = data;
        //transvering
        bantu = head;
        int nomor = 1;
        while(nomor < posisi - 1){
            bantu = bantu->next;
            nomor++;
        }
        baru->next = bantu->next;
        bantu->next = baru;
    }
}

//hapus depan
void hapusdepan(){
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

//hapus belakang
void hapusbelakang(){
    node *hapus;
    node *bantu;
    if(isEmpty() == false){
        if(head != tail){
            hapus = tail;
            bantu = tail;
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

//hapus tengah
void hapustengah(int posisi){
    node *hapus, *bantu, *bantu2;
    if(posisi < 1 || posisi > hitunglist()){
        cout << "posisi diluar jangkauan" << endl;
    } else if(posisi == 1){
        cout << "posisi bukan posisi tengah" << endl;
    } else {
        int nomor = 1;
        bantu = head;
        while(nomor <= posisi){
            if(nomor == posisi - 1){
                bantu2 = bantu;
            }
            bantu = bantu->next;
            nomor++;
        }
        bantu2->next = bantu;
        delete hapus;
    }
}

//Ubah Depan
void ubahdepan(int data){
    if (isEmpty() == false){
        head->data = data;
    } else {
        cout << "List masih kosong!" << endl;
    }
}

//Ubah Tengah
void ubahtengah(int data, int posisi){
    node *bantu;
    if (isEmpty() == false){
        if( posisi < 1 || posisi > hitunglist() ){
            cout << "Posisi di luar jangkauan" << endl;
        } else if( posisi == 1){
            cout << "Posisi bukan posisi tengah" << endl;
        } else {
            bantu = head;
            int nomor = 1;
            while (nomor < posisi){
                bantu = bantu->next;nomor++;
            }
            bantu->data = data;
        }
    } else {
        cout << "List masih kosong!" << endl;
    }
}

//Ubah Belakang
void ubahbelakang(int data){
    if (isEmpty() == false){
        tail->data = data;
    } else {
        cout << "List masih kosong!" << endl;
    }
}

//Hapus List
void clearList(){
    node *bantu, *hapus;
    bantu = head;
    while (bantu != NULL){
        hapus = bantu;bantu = bantu->next;
        delete hapus;
    }
    head = tail = NULL;
    cout << "List berhasil terhapus!" << endl;
}

//Tampilkan List
void tampil(){
    node *bantu;
    bantu = head;
    if (isEmpty() == false){
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
    insertdepan(3);
    tampil();
    insertbelakang(5);
    tampil();
    insertdepan(2);
    tampil();
    insertdepan(1);
    tampil();
    hapusdepan();
    tampil();
    hapusbelakang();
    tampil();
    inserttengah(7,2);
    tampil();
    hapustengah(2);
    tampil();
    ubahdepan(1);
    tampil();
    ubahbelakang(8);
    tampil();
    ubahtengah(11, 2);
    tampil();
    
    return 0;
}
```
Deskripsi guided 1

### 2. Latihan Double Linked List

```C++
#include<iostream>

using namespace std;

class node{
    public:
    int data;
    node* prev;
    node* next;
};

class doublelinkedlist{
    public:
    node* head;
    node* tail;
    doublelinkedlist(){
        head == nullptr;
        tail = nullptr;
    }
    void push(int data){
        node* newnode = new node;
        newnode->data = data;
        newnode->prev = nullptr;
        newnode->next = head;
        if(head != nullptr){
            head->prev = newnode;
        } else {
            tail = newnode;
        }
        head = newnode;
    }
    void pop(){
        if(head == nullptr){
            return;
        }
        node* temp = head;
        head = head->next;
        if(head != nullptr){
            head->prev = nullptr;
        } else {
            tail = nullptr;
        }
        delete temp;
    }
    bool update(int olddata, int newdata){
        node* current = head;
        while(current != nullptr){
            if(current->data == olddata){
                current->data = newdata;
                return true;
            }
            current = current->next;
        }
        return false;
    }
    void deleteall(){
        node* current = head;
        while (current != nullptr) {
            node* temp = current;
            current = current->next;
            delete temp;
        }
        head = nullptr;
        tail = nullptr;
    }
    void display(){
        node* current = head;
        while(current != nullptr){
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }
    
};

int main(){
    doublelinkedlist list;
    while(true){
        cout << "1. add data" << endl;
        cout << "2. Delete data" << endl;
        cout << "3. Update data" << endl;
        cout << "4. Clear data" << endl;
        cout << "5. Display data" << endl;
        cout << "6. Exit" << endl;
        int choice;
        cout << "Enter your choice: ";
        cin >> choice;

        switch(choice){
            case 1 : {
                int data;
                cout << "enter data to add : ";
                cin >> data;
                list.push(data);
                break;
            }
            case 2 : {
                list.pop();
                break;
            }
            case 3 : {
                int olddata, newdata;
                cout << "enter old data : ";
                cin >> olddata;
                cout << "enter new data : ";
                cin >> newdata;
                bool update = list.update(olddata, newdata);
                if(!update){
                    cout << "data not found" << endl;
                }
                break;
            }
            case 4 : {
                list.deleteall();
                break;
            }
            case 5 : {
                list.display();
                break;
            }
            case 6 : {
                return 0;
            }
            default : {
                cout << "invalid choice" << endl;
                break;
            }
        }
    }

    return 0;
}
```
Deskripsi guided 2

## Unguided 

### 1. Soal mengenai Single Linked List
Buatlah program menu Single Linked List Non-Circular untuk menyimpan Nama dan usia mahasiswa, dengan menggunakan inputan dari user. Lakukan operasi berikut: </br>

![Dhimas_Soal-Unguided1-Modul3](https://github.com/Masdim37/2311102151_Muhammad-Dhimas-Hafizh-Fathurrahman/blob/main/Pertemuan3_Modul3-Linked-List/Laprak/Soal-Unguided1-Modul3.png)

```C++
#include<iostream>

using namespace std;

//Deklarasi Struct node
struct node{ //node berisi variable nama_151, umur_151, dan pointer next
    string nama_151;
    int umur_151;
    node *next;
};
    node *head; //deklrasi node sebagai head
    node *tail; //deklarasi node sebagai tail

//prosedur inisialisasi node
void inisialisasi_151(){
    //mengosongkan nilai head dan tail 
    head = NULL;
    tail = NULL;
}

//prosedur pengecekan head & tail
bool kosong_151(){
    if(head == NULL){
        return true; //jika head tidak ada isinya (NULL), maka true
    } else {
        return false; //jika head ada isinya, maka false
    }
}

//prosedur tambah depan
void TambahDepan_151(string name_151, int age_151){
    node *baru = new node; //tambah node baru
    baru->nama_151 = name_151; //isi node baru
    baru->umur_151 = age_151; //isi node baru
    baru->next = NULL; // next node nya NULL
    //ini artinya node baru tersebut blom digabung ke linked list
    if(kosong_151() == true){ //jika linked listnya masih kosong, maka node baru adalah head dan tailnya
        head = tail = baru;
        tail->next = NULL; //tail dari node baru = NULL
    } else {
        baru->next = head; //jika linked listnya tidak kosong, maka next node baru dihubungkan ke head linked list
        head = baru; //dan node baru dijadikan head
    }
}

//prosedur tambah belakang
void TambahBelakang_151(string name_151, int age_151){
    node *baru = new node; //tambah node baru
    baru->nama_151 = name_151; //isi node baru
    baru->umur_151 = age_151; //isi node baru
    baru->next = NULL; // next node nya NULL
    //ini artinya node baru tersebut blom digabung ke linked list
    if(kosong_151() == true){ //jika linked listnya masih kosong, maka node baru adalah head dan tailnya
        head = tail = baru;
        tail->next = NULL; //tail dari node baru = NULL
    } else {
        tail->next = baru; //jika linked listnya tidak kosong, maka next node baru dihubungkan ke head linked list
        tail = baru; //dan node baru dijadikan head
    }
}

//fungsi hitung node
int HitungNode_151(){
    node *hitung; //tambah node hitung
    hitung = head; //node hitung sebagai head
    int jumlah = 0;
    while(hitung != NULL){ //perulangan while
        jumlah++; //deklarasi variabel jumlah
        hitung = hitung->next; //jika next node hitung bukan NULL, maka variabel jumlah +1
    }
    return jumlah;
}

//prosedur tambah tengah
void TambahTengah_151(string name_151, int age_151, int posisi_151){
    if(posisi_151 < 1 || posisi_151 > HitungNode_151()){ //jika posisi node yang akan ditambahkan kurang dari 1 atau lebih dari jumlah node yang ada, maka tampilkan output
        cout << "Posisi node yang akan ditambahkan offside" << endl;
    } else if(posisi_151 == 1){ //jika posisi node yang akan ditambahkan adalah posisi pertama, maka tampilkan output
        cout << "Posisi node yang akan ditambahkan bukan di tengah" << endl;
    } else {
        //tambah node baru & node bantu
        node *baru, *bantu;
        baru = new node; //buat node baru
        baru->nama_151 = name_151; //isi node baru
        baru->umur_151 = age_151; //isi node baru
        baru->next = NULL; //next nodenya NULL
        //transvering
        bantu = head; //node bantu dijadikan head
        int nomor_151 = 1; //deklarasi variabel nomor_151
        //hitung posisi node baru akan ditambahkan sebagai node keberapa
        while(nomor_151 < posisi_151 - 1){ //ketika variabel nomor_151 kurang dari posisi node baru yang akan ditambahkan - 1, maka
            bantu = bantu->next; //node bantu berlanjut ke node selanjutnya sampai variabel nomor = posisi node baru yang akan ditambahkan
            nomor_151++; //variable nomor_151 +1
        }
        //maka akan diketahui posisi node baru yang akan ditambahkan berada dimana
        baru->next = bantu->next; // next node baru sama dengan next node bantu
        bantu->next = baru; //next node bantu sama dengan node baru 
    }
}

//prosedur hapus depan
void HapusDepan_151(){
    node *hapus; //tambah node hapus
    if(kosong_151() == false){ //jika head saat ini sudah ada nilainya, maka 
        if(head->next != NULL){ //jika next dari head saat ini tidak ada nilainya (NULL), maka
            hapus = head; //node hapus dijadikan head
            head = head->next; //yang dijadikan head adalah next dari head saat ini
            delete hapus; //delete node hapus
        } else { //jika next dari head saat ini ada nilainya, maka
            head = tail = NULL; //head dan tail = NULL
        }
    } else { //jika head saat ini tidak ada nilainya, maka tampilkan output
        cout << "List masih kosong!" << endl; 
    }
}

//prosedur hapus belakang
void HapusBelakang_151(){
    node *hapus; //tambah node hapus
    node *bantu; //tambah node bantu
    if (kosong_151() == false){ //jika head saat ini ada nilainya, maka
        if(head != tail){ //jika head saat ini bukan sama dengan tail saat ini, maka
            hapus = tail; //node hapus sebagai tail
            bantu = tail; //node bantu sebagai tail
            bantu = head; //node bantu sebagai head
            while(bantu->next != tail){ //ketika next dari node bantu bukan sama dengan tail, maka ulangi
                bantu = bantu->next; //node bantu berlanjut ke next dari bantu saat ini
            }
            tail = bantu; //tail adalah node bantu
            tail->next = NULL; //next dari tail adalah NULL
            delete hapus; //delete node hapus
        } else {
            head = tail = NULL;
        }
    } else {
        cout << "List masih kosong!" << endl;
    }
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

//prosedur ubah isi head
void UbahDepan_151(string name_151, int age_151){
    if(kosong_151() == false){
        head->nama_151 = name_151;
        head->umur_151 = age_151;
    } else {
        cout << "List masih kosong!" << endl;
    }
}

//prosedur ubah isi tail
void UbahBelakang_151(string name_151, int age_151){
    if(kosong_151() == false){
        tail->nama_151 = name_151;
        tail->umur_151 = age_151;
    } else {
        cout << "List masih kosong!" << endl;
    }
}

//prosedur ubah isi node tengah
void UbahTengah_151(string name_151, int age_151, int posisi_151){
    node *bantu;
    if(kosong_151() == false){
        if(posisi_151 < 1 || posisi_151 > HitungNode_151()){
            cout << "Node yang ingin diubah isinya diluar jangkauan" << endl;
        } else if(posisi_151 == 1){
            cout << "Node yang ingin diubah isinya bukan head" << endl;
        } else {
            bantu = head;
            int nomor_151 = 1;
            while(nomor_151 < posisi_151){
                nomor_151++;
                bantu = bantu->next;
            }
            bantu->nama_151 = name_151;
            bantu->umur_151 = age_151;
        }
    } else {
        cout << "List masih kosong!" << endl;
    }
}

//prosedur hapus list
void HapusList_151(){
    node *bantu, *hapus;
    bantu = head;
    while(bantu != NULL){
        hapus = bantu;
        bantu = bantu->next;
        delete hapus;
    }
    head = tail = NULL;
    cout << "List sudah terhapus!" << endl;
}

//prosedur menampilkan list
void TampilList_151(){
    node *bantu;
    bantu = head;
    if(kosong_151() == false){
        for(int i=0; i<=HitungNode_151() && bantu != NULL; i++){
            cout << bantu->nama_151 << '\t' << bantu->umur_151 << endl;
            bantu = bantu->next;
        }
        cout << endl;
    } else {
        cout << "List masih kosong!" << endl;
    }
}

int main(){
    inisialisasi_151();
    //jawaban poin a
    cout << "--- Menambahkan List ---" << endl;
    TambahDepan_151("Karin", 18);
    TambahDepan_151("Hoshino", 18);
    TambahDepan_151("Akechi", 20);
    TambahDepan_151("Yusuke", 19);
    TambahDepan_151("Michael", 18);
    TambahDepan_151("Jane", 20);
    TambahDepan_151("John", 19);
    TambahDepan_151("Dhimas", 19);
    TampilList_151();

    //Jawaban poin b
    cout << "--- Menghapus data 'Akechi' ---" << endl; 
    HapusTengah_151(6);
    TampilList_151();

    //Jawaban poin c
    cout << "--- Tambahkan data 'Futaba, 18' diantara John dan Jane ---" << endl;
    TambahTengah_151("Futaba", 18, 3);
    TampilList_151();

    //Jawaban poin d
    cout << "--- Tambahkan data 'Igor, 20' diawal ---" << endl;
    TambahDepan_151("Igor", 20);
    TampilList_151();

    //Jawaban poin e
    cout << "--- Ubah data 'Michael' menjadi 'Reyn, 18' ---" << endl;
    UbahTengah_151("Reyn", 18, 6);
    TampilList_151();

    //jawaban poin f
    cout << "--- Tampilkan Seluruh Data ---" << endl;
    TampilList_151();

    return 0;
}
```
#### Output:

##### Output Poin a
![Dhimas_Output-Unguided1-1](https://github.com/Masdim37/2311102151_Muhammad-Dhimas-Hafizh-Fathurrahman/blob/main/Pertemuan3_Modul3-Linked-List/Laprak/Dhimas_Output-Unguided1-1.png)

##### Output Poin b
![Dhimas_Output-Unguided1-2](https://github.com/Masdim37/2311102151_Muhammad-Dhimas-Hafizh-Fathurrahman/blob/main/Pertemuan3_Modul3-Linked-List/Laprak/Dhimas_Output-Unguided1-2.png)

##### Output Poin c
![Dhimas_Output-Unguided1-3](https://github.com/Masdim37/2311102151_Muhammad-Dhimas-Hafizh-Fathurrahman/blob/main/Pertemuan3_Modul3-Linked-List/Laprak/Dhimas_Output-Unguided1-3.png)

##### Output Poin d
![Dhimas_Output-Unguided1-4](https://github.com/Masdim37/2311102151_Muhammad-Dhimas-Hafizh-Fathurrahman/blob/main/Pertemuan3_Modul3-Linked-List/Laprak/Dhimas_Output-Unguided1-4.png)

##### Output Poin e
![Dhimas_Output-Unguided1-5](https://github.com/Masdim37/2311102151_Muhammad-Dhimas-Hafizh-Fathurrahman/blob/main/Pertemuan3_Modul3-Linked-List/Laprak/Dhimas_Output-Unguided1-5.png)

##### Output Poin f
![Dhimas_Output-Unguided1-6](https://github.com/Masdim37/2311102151_Muhammad-Dhimas-Hafizh-Fathurrahman/blob/main/Pertemuan3_Modul3-Linked-List/Laprak/Dhimas_Output-Unguided1-6.png)

Deskripsi program unguided 1

### 2. Soal mengenai Double Linked List
Modifikasi Guided Double Linked List dilakukan dengan penambahan operasi untuk menambah data, menghapus, dan update di tengah / di urutan tertentu yang diminta. Selain itu, buatlah agar tampilannya menampilkan Nama produk dan harga. </br>

![Dhimas_Soal-Unguided2-1-Modul3](https://github.com/Masdim37/2311102151_Muhammad-Dhimas-Hafizh-Fathurrahman/blob/main/Pertemuan3_Modul3-Linked-List/Laprak/Soal-Unguided2-1-Modul3.png)

Case :
1. Tambahkan produk Azarine dengan harga 65000 diantara Somethinc dan Skintific.
2. Hapus produk wardah.
3. Update produk Hanasui menjadi Cleora dengan harga 55.000.
4. Tampilkan menu seperti dibawah ini.
```C++
1. Tambah data
2. Hapus data
3. Update data
4. Tambah data urutan tertentu
5. Hapus data urutan tertentu
6. Hapus seluruh data
7. Tampilkan data
8. Exit
```
Pada menu 7, tampilan akhirnya akan menjadi seperti dibawah ini :

![Dhimas_Soal-Unguided2-2-Modul3](https://github.com/Masdim37/2311102151_Muhammad-Dhimas-Hafizh-Fathurrahman/blob/main/Pertemuan3_Modul3-Linked-List/Laprak/Soal-Unguided2-2-Modul3.png)

```C++
#include<iostream>
#include<iomanip>

using namespace std;

struct node{
    string barang_151;
    int harga_151;
    node *prev;
    node *next;
};
    node *head;
    node *tail;

//prosedur inisiaslisasi 
void Inisialisasi_151(){
    head = nullptr;
    tail = nullptr;
}

//prosedur tambah node
void TambahNode_151(string produk_151, int harga_151, int posisi_151){
    if(posisi_151 < 1 ){
        cout << "Node yang ingin ditambah diluar jangkauan" << endl;
    } else if(posisi_151 == 1){
        node *baru = new node;
        baru->barang_151 = produk_151;
        baru->harga_151 = harga_151;
        baru->next = head;
        baru->prev = nullptr;
        if(head != nullptr){
            head->prev = baru;
        } else {
            tail = baru;
        }
        head = baru;
    } else {
        node *current = head;
        node *baru = new node;
        baru->barang_151 = produk_151;
        baru->harga_151 = harga_151;
        baru->next = nullptr;
        baru->prev = nullptr;
        int hitung_151 = 1;
        while(hitung_151 < posisi_151 - 1){
            hitung_151++;
            current = current->next;
        }
        baru->next = current->next;
        baru->prev = current;
        if(current->next != nullptr){
            current->next->prev = baru;
        } else {
            tail = baru;
        }
        current->next = baru;
    }
}

//prosedur hapus node
void HapusNode_151(int posisi_151){
    if(posisi_151 < 1){
        cout << "Posisi node yang ingin dihapus diluar jangkauan" << endl;
    } else if(posisi_151 == 1){
        node *current = head;  // Simpan node pertama
        head = head->next;     // Geser head ke node berikutnya
        if(head != nullptr) {
            head->prev = nullptr;  // Tetapkan nullptr ke prev dari node baru pertama
        }
        delete current;  // Hapus node pertama
    } else {
        node *current = head;
        int hitung_151 = 1;
        while(hitung_151 < posisi_151){
            hitung_151++;
            current = current->next;
        }
        current->prev->next = current->next;
        current->next->prev = current->prev;
        delete current;
    }
}

//fungsi update data
bool UpdateData_151(string ProdukLama_151, string ProdukBaru_151, int HargaBaru_151){
    node *current = head;
    while (current != nullptr){
        if(current->barang_151 == ProdukLama_151){
            current->barang_151 = ProdukBaru_151;
            current->harga_151 = HargaBaru_151;
            return true;
        }
        current = current->next;
    }
    return false;
}

//prosedur hapus semua data
void HapusSemua_151(){
    node *current = head;
    while(current != nullptr){
        node *temp = current;
        current = current->next;
        delete temp;
    }
    head = nullptr;
    tail = nullptr;
}

//prosedur tampilkan data
void TampilData_151(){
    node *current = head;
    if(head != nullptr){
        cout << left << setw(20) << "- Nama Produk -" << right << setw(5) << "- Harga -" << endl; 
        while(current != nullptr){
            cout << left << setw(20) << current->barang_151 << right << setw(7) << current->harga_151 << endl; 
            current = current->next;
        }
    }
    cout << endl;
}

int main(){
    int pilih_151, HargaBaru_151, PosisiProduk_151;
    string ProdukBaru_151, ProdukLama_151;
    char yakin_151;
    Inisialisasi_151();
    cout << "--- DAFTAR PRODUK SKINCARE ---" << endl;
    TambahNode_151("Hanasui", 30000, 1 );
    TambahNode_151("Wardah", 50000, 1);
    TambahNode_151("Skintific", 100000, 1);
    TambahNode_151("Somethinc", 150000, 1);
    TambahNode_151("Originote", 60000, 1);
    TampilData_151();

    MenuUtama:
    cout << "--- TOKO SKINCARE PURWOKERTO ---" << endl;
    cout << "1. Tambah data" << endl;
    cout << "2. Hapus data" << endl;
    cout << "3. Update data" << endl;
    cout << "4. Tambah data urutan tertentu" << endl;
    cout << "5. Hapus data urutan tertentu" << endl;
    cout << "6. Hapus seluruh data" << endl;
    cout << "7. Tampilkan data" << endl;
    cout << "8. exit" << endl;
    cout << "Pilihan anda = "; cin >> pilih_151;
    cout << endl;

    switch(pilih_151){
        case 1 :
            cout << "- Tambah Data Produk -" << endl;
            cout << "Masukkan nama produk yang ingin ditambahkan = "; cin >> ProdukBaru_151;
            cout << "Masukkan harga produk = "; cin >> HargaBaru_151;
            TambahNode_151(ProdukBaru_151, HargaBaru_151, 1);
            cout << "Produk telah ditambahkan" << endl;
            cout << endl;
            goto MenuUtama;
            break;
        case 2 :
            cout << "- Hapus Data Produk Pertama - " << endl;
            HapusNode_151(1);
            cout << "Data produk ke-1 telah dihapus" << endl;
            cout << endl;
            goto MenuUtama;
            break;
        case 3 :
            cout << "- Update Data Produk -" << endl;
            cout << "Masukkan produk lama yang ingin diganti = ";cin >> ProdukLama_151;
            cout << "Masukkan nama produk baru = "; cin >> ProdukBaru_151;
            cout << "Masukkan harga produk baru = "; cin >> HargaBaru_151;
            UpdateData_151(ProdukLama_151, ProdukBaru_151, HargaBaru_151);
            cout << "Produk telah diupdate" << endl;
            cout << endl;
            goto MenuUtama;
            break;
        case 4 :
            cout << "- Tambah Data Urutan Tertentu -" << endl;
            cout << "Masukkan nama produk yang ingin ditambahkan = "; cin >> ProdukBaru_151;
            cout << "Masukkan harga produk baru = "; cin >> HargaBaru_151;
            cout << "Masukkan posisi produk dalam database = "; cin >> PosisiProduk_151;
            TambahNode_151(ProdukBaru_151, HargaBaru_151, PosisiProduk_151);
            cout << "Produk telah ditambahkan" << endl;
            cout << endl;
            goto MenuUtama;
            break;
        case 5 :
            cout << "- Hapus Data Urutan Tertentu -" << endl;
            cout << "Masukkan urutan produk yang ingin dihapus = "; cin >> PosisiProduk_151;
            HapusNode_151(PosisiProduk_151);
            cout << "Data produk urutan ke-" << PosisiProduk_151 << " telah dihapus" << endl;
            cout << endl;
            goto MenuUtama;
            break;
        case 6 :
            cout << "- Hapus Seluruh Data -" << endl;
            cout << "Apakah anda yakin ingin menghapus semua produk? [y/n] = "; cin >> yakin_151;
            if(yakin_151 == 'y' || yakin_151 == 'Y'){
                HapusSemua_151();
                cout << "Semua data produk telah dihapus" << endl;
            } else if(yakin_151 == 'n' || yakin_151 == 'N'){
                cout << "Aksi dibatalkan" << endl;
            }
            cout << endl;
            goto MenuUtama;
            break;
        case 7 :
            cout << "- Tampilkan Data -" << endl;
            TampilData_151();
            cout << endl;
            goto MenuUtama;
            break;
        case 8 :
            cout << "Anda keluar dari program" << endl;
            return 0;
        default :
            cout << "Pilihan yang anda masukkan tidak tersedia" << endl;
            cout << endl;
            goto MenuUtama;
            break;
    }    
}
```
#### Output:

##### Output 1 :
Tampilan menu utama.

![Dhimas_Output-Unguided2-1](https://github.com/Masdim37/2311102151_Muhammad-Dhimas-Hafizh-Fathurrahman/blob/main/Pertemuan3_Modul3-Linked-List/Laprak/Dhimas_Output-Unguided2-1.png)

##### Output 2 :
Menambahkan produk Azarine dengan harga 65000 diantara Somethinc dan Skintific.

![Dhimas_Output-Unguided2-2](https://github.com/Masdim37/2311102151_Muhammad-Dhimas-Hafizh-Fathurrahman/blob/main/Pertemuan3_Modul3-Linked-List/Laprak/Dhimas_Output-Unguided2-2.png)

##### Output 3 :
Hapus produk wardah.

![Dhimas_Output-Unguided2-3](https://github.com/Masdim37/2311102151_Muhammad-Dhimas-Hafizh-Fathurrahman/blob/main/Pertemuan3_Modul3-Linked-List/Laprak/Dhimas_Output-Unguided2-3.png)

##### Output 4 :
Update produk Hanasui menjadi Cleora dengan harga 55.000.

![Dhimas_Output-Unguided2-4](https://github.com/Masdim37/2311102151_Muhammad-Dhimas-Hafizh-Fathurrahman/blob/main/Pertemuan3_Modul3-Linked-List/Laprak/Dhimas_Output-Unguided2-4.png)

##### Output 5 :
Tampilan akhir data yang tersimpan.

![Dhimas_Output-Unguided2-5](https://github.com/Masdim37/2311102151_Muhammad-Dhimas-Hafizh-Fathurrahman/blob/main/Pertemuan3_Modul3-Linked-List/Laprak/Dhimas_Output-Unguided2-5.png)

Deskripsi program unguided 2

## Kesimpulan

## Referensi
[1] Triase. (2020). Diktat Edisi Revisi : STRUKTUR DATA. Medan: UNIVERSTAS ISLAM NEGERI SUMATERA UTARA MEDAN.
<br>[2] Harihayati Mardzuki, Tati. (2020). Double Linked List. [Teaching Resource]. Diakses pada 26 Maret 2024 melalui http://repository.unikom.ac.id/id/eprint/64221.
