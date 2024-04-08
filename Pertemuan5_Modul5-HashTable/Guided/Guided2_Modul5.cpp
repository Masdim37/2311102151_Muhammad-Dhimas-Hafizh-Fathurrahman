#include <iostream>
#include <string>
#include <vector>

using namespace std;

//Deklarasi isi tabel sebanyak 11
const int TABLE_SIZE = 11;

string name;
string phone_number;

//Deklarasi class HashNode
class HashNode{
    public:
    string name;
    string phone_number;

    //deklarasi konstruktor HashNode yang digunakan untuk membuat objek HashNode dengan parameter nama dan nomor telepon
    HashNode(string name, string phone_number){
        this->name = name;
        this->phone_number = phone_number;
    }
};

//Deklarasi class HashMap
class HashMap{
    private:
    //inisialisasi array table dengan ukuran TABLE_SIZE yang setiap elemen dari array tersebut merupakan sebuah vektor yang menyimpan pointer ke HashNode.
    vector<HashNode*> table[TABLE_SIZE];

    public:
    //fungsi hashFunc untuk menghitung nilai hash dari sebuah string key_151
    int hashFunc(string key){
        int hash_val = 0;
        for(char c : key){
            hash_val += c;
        }
    return hash_val % TABLE_SIZE;
    }

    //Prosedur insert untuk menambahkan data 
    void insert(string name, string phone_number){
        int hash_val = hashFunc(name);

        for(auto node : table[hash_val]){
            if(node->name == name){
                node->phone_number = phone_number;
                return;
            }
        }
        table[hash_val].push_back(new HashNode(name, phone_number));
    }

    //Prosedur remove untuk menghapus data tertentu berdasarkan key nama yang diinputkan user.
    void remove(string name){
        int hash_val = hashFunc(name);

        for(auto it = table[hash_val].begin(); it != table[hash_val].end(); it++){
            if((*it)->name == name){
                table[hash_val].erase(it);
                return;
            }
        }
    }

    //fungsi searchByName untuk mencari data nomor telepon berdasarkan key nama yang diinputkan user.
    string searchByName(string name){
        int hash_val = hashFunc(name);
        for(auto node : table[hash_val]){
            if(node->name == name){
                return node->phone_number;
            }
        }
        return "";
    }

    //prosedur print() untuk menampilkan data yang tersimpan dalam tabel 
    void print(){
        for(int i = 0; i < TABLE_SIZE; i++){
            cout << i << ": ";
            for(auto pair : table[i]){
                if(pair != nullptr){
                    cout << "[" << pair->name << ", " << pair->phone_number << "]";
                }
            }
            cout << endl;
        }
    }
};

int main(){
    //deklarasik objek employee_map dari kelas HashMap
    HashMap employee_map;

    //insertion
    employee_map.insert("Mistah", "1234");
    employee_map.insert("Pastah", "5678");
    employee_map.insert("Ghana", "91011");

    //Search by name
    cout << "Nomor HP Mistah : " << employee_map.searchByName("Mistah") << endl;
    cout << "Nomor HP Pastah : " << employee_map.searchByName("Pastah") << endl;

    //remove
    employee_map.remove("Mistah");

    //search by name
    cout << "Nomor HP Mistah setelah dihapus : " << employee_map.searchByName("Mistah") << endl << endl;

    //print
    employee_map.print();

    return 0;
}