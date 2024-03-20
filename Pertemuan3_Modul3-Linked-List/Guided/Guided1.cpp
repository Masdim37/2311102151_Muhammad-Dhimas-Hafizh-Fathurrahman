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