#include<iostream>

using namespace std;

//Prosedur untuk menampilkan huruf-huruf didalam kalimat
void TampilkanHurufKalimat_151(char ArrayKalimat_151[], int PanjangKalimat_151){
    for(int i = 0; i < PanjangKalimat_151; i++){ //perulangan for untuk menampilkan huruf
        cout << ArrayKalimat_151[i] << '\t';
    }
    cout << endl;
}

//Prosedur untuk mengurutkan huruf sesuai abjad menggunakan bubble sort
void BubbleSort_151(char ArrayKalimat_151[], int PanjangKalimat_151){
    bool Urut_151 = true; //deklarasi variabel boolean Urut_151 dengan nilai true
    int j = 0; //deklarasi variabel j dengan nilai 0 yang digunanakn dalam perulangan
    char temp_151; //deklarasi variabel temp_151 untuk menampung huruf sementara
    while(Urut_151){ //jika variabel boolean Urut_151 bernilai true, maka ulangi
        Urut_151 = false; //variabel Urut_151 menjadi false
        j++; //nilai j bertambah
        for(int i = 0; i < PanjangKalimat_151 - j; i++){ //perulangan untuk mengurutkan huruf
            if(ArrayKalimat_151[i] > ArrayKalimat_151[i + 1]){  //Jika nilai ArrayKalimat_151 index ke i lebih besar dari nilai index selanjutnya, maka lanjutkan
                temp_151 = ArrayKalimat_151[i]; //masukkan nilai ArrayKalimat_151 index ke i kedalam variabel temp_151
                ArrayKalimat_151[i] = ArrayKalimat_151[i + 1]; //masukkan nilai ArrayKalimat_151 index ke i + 1 kedalam ArrayKalimat_151 index ke i
                ArrayKalimat_151[i + 1] = temp_151; //masukkan nilai variabel temp_151 kedalam ArrayKalimat_151 index ke i + 1
                Urut_151 = true; //variabel boolean Urut_151 menjadi true
            }
        }
    }
}

//Prosedur untuk mencari huruf didalam kalimat menggunakan binary search
void BinarySearch_151(char ArrayKalimat_151[], int PanjangKalimat_151, char HurufYangDicari_151){
    int awal_151, tengah_151, akhir_151, Posisi_151; //Deklarasi variabel awal_151, tengah_151, akhir_151, posisi_151
    bool b_flag = false; //deklarasi variabel boolean b_flag dengan nilai false
    awal_151 = 0; //nilai variabel awal_151 adalah 0
    akhir_151 = PanjangKalimat_151; //nilai variabel akhir_151 adalah nilai varaibel PanjangKalimat_151
    while(!b_flag && awal_151 <= akhir_151){ //Jika b_flag false & nilai awal_151 kurang dari sama dengan nilai akhir_151, maka lanjutkan
        tengah_151 = (awal_151 + akhir_151)/2; //hitung nilai tengah_151
        if(HurufYangDicari_151 == ArrayKalimat_151[tengah_151]){ //jika huruf yang dicari berada di tengah, maka
            Posisi_151 = tengah_151; //nilai variabel posisi_151 sama dengan nilai variabel tengah_151
            b_flag = true; //b_flag menjadi true
            break; //perulangan selesai
        } else if(HurufYangDicari_151 < ArrayKalimat_151[tengah_151]){ //jika huruf yang dicari posisinya kurang dari tengah_151 (berada di kiri), maka
            akhir_151 = tengah_151 - 1; //nilai akhir_151 adalah nilai tengah_151 dikurang 1 
        } else if(HurufYangDicari_151 > ArrayKalimat_151[tengah_151]){ //jika huruf yang dicari posisinya lebih dari tengah_151 (berada di kanan), maka
            awal_151 = tengah_151 + 1; //nilai awal_151 adalah nilai tengah_151 ditambah 1
        }
    }
    if(b_flag){ //jika b_flag true (huruf ditemukan), maka 
        //tampilkan huruf ditemukan beserta indexnya
        cout << "Huruf " << HurufYangDicari_151 << " ditemukan pada index ke-";
        for(int i = 0; i < PanjangKalimat_151; i++){
            if(HurufYangDicari_151 == ArrayKalimat_151[i]){
                cout << i;
                if(ArrayKalimat_151[i + 1] == HurufYangDicari_151){
                    cout << ", ";
                }
            }
        }
    } else { //jika b_flag false (huruf tidak ditemukan), maka tampilkan "Huruf tidak ditemukan"
        cout << "Huruf " << HurufYangDicari_151 << " tidak ditemukan" << endl;
    }
}

int main(){
    string InputKalimat_151, KalimatTanpaSpasi_151; //deklarasi variabel string InputKalimat_151 dan KalimatTanpaSpasi_151
    int PanjangKalimat_151; //deklarasi variabel integer PanjangKalimat_151
    char HurufYangDicari_151; //deklarasi variabel char HurufYangDicari_151
    cout << "--- PROGRAM MENCARI HURUF DALAM KALIMAT ---" << endl;
    cout << "Masukkan kalimat = "; 
    getline(cin, InputKalimat_151); //kalimat yang diinputkan user dimasukkan kedalam variabel InputKalimat_151
    cout << endl;

    // Menghapus karakter spasi dari kalimat
    KalimatTanpaSpasi_151 = ""; //variabel KalimatTanpaSpasi_151 dikosongkan
    //perulangan for-each yang mengiterasi setiap karakter atau huru didalam kalimat yang diinputkan user
    for(char c : InputKalimat_151){
        if(c != ' ') { //jika huruf atau karakter yang diperiksa saat ini bukan spasi, maka masukkan kedalam variabel KalimatTanpaSpasi_151
            KalimatTanpaSpasi_151 += c; 
        }
    }

    //menghitung panjang kalimat
    PanjangKalimat_151 = KalimatTanpaSpasi_151.length();

    //memasukkan setiap karakter dalam kalimat kedalam array char ArrayKalimat_151 dengan ukuran PanjangKalimat_151
    char ArrayKalimat_151[PanjangKalimat_151];
    for(int i = 0; i < PanjangKalimat_151; i++){
        ArrayKalimat_151[i] = KalimatTanpaSpasi_151[i]; //masukkan semua huruf yang tersimpan di KalimatTanpaSpasi_151 kedalam array ArrayKalimat_151[]
    }

    //Menampilkan setiap huruf dalam kalimat sebelum di urutkan
    cout << "Urutan huruf dalam kalimat sebelum diurutkan (spasi dihilangkan) = " << endl;
    TampilkanHurufKalimat_151(ArrayKalimat_151, PanjangKalimat_151); //pemanggilan prosedur TampilkanHurufKalimat()
    cout << endl;

    //Menampilkan setiap huruf dalam kalimat setelah di urutkan
    cout << "Urutan huruf dalam kalimat setelah diurutkan (spasi dihilangkan) = " << endl;
    BubbleSort_151(ArrayKalimat_151, PanjangKalimat_151); //pemanggilan prosedur BubbleSort_151()
    TampilkanHurufKalimat_151(ArrayKalimat_151, PanjangKalimat_151); //pemanggilan prosedur TampilkanHurufKalimat() dengan huruf yang sudah diurutkan secara ascending
    cout << endl;

    //User menginputkan huruf yang ingin dicari
    cout << "Masukkan huruf yang ingin dicari = ";
    cin >> HurufYangDicari_151; 

    //Pemanggilan prosedur BinarySearch_151()
    BinarySearch_151(ArrayKalimat_151, PanjangKalimat_151, HurufYangDicari_151);

    return 0;
}