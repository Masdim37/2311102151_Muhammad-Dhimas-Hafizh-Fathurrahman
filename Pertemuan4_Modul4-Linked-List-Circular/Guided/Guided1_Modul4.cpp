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