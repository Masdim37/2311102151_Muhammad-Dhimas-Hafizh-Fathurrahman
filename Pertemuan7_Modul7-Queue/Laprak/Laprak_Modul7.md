# <h1 align="center">Laporan Praktikum Modul 7 - Queue</h1>
<p align="center">Muhammad Dhimas Hafizh Fathurrahman - 2311102151</p>

## Dasar Teori

### A. Queue
Queue (antrian) adalah daftar berurutan di mana penyisipan dilakukan di satu ujung (belakang) dan penghapusan dilakukan di ujung lain (depan)[1]. Queue menggunakan konsep FIFO (First In First Out) yang artinya data atau elemen pertama yang ditambahkan adalah data atau elemen yang pertama kali dikeluarkan. Contoh penerapan queue dalam kehidupan sehari-hari adalah antrian pada kasir supermarket, antrian pada bank, dan sebagainya dimana pelanggan atau costumer pertama yang mengantri adalah yang pertama kali dilayani. Queue dapat diimplementasikan menggunakan array maupun linked list. Berikut merupakan gambar penjelasan konsep FIFO pada queue.

- Konsep FIFO pada queue dengan implementasi array
![Dhimas_Konsep-FIFO-Queue-Array](https://github.com/Masdim37/2311102151_Muhammad-Dhimas-Hafizh-Fathurrahman/blob/main/Pertemuan7_Modul7-Queue/Laprak/Dhimas_Konsep-FIFO-Queue-Array.png)

- Konsep FIFO pada queue dengan implementasi linked list
![Dhimas_Konsep-FIFO-Queue-LinkedList](https://github.com/Masdim37/2311102151_Muhammad-Dhimas-Hafizh-Fathurrahman/blob/main/Pertemuan7_Modul7-Queue/Laprak/Dhimas_Konsep-FIFO-Queue-LinkedList.png)

Pada implementasi queue menggunakan array dan linked list, terdapat penanda front atau head dan penanda back atau tail atau rear. Front menandakan elemen atau data pertama pada queue dan back menandakan data atau elemen terakhir pada queue. 

### B. Operasi Pada Queue
Seperti halnya struktur data yang lain, pada queue juga dapat dilakukan beberapa operasi. Berikut beberapa istilah dan operasi yang dapat dilakukan pada queue, antara lain[2][3] =
- isFull(); fungsi untuk mengetahui apakah queue penuh atau tidak. Fungsi ini hanya berlaku untuk queue yang jumlahnya terbatas (queue yang diimplementasikan menggunakan array).
- isEmpty(); fungsi untuk mengetahui apakah queue dalam keadaan kosong atau tidak. Dengan status ini maka dapat dicegah dilakukannya operasi Dequeue dari suatu queue yang kosong.
- Size(); operasi untuk mendapatkan banyaknya elemen queue.
- Enqueue(); prosedur untuk menambahkan elemen ke dalam Antrian, penambahan elemen selalu ditambahkan di elemen paling belakang. Penanda back akan dipindahkan ke elemen yang ditambahkan.
- Dequeue(); prosedur yang digunakan untuk menghapus elemen terdepan atau pertama (head) dari antrian. Penanda front akan dipindahkan ke elemen selanjutnya kemudian elemen pertama dihapus.

## Guided 

### 1. Latihan Queue Sederhana

```C++
#include<iostream>

using namespace std;

const int MaksimalAntrian = 5;
int front = 0;
int back = 0;
string QueueTeller[5];

//Mengecek apakah antrian sudah penuh atau belum
bool isFull(){
    if(back == MaksimalAntrian){
        return true;
    } else {
        return false;
    }
}

//Mengecek apakah antrian masih kosong atau tidak
bool isEmpty(){
    if(back == 0){
        return true;
    } else {
        return false;
    }
}

//Menambah antrian
void TambahData(string nama){
    if(isFull()){
        cout << "Antrian sudah penuh" << endl;
    } else if(!isFull()){
        if(isEmpty()){
            QueueTeller[0] = nama;
            front++;
            back++;
        } else if(!isEmpty()){
            QueueTeller[back] = nama;
            back++;
        }
    }
}

//Mengurangi antrian
void KurangAntrian(){
    if(isEmpty()){
        cout << "Antrian masih kosong" << endl;
    } else if(!isEmpty()){
        for(int i = 0; i < back; i++){
            QueueTeller[i] =  QueueTeller[i+1];
        }
        back--;
    }
}

//Menghitung banyak antrian
int Count(){
    return back;
}

//Menghapus seluruh antrian
void ClearQueue(){
    if(isEmpty()){
        cout << "Antrian masih kosong" << endl;
    } else if(!isEmpty()){
        for(int i = 0; i < back; i++){
            QueueTeller[i] = "";
        }
        back = 0;
        front = 0;
    }
}

//Melihat Antrian
void ViewQueue(){
    cout << "Data antrian = " << endl;
    for(int i = 0; i < MaksimalAntrian; i++){
        if(QueueTeller[i] != ""){
            cout << i+1 << ". " << QueueTeller[i] << endl;
        } else {
            cout << i+1 << ". " << "(kosong)" << endl;
        }
    }
    cout << endl;
}

//main fungsi
int main(){
    //Menambah 3 data nama kedalam antrian
    TambahData("Alya");
    TambahData("Kiki");
    TambahData("Artika");

    //menampilkan data yang sudah ditambahkan
    ViewQueue();

    //mengurangi data
    KurangAntrian();

    //menampilkan data setelah dikurangi
    ViewQueue();

    //menghapus seluruh antrian
    ClearQueue();

    //menampilkan data setelah dihapus
    ViewQueue();
}
```

#### Deskripsi Program
Kode diatas merupakan program latihan queue sederhana. Implementasi queue pada program ini menggunakan array yang bernama `QueueTeller`, oleh karena itu, implementasi queue menggunakan array memerlukan batas maksimal antrian atau kapasitas array. Pada program ini, batas maksimal antrian adalah sebanyak 5. Pada awal program dideklarasikan integer konstanta bernama `MaksimalAntrian` dengan ukuran 5, variabel `front` dan `back` dengan nilai 0, serta deklarasi array `QueueTeller` dengan ukuran 5. Pada program ini terdapat beberapa fungsi dan prosedur yang digunakan untuk memanipulasi queue, antara lain = 
- bool isFull(); digunakan untuk mengecek apakah queue penuh atau tidak
- bool isEmpty(); digunakan untuk mengecek apakah queue masih kosong atau tidak
- void TambahData(string nama); digunakan untuk menambahkan data nama pada antrian
- void KurangAntrian(); digunakan untuk mengurangi antrian (melanjutkan atau memajukan antrian (menghapus antrian pertama))
- int Count(); digunakan untuk menghitung jumlah antrian
- void ClearQueue(); digunakan untuk menghapus seluruh antrian
- void ViewQueue(); digunakan untuk menampilkan seluruh antrian

Kemudian pada `int main()`, dilakukan beberapa operasi terkait queue, yaitu menambahkan 3 data kedalam antrian (Alya, Kiki, Artika) menggunakan prosedur `TambahData()`, menampilkan antrian dengan data yang sudah ditambahkan menggunakan prosedur `ViewQueue()`, mengurangi antrian menggunakan prosedur `KurangAntrian()`, menampilkan antrian dengan data yang sudah dikurangi menggunakan prosedur `ViewQueue()`, menghapus seluruh antrian menggunakan prosedur `ClearQueue()`, serta menampilkan antrian dengan data yang sudah dihapus menggunakan prosedur `ViewQueue()`.

## Unguided 

### 1. Ubahlah penerapan konsep queue pada bagian guided dari array menjadi linked list!

```C++
#include<iostream>

using namespace std;

//Deklarasi struct node
struct node{ //node berisi variabel nama_151 dan pointer next
    string nama_151;
    node *next;
};
    node *front; //deklarasi node front 
    node *back; //deklarasi node back

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
void TambahData_151(string name_151){
    node *baru = new node; //tambah node baru
    baru->nama_151 = name_151; //node baru berisi variabel name_151
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
    if(isEmpty_151() == true){ //jika antrian kosong, maka tampilkan "Antrian masih kosong!"
        cout << "Antrian masih kosong!" << endl;
    } else if(isEmpty_151() == false){ //jika antrian tidak kosong, maka lanjutkan
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
        cout << "--- Antrian saat ini ---" << endl;  
        int NomorAntrian_151 = 1; //inisialisasi variabel NomorAntrian_151 dengan nilai 1
        while(bantu != NULL){ //jika node bantu bukan NULL, maka ulangi
            cout << NomorAntrian_151 << ". " << bantu->nama_151 << endl; //tampilkan antrian dengan nomor urutnya
            bantu = bantu->next; //node bantu berlanjut ke node selanjutnya
            NomorAntrian_151++; //nomor antrian bertambah
        }
    }
    cout << endl;
}

int main(){
    //Menambah 3 data nama kedalam antrian
    TambahData_151("Alya");
    TambahData_151("Kiki");
    TambahData_151("Artika");

    //Menampilkan data yang sudah ditambahkan
    LihatAntrian_151();

    //Mengurangi data
    KurangiAntrian_151();

    //menampilkan data setelah dikurangi
    LihatAntrian_151();

    //Menghapus seluruh antrian
    HapusAntrian_151();

    //menampilkan data setelah dihapus
    LihatAntrian_151();
    
    return 0;
}
```

#### Output:
![Dhimas_Output-Unguided1](https://github.com/Masdim37/2311102151_Muhammad-Dhimas-Hafizh-Fathurrahman/blob/main/Pertemuan7_Modul7-Queue/Laprak/Dhimas_Output-Unguided1.png)

#### Deskripsi Program
Kode diatas merupakan program latihan queue sederhana, sama seperti pada bagian guided. Implementasi queue pada program ini menggunakan linked list, berbeda dengan bagian guided yang implementasi queue-nya menggunakan array. Dikarenakan implementasi queue pada program ini menggunakan linked list, maka tidak diperlukan batas maksimal antrian (antrian bisa bertambah sampai tak terhingga). Pada awal program dideklarasika struct node dengan isi variabel `nama_151` dan pointer next. Kemudian dideklarasikan node front dan back. Pada program ini terdapat beberapa fungsi dan prosedur yang digunakan untuk memanipulasi queue, antara lain =
- void Inisialisasi_151(); digunakan untuk menginisialisasikan front dan back sebagai NULL
- bool isEmpty_151(); digunakan untuk mengecek apakah queue masih kosong atau tidak
- void TambahData_151(string name_151); digunakan untuk menambahkan data nama pada antrian
- void KurangiAntrian_151(); digunakan untuk mengurangi antrian (melanjutkan atau memajukan antrian (menghapus antrian pertama))
- int HitungAntrian_151(); digunakan untuk menghitung jumlah antrian
- void HapusAntrian_151(); digunakan untuk menghapus seluruh antrian
- void LihatAntrian_151(); digunakan untuk menampilkan seluruh antrian

Kemudian pada `int main()`, dilakukan beberapa operasi terkait queue, yaitu menambahkan 3 data kedalam antrian (Alya, Kiki, Artika) menggunakan prosedur `TambahData_151()`, menampilkan antrian dengan data yang sudah ditambahkan menggunakan prosedur `LihatAntrian_151()`, mengurangi antrian menggunakan prosedur `KurangiAntrian_151()`, menampilkan antrian dengan data yang sudah dikurangi menggunakan prosedur `LihatAntrian_151()`, menghapus seluruh antrian menggunakan prosedur `HapusAntrian_151()`, serta menampilkan antrian dengan data yang sudah dihapus menggunakan prosedur `LihatAntrian_151()`.


### 2. Dari nomor 1 buatlah konsep antri dengan atribut Nama mahasiswa dan NIM Mahasiswa!

```C++
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
```
#### Output:

##### Menambahkan 3 Data (Dhimas - 2311102151, Hafizh - 2311102121, Fathurrahman - 2311102137)
![Dhimas_Output-Unguided2-1-1](https://github.com/Masdim37/2311102151_Muhammad-Dhimas-Hafizh-Fathurrahman/blob/main/Pertemuan7_Modul7-Queue/Laprak/Dhimas_Output-Unguided2-1-1.png)

![Dhimas_Output-Unguided2-1-2](https://github.com/Masdim37/2311102151_Muhammad-Dhimas-Hafizh-Fathurrahman/blob/main/Pertemuan7_Modul7-Queue/Laprak/Dhimas_Output-Unguided2-1-2.png)

##### Menghitung Jumlah Antrian yang Sudah Tersimpan dan Menampilkannya
![Dhimas_Output-Unguided2-2](https://github.com/Masdim37/2311102151_Muhammad-Dhimas-Hafizh-Fathurrahman/blob/main/Pertemuan7_Modul7-Queue/Laprak/Dhimas_Output-Unguided2-2.png)

##### Mengurangi Antrian (Menghapus Antrian Pertama (Dhimas - 2311102151))
![Dhimas_Output-Unguided2-3](https://github.com/Masdim37/2311102151_Muhammad-Dhimas-Hafizh-Fathurrahman/blob/main/Pertemuan7_Modul7-Queue/Laprak/Dhimas_Output-Unguided2-3.png)

##### Menghitung Jumlah Antrian Setelah Dikurangi dan Menampilkannya
![Dhimas_Output-Unguided2-4](https://github.com/Masdim37/2311102151_Muhammad-Dhimas-Hafizh-Fathurrahman/blob/main/Pertemuan7_Modul7-Queue/Laprak/Dhimas_Output-Unguided2-4.png)

##### Menghapus Seluruh Antrian
![Dhimas_Output-Unguided2-5](https://github.com/Masdim37/2311102151_Muhammad-Dhimas-Hafizh-Fathurrahman/blob/main/Pertemuan7_Modul7-Queue/Laprak/Dhimas_Output-Unguided2-5.png)

##### Menghitung Jumlah Antrian Setelah Dihapus dan Menampilkannya
![Dhimas_Output-Unguided2-6](https://github.com/Masdim37/2311102151_Muhammad-Dhimas-Hafizh-Fathurrahman/blob/main/Pertemuan7_Modul7-Queue/Laprak/Dhimas_Output-Unguided2-6.png)

##### Keluar Dari Program
![Dhimas_Output-Unguided2-7](https://github.com/Masdim37/2311102151_Muhammad-Dhimas-Hafizh-Fathurrahman/blob/main/Pertemuan7_Modul7-Queue/Laprak/Dhimas_Output-Unguided2-7.png)


#### Deskripsi Program
Kode diatas merupakan program penerapan queue yang menyimpan atribut nama mahasiswa dan NIM mahasiswa. Implementasi queue pada program ini sama seperti unguided 1, yaitu menggunakan linked list. Dikarenakan implementasi queue pada program ini menggunakan linked list, maka tidak diperlukan batas maksimal antrian (antrian bisa bertambah sampai tak terhingga). Pada awal program dideklarasikan struct node dengan isi variabel `NamaMahasiswa_151`, variabel `NIM_151`, serta pointer next. Kemudian dideklarasikan node front dan back. Pada program ini terdapat beberapa fungsi dan prosedur yang digunakan untuk memanipulasi queue, antara lain =
- void Inisialisasi_151(); digunakan untuk menginisialisasikan front dan back sebagai NULL
- bool isEmpty_151(); digunakan untuk mengecek apakah queue masih kosong atau tidak
- void TambahData_151(string Name_151, string NIM_151); digunakan untuk menambahkan data nama mahaiswa beserta NIM-nya pada antrian
- void KurangiAntrian_151(); digunakan untuk mengurangi antrian (melanjutkan atau memajukan antrian (menghapus antrian pertama))
- int HitungAntrian_151(); digunakan untuk menghitung jumlah antrian
- void HapusAntrian_151(); digunakan untuk menghapus seluruh antrian
- void LihatAntrian_151(); digunakan untuk menampilkan seluruh antrian

Kemudian pada `int main()`, terdapat Menu Antrian Mahasiswa yang berisi beberapa opsi sub menu, yaitu sub menu tambah antrian, sub menu kurangi antrian, sub menu hitung jumlah antrian, sub menu hapus antrian, sub menu lihat antrian, dan sub menu keluar. Menu-menu ini menggunakan percabangan switch case. Jika user memilih 1, maka masuk ke sub menu tambah antrian. Pada sub menu ini dipanggil prosedur `TambahData_151()` dengan parameter nama mahasiswa dan NIM-nya yang sudah diinputkan user sebelumnya. Kemudian jika user memilih 2, maka masuk ke sub menu kurangi antrian. Pada sub menu ini dipanggil prosedur `KurangiAntrian_151()` untuk mengurangi antrian. Kemudian jika user memilih 3, maka masuk ke sub menu hitung jumlah antrian. Pada sub menu ini dipanggil fungsi `HitungAntrian_151()` untuk menghitung jumlah antrian yang tersimpan. Kemudian jika user memilih 4, maka masuk ke sub menu hapus antrian. Pada sub menu ini dipanggil prosedur `HapusAntrian_151()` untuk menghapus seluruh antrian. Kemudian jika user memilih 5, maka masuk ke sub menu lihat antrian. Pada sub menu ini dipanggil prosedur `LihatAntrian_151()` untuk menampilkan seluruh antrian. Terakhir jika user memilih 6, maka user keluar dari program. 

## Kesimpulan
Antrian (queue) adalah daftar terurut di mana penyisipan dilakukan di belakang (back) dan penghapusan dilakukan di depan (front). Elemen atau data pertama yang ditambahkan adalah elemen atau data yang pertama kali dikeluarkan. Oleh karena itu, queue disebut daftar First In First Out (FIFO). Pada queue terdapat beberapa istilah dan fungsi yang dapat digunakan antara lain front, back, isFull, isEmpty, size, Enqueue, serta Dequeue. 

## Referensi
[1] Joseph Teguh Santoso. (2021). "STRUKTUR DATA dan ALGORITMA (Bagian 1)". Penerbit Yayasan Prima Agus Teknik, 7(1), 1-333. Retrieved from https://penerbit.stekom.ac.id/index.php/yayasanpat/article/view/288. 
<br>[2] Triase, Triase. (2020). "Struktur Data: Diktat Edisi Revisi." (2020). Retrieved from http://repository.uinsu.ac.id/id/eprint/9717.
<br>[3] Sindar, Anita. (2019). "STRUKTUR DATA DAN ALGORITMA DENGAN C++". Serang: CV. AA. RIZKY.