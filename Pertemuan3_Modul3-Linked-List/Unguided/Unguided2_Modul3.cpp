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