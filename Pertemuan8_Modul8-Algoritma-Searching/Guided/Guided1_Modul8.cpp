#include <iostream>

using namespace std;

int main(){
    int n = 10;
    int data[10] = {9, 4, 1, 7, 5, 12, 4, 13, 3, 10};
    int cari = 10;
    bool ketemu = false;
    int i;

    for(i=0; i < n; i++){
        if(data[i] == cari){
            ketemu = true;
            break;
        }
    }

    cout << "Program Sequential Search" << endl;
    cout << "Data = {9, 4, 1, 7, 5, 12, 4, 13, 3, 10}" << endl;

    if(ketemu){
        cout << "\nAngka " << cari << " ditemukan pada indeks ke " << i << endl; 
    } else {
        cout << "Data tidak ditemukan!" << endl;
    }

    return 0;
}