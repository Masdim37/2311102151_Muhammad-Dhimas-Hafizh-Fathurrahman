#include<iostream>

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
void TambahNode(string produk_151, int harga_151, int posisi_151){
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
        node *current;
        current = head;
        node *baru = new node;
        baru->barang_151 = produk_151;
        baru->harga_151 = harga_151;
        baru->next = nullptr;
        baru->prev = nullptr;
        int hitung_151 = 1;
        while(hitung_151 < posisi_151){
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
void HapusNode(int posisi_151){
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

int main(){

    
}