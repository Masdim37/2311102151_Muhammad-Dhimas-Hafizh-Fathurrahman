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
        cout << "- Nama -     - umur -" << endl; 
        for(int i=0; i<=HitungNode_151() && bantu != NULL; i++){
            cout << bantu->nama_151 << '\t' << '\t' << bantu->umur_151 << endl;
            bantu = bantu->next;
        }
        cout << endl;
    } else {
        cout << "List masih kosong!" << endl;
    }
}

int main(){
    int Posisi_151, umur_151;
    char Yakin_151, Pilihan_151;
    string nama_151;
    MenuJawaban:
    cout << "--- MENU JAWABAN ---" << endl;
    cout << "a. Jawab poin a" << endl;
    cout << "b. Jawab poin b" << endl;
    cout << "c. Jawab poin c" << endl;
    cout << "d. Jawab poin d" << endl;
    cout << "e. Jawab poin e" << endl;
    cout << "f. Jawab poin f" << endl;
    cout << "g. exit" << endl;
    cout << "Pilihan anda = "; cin >> Pilihan_151;
    cout << endl;

    switch(Pilihan_151){
        case 'a' :
            //Jawaban poin a
            inisialisasi_151();
            cout << "- Masukkan Data Sesuai Urutan -" << endl;
            for(int i=1; i <= 8; i++){
                cout << "Masukkan data nama ke-" << i << " = ";
                cin >> nama_151;
                cout << "Masukkan umur data ke-" << i << " = ";
                cin >> umur_151;
                TambahBelakang_151(nama_151, umur_151);
            }
            cout << endl;
            TampilList_151();
            goto MenuJawaban;
            break;
        case 'b' :
            cout << "--- Menghapus data 'Akechi' ---" << endl;
            cout << "Masukkan posisi data Akechi = "; cin >> Posisi_151;
            cout << "Apakah anda yakin ingin menghapus data 'Akechi' yang berada di posisi ke-" << Posisi_151 << "? [y/n] = "; cin >> Yakin_151;
            if(Yakin_151 == 'y' || Yakin_151 == 'Y'){
                HapusTengah_151(6);
                cout << "Data telah dihapus" << endl;
                cout << endl;
            } else if(Yakin_151 =='n' || Yakin_151 == 'N'){
                cout << "Aksi dibatalkan" << endl;
                cout << endl;
            }
            TampilList_151();
            goto MenuJawaban;
            break;
        case 'c' :
            cout << "--- Tambahkan data 'Futaba, 18' diantara John dan Jane ---" << endl;
            cout << "Masukkan data nama = "; cin >> nama_151;
            cout << "Masukkan umur = "; cin >> umur_151;
            cout << "Masukkan posisi data yang ingin ditambahkan = "; cin >> Posisi_151;
            TambahTengah_151(nama_151, umur_151, Posisi_151);
            cout << endl;
            TampilList_151();
            goto MenuJawaban;
            break;
        case 'd' : 
            cout << "--- Tambahkan data 'Igor, 20' diawal ---" << endl;
            cout << "Masukkan data nama = "; cin >> nama_151;
            cout << "Masukkan umur = "; cin >> umur_151;
            TambahDepan_151(nama_151, umur_151);
            cout << endl;
            TampilList_151();
            goto MenuJawaban;
            break;
        case 'e' :
            cout << "--- Ubah data 'Michael' menjadi 'Reyn, 18' ---" << endl;
            cout << "Masukkan nama data baru = "; cin >> nama_151;
            cout << "Masukkan umur = "; cin >> umur_151;
            cout << "Masukkan posisi data lama yang ingin diubah = "; cin >> Posisi_151;
            UbahTengah_151(nama_151, umur_151, Posisi_151);
            cout << endl;
            TampilList_151();
            goto MenuJawaban;
            break;
        case 'f' :
            cout << "--- Tampilkan Seluruh Data ---" << endl;
            TampilList_151();
            goto MenuJawaban;
            break;
        case 'g' :
            cout << "Anda keluar dari program" << endl;
            return 0;
            break;
        default :
            cout << "Pilihan yang anda masukkan tidak tersedia" << endl;
            goto MenuJawaban;
            break;
    }
}