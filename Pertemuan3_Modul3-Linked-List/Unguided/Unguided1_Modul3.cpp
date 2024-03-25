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