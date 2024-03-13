#include <iostream>

using namespace std;

//Program Input Array 3 Dimensi
int main(){
    //Deklarasi Array
    int arr[2][3][3];

    //Input Elemen
    for(int x=0; x<2; x++){
        for(int y=0; y<3; y++){
            for(int z=0; z<3; z++){
                cout << "Input array[" << x << "][" << y << "][" << z << "] = ";
                cin >> arr[x][y][z];
            }
        }
        cout << endl;
    }

    //Output Array
    for(int x=0; x<2; x++){
        for(int y=0; y<3; y++){
            for(int z=0; z<3; z++){
                cout << "Data array[" << x << "][" << y << "][" << z << "] = " << arr[x][y][z] << endl;
            }
        }
    }

    //Tampilan Array
    for(int x=0; x<2; x++){
        for(int y=0; y<3; y++){
            for(int z=0; z<3; z++){
                cout << arr[x][y][z] << " " << ends;
            }
            cout << endl;
        }
        cout << endl;
    }

    return 0;
}