#include<iostream>

using namespace std;

//Deklarasi struct node
struct node{ //node berisi variabel NamaMahasiswa_151, NIM_151, dan pointer next
    string NamaMahasiswa_151;
    string NIM_151;
    node *next;
};
    node *front; //Deklarasi node front
    node *back; //Deklarasi node back

//Prosedur inisialisasi node front dan back sebagai NULL
void Inisialisasi_151(){ 
    front = NULL;
    back = NULL;
}

//Fungsi untuk mengecek apakah queue kosong atau tidak
bool isEmpty_151(){
    if (front == 0){
        return true; //jika antrian pertama tidak ada, maka antrian kosong (kembalikan true)
    } else {
        return false; //jika antrian pertama ada, maka antrian tidak kosong (kembalikan false)
    }
}

//Prosedur untuk menambahkan data pada antrian
void TambahData_151(string Name_151, string NIM_151){
    node *baru = new node; //tambah node baru
    baru->NamaMahasiswa_151 = Name_151; //node baru berisi nama mahasiswa dan NIM 
    baru->NIM_151 = NIM_151; 
    baru->next = NULL; //next dari node baru adalah NULL
    if(isEmpty_151() == true){ //jika antrian kosong, maka lanjutkan
        front = back = baru; //node baru sebagai front dan back
        back->next = NULL; //node selanjutnya dari node baru adalah NULL
    } else if(isEmpty_151() == false){ //jika antrian tidak kosong, maka lanjutkan
        back->next = baru; //node baru sebagai node selanjutnya dari antrian yang sudah ada
        back = baru; //node baru sebagai back
    }
}

//Prosedur untuk mengurangi antrian (lanjut ke antrian selanjutnya)
void KurangiAntrian_151(){
    node *hapus; //inisialisasi node hapus
    if(isEmpty_151() == false){ //jika antrian tidak kosong, maka lanjutkan
        if(front->next != NULL){ //jika node selanjutnya setelah antrian pertama bukan NULL, maka lanjutkan
            hapus = front; //node hapus sebagai front
            front = front->next; //pindahkan front ke node selanjutnya setelah node pertama
            delete hapus; //hapus node pertama
        } else { //jika tidak ada node selanjutnya setelah antrian pertama, maka lanjutkan
            front = back = NULL; //front dan back adalah NULL
        }
    }
}

//Fungsi untuk menghitung jumlah antrian
int HitungAntrian_151(){
    node *hitung; //inisialisasi node hitung
    hitung = front; //node hitung sebagai front
    int jumlah_151 = 0; //inisialisasi variabel jumlah_151
    while(hitung != NULL){ //jika node hitung bukan NULL, maka ulangi
        hitung = hitung->next; //node hitung berlanjut ke node selanjutnya
        jumlah_151++; //variabel jumlah_151 bertambah nilainya
    }
    return jumlah_151; //kembalikan nilai variabel jumlah_151
}

//Prosedur untuk menghapus seluruh antrian
void HapusAntrian_151(){
    node *hapus, *bantu; //inisialisasi node hapus dan node bantu
    bantu = front; //node bantu sebagai front
    while(bantu != NULL){ ///jika node bantu bukan NULL, maka ulangi
        hapus = bantu; //node hapus sama dengan node bantu
        bantu = bantu->next; //node selanjutnya dari posisi node bantu saat ini, juga merupakan node bantu
        delete hapus; //hapus seluruh node yang merupakan node bantu
    }
    front = back = NULL; //front dan back sebagai NULL
}

//Prosedur untuk menampilkan antrian
void LihatAntrian_151(){
    node *bantu; //inisialisasi node bantu
    bantu = front; //node bantu sebagai front
    if(isEmpty_151() == true){ //jika antrian kosong, maka tampilkan "Antrian kosong!" 
        cout << "Antrian kosong!" << endl; 
    } else if(isEmpty_151() == false){ //jika antrian tidak kosong, maka lanjutkan
        cout << "--- Antrian Saat Ini ---" << endl; 
        int NomorAntrian_151 = 1; //inisialisasi variabel NomorAntrian_151 dengan nilai 1
        while(bantu != NULL){ //jika node bantu bukan NULL, maka ulangi
            cout << NomorAntrian_151 << ". " << bantu->NamaMahasiswa_151 << " - " << bantu->NIM_151 << endl; //tampilkan antrian dengan nomor urut, nama mahasiswa - NIM
            bantu = bantu->next; //node bantu berlanjut ke node selanjutnya
            NomorAntrian_151++; //nomor antrian bertambah
        }
    }
    cout << endl;
}

int main(){
    string NamaMahasiswa_151, NIM_151; 
    int Pilih_151; 
    char Yakin_151;
    MenuUtama:
    cout << "----- MENU ANTRIAN MAHASISWA -----" << endl; //Tampilan menu antrian mahasiswa
    cout << "1. Tambah antrian" << endl;
    cout << "2. Kurangi antrian" << endl;
    cout << "3. Hitung jumlah antrian" << endl;
    cout << "4. Hapus antrian" << endl;
    cout << "5. Lihat antrian" << endl;
    cout << "6. Keluar" << endl;
    cout << "Pilihan Anda [1-6] = ";
    cin >> Pilih_151;
    cout << endl;
    switch(Pilih_151){ //switch case berdasarkan pilihan user
        case 1: //jika user memilih 1, maka tampilkan menu tambah antrian
            cout << "--- Tambah Antrian ---" << endl;
            cout << "Masukkan nama mahasiswa = ";
            cin >> NamaMahasiswa_151;
            cout << "Masukkan NIM mahasiswa = ";
            cin >> NIM_151;
            TambahData_151(NamaMahasiswa_151, NIM_151); //pemanggilan prosedur TambahData_151 dengan parameter nama mahasiswa dan NIM
            cout << "Data mahasiswa telah tersimpan!" << endl;
            cout << endl;
            goto MenuUtama;
            break;
        case 2: //jika user memilih 2, maka tampilkan menu kurangi antrian
            cout << "--- Kurangi Antrian ---" << endl;
            if(isEmpty_151() == true){ //Jika antrian kosong, maka tampilkan "Antrian masih kosong!"
                cout << "Antrian masih kosong!" << endl;
            } else { //jika antrian tidak kosong, maka lanjutkan
                cout << "Apakah anda ingin mengurangi antrian (menghapus antrian pertama)? [y/n] = "; //validasi keyakinan user untuk mengurangi antrian
                cin >> Yakin_151;
                if(Yakin_151 == 'y' || Yakin_151 == 'Y'){ //jika user menginputkan y atau Y, maka lanjutkan
                    KurangiAntrian_151(); //pemanggilan prosedur KurangiAntrian_151()
                    cout << "Antrian telah dikurangi" << endl;
                } else if(Yakin_151 == 'n' || Yakin_151 == 'Y'){ //jika user menginputkan n atau N, maka tampilkan "Aksi dibatalkan"
                    cout << "Aksi dibatalkan" << endl;
                }
            }
            cout << endl;
            goto MenuUtama;
            break;
        case 3: //jika user memilih 3, maka tampilkan menu Hitung Jumlah Antrian
            cout << "--- Hitung Jumlah Antrian ---" << endl;
            cout << "Anrian yang tersimpan saat ini sebanyak " << HitungAntrian_151() << endl; //Pemanggilan fungsi HitungAntrian_151()
            cout << endl;
            goto MenuUtama;
            break;
        case 4: //jika user memilih 4, maka tampilkan menu hapus antrian
            cout << "--- Hapus Antrian ---" << endl;
            cout << "Apakah Anda yakin untuk menghapus seluruh antrian? [y/n] = "; //validasi keyakinan user untuk menghapus seluruh antrian
            cin >> Yakin_151;
            if(Yakin_151 == 'y' || Yakin_151 == 'Y'){ //jika user menginputkan y atau Y, maka lanjutkan
                HapusAntrian_151(); //pemanggilan prosedur HapusAntrian_151()
                cout << "Antrian telah dihapus" << endl;
            } else if(Yakin_151 == 'n' || Yakin_151 == 'N'){ //jika user menginputkan n atau N, maka tampilkan "Aksi dibatalkan"
                cout << "Aksi dibatalkan" << endl;
            }
            cout << endl;
            goto MenuUtama;
            break;
        case 5: //jika user memilih 5, maka tampilkan antrian
            LihatAntrian_151(); //pemanggilan prosedur LihatAntrian_151()
            cout << endl;
            goto MenuUtama;
            break;
        case 6:
            cout << "Anda keluar dari program" << endl;
            cout << endl;
            return 0;
            break;
        default: //jika user memilih selain 1-5, maka tampilkan "Pilihan yang anda masukkan salah!"
            cout << "Pilihan yang anda masukkan salah!" << endl;
            cout << endl;
            goto MenuUtama;
            break;
    }
}