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