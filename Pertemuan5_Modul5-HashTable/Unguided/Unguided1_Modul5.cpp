#include<iostream>
#include<vector> 
#include<iomanip>

using namespace std;

//Deklarasi isi tabel sebanyak 100
const int TableSize_151 = 100;

//Deklarasi class HashNode_151
class HashNode_151{
    public:
    string nama_151;
    string NIM_151;
    int nilai_151;

    //deklarasi konstruktor HashNode_151 yang digunakan untuk membuat objek HashNode_151 dengan parameter nama, nim, dan nilai
    HashNode_151(string name_151, string NIM_151, int grade_151){
        this->nama_151 = name_151;
        this->NIM_151 = NIM_151;
        this->nilai_151 = grade_151;
    }
};

//Deklarasi class HashMap_151
class HashMap_151{
    private:
    //array table yang berisi vektor dari pointer ke HashNode_151, 
    //yang digunakan sebagai wadah untuk menyimpan data secara terorganisir berdasarkan hasil hashing dari kunci (key).
    vector<HashNode_151*> table[TableSize_151];

    public:
    //Fungsi hashFunc_151 untuk menghitung nilai hash dari sebuah string key_151
    int hashFunc_151(string key_151){
        int hashValue_151 = 0;
        for(char c : key_151){
            hashValue_151 += c;
        }
        return hashValue_151 % TableSize_151;
    }

    //prosedur Tambah_151 untuk menambah data baru kedalam tabel
    void Tambah_151(string name_151, string NIM_151, int grade_151){
        int hashValue_151 = hashFunc_151(name_151); //inisialisasi nilai hash

        //perulangan for-each yang memeriksa setiap node atau isi tabel
        for(auto node : table[hashValue_151]){
            if(node->nama_151 == name_151){ //jika nama_151 dari node saat ini sama dengan inputan name_151, maka
                node->NIM_151 = NIM_151; //ubah nim node saat ini dengan inputan nim baru
                node->nilai_151 = grade_151; //ubah nilai saat ini dengan inputan nilai baru
                return;
            }
        }
        //jika tidak terdapat node dengan nama yang sama, maka buat node baru
        table[hashValue_151].push_back(new HashNode_151(name_151, NIM_151, grade_151));
    }

    //fungsi CekData_151 untuk mengecek data tertentu dalam tabel apakah ada atau tidak
    bool CekData_151(string name_151){
        int hashValue_151 = hashFunc_151(name_151); //inisialisasi nilai hash

        //perulangan for-each yang memeriksa setiap node atau isi tabel
        for(auto node = table[hashValue_151].begin(); node != table[hashValue_151].end(); node++){
            if((*node)->nama_151 == name_151){  //jika nama dari node saat ini sama dengan inputan name_151, maka
                return true; //kembalikan true
            } 
        }
        return false; //kembalikan false jika nama dari node saat ini tidak sama dengan inputan name_151
    }

    //fungsi IsEmpty_151 untuk mengecek apakah tabel kosong atau tidak 
    bool IsEmpty_151() {
        for (int i = 0; i < TableSize_151; i++) {
            if (!table[i].empty()) {
                return false; // Jika ditemukan tabel tidak kosong, kembalikan false
            }
        }
        return true; // Jika tabel kosong, kembalikan true
    }

    //prosedur Hapus_151 untuk menghapus data tertentu yang ada didalam tabel
    void Hapus_151(string name_151){
        int hashValue_151 = hashFunc_151(name_151); //inisialisasi nilai hash

        //perulangan for-each yang memeriksa setiap node atau isi tabel
        for(auto node = table[hashValue_151].begin(); node != table[hashValue_151].end(); node++){
            if((*node)->nama_151 == name_151){ //jika nama dari node saat ini sama dengan inputan name_151, maka
                table[hashValue_151].erase(node); //hapus node saat ini
                return;
            } else { //jika nama dari node saat ini tidak sama dengan inputan name_151, maka tampilkan output
                cout << "Data mahasiswa " << name_151 << " tidak ditemukan" << endl;
            }
        }
    }

    //prosedur SearchByNIM_151 untuk mencari data tertentu berdasarkan NIM
    void SearchByNIM_151(string NIM_151){
        bool ketemu = false; //deklarasi variable bool ketemu sebagai false
        cout << "-------------- HASIL PENCARIAN --------------" << endl;
        cout << "---------------------------------------------" << endl;
        cout << "|" << left << setw(14) << "Nama" << "|" << left << setw(14) << "NIM" << "|" << left << setw(13) << "Nilai" << "|" << endl;
        cout << "---------------------------------------------" << endl;
        for(int i=0; i < TableSize_151; i++){
            //perulangan for-each yang memeriksa setiap node atau isi tabel
            for(auto node : table[i]){
                if(node->NIM_151 == NIM_151){ //jika nim dari node saat ini sama dengan inputan NIM_151, maka tampilkan data
                    cout << "|" << left << setw(14) << node->nama_151 << "|" << left << setw(14) << node->NIM_151 << "|" << left << setw(13) << node->nilai_151 << "|" << endl;
                    ketemu = true; //ubah bool ketemu menjadi true
                }
            }
        }
        if(!ketemu){ //jika nim dari node saat ini tidak sama dengan inputan NIM_151, maka tampilkan output
            cout << "Data mahasiswa dengan NIM " << NIM_151 << " tidak ditemukan" << endl;
        }
        cout << "---------------------------------------------" << endl;
    }

    //prosedur SearchByGrade_151 untuk mencari data tertentu berdasarkan rentang nilai
    void SearchByGrade_151(int min_151, int max_151){
        bool ketemu = false; //deklarasi variable bool ketemu sebagai false
        cout << "-------------- HASIL PENCARIAN --------------" << endl;
        cout << "---------------------------------------------" << endl;
        cout << "|" << left << setw(14) << "Nama" << "|" << left << setw(14) << "NIM" << "|" << left << setw(13) << "Nilai" << "|" << endl;
        cout << "---------------------------------------------" << endl;
        for (int i=0; i < TableSize_151; i++){
            //perulangan for-each yang memeriksa setiap node atau isi tabel
            for(auto node : table[i]){
                if(node->nilai_151 >= min_151 && node->nilai_151 <= max_151){ //jika nilai dari node saat ini lebih dari sama dengan inputan min_151 dan kurang dari sama degan max_151, maka tampilkan data  
                    cout << "|" << left << setw(14) << node->nama_151 << "|" << left << setw(14) << node->NIM_151 << "|" << left << setw(13) << node->nilai_151 << "|" << endl;
                    ketemu = true; //ubah bool ketemu menjadi true
                }
            }
        }
        if(!ketemu){ //jika nilai dari node saat ini tidak lebih dari sama dengan inputan min_151 dan tidak kurang dari sama degan max_151, maka tampilkan output
            cout << "Data mahasiswa dengan rentang nilai " << min_151 << " - " << max_151 << " tidak ditemukan" << endl;
        }
        cout << "---------------------------------------------" << endl;
    }

    //prosedur TampilData_151 untuk menampilkan tabel
    void TampilData_151(){
        for(int i=0; i < TableSize_151; i++){
            //perulangan for-each yang memeriksa setiap node atau isi tabel
            for(auto node : table[i]){ //tampilkan data setiap node 
            cout << "|" << left << setw(14) << node->nama_151 << "|" << left << setw(14) << node->NIM_151 << "|" << left << setw(13) << node->nilai_151 << "|" << endl;
            }
        }
        cout << "---------------------------------------------" << endl;
    }
};

int main(){
    //menggunakan class
    HashMap_151 StudentMap;
    //deklarasi variablel yang diperlukan
    int choose_151, grade_151, GradeMin_151, GradeMax_151;
    string name_151, NIM_151;
    char yakin_151;
    //tag Menu Utama
    MenuUtama:
    cout << "--------------- DATA MAHASISWA --------------" << endl;
    cout << "| 1. Tambah Data                            |" << endl;
    cout << "| 2. Hapus Data                             |" << endl;
    cout << "| 3. Cari Data Berdasarkan NIM              |" << endl;
    cout << "| 4. Cari Data Berdasarkan Nilai            |" << endl;
    cout << "| 5. Tampilkan Data                         |" << endl;
    cout << "| 6. Keluar                                 |" << endl;
    cout << "---------------------------------------------" << endl;
    cout << "Masukkan pilihan anda = ";
    cin >> choose_151;
    cout << endl;

    switch(choose_151){ //percabangan switchcase berdasarkan inputan variabel choose_151
        case 1: //jika memilih 1, maka tambah data
            cout << "---------------- TAMBAH DATA ----------------" << endl;
            cout << "Masukkan nama mahasiswa = "; cin >> name_151;
            cout << "Masukkan NIM = "; cin >> NIM_151;
            cout << "Masukkan nilai mahasiswa = "; cin >> grade_151;
            StudentMap.Tambah_151(name_151, NIM_151, grade_151); //pemanggilan metode Tambah_151 pada objek StudentMap dari kelas HashMap_151
            cout << "Data mahasiswa " << name_151 << " berhasil ditambahkan" << endl;
            cout << endl;
            goto MenuUtama; //kembali ke Menu Utama
            break;
        case 2: //jika memilih 2, maka hapus data
            cout << "----------------- HAPUS DATA ----------------" << endl;
            if(StudentMap.IsEmpty_151() == false){ //jika metode IsEmpty_151 pada objek StudentMap dari kelas HashMap_151 bernilai false, maka lanjutkan
                cout << "Masukkan nama mahasiswa yang ingin dihapus = "; cin >> name_151;
                StudentMap.CekData_151(name_151); //pemanggilan metode CekData_151 pada objek StudentMap dari kelas HashMap_151
                if(StudentMap.CekData_151(name_151) == true){ //jika metode CekData_151 bernilai true, maka lanjutkan
                    cout << "Apakah anda yakin unuk menghapus data mahasiswa " << name_151 << "? [y/n] = "; cin >> yakin_151;
                    if(yakin_151 == 'y' || yakin_151 == 'Y'){
                        StudentMap.Hapus_151(name_151); //pemanggilan metode Hapus_151 pada objek StudentMap dari kelas HashMap_151
                        cout << "Data mahasiswa " << name_151 << " berhasil dihapus" << endl;
                    } else if(yakin_151 == 'n' || yakin_151 == 'N'){
                        cout << "Aksi dibatalkan" << endl;
                    }
                } else { //jika data name_151 tidak ditemukan pada tabel, maka tampilkan output
                    cout << "Data mahasiswa " << name_151 << " tidak ditemukan" << endl;
                }
            } else { //jika metode IsEmpty bernilai true, maka tabel masih kosong
                cout << "Tabel masih kosong!" << endl;
            }
            cout << endl;
            goto MenuUtama; //kembali ke Menu Utama
            break;
        case 3: //jika memilih 3, maka cari data berdasarkan NIM
            cout << "--------- CARI DATA BERDASARKAN NIM ---------" << endl;
            if(StudentMap.IsEmpty_151() == false){ //jika metode IsEmpty_151 pada objek StudentMap dari kelas HashMap_151 bernilai false, maka lanjutkan
                cout << "Masukkan NIM = "; cin >> NIM_151;
                cout << endl;
                StudentMap.SearchByNIM_151(NIM_151); //pemanggilan metode SearchByNIM_151 pada objek StudentMap dari kelas HashMap_151
            } else { //jika metode IsEmpty bernilai true, maka tabel masih kosong
                cout << "Tabel masih kosong!" << endl;
            }
            cout << endl;
            goto MenuUtama; //kembali ke Menu Utama
            break;
        case 4: //jika memilih 4, maka cari data berdasarkan nilai
            cout << "-------- CARI DATA BERDASARKAN NILAI --------" << endl;
            if(StudentMap.IsEmpty_151() == false){ //jika metode IsEmpty_151 pada objek StudentMap dari kelas HashMap_151 bernilai false, maka lanjutkan
                cout << "Masukkan rentang nilai minimum = "; cin >> GradeMin_151;
                cout << "Masukkan rentang nilai maksimum = "; cin >> GradeMax_151;
                cout << endl;
                StudentMap.SearchByGrade_151(GradeMin_151,GradeMax_151); //pemanggilan metode SearchByGrade_151 pada objek StudentMap dari kelas HashMap_151
            } else { //jika metode IsEmpty bernilai true, maka tabel masih kosong
                cout << "Tabel masih kosong!" << endl;
            }
            cout << endl;
            goto MenuUtama; //kembali ke Menu Utama
            break;
        case 5: //jika memilih 5, maka tampilkan data
            cout << "---------------- TAMPIL DATA ----------------" << endl;
            if(StudentMap.IsEmpty_151() == false){ //jika metode IsEmpty_151 pada objek StudentMap dari kelas HashMap_151 bernilai false, maka lanjutkan
                cout << "---------------------------------------------" << endl;
                cout << "|" << left << setw(14) << "Nama" << "|" << left << setw(14) << "NIM" << "|" << left << setw(13) << "Nilai" << "|" << endl;
                cout << "---------------------------------------------" << endl;
                StudentMap.TampilData_151(); //pemanggilan metode TampilData_151 pada objek StudentMap dari kelas HashMap_151
            } else { //jika metode IsEmpty bernilai true, maka tabel masih kosong
                cout << "Tabel masih kosong!" << endl;
            }
            cout << endl;
            goto MenuUtama; //kembali ke Menu Utama
            break;
        case 6: //jika memilih 6, maka keluar dari program
            cout << "Anda keluar dari program" << endl;
            return 0;
        default: //opsi jika inputan pilihan tidak tersedia
            cout << "Pilihan anda tidak tersedia" << endl;
            cout << endl;
            goto MenuUtama; //kembali ke Menu Utama
            break;
    }
}