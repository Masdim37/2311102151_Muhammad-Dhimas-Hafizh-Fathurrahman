#include<iostream>
#include<vector> 
#include<iomanip>

using namespace std;

const int TableSize_151 = 100;

string name_151, NIM_151;
int grade_151;
class HashNode_151{
    public:
    string nama_151;
    string NIM_151;
    int nilai_151;

    HashNode_151(string name_151, string NIM_151, int grade_151){
        this->nama_151 = name_151;
        this->NIM_151 = NIM_151;
        this->nilai_151 = grade_151;
    }
};

class HashMap_151{
    private:
    vector<HashNode_151*> table[TableSize_151];

    public:
    int hashFunc_151(string key_151){
        int hashValue_151 = 0;
        for(char c : key_151){
            hashValue_151 += c;
        }
        return hashValue_151 % TableSize_151;
    }

    void Tambah_151(string name_151, string NIM_151, int grade_151){
        int hashValue_151 = hashFunc_151(name_151);

        for(auto node : table[hashValue_151]){
            if(node->nama_151 == name_151){
                node->NIM_151 = NIM_151;
                node->nilai_151 = grade_151;
                return;
            }
        }
        table[hashValue_151].push_back(new HashNode_151(name_151, NIM_151, grade_151));
    }

    bool CekData_151(string name_151){
        int hashValue_151 = hashFunc_151(name_151);

        for(auto it = table[hashValue_151].begin(); it != table[hashValue_151].end(); it++){
            if((*it)->nama_151 == name_151){
                return true;
            } 
        }
        return false;
    }

    bool IsEmpty_151() {
        for (int i = 0; i < TableSize_151; i++) {
            if (!table[i].empty()) {
                return false; // Jika ditemukan vektor tidak kosong, kembalikan false
            }
        }
        return true; // Jika semua vektor kosong, kembalikan true
    }

    void Hapus_151(string name_151){
        int hashValue_151 = hashFunc_151(name_151);

        for(auto it = table[hashValue_151].begin(); it != table[hashValue_151].end(); it++){
            if((*it)->nama_151 == name_151){
                table[hashValue_151].erase(it);
                return;
            } else {
                cout << "Data mahasiswa " << name_151 << " tidak ditemukan" << endl;
            }
        }
    }

    void SearchByNIM_151(string NIM_151){
        bool ketemu = false;
        cout << "-------------- HASIL PENCARIAN --------------" << endl;
        cout << "---------------------------------------------" << endl;
        cout << "|" << left << setw(14) << "Nama" << "|" << left << setw(14) << "NIM" << "|" << left << setw(13) << "Nilai" << "|" << endl;
        cout << "---------------------------------------------" << endl;
        for(int i=0; i < TableSize_151; i++){
            for(auto node : table[i]){
                if(node->NIM_151 == NIM_151){
                    cout << "|" << left << setw(14) << node->nama_151 << "|" << left << setw(14) << node->NIM_151 << "|" << left << setw(13) << node->nilai_151 << "|" << endl;
                    ketemu = true;
                }
            }
        }
        if(!ketemu){
            cout << "Data mahasiswa dengan NIM " << NIM_151 << " tidak ditemukan" << endl;
        }
        cout << "---------------------------------------------" << endl;
    }

    void SearchByGrade_151(int min_151, int max_151){
        bool ketemu=false;
        cout << "-------------- HASIL PENCARIAN --------------" << endl;
        cout << "---------------------------------------------" << endl;
        cout << "|" << left << setw(14) << "Nama" << "|" << left << setw(14) << "NIM" << "|" << left << setw(13) << "Nilai" << "|" << endl;
        cout << "---------------------------------------------" << endl;
        for (int i=0; i < TableSize_151; i++){
            for(auto node : table[i]){
                if(node->nilai_151 >= min_151 && node->nilai_151 <= max_151){    
                    cout << "|" << left << setw(14) << node->nama_151 << "|" << left << setw(14) << node->NIM_151 << "|" << left << setw(13) << node->nilai_151 << "|" << endl;
                    ketemu = true;
                }
            }
        }
        if(!ketemu){
            cout << "Data mahasiswa dengan rentang nilai " << min_151 << " - " << max_151 << " tidak ditemukan" << endl;
        }
        cout << "---------------------------------------------" << endl;
    }

    void TampilData_151(){
        for(int i=0; i < TableSize_151; i++){
            for(auto node : table[i]){
            cout << "|" << left << setw(14) << node->nama_151 << "|" << left << setw(14) << node->NIM_151 << "|" << left << setw(13) << node->nilai_151 << "|" << endl;
            }
        }
        cout << "---------------------------------------------" << endl;
    }
};

int main(){
    HashMap_151 StudentMap;
    int choose_151, grade_151, GradeMin_151, GradeMax_151;
    string name_151, NIM_151;
    char yakin_151;
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

    switch(choose_151){
        case 1:
            cout << "---------------- TAMBAH DATA ----------------" << endl;
            cout << "Masukkan nama mahasiswa = "; cin >> name_151;
            cout << "Masukkan NIM = "; cin >> NIM_151;
            cout << "Masukkan nilai mahasiswa = "; cin >> grade_151;
            StudentMap.Tambah_151(name_151, NIM_151, grade_151);
            cout << "Data mahasiswa " << name_151 << " berhasil ditambahkan" << endl;
            cout << endl;
            goto MenuUtama;
            break;
        case 2:
            cout << "----------------- HAPUS DATA ----------------" << endl;
            if(StudentMap.IsEmpty_151() == false){
                cout << "Masukkan nama mahasiswa yang ingin dihapus = "; cin >> name_151;
                StudentMap.CekData_151(name_151);
                if(StudentMap.CekData_151(name_151) == true){
                    cout << "Apakah anda yakin unuk menghapus data mahasiswa " << name_151 << "? [y/n] = "; cin >> yakin_151;
                    if(yakin_151 == 'y' || yakin_151 == 'Y'){
                        StudentMap.Hapus_151(name_151);
                        cout << "Data mahasiswa " << name_151 << " berhasil dihapus" << endl;
                    } else if(yakin_151 == 'n' || yakin_151 == 'N'){
                        cout << "Aksi dibatalkan" << endl;
                    }
                } else {
                    cout << "Data mahasiswa " << name_151 << " tidak ditemukan" << endl;
                }
            } else {
                cout << "Tabel masih kosong!" << endl;
            }
            cout << endl;
            goto MenuUtama;
            break;
        case 3:
            cout << "--------- CARI DATA BERDASARKAN NIM ---------" << endl;
            if(StudentMap.IsEmpty_151() == false){
                cout << "Masukkan NIM = "; cin >> NIM_151;
                cout << endl;
                StudentMap.SearchByNIM_151(NIM_151);
            } else {
                cout << "Tabel masih kosong!" << endl;
            }
            cout << endl;
            goto MenuUtama;
            break;
        case 4:
            cout << "-------- CARI DATA BERDASARKAN NILAI --------" << endl;
            if(StudentMap.IsEmpty_151() == false){
                cout << "Masukkan rentang nilai minimum = "; cin >> GradeMin_151;
                cout << "Masukkan rentang nilai maksimum = "; cin >> GradeMax_151;
                cout << endl;
                StudentMap.SearchByGrade_151(GradeMin_151,GradeMax_151);
            } else {
                cout << "Tabel masih kosong!" << endl;
            }
            cout << endl;
            goto MenuUtama;
            break;
        case 5:
            cout << "---------------- TAMPIL DATA ----------------" << endl;
            if(StudentMap.IsEmpty_151() == false){
                cout << "---------------------------------------------" << endl;
                cout << "|" << left << setw(14) << "Nama" << "|" << left << setw(14) << "NIM" << "|" << left << setw(13) << "Nilai" << "|" << endl;
                cout << "---------------------------------------------" << endl;
                StudentMap.TampilData_151();
            } else {
                cout << "Tabel masih kosong!" << endl;
            }
            cout << endl;
            goto MenuUtama;
            break;
        case 6:
            cout << "Anda keluar dari program" << endl;
            return 0;
        default:
            cout << "Pilihan anda tidak tersedia" << endl;
            cout << endl;
            goto MenuUtama;
            break;
    }
}