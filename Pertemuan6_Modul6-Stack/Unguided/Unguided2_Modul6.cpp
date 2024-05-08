#include<iostream>

using namespace std;

const int Max_151 = 100;
string ArrayKalimat_151[Max_151]; //deklarasi array bernama ArrayKalimat sebagai stack
int Top_151 = 0;

//fungsi isEmpty untuk mengecek apakah stack kosong atau tidak
bool isEmpty(){
    return (Top_151 == 0);
}

//prosedur PushKata_151 untuk menambahkan kata pada stack
void PushKata_151(string InputKata_151){
    if(!InputKata_151.empty()){  // Periksa apakah input kata tidak kosong
        ArrayKalimat_151[Top_151] = InputKata_151;
        Top_151++;
    }
}

//prosedur PopKata_151 untuk mengeluarkan elemen pertama pada stack
void PopKata_151(){
    if(Top_151 > 0){
        ArrayKalimat_151[Top_151 - 1] = "";
        Top_151--;
    }
}

//fungsi HitungKata_151 untuk menghitung jumlah kata yang diinputkan user
int HitungKata_151(const char* InputKata_151){
    int JumlahKata_151 = 0;
    int i = 0;
    while (InputKata_151[i] != '\0') {
        // Jika karakter saat ini bukan spasi dan karakter selanjutnya adalah spasi atau null terminator,
        // itu menandakan bahwa kata baru dimulai.
        if (InputKata_151[i] != ' ' && (InputKata_151[i + 1] == ' ' || InputKata_151[i + 1] == '\0')) {
            JumlahKata_151++;
        }
        i++;
    }
    return JumlahKata_151;
}

//Fungsi BalikKata_151 untuk membalikkan urutan huruf pada kata di kalimat yang diinputkan user
string BalikKata_151(const char* InputKata_151){
    string KalimatTerbalik_151; //variabel untuk menampung kata yang sudah terbalik secara keseluruhan
    string KataBelumTerbalik_151;  // variabel untuk menampung kata sementara yang belum dibalik
    string KataSudahTerbalik_151; //variabel untuk menampung kata sementara yang sudah dibalik
    int i = 0;
    //perulangan while
    while (InputKata_151[i] != '\0') { //jika setiap elemen pada InputKata_151 bukan spasi, maka lanjutkan
        char Huruf_151 = InputKata_151[i]; //masukkan setiap elemen di InputKata_151 ke variabel Huruf_151
        //percabangan if-else
        if (Huruf_151 != ' ') { //jika karakter yang sedang diproses bukan spasi, maka lanjutkan
            KataBelumTerbalik_151 += Huruf_151; //tambahkan karakter bukan spasi ke dalam KataBelumTerbalik_151
        } else { //jika karakter yang sedang diproses adalah spasi, maka lanjutkan
            int PanjangKata_151 = KataBelumTerbalik_151.length(); //Hitung panjang kata pada KataBelumTerbalik_151
            for (int j = PanjangKata_151 - 1; j >= 0; --j) {
                KataSudahTerbalik_151 += KataBelumTerbalik_151[j]; //balikkan kata pada KataBelumTerbalik_151 dan masukkan kedalam KataSudahTerbalik_151
            }
            //Tambahkan kata yang sudah terbalik ke dalam stack menggunakan PushKata_151
            if (!KataSudahTerbalik_151.empty()) {
                PushKata_151(KataSudahTerbalik_151);
            }
            KataBelumTerbalik_151 = "";  // Kosongkan KataBelumTerbalik_151 untuk menampung kata baru
            KataSudahTerbalik_151 = "";  // Kosongkan KataBelumTerbalik_151 untuk menampung kata baru
        }
        ++i;
    }
    // Balik kata terakhir jika setelah kata tersebut tidak diikuti oleh spasi
    if(!KataBelumTerbalik_151.empty()) {
        int PanjangKata_151 = KataBelumTerbalik_151.length(); //Hitung panjang kata 
        for (int j = PanjangKata_151 - 1; j >= 0; --j) {
            KataSudahTerbalik_151 += KataBelumTerbalik_151[j]; //balikkan kata dan masukkan kedalam KataSudahTerbalik_151
        }
        if (!KataSudahTerbalik_151.empty()) { //Tambahkan kata yang sudah terbalik ke dalam stack menggunakan PushKata_151
            PushKata_151(KataSudahTerbalik_151);
        }
    }
    
    //keluarkan kata yang sudah dibalik dari stack mengguakan perulangan while
    while(!isEmpty()){
        KalimatTerbalik_151 += ArrayKalimat_151[Top_151 - 1]; //masukkan kata yang sudah dibalik kedalam KalimatTerbalik_151
        PopKata_151(); //hapus kalimat terbalik pada array ArrayKalimat_151 indek ke top_151 - 1 menggunakan PopKata_151
        if (!isEmpty()) { // Jika stack belum kosong, tambahkan spasi di antara kata yang sudah dibalik
            KalimatTerbalik_151 += " ";
        }
    }
    return KalimatTerbalik_151; //kembalikan nilai KalimatTerbalik_151
}

int main(){
    char InputKata_151[Max_151];
    string KalimatTerbalik_151, hasil_151;
    cout << "--- PEMBALIK KALIMAT ---" << endl;
    cout << "Anda bisa memasukkan minimal 3 kata untuk dibalik" << endl;
    MasukkanKalimat:
    cout << "Masukkan kalimat (minimal 3 kata) = ";
    cin.getline(InputKata_151, Max_151);  //Kalimat yang diinputkan user dimasukkan kedalam array InputKata_151

    //Pengecekan apakah kata yang diinputkan user lebih dari 3 atau tidak
    if(HitungKata_151(InputKata_151) < 3){ //Jika kata yang dimasukkan user kurang dari 3 maka user harus memasukkan kalimat lagi 
        cout << "Jumlah kata = " << HitungKata_151(InputKata_151) << endl;
        cout << "Kata yang anda masukkan kurang dari 3, silahkan masukkan ulang kalimat anda" << endl;
        cout << endl;
        goto MasukkanKalimat;
    } else { //jika kata yang diinputkan user lebih dari sama dengan 3 maka tampilkan urutan huruf setiap kata pada kalimat secara terbalik
        cout << "Jumlah kata = " << HitungKata_151(InputKata_151) << endl;
        hasil_151 = BalikKata_151(InputKata_151);
        cout << "Kalimat yang dibalik menjadi " << hasil_151 << endl;
    }
    
    return 0;
}
