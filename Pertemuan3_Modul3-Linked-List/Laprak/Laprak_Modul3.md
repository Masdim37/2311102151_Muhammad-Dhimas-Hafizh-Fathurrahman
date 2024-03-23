# <h1 align="center">Laporan Praktikum Modul 3 - Linked List</h1>
<p align="center">Muhammad Dhimas Hafizh Fathurrahman - 2311102151</p>

## Dasar Teori

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
Buatlah program menu Single Linked List Non-Circular untuk menyimpan Nama dan usia mahasiswa, dengan menggunakan inputan dari user. Lakukan operasi berikut:
![Dhimas_Soal-Unguided1-Modul3](https://github.com/Masdim37/2311102151_Muhammad-Dhimas-Hafizh-Fathurrahman/blob/main/Pertemuan3_Modul3-Linked-List/Laprak/Soal-Unguided1-Modul3.png)

```C++

```
#### Output:
![Screenshot Output Unguided ...](https://github.com/Masdim37/2311102151_Muhammad-Dhimas-Hafizh-Fathurrahman/blob/main/Pertemuan3_Modul3-Linked-List/Laprak/Dhimas_Output-Unguided[nomor].png)

Deskripsi program unguided 1

### 2. Soal mengenai Double Linked List
Modifikasi Guided Double Linked List dilakukan dengan penambahan operasi untuk menambah data, menghapus, dan update di tengah / di urutan tertentu yang diminta. Selain itu, buatlah agar tampilannya menampilkan Nama produk dan harga.
![Dhimas_Soal-Unguided2-1-Modul3](https://github.com/Masdim37/2311102151_Muhammad-Dhimas-Hafizh-Fathurrahman/blob/main/Pertemuan3_Modul3-Linked-List/Laprak/Soal-Unguided2-1-Modul3.png)
Case :
1. Tambahkan produk Azarine dengan harga 65000 diantara Somethinc dan Skintific.
2. Hapus produk wardah.
3. Update produk Hanasui menjadi Cleora dengan harga 55.000.
4. Tampilkan menu seperti dibawah ini.
```C++
#include<iostream>

using namespace std;

int main(){
    cout << "1. Tambah data" << endl;
    cout << "2. Hapus data" << endl;
    cout << "3. Update data" << endl;
    cout << "4. Tambah data urutan tertentu" << endl;
    cout << "5. Hapus data urutan tertentu" << endl;
    cout << "6. Hapus seluruh data" << endl;
    cout << "7. Tampilkan data" << endl;
    cout << "8. Exit" << endl;
}
```
Pada menu 7, tampilan akhirnya akan menjadi seperti dibawah ini :
![Dhimas_Soal-Unguided2-2-Modul3](https://github.com/Masdim37/2311102151_Muhammad-Dhimas-Hafizh-Fathurrahman/blob/main/Pertemuan3_Modul3-Linked-List/Laprak/Soal-Unguided2-2-Modul3.png)

```C++

```
#### Output:
![Screenshot Output Unguided ...](https://github.com/Masdim37/2311102151_Muhammad-Dhimas-Hafizh-Fathurrahman/blob/main/Pertemuan3_Modul3-Linked-List/Laprak/Dhimas_Output-Unguided[nomor].png)

Deskripsi program unguided 2

## Kesimpulan

## Referensi
