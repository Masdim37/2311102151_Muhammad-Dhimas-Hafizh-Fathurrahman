#include <iostream>

using namespace std;

//Struct Student_151 yang berisi data nama string, data kelas char, dan data NIS integer
struct Student_151 {
    string Name_151;
    char Class_151;
    int NIS_151;
};

//Class Subject_151 yang berisi data integer nilai matematika, IPA, dan Bahasa Indonesia
class Subject_151 {
    public:
        int Math_151;
        int Science_151;
        int Indonesian_151;
};

//fungsi RataRataNilai_151 yang digunakan untuk menghitung nilai rata-rata
float RataRataNilai_151 (float Rata_151, int MTK_151, int IPA_151, int INDO_151){
    Rata_151 = (MTK_151 + IPA_151 + INDO_151) / 3;
    return Rata_151;
}

int main(){
    int JumlahMurid_151 = 2; 
    float RataRata_151;

    //Menggunakan struct
    Student_151 Murid[JumlahMurid_151];

    //menggunakan class
    Subject_151 Nilai[JumlahMurid_151];

    //Pengisian data ke struct dan class menggunakan perulangan for
    for(int i = 0; i < JumlahMurid_151; i++){
        cout << "Masukkan data murid ke "<< i+1 << endl;
        cout << "Nama = "; 
        cin >> Murid[i].Name_151; //menginput nama murid kedalam array Murid indeks ke i pada atribut Name_151 yang ada pada struct Student_151
        cout << "Kelas = ";
        cin >> Murid[i].Class_151; //menginput kelas murid kedalam array Murid indeks ke i pada atribut Class_151 yang ada pada struct Student_151
        cout << "Nomor Induk Siswa = ";
        cin >> Murid[i].NIS_151; //menginput NIS murid kedalam array Murid indeks ke i pada atribut NIS_151 yang ada pada struct Student_151
        cout << "Masukkan nilai mata pelajaran matematika = ";
        cin >> Nilai[i].Math_151; //menginput nilai matematika kedalam array Nilai indeks ke i pada atribut Math_151 yang ada pada class Subject_151
        cout << "Masukkan nilai mata pelajaran IPA = ";
        cin >> Nilai[i].Science_151; //menginput nilai IPA kedalam array Nilai indeks ke i pada atribut Science_151 yang ada pada class Subject_151
        cout << "Masukkan nilai mata pelajaran Bahasa Indonesia = ";
        cin >> Nilai[i].Indonesian_151; //menginput nilai Bahasa Indonesia kedalam array Nilai indeks ke i pada atribut Indonesian_151 yang ada pada class Subject_151
        cout << endl;
    }

    cout << "--- REKAPITULASI NILAI MURID ---" << endl;
    //Menampilkan data yang ada pada struct & class
    for(int i = 0; i < JumlahMurid_151; i++){
        cout << "Murid ke " << i+1 << endl;
        cout << "Nama = " << Murid[i].Name_151 << endl; //menampilkan nama murid yang ada pada array Murid indeks ke i pada atribut Name_151 yang ada pada struct Student_151
        cout << "Kelas = " << Murid[i].Class_151 << endl; //menampilkan kelas murid yang ada pada array Murid indeks ke i pada atribut Class_151 yang ada pada struct Student_151
        cout << "Nomor Induk Siswa (NIS) = " << Murid[i].NIS_151 << endl;  //menampilkan NIS murid yang ada pada array Murid indeks ke i pada atribut NIS_151 yang ada pada struct Student_151
        cout << "Nilai mata pelajaran Matematika = " << Nilai[i].Math_151 << endl; //menampilkan nilai matematika murid yang ada pada array Nilai indeks ke i pada atribut Math_151 yang ada pada class Subject_151
        cout << "Nilai mata pelajaran IPA = " << Nilai[i].Science_151 << endl;//menampilkan nilai IPA murid yang ada pada array Nilai indeks ke i pada atribut Science_151 yang ada pada class Subject_151
        cout << "Nilai mata pelajaran Bahasa Indonesia = " << Nilai[i].Indonesian_151 << endl; //menampilkan nilai Bahasa Indonesia murid yang ada pada array Nilai indeks ke i pada atribut Indonesian_151 yang ada pada class Subject_151
        cout << "Rata - rata nilai = " << RataRataNilai_151(RataRata_151, Nilai[i].Math_151, Nilai[i].Science_151, Nilai[i].Indonesian_151) << endl; //memanggil fungsi RataRataNilai_151 untuk menghitung nilai rata-rata
        cout << endl;
    }

    return 0;
}