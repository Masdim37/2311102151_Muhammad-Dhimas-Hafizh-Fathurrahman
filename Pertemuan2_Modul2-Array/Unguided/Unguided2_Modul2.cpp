#include <iostream>

using namespace std;

int main(){
    int X_151, Y_151, Z_151;
    cout << "--- Program Input Array 3 Dimensi ---" << endl;
    //Input ukuran dimensi array
    cout << "Masukkan ukuran dimensi x (lapisan) = "; cin >> X_151;
    cout << "Masukkan ukuran dimensi y (baris) = "; cin >> Y_151;
    cout << "Masukkan ukuran dimensi z (kolom) = "; cin >> Z_151;
    cout << endl;

    //Deklarasi array 3 dimensi
    int Array_151[X_151][Y_151][Z_151];

    //Input elemen array
    cout << "- Inputkan nilai masing-masing elemen array -" << endl;
    for(int i=0; i<X_151; i++){
        for(int j=0; j<Y_151; j++){
            for(int k=0; k<Z_151; k++){
                cout << "Input array[" << i << "][" << j << "][" << k << "] = ";
                cin >> Array_151[i][j][k];
            }
        }
        cout << endl;
    }

    //Output data array
    cout << "- Data Array Yang Diinputkan -" << endl;
    for(int i=0; i<X_151; i++){
        cout << "Data array lapisan ke-" << i+1 << endl;
        for(int j=0; j<Y_151; j++){
            for(int k=0; k<Z_151; k++){
                cout << "Data array[" << i << "][" << j << "][" << k << "] = " << Array_151[i][j][k] << endl;
            }
        }
        cout << endl;
    }

    //Tampilan Array dalam bentuk matriks
    cout << "- Tampilan array 3 dimensi dalam bentuk matriks -" << endl;
    for(int i=0; i<X_151; i++){
        cout << "Matriks lapisan ke-" << i+1 << endl;
        for(int j=0; j<Y_151; j++){
            for(int k=0; k<Z_151; k++){
                cout << Array_151[i][j][k] << " " << ends;
            }
            cout << endl;
        }
        cout << endl;
    }

    return 0;
}