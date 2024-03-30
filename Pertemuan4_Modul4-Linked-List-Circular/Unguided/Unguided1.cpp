#include<iostream>
#include<iomanip>

using namespace std;

//deklarasi struct node
struct node{
    string Nama_151;
    int NIM_151;
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
    while (head != NULL){
        hitung = hitung->next;
        jumlah_151++;
    }
    return jumlah_151;
}

//prosedur tambah depan
void TambahDepan_151(string Name_151, int NIM_151){
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
void TambahBelakang_151(string Name_151, int NIM_151){
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
void TambahTengah_151(string Name_151, int NIM_151, int Position_151){
    if(Position_151 < 1 || Position_151 > HitungNode_151()){
        cout << "Node yang ingin ditambah diluar jangkauan!" << endl;
    } else if(Position_151 == 1){
        cout << "Node yang ingin ditambah bukan ditengah!"<< endl;
    } else {
        node *baru = new node;
        node *bantu = head;
        baru->Nama_151 = Name_151;
        baru->NIM_151 = NIM_151;
        baru->next = NULL;
        int hitung_151 = 1;
        while(hitung_151 < Position_151){
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
            head->next = head;
            delete hapus;
        } else {
            head = tail = NULL;
        }
    }
}

//prosedur hapus belakang
void HapusBelakang_151(){
    node *hapus, *bantu;
    if(isEmpty_151() == true){
        cout << "List masih kosong!" << endl;
    } else {
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
    }
}

//prosedur hapus tengah
void HapusTengah_151(int Position_151){
    if(Position_151 < 1 || Position_151 > HitungNode_151()){
        cout << "Node yang ingin dihapus diluar jangkauan!" << endl;
    } else if(Position_151 == 1){
        cout << "Node yang ingin dihapus bukan di tengah!" << endl;
    } else {
        node *hapus, *bantu;
        int nomor_151 = 1;
        bantu = head;
        while (nomor_151 < Position_151){
            bantu = bantu->next;
            nomor_151++;
        }
        hapus = bantu->next;
        bantu->next = hapus->next;
        delete hapus;
    }
}

//prosedur Ubah depan
void UbahDepan_151(string NewName_151, int NewNIM_151){
    if(isEmpty_151() == true){
        cout << "List masih kosong!" << endl;
    } else {
        head->Nama_151 = NewName_151;
        head->NIM_151 = NewNIM_151;
    }
}

//prosedur ubah belakang
void UbahBelakang(string NewName_151, int NewNIM_151){
    if(isEmpty_151() == true){
        cout << "List masih kosong!" << endl;
    } else {
        tail->Nama_151 = NewName_151;
        tail->NIM_151 = NewNIM_151;
    }
}

//prosedur ubah tengah
void UbahTengah(string NewName_151, int NewNIM_151, int Position_151){
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
            int nomor_151;
            while(nomor_151 <= Position_151){
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
        while(head != NULL){
            hapus = bantu;
            bantu = bantu->next;
            delete hapus;   
        }
        head = tail = NULL;
        cout << "List telah terhapus!" << endl; 
    }
}

//prosedur tampil list
void TampilList_151(){
    node *bantu = head;
    if(isEmpty_151() == true){
        cout << "List masih kosong!" << endl;
    } else {
        cout << "--------------------------------" << endl;
        cout << "|       Nama      |    NIM     |" << endl;
        cout << "|------------------------------|" << endl;
        while(bantu != NULL){
            cout << "|" << setw(15) << left << bantu->Nama_151 << "|" << right << setw(10) << bantu->NIM_151 << "|" << endl;
            bantu = bantu->next;
        }
        cout << "--------------------------------" << endl;
    }
}

int main(){
    
}