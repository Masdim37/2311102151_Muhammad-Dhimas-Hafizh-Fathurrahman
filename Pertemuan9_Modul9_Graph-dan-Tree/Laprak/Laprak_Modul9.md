# <h1 align="center">Laporan Praktikum Modul 9 - Graph and Tree</h1>
<p align="center">Muhammad Dhimas Hafizh Fathurrahman - 2311102151</p>

## Dasar Teori
### A. Graph
Graf adalah sekumpulan simpul/vertex/titik/node didalam bidang 2 dimemnsi yang dihubungkan dengan sekumpulan garis atau sisi. Teori graf lahir pada tahun 1736 melalui tulisan Euler yang berisi tentang upaya pemecahan masalah jembatan Konigsberg yang sangat terkenal di Eropa. Graph dapat digunakan untuk merepresentasikan objek-objek diskrit dan hubungan antara objek-objek tersebut. Secara matematis, Graph dinyatakan dengan :
<br>G = (V, E)
<br>Dengan G menyatakan graph, V menyatakan simpul (vertex), dan E menyatakan sisi (edge)
<br>Simpul pada graf dapat dinomori dengan huruf seperti a, b, c, d, dst atau bisa dengan bilangan asli 1, 2, 3, dst atau gabungan keduanya. Sedangkan sisi yang menghubungkan simpul a dan b dinyatakan dalam sepasang (a,b) atau dinyatakan dalam lambang e1, e2, e3, dst. Berikut merupakan contoh graf.

![Dhimas_Contoh-Graph](https://github.com/Masdim37/2311102151_Muhammad-Dhimas-Hafizh-Fathurrahman/blob/main/Pertemuan9_Modul9-Graph-dan-Tree/Laprak/Dhimas_Contoh-Graph.png)

Dalam kehidupan sehari-hari, graph digunakan untuk mencari rute terpendek pada GPS, memodelkan struktur internet dan routing data, perencanaan rute dan jadwal transportasi umum, dll.
<br>Terdapat beberapa jenis graph, antara lain sebagai berikut..

#### 1. Graph Berarah (Directed Graph)
Graph berarah adalah jenis graph di mana setiap sisi (edge) memiliki arah tertentu. Dalam graf berarah, sisi-sisi tersebut disebut panah (arc), yang menghubungkan sepasang simpul (vertex) dengan urutan tertentu, sehingga setiap urutan simpul mempunyai arti tersendiri. Berikut merupakan contoh graph berarah.

![Dhimas_Contoh-Graph-Berarah](https://github.com/Masdim37/2311102151_Muhammad-Dhimas-Hafizh-Fathurrahman/blob/main/Pertemuan9_Modul9-Graph-dan-Tree/Laprak/Dhimas_Contoh-Graph-Berarah.png)

#### 2. Graph Tak Berarah (Undirected Graph)
Graph tak berarah adalah jenis graf di mana setiap sisi (edge) tidak memiliki arah tertentu

## Guided 

### 1. Program Graph

```C++
#include <iostream>
#include <iomanip>

using namespace std;

//Deklarasi array simpul yang berisi nama-nama kota
string simpul[7] = {
    "Ciamis", "Bandung", "Bekasi", "Tasikmalaya", "Cianjur", "Purwokerto", "Yogyakarta"
};

//Deklarasi array busur 2 dimensi yang berisi bobot atau nilai antar kota
int busur[7][7]= {
    {0, 7, 8, 0, 0, 0, 0},
    {0, 0, 5, 0, 0, 15, 0},
    {0, 6, 0, 0, 5, 0, 0},
    {0, 5, 0, 0, 2, 4, 0},
    {23, 0, 0, 10, 0, 0, 8},
    {0, 0, 0, 0, 7, 0, 3},
    {0, 0, 0, 0, 9, 4, 0}
};

//Prosedur TampilGraph untuk menampilkan kota dengan bobot jarak ke kota lainnya
void TampilGraph(){
    for(int baris = 0; baris < 7; baris++){
        cout << " " << setiosflags(ios :: left) << setw(15) << simpul[baris] << " : ";
        for(int kolom = 0; kolom < 7; kolom++){
            if(busur[baris][kolom] != 0){
                cout << " " << simpul[kolom] << "(" << busur[baris][kolom] << ")";
            }
        } cout << endl;
    }
}

int main(){
    //Pemanggilan prosedur TampilGraph
    TampilGraph();

    return 0;
}
```

#### Deskripsi Program
Kode diatas merupakan program implementasi graph sederhana. Pada program ini terdapat beberapa simpul yang merepresentasikan nama-nama kota dan busur yang merepresentasikan bobot atau jarak antar kota. Pada awal program dideklarasikan array `simpul` dengan ukuran 7 yang berisi nama-nama kota. kemudian dideklarasikan array 2 dimensi bernama `busur` berukuran 7x7 yang berisi bobot atau nilai antar kota. Kemudian dideklarasikan prosedur bernama `TampilGraph` untuk menampilkan kota-kota beserta bobotnya dalam bentuk matriks. Pada int main() dipanggil prosedur `TampilGraph` untuk menampilkan matriks tersebut.

### 2. Program Tree
```C++
#include <iostream>
#include <iomanip>
    using namespace std;

//Deklarasi struct pohon yang nodenya berisi variabel data
struct Pohon{
    char data;
    Pohon *left, *right, *parent; //deklarasi node left, right, dan parent 
};
Pohon *root, *baru; //Deklarasi node root dan node baru

//Prosudr inisialisasi
void init(){
    root = NULL; //Menyatakan node root adalah NULL
}

//Fungsi isEmpty untuk memeriksa apakah tree kosong atau tidak
bool isEmpty(){
    return root == NULL;
}

//Prosedur buatNode untuk membuat node baru
void buatNode(char data){
    if (isEmpty())
    {
        root = new Pohon();
        root->data = data;
        root->left = NULL;
        root->right = NULL;
        root->parent = NULL;
        cout << "\n Node " << data << " berhasil dibuat sebagai root."
             << endl;
    }
    else
    {
        cout << "\n Tree sudah ada!" << endl;
    }
}

//Fungsi untuk membuat node child kiri
Pohon *insertLeft(char data, Pohon *node)
{
    if (isEmpty())
    {
        cout << "\n Buat tree terlebih dahulu!" << endl;
        return NULL;
    }
    else
    {
        if (node->left != NULL)
        {
            cout << "\n Node " << node->data << " sudah ada child kiri !" << endl;
                return NULL;
        }
        else
        {
            Pohon *baru = new Pohon();
            baru->data = data;
            baru->left = NULL;
            baru->right = NULL;
            baru->parent = node;
            node->left = baru;
            cout << "\n Node " << data << " berhasil ditambahkan ke child kiri " << baru->parent->data << endl;
                return baru;
        }
    }
}

//Fungsi untuk membuat node child kanan
Pohon *insertRight(char data, Pohon *node)
{
    if (isEmpty())
    {
        cout << "\n Buat tree terlebih dahulu!" << endl;
        return NULL;
    }
    else
    {
        if (node->right != NULL)
        {
            cout << "\n Node " << node->data << " sudah ada child kanan !" << endl;
                return NULL;
        }
        else
        {
            Pohon *baru = new Pohon();
            baru->data = data;
            baru->left = NULL;
            baru->right = NULL;
            baru->parent = node;
            node->right = baru;
            cout << "\n Node " << data << " berhasil ditambahkan ke child kanan " << baru->parent->data << endl;
                return baru;
        }
    }
}

//Prosedur untuk mengupdate nilai suatu node
void update(char data, Pohon *node)
{
    if (isEmpty())
    {
        cout << "\n Buat tree terlebih dahulu!" << endl;
    }
    else
    {
        if (!node)
        {
            cout << "\n Node yang ingin diganti tidak ada!!" << endl;
        }
        else
        {
            char temp = node->data;
            node->data = data;
            cout << "\n Node " << temp << " berhasil diubah menjadi "
                 << data << endl;
        }
    }
}

//Prosedur untuk menunjuk suatu node
void retrieve(Pohon *node)
{
    if (isEmpty())
    {
        cout << "\n Buat tree terlebih dahulu!" << endl;
    }
    else
    {
        if (!node)
        {
            cout << "\n Node yang ditunjuk tidak ada!" << endl;
        }
        else
        {
            cout << "\n Data node : " << node->data << endl;
        }
    }
}

//Prosedur untuk mencari suatu node kemudian menampilkan root, parent, sibling, dan child node tersebut
void find(Pohon *node)
{
    if (isEmpty())
    {
        cout << "\n Buat tree terlebih dahulu!" << endl;
    }
    else
    {
        if (!node)
        {
            cout << "\n Node yang ditunjuk tidak ada!" << endl;
        }
        else
        {
            cout << "\n Data Node : " << node->data << endl;
            cout << " Root : " << root->data << endl;
            if (!node->parent)
                cout << " Parent : (tidak punya parent)" << endl;
            else
                cout << " Parent : " << node->parent->data << endl;
            if (node->parent != NULL && node->parent->left != node &&
                node->parent->right == node)
                cout << " Sibling : " << node->parent->left->data << endl;
            else if (node->parent != NULL && node->parent->right != node && node->parent->left == node)
                cout << " Sibling : " << node->parent->right->data << endl;
            else
                cout << " Sibling : (tidak punya sibling)" << endl;
            if (!node->left)
                cout << " Child Kiri : (tidak punya Child kiri)" << endl;
            else
                cout << " Child Kiri : " << node->left->data << endl;
            if (!node->right)
                cout << " Child Kanan : (tidak punya Child kanan)" << endl;
            else
                cout << " Child Kanan : " << node->right->data << endl;
        }
    }
}

// Penelusuran (Traversal)
//Prosedur untuk menampilkan traversal secara pre order
void preOrder(Pohon *node = root)
{
    if (isEmpty())
    {
        cout << "\n Buat tree terlebih dahulu!" << endl;
    }
    else
    {
        if (node != NULL)
        {
            cout << " " << node->data << ", ";
            preOrder(node->left);
            preOrder(node->right);
        }
    }
}

//Prosedur untuk menampilkan traversal secara in order
void inOrder(Pohon *node = root)
{
    if (isEmpty())
    {
        cout << "\n Buat tree terlebih dahulu!" << endl;
    }
    else
    {
        if (node != NULL)
        {
            inOrder(node->left);
            cout << " " << node->data << ", ";
            inOrder(node->right);
        }
    }
}

//Prosedur untuk menampilkan traversal secara post order
void postOrder(Pohon *node = root)
{
    if (isEmpty())
    {
        cout << "\n Buat tree terlebih dahulu!" << endl;
    }
    else
    {
        if (node != NULL)
        {
            postOrder(node->left);
            postOrder(node->right);
            cout << " " << node->data << ", ";
        }
    }
}

//Prosedur untuk menhapus sebuah node didalam tree
void deleteTree(Pohon *node)
{
    if (isEmpty())
    {
        cout << "\n Buat tree terlebih dahulu!" << endl;
    }
    else
    {
        if (node != NULL)
        {
            if (node != root)
            {
                node->parent->left = NULL;
                node->parent->right = NULL;
            }
            deleteTree(node->left);
            deleteTree(node->right);
            if (node == root)
            {
                delete root;
                root = NULL;
            }
            else
            {
                delete node;
            }
        }
    }
}

//Prosedur untuk menghapus sub tree
void deleteSub(Pohon *node)
{
    if (isEmpty())
    {
        cout << "\n Buat tree terlebih dahulu!" << endl;
    }
    else
    {
        deleteTree(node->left);
        deleteTree(node->right);
        cout << "\n Node subtree " << node->data << " berhasil dihapus." << endl;
    }
}

//Prosedur untuk menghapus seluruh tree
void clear()
{
    if (isEmpty())
    {
        cout << "\n Buat tree terlebih dahulu!!" << endl;
    }
    else
    {
        deleteTree(root);
        cout << "\n Pohon berhasil dihapus." << endl;
    }
}

//Fungsi untuk memeriksa jumlah node (size) didalam tree
int size(Pohon *node = root)
{
    if (isEmpty())
    {
        cout << "\n Buat tree terlebih dahulu!!" << endl;
        return 0;
    }
    else
    {
        if (!node)
        {
            return 0;
        }
        else
        {
            return 1 + size(node->left) + size(node->right);
        }
    }
}

//Fungsi untuk memeriksa level atau aras (height) tree
int height(Pohon *node = root)
{
    if (isEmpty())
    {
        cout << "\n Buat tree terlebih dahulu!" << endl;
        return 0;
    }
    else
    {
        if (!node)
        {
            return 0;
        }
        else
        {
            int heightKiri = height(node->left);
            int heightKanan = height(node->right);
            if (heightKiri >= heightKanan)
            {
                return heightKiri + 1;
            }
            else
            {
                return heightKanan + 1;
            }
        }
    }
}

//Prosedur untuk memeriksa karakteristik tree
void characteristic()
{
    cout << "\n Size Tree : " << size() << endl;
    cout << " Height Tree : " << height() << endl;
    cout << " Average Node of Tree : " << size() / height() << endl;
}

int main()
{
    buatNode('A'); //buat node A sebagai root
    Pohon *nodeB, *nodeC, *nodeD, *nodeE, *nodeF, *nodeG, *nodeH, *nodeI, *nodeJ; //deklarasi node B-J
    
    nodeB = insertLeft('B', root), //tambah node B sebagai child kiri node A
    nodeC =  insertRight('C', root), //tambah node C sebagai child kanan node A
    nodeD = insertLeft('D', nodeB), //tambah node D sebagai child kiri node B
    nodeE = insertRight('E', nodeB), //tambah node e sebagai child kanan node B
    nodeF = insertLeft('F', nodeC), //tambah node F sebagai child kiri node C
    nodeG = insertLeft('G', nodeE), //tambah node G sebagai child kiri node E
    nodeH = insertRight('H', nodeE), //tambah node H sebagai child kanan node E
    nodeI = insertLeft('I', nodeG), //tambah node I sebagai child kiri node G
    nodeJ = insertRight('J', nodeG); //tambah node J sebagai child kanan node G

    update('Z', nodeC); //update (ubah) nama node C menjadi Z
    update('C', nodeC); //update (ubah) kembali nama node C menjadi C

    retrieve(nodeC); //Tunjuk node C

    find(nodeC); //Mencari node C dan menampilkan root, parent, sibling, dan child node tersebut

    characteristic(); //Menampilkan karakteristik tree

    //Menampilkan traversal tree secara pre order
    cout << "PreOrder : " << endl;
    preOrder(root);
    cout << "\n" << endl;

    //menampilkan traversal tree secara in order
    cout << "InOrder : " << endl;
    inOrder(root);
    cout << "\n" << endl;

    //menampilkan traversal tree secara post order
    cout << "PostOrder : " << endl;
    postOrder(root);
    cout << "\n" << endl;

    return 0;
}
```

#### Deskripsi Program
Kode diatas merupakan program implementasi tree atau pohon menggunakan struct.  


## Unguided 

Cantumkan NIM pada salah satu variabel di dalam program.
Contoh : int nama_22102003;

### 1. Buatlah program graph dengan menggunakan inputan user untuk menghitung jarak dari sebuah kota ke kota lainnya.
Berikut contoh output program :

![Dhimas_Contoh-Output-Unguided1](https://github.com/Masdim37/2311102151_Muhammad-Dhimas-Hafizh-Fathurrahman/blob/main/Pertemuan9_Modul9-Graph-dan-Tree/Laprak/Dhimas_Contoh-Output-Unguided1.png)

```C++
#include <iostream>
#include <iomanip>

using namespace std;

//Fungsi untuk menampilkan graph dalam format matriks
void TampilGraph_151(int JumlahSimpul_2311102151, string* NamaSimpul_2311102151, int** BobotSimpul_151) {
    //menampilkan baris pertama berupa simpul nama kota
    cout << setw(10) << " ";
    for (int i = 0; i < JumlahSimpul_2311102151; i++) {
        cout << setw(10) << NamaSimpul_2311102151[i];
    }
    cout << endl;

    // Menampilkan bobot kota secara matriks
    for (int baris_151 = 0; baris_151 < JumlahSimpul_2311102151; baris_151++) {
        cout << setw(10) << NamaSimpul_2311102151[baris_151];
        for (int kolom_151 = 0; kolom_151 < JumlahSimpul_2311102151; kolom_151++) {
            cout << setw(10) << BobotSimpul_151[baris_151][kolom_151];
        }
        cout << endl;
    }
}

int main() {
    int JumlahSimpul_2311102151;
    int Nomor_151 = 1;
    int Bobot_151;

    cout << "--- PROGRAM GRAPH SEDERHANA ---" << endl;

    //User menginputkan jumlah simpul (jumlah kota)
    cout << "Masukkan jumlah simpul = ";
    cin >> JumlahSimpul_2311102151;

    //membuat array NamaSimpul_2311102151 yang dialokasikan secara dinamis berdasarkan input jumlah simpul
    string* NamaSimpul_2311102151 = new string[JumlahSimpul_2311102151];

    //user memasukkan nama simpul (nama kota)
    cout << "--- Masukkan nama simpul ---" << endl; 
    for (int i = 0; i < JumlahSimpul_2311102151; i++) {
        cout << "Masukkan nama simpul " << Nomor_151++ << " = ";
        cin >> NamaSimpul_2311102151[i];
    }
    cout << endl;

    //membuat array BobotSimpul_151 yang dialokasikan secara dinamis berdasarkan input jumlah simpul
    int** BobotSimpul_151 = new int*[JumlahSimpul_2311102151];
    for (int i = 0; i < JumlahSimpul_2311102151; i++) {
        BobotSimpul_151[i] = new int[JumlahSimpul_2311102151]();
    }

    //user emasukkan bobot antar simpul
    cout << "--- Masukkan Bobot Antar Simpul ---" << endl;
    for (int i = 0; i < JumlahSimpul_2311102151; i++) {
        for (int j = 0; j < JumlahSimpul_2311102151; j++) {
            if (i != j) {
                cout << "Bobot " << NamaSimpul_2311102151[i] << " --> " << NamaSimpul_2311102151[j] << " = ";
                cin >> Bobot_151;
                BobotSimpul_151[i][j] = Bobot_151;
            }
        }
    }
    cout << endl;

    //memanggil fungsi TampilGraph_151
    TampilGraph_151(JumlahSimpul_2311102151, NamaSimpul_2311102151, BobotSimpul_151);

    return 0;
}
```

#### Output:

![Dhimas_Output-Unguided1](https://github.com/Masdim37/2311102151_Muhammad-Dhimas-Hafizh-Fathurrahman/blob/main/Pertemuan9_Modul9-Graph-dan-Tree/Laprak/Dhimas_Output-Unguided1.png)

#### Deskripsi Program
Kode diatas merupakan program penerapa graph sederhana. Pada awal program terdapat prosedur `TampilGraph_151` yang digunakan untuk menampilkan simpul-simpul (nama-nama kota) beserta busurnya (bobot atau nilai antar simpul). Pada int main() user diminta memasukkan jumlah simpul, kemudian disimpan pada variabel `JumlahSimpul_2311102151`. Kemudian program mendeklarasikan array dinamis bernama `NamaSimpul_2311102151[]` dengan ukuran nilai variabel `JumlahSimpul_2311102151`. Kemudian user diminta menginputkan nama-nama simpul yang kemudian disimpan pada array `NamaSimpul_2311102151[]` menggunakan perulangan. Kemudian program mendeklarasikan array dinamis 2 dimensi bernama `BobotSimpul_151[]` dengan ukuran nilai variabel `JumlahSimpul_2311102151`. Kemudian user diminta memasukkan bobot antar simpul yang kemudian nilainya dimasukkan menggunakan perulangan kedalam array `BobotSimpul_151[]`. Setelah itu program memanggil prosedur `TampilGraph_151` untuk menampilkan simpul-simpul beserta busurnya (bobot) dalam bentuk matriks.

### 2. Modifikasi guided tree diatas dengan program menu menggunakan input data tree dari user dan berikan fungsi tambahan untuk menampilkan node child dan descendant dari node yang diinput kan!

```C++
#include <iostream>
#include <iomanip>

using namespace std;

//Deklarasi struct Pohon_2311102151 yang berisi variabel data
struct Pohon_2311102151{
    char data;
    Pohon_2311102151 *left, *right, *parent; //deklarasi node left, right, dan parent didalam struct Pohon_2311102151
};

Pohon_2311102151 *root, *baru; //deklarasi node root dan baru

//Prosedur inisialisasi root sebagai NULL
void init_151(){
    root = NULL;
}

//Fugsi isEmpty_151 untuk memeriksa apakah tree kosong atau tidak
bool isEmpty_151(){
    return root == NULL;
}

//Prosedur BuatNode_151 untuk membuat node root
void BuatNode_151(char data_151){
    if (isEmpty_151()){
        root = new Pohon_2311102151();
        root->data = data_151;
        root->left = NULL;
        root->right = NULL;
        root->parent = NULL;
        cout << "\n Node " << data_151 << " berhasil dibuat sebagai root." << endl;
    }
}

//Fungsi untuk menambahkan node child kiri
Pohon_2311102151 *TambahKiri_151(char data_151, Pohon_2311102151 *node){
    if (!isEmpty_151()){
        if(node->left != NULL) {
            cout << "\n Node " << node->data << " sudah ada child kiri !" << endl;
            return NULL;
        } else {
            Pohon_2311102151 *baru = new Pohon_2311102151();
            baru->data = data_151;
            baru->left = NULL;
            baru->right = NULL;
            baru->parent = node;
            node->left = baru;
            cout << "\n Node " << data_151 << " berhasil ditambahkan ke child kiri " << baru->parent->data << endl;
            return baru;
        }
    }
}

//Fungsi untuk menambahkan node child kanan
Pohon_2311102151 *TambahKanan_151(char data_151, Pohon_2311102151 *node){
    if(!isEmpty_151()){
        if(node->right != NULL){
            cout << "\n Node " << node->data << " sudah ada child kanan !" << endl;
            return NULL;
        } else {
            Pohon_2311102151 *baru = new Pohon_2311102151();
            baru->data = data_151;
            baru->left = NULL;
            baru->right = NULL;
            baru->parent = node;
            node->right = baru;
            cout << "\n Node " << data_151 << " berhasil ditambahkan ke child kanan " << baru->parent->data << endl;
            return baru;
        }
    }
}

//Fungsi untuk mencari Node berdasarkan char data
Pohon_2311102151* CariNodeByData_151(Pohon_2311102151 *node, char data_151) {
    if (node == NULL) {
        return NULL;
    }
    if (node->data == data_151) {
        return node;
    }
    Pohon_2311102151 *foundNode = CariNodeByData_151(node->left, data_151);
    if (foundNode == NULL) {
        foundNode = CariNodeByData_151(node->right, data_151);
    }
    return foundNode;
}

//Prosedur untuk mengupdate (mengubah) nama suatu node
void UpdateNode_151(char data_151, Pohon_2311102151 *node){
    if(!isEmpty_151()){
        if(node){
            char temp = node->data;
            node->data = data_151;
            cout << "\n Node " << temp << " berhasil diubah menjadi " << data_151 << endl;
        }
    }
}

//Prosedur untuk menunjuk suatu node
void Retrieve_151(Pohon_2311102151 *node){
    if(!isEmpty_151()){
        if(node){
            cout << "\n Data node : " << node->data << endl;
        }
    }
}

//Prosedur untuk mencari node dan menampilkan root, parent, sibling, dan child node tersebut 
void CariNode_151(Pohon_2311102151 *node){
    if(isEmpty_151()){
        cout << "\n Buat tree terlebih dahulu!" << endl;
    } else {
        if (!node){
            cout << "\n Node yang ditunjuk tidak ada!" << endl;
        } else {
            cout << "\n Data Node : " << node->data << endl;
            cout << " Root : " << root->data << endl;
            if(!node->parent){
                cout << " Parent : (tidak punya parent)" << endl;
            } else {
                cout << " Parent : " << node->parent->data << endl;
            }

            if(node->parent != NULL && node->parent->left != node && node->parent->right == node){
                cout << " Sibling : " << node->parent->left->data << endl;
            } else if(node->parent != NULL && node->parent->right != node && node->parent->left == node){
                cout << " Sibling : " << node->parent->right->data << endl;
            } else {
                cout << " Sibling : (tidak punya sibling)" << endl;
            }

            if(!node->left){
                cout << " Child Kiri : (tidak punya Child kiri)" << endl;
            } else {
                cout << " Child Kiri : " << node->left->data << endl;
            }

            if(!node->right){
                cout << " Child Kanan : (tidak punya Child kanan)" << endl;
            } else {
                cout << " Child Kanan : " << node->right->data << endl;
            }
        }
    }
}

//Penelusuran (Traversal)
//Prosedur untuk menampilkan traversal secara pre order
void preOrder_151(Pohon_2311102151 *node = root){
    if(isEmpty_151()){
        cout << "\n Buat tree terlebih dahulu!" << endl;
    } else {
        if(node != NULL){
            cout << " " << node->data << ", ";
            preOrder_151(node->left);
            preOrder_151(node->right);
        }
    }
}

//prosedur untuk menampilkan traversal secara in order
void inOrder_151(Pohon_2311102151 *node = root){
    if(isEmpty_151()){
        cout << "\n Buat tree terlebih dahulu!" << endl;
    } else {
        if(node != NULL){
            inOrder_151(node->left);
            cout << " " << node->data << ", ";
            inOrder_151(node->right);
        }
    }
}

//prosedur untuk menampilkan traversal secara post order
void postOrder_151(Pohon_2311102151 *node = root){
    if(isEmpty_151()){
        cout << "\n Buat tree terlebih dahulu!" << endl;
    } else {
        if(node != NULL){
            postOrder_151(node->left);
            postOrder_151(node->right);
            cout << " " << node->data << ", ";
        }
    }
}

//Prosedur untuk menghapus suatu node pada tree
void HapusNodeTree_151(Pohon_2311102151 *node){
    if (isEmpty_151()){
        cout << "\n Buat tree terlebih dahulu!" << endl;
    } else {
        if(node != NULL){
            if(node != root){
                node->parent->left = NULL;
                node->parent->right = NULL;
            }
            HapusNodeTree_151(node->left);
            HapusNodeTree_151(node->right);
            if(node == root){
                delete root;
                root = NULL;
            } else {
                delete node;
            }
        }
    }
}

//prosedur untuk menghapus sub tree
void HapusSubTree_151(Pohon_2311102151 *node){
    if(isEmpty_151()){
        cout << "\n Buat tree terlebih dahulu!" << endl;
    } else {
        HapusNodeTree_151(node->left);
        HapusNodeTree_151(node->right);
        cout << "\n Node subtree " << node->data << " berhasil dihapus." << endl;
    }
}

//prosedur untuk menghapus seluruh tree
void HapusTree_151(){
    if(isEmpty_151()){
        cout << "\n Buat tree terlebih dahulu!!" << endl;
    } else {
        HapusNodeTree_151(root);
        cout << "\n Tree berhasil dihapus." << endl;
    }
}

//fungsi untuk menghitung jumlah node (size) yang ada pada tree
int CekSizeTree_151(Pohon_2311102151 *node = root){
    if(isEmpty_151()){
        cout << "\n Buat tree terlebih dahulu!!" << endl;
        return 0;
    } else {
        if(!node){
            return 0;
        } else {
            return 1 + CekSizeTree_151(node->left) + CekSizeTree_151(node->right);
        }
    }
}

//fungsi untuk menghitung level atau aras (height) tree
int CekHeightTree_151(Pohon_2311102151 *node = root){
    if(isEmpty_151()){
        cout << "\n Buat tree terlebih dahulu!" << endl;
        return 0;
    } else {
        if(!node){
            return 0;
        } else {
            int heightKiri_151 = CekHeightTree_151(node->left);
            int heightKanan_151 = CekHeightTree_151(node->right);
            if (heightKiri_151 >= heightKanan_151){
                return heightKiri_151 + 1;
            } else {
                return heightKanan_151 + 1;
            }
        }
    }
}

//prosedur untuk menampilkan karakteristik tree
void KarakteristikTree_151(){
    cout << "\n Size Tree : " << CekSizeTree_151() << endl;
    cout << " Height Tree : " << CekHeightTree_151() << endl;
    cout << " Average Node of Tree : " << CekSizeTree_151() / CekHeightTree_151() << endl;
    cout << endl;
}

//Prosedur untuk menampilkan child (kiri dan kanan) suatu node
void TampilkanChildNode_151(Pohon_2311102151 *node) {
    if (node) {
        if (node->left) {
            cout << "Child Kiri: " << node->left->data << endl;
        } else {
            cout << "Child Kiri: (tidak punya Child kiri)" << endl;
        }
        if (node->right) {
            cout << "Child Kanan: " << node->right->data << endl;
        } else {
            cout << "Child Kanan: (tidak punya Child kanan)" << endl;
        }
    } else {
        cout << "\n Node yang ditunjuk tidak ada!" << endl;
    }
}

//prosedur untuk menampilan node keturunan (descendant node) dari suatu node 
void TampilkanDescendantNode_151(Pohon_2311102151 *node) {
    if (node) {
        cout << "Keturunan node (descendant node) " << node->data << ": ";
        preOrder_151(node->left);
        preOrder_151(node->right);
        cout << endl;
    } else {
        cout << "\n Node yang ditunjuk tidak ada!" << endl;
    }
}


int main(){
    int Pilihan_151;
    char Data_151, DataParent_151, DataNodeLama_151, Yakin_151;
    Pohon_2311102151 *ParentNode, *NodeLama, *NodeYangDitunjuk; //deklarasi node ParentNode, NodeLama, dan NodeYangDitunjuk

    do{ //perulangan do-while untuk menampilkan menu
        Menu:
        cout << "--- PROGRAM SIMULASI GRAPH DAN TREE ---" << endl;
        cout << "1. Buat Node Akar" << endl;
        cout << "2. Tambah Node Kiri" << endl;
        cout << "3. Tambah Node Kanan" << endl;
        cout << "4. Update Node" << endl;
        cout << "5. Retrieve (tunjuk) Node" << endl;
        cout << "6. Cari Node" << endl;
        cout << "7. Tampilkan Child (Anak) Node" << endl;
        cout << "8. Tampilkan Descendant Node (Keturunan Node)" << endl;
        cout << "9. Hapus Subtree" << endl;
        cout << "10. Hapus Tree" << endl;
        cout << "11. Tampilkan Karakteristik Tree" << endl;
        cout << "12. Tampilkan Traversal PreOrder" << endl;
        cout << "13. Tampilkan Traversal InOrder" << endl;
        cout << "14. Tampilkan Traversal PostOrder" << endl;
        cout << "15. Keluar" << endl;
        cout << "Pilihan anda [1 - 15] = ";
        cin >> Pilihan_151;
        cout << endl;


        //swtich-case berdasarkan inputan user
        switch (Pilihan_151){
            case 1: //jika memilih 1, maka tampilkan menu buat node akar
                if(isEmpty_151()){
                    cout << "--- BUAT NODE AKAR ---" << endl;
                    cout << "Masukkan huruf node akar = ";
                    cin >> Data_151;
                    BuatNode_151(Data_151);
                    cout << endl;
                } else {
                    cout << "Tree sudah ada!" << endl;
                    cout << endl;
                }
                break;
            case 2: //jika memilih 2, maka tampilkan menu tambah node kiri
                if(!isEmpty_151()){
                    cout << "--- TAMBAH NODE KIRI ---" << endl;
                    cout << "Masukkan kode node kiri = ";
                    cin >> Data_151;
                    cout << "Masukkan kode node parent = ";
                    cin >> DataParent_151;
                    ParentNode = CariNodeByData_151(root, DataParent_151);
                    if(ParentNode){
                        TambahKiri_151(Data_151, ParentNode);
                        cout << endl;
                    } else {
                        cout << "Node parent tidak ditemukan!" << endl;
                        cout << endl;
                    }
                } else {
                    cout << "Tree masih kosong!" << endl;
                    cout << endl;
                }
                break;
            case 3: //jika memilih 3, maka tampilkan menu tambah node kanan
                if(!isEmpty_151()){
                    cout << "--- TAMBAH NODE KANAN ---" << endl;
                    cout << "Masukkan kode node kanan = ";
                    cin >> Data_151;
                    cout << "Masukkan kode node parent = ";
                    cin >> DataParent_151;
                    ParentNode = CariNodeByData_151(root, DataParent_151);
                    if(ParentNode){
                        TambahKanan_151(Data_151, ParentNode);
                        cout << endl;
                    } else {
                        cout << "Node parent tidak ditemukan!" << endl;
                        cout << endl;
                    }
                } else {
                    cout << "Tree masih kosong!" << endl;
                    cout << endl;
                }
                break;
            case 4: //jika memilih 4, maka tampilkan menu update node
                if(!isEmpty_151()){
                    cout << "--- UPDATE NODE ---" << endl;
                    cout << "Masukkan kode node baru = ";
                    cin >> Data_151;
                    cout << "Masukkan kode node yang ingin diupdate = ";
                    cin >> DataNodeLama_151;
                    NodeLama = CariNodeByData_151(root, DataNodeLama_151);
                    if(NodeLama){
                        UpdateNode_151(Data_151, NodeLama);
                        cout << endl;
                    } else {
                        cout << "Data node lama tidak ditemukan!" << endl;
                        cout << endl;
                    }
                } else {
                    cout << "Tree masih kosong!" << endl;
                    cout << endl;
                }
                break;
            case 5: //jika memilih 5, maka tampilkan menu retrieve node (tunjuk node)
                if(!isEmpty_151()){
                    cout << "--- RETRIEVE NODE ---" << endl;
                    cout << "Masukkan node yang ingin ditunjuk = ";
                    cin >> Data_151;
                    NodeYangDitunjuk = CariNodeByData_151(root, Data_151);
                    if(NodeYangDitunjuk){
                        Retrieve_151(NodeYangDitunjuk);
                        cout << endl;
                    } else {
                        cout << "Node yang ingin ditunjuk tidak ditemukan!" << endl;
                        cout << endl;
                    }
                } else {
                    cout << "Tree masih kosong!" << endl;
                    cout << endl;
                } 
                break;
            case 6: //jika memilih 6, maka tampilkan menu cari node
                if(!isEmpty_151()){
                    cout << "--- CARI NODE ---" << endl;
                    cout << "Masukkan kode node yang ingin dicari = ";
                    cin >> Data_151;
                    NodeYangDitunjuk = CariNodeByData_151(root, Data_151);
                    if(NodeYangDitunjuk){
                        CariNode_151(NodeYangDitunjuk);
                        cout << endl;
                    } else {
                        cout << "Node yang ingin dicari tidak ditemukan!" << endl;
                        cout << endl;
                    }
                } else {
                    cout << "Tree masih kosong!" << endl;
                    cout << endl;
                }
                break;
            case 7: //jika memilih 7, maka tampilkan menu tampilkan child suatu node
                if(!isEmpty_151()){
                    cout << "--- TAMPILKAN CHILD SUATU NODE ---" << endl;
                    cout << "Masukkan kode node yang ingin ditampilkan child-nya = ";
                    cin >> Data_151;
                    NodeYangDitunjuk = CariNodeByData_151(root, Data_151);
                    if(NodeYangDitunjuk){
                        TampilkanChildNode_151(NodeYangDitunjuk);
                        cout << endl;
                    } else {
                        cout << "Node yang ingin ditampilkan child-nya tidak ditemukan!" << endl;
                        cout << endl;
                    }
                } else {
                    cout << "Tree masih kosong!" << endl;
                    cout << endl;
                }
                break;
            case 8: //jika memilih 8, maka tampilkan menu tampilkan descendant node
                if(!isEmpty_151()){
                    cout << "--- TAMPILKAN DESCENDANT NODE (KETURUNAN SUATU NODE) ---" << endl;
                    cout << "Masukkan kode node yang ingin ditampilkan keturunannya = ";
                    cin >> Data_151;
                    NodeYangDitunjuk = CariNodeByData_151(root, Data_151);
                    if(NodeYangDitunjuk){
                        TampilkanDescendantNode_151(NodeYangDitunjuk);
                        cout << endl;
                    } else {
                        cout << "Node yang igin ditampilkan keturunannya tidak ditemukan!" << endl;
                        cout << endl;
                    }
                } else {
                    cout << "Tree masih kosong!" << endl;
                    cout << endl;
                }
                break;
            case 9: //jika memilih 9, maka tampilkan menu hapus subtree
                if(!isEmpty_151()){
                    cout << "--- HAPUS SUBTREE ---" << endl;
                    cout << "Masukkan kode node sebagai root subtree yang ingin dihapus = ";
                    cin >> Data_151;
                    NodeYangDitunjuk = CariNodeByData_151(root, Data_151);
                    if(NodeYangDitunjuk){
                        HapusSubTree_151(NodeYangDitunjuk);
                        cout << endl;
                    } else {
                        cout << "Node sebagai root subtree tidak ditemukan!" << endl;
                        cout << endl;
                    }
                } else {
                    cout << "Tree masih kosong!" << endl;
                    cout << endl;
                }
                break;
            case 10: //jika memilih 10, maka tampilkan menu hapus tree
                if(!isEmpty_151()){
                    cout << "--- HAPUS TREE ---" << endl;
                    cout << "Apakah anda yakin untuk menghapus seluruh tree? [y/n] = ";
                    cin >> Yakin_151;
                    if(Yakin_151 ==  'Y' || 'y'){
                        HapusTree_151();
                        cout << endl;
                    } else if(Yakin_151 == 'N' || 'n'){
                        cout << "Aksi dibatalkan" << endl;
                        cout << endl;
                    }
                } else {
                    cout << "Tree masih kosong!" << endl;
                    cout << endl;
                }
                break;
            case 11: //jika memilih 11, maka tampilkan menu karakteristik tree
                if(!isEmpty_151()){
                    cout << "--- KARAKTERISTIK TREE ---" << endl;
                    KarakteristikTree_151();
                } else {
                    cout << "Tree masih kosong!" << endl;
                    cout << endl;
                }
                break;
            case 12: //jika memilih 12, maka tampilkan menu traversal preorder
                cout << "--- TRAVERSAL PREORDER ---" << endl;
                preOrder_151(root);
                cout << endl;
                cout << endl;
                break;
            case 13: //jika memilih 13, maka tampilkan menu traversal inorder
                cout << "--- TRAVERSAL INORDER ---" << endl;
                inOrder_151(root);
                cout << endl;
                cout << endl;
                break;
            case 14: //jika memilih 14, maka tampilkan menu traversal postorder
                cout << "--- TRAVERSAL POSTORDER ---" << endl;
                postOrder_151(root);
                cout << endl;
                cout << endl;
                break;
            case 15: //jika memilih 15, maka keluar dari program
                cout << "Anda keluar dari program" << endl;
                return 0;
                break;
            default: //output jika memilih selain 1 - 15
                cout << "Pilihan anda tidak tersedia!" << endl;
                cout << endl;
                goto Menu;
                break;
        }
    } while(Pilihan_151 != 0); //menu akan ditampilkan berulang ketika variabel Pilihan_151 bukan sama dengan 0
}
```

#### Output:

Gunakan fungsi BuatNode_151, TambahKanan_151, dan TambahKiri_151 untuk membuat tree seperti gambar berikut.

![Dhimas_Tree-Unguided2](https://github.com/Masdim37/2311102151_Muhammad-Dhimas-Hafizh-Fathurrahman/blob/main/Pertemuan9_Modul9-Graph-dan-Tree/Laprak/Dhimas_Tree-Unguided2.png)

##### Menambahkan Node A (Root)
![Dhimas_Output-Unguided2-1](https://github.com/Masdim37/2311102151_Muhammad-Dhimas-Hafizh-Fathurrahman/blob/main/Pertemuan9_Modul9-Graph-dan-Tree/Laprak/Dhimas_Output-Unguided2-1.png)

##### Menambahkan Node B (Child Kiri Node A)
![Dhimas_Output-Unguided2-2](https://github.com/Masdim37/2311102151_Muhammad-Dhimas-Hafizh-Fathurrahman/blob/main/Pertemuan9_Modul9-Graph-dan-Tree/Laprak/Dhimas_Output-Unguided2-2.png)

##### Menambahkan Node C (Child Kanan Node A)
![Dhimas_Output-Unguided2-3](https://github.com/Masdim37/2311102151_Muhammad-Dhimas-Hafizh-Fathurrahman/blob/main/Pertemuan9_Modul9-Graph-dan-Tree/Laprak/Dhimas_Output-Unguided2-3.png)

##### Menambahkan Node D (Child Kiri Node B)
![Dhimas_Output-Unguided2-4](https://github.com/Masdim37/2311102151_Muhammad-Dhimas-Hafizh-Fathurrahman/blob/main/Pertemuan9_Modul9-Graph-dan-Tree/Laprak/Dhimas_Output-Unguided2-4.png)

##### Menambahkan Node E (Child Kanan Node B)
![Dhimas_Output-Unguided2-5](https://github.com/Masdim37/2311102151_Muhammad-Dhimas-Hafizh-Fathurrahman/blob/main/Pertemuan9_Modul9-Graph-dan-Tree/Laprak/Dhimas_Output-Unguided2-5.png)

##### Menambahkan Node F (Child Kanan Node C)
![Dhimas_Output-Unguided2-6](https://github.com/Masdim37/2311102151_Muhammad-Dhimas-Hafizh-Fathurrahman/blob/main/Pertemuan9_Modul9-Graph-dan-Tree/Laprak/Dhimas_Output-Unguided2-6.png)

##### Menambahkan Node G (Child Kiri Node E)
![Dhimas_Output-Unguided2-7](https://github.com/Masdim37/2311102151_Muhammad-Dhimas-Hafizh-Fathurrahman/blob/main/Pertemuan9_Modul9-Graph-dan-Tree/Laprak/Dhimas_Output-Unguided2-7.png)

##### Menambahkan Node H (Child Kanan Node E)
![Dhimas_Output-Unguided2-8](https://github.com/Masdim37/2311102151_Muhammad-Dhimas-Hafizh-Fathurrahman/blob/main/Pertemuan9_Modul9-Graph-dan-Tree/Laprak/Dhimas_Output-Unguided2-8.png)

##### Update Node F Menjadi M
![Dhimas_Output-Unguided2-9](https://github.com/Masdim37/2311102151_Muhammad-Dhimas-Hafizh-Fathurrahman/blob/main/Pertemuan9_Modul9-Graph-dan-Tree/Laprak/Dhimas_Output-Unguided2-9.png)

##### Retrieve (Tunjuk) Node M
![Dhimas_Output-Unguided2-10](https://github.com/Masdim37/2311102151_Muhammad-Dhimas-Hafizh-Fathurrahman/blob/main/Pertemuan9_Modul9-Graph-dan-Tree/Laprak/Dhimas_Output-Unguided2-10.png)

##### Cari Node E
![Dhimas_Output-Unguided2-11](https://github.com/Masdim37/2311102151_Muhammad-Dhimas-Hafizh-Fathurrahman/blob/main/Pertemuan9_Modul9-Graph-dan-Tree/Laprak/Dhimas_Output-Unguided2-11.png)

##### Tampilkan Child Node B
![Dhimas_Output-Unguided2-12](https://github.com/Masdim37/2311102151_Muhammad-Dhimas-Hafizh-Fathurrahman/blob/main/Pertemuan9_Modul9-Graph-dan-Tree/Laprak/Dhimas_Output-Unguided2-12.png)

##### Tampilkan Descendant Node B
![Dhimas_Output-Unguided2-13](https://github.com/Masdim37/2311102151_Muhammad-Dhimas-Hafizh-Fathurrahman/blob/main/Pertemuan9_Modul9-Graph-dan-Tree/Laprak/Dhimas_Output-Unguided2-13.png)

##### Hapus Subtree Dengan Root Node C
![Dhimas_Output-Unguided2-14](https://github.com/Masdim37/2311102151_Muhammad-Dhimas-Hafizh-Fathurrahman/blob/main/Pertemuan9_Modul9-Graph-dan-Tree/Laprak/Dhimas_Output-Unguided2-14.png)

##### Tampilkan Karakteristik Tree
![Dhimas_Output-Unguided2-15](https://github.com/Masdim37/2311102151_Muhammad-Dhimas-Hafizh-Fathurrahman/blob/main/Pertemuan9_Modul9-Graph-dan-Tree/Laprak/Dhimas_Output-Unguided2-15.png)

##### Tampilkan Traversal Secara PreOrder
![Dhimas_Output-Unguided2-16](https://github.com/Masdim37/2311102151_Muhammad-Dhimas-Hafizh-Fathurrahman/blob/main/Pertemuan9_Modul9-Graph-dan-Tree/Laprak/Dhimas_Output-Unguided2-16.png)

##### Tampilkan Traversal Secara InOrder
![Dhimas_Output-Unguided2-17](https://github.com/Masdim37/2311102151_Muhammad-Dhimas-Hafizh-Fathurrahman/blob/main/Pertemuan9_Modul9-Graph-dan-Tree/Laprak/Dhimas_Output-Unguided2-17.png)

##### Tampilkan Traversal Secara PostOrder
![Dhimas_Output-Unguided2-18](https://github.com/Masdim37/2311102151_Muhammad-Dhimas-Hafizh-Fathurrahman/blob/main/Pertemuan9_Modul9-Graph-dan-Tree/Laprak/Dhimas_Output-Unguided2-18.png)

##### Hapus Tree
![Dhimas_Output-Unguided2-19](https://github.com/Masdim37/2311102151_Muhammad-Dhimas-Hafizh-Fathurrahman/blob/main/Pertemuan9_Modul9-Graph-dan-Tree/Laprak/Dhimas_Output-Unguided2-19.png)

##### Keluar Dari Program
![Dhimas_Output-Unguided2-20](https://github.com/Masdim37/2311102151_Muhammad-Dhimas-Hafizh-Fathurrahman/blob/main/Pertemuan9_Modul9-Graph-dan-Tree/Laprak/Dhimas_Output-Unguided2-20.png)

#### Deskripsi Program
Kode diatas merupakan program implementasi tree menggunakan struct. Manipulasi tree pada program ini menggunakan menu-menu yang dapat dipilih oleh user. Setiap pilihan menu akan melakukan aksi yang berbeda beda. Terdapat beberapa fungsi dan prosedur yang dapat digunakan untuk memanipulasi tree, antara lain :
- struct Pohon_2311102151; mendeklarasikan struct Pohon
- void init_151(); digunakan untuk menginisialisasi root seagai NULL
- bool isEmpty_151(); digunakan untuk memeriksa apakah tree masih kosong atau tidak
- void BuatNode_151(char data_151); digunakan untuk membuat node root (akar)
- Pohon_2311102151 *TambahKiri_151(char data_151, Pohon_2311102151 *node); digunakan untuk membuat child kiri suatu node
- Pohon_2311102151 *TambahKanan_151(char data_151, Pohon_2311102151 *node); digunakan untuk membuat child kanan suatu node
- Pohon_2311102151* CariNodeByData_151(Pohon_2311102151 *node, char data_151); digunakan untuk menujuk suatu node berdasarkan inputan char
- void UpdateNode_151(char data_151, Pohon_2311102151 *node); digunakan untuk mengupdate isi suatu node
- void Retrieve_151(Pohon_2311102151 *node); digunakan untuk menunjuk suatu node
- void CariNode_151(Pohon_2311102151 *node); digunakan untuk mencari node dan menampilkan root, parent, sibling, dan child node tersebut
- void preOrder_151(Pohon_2311102151 *node = root); digunakan untuk menampilkan traversal tree secara preOrder
- void inOrder_151(Pohon_2311102151 *node = root); digunakan untuk menampilkan traversal tree secara inOrder
- void postOrder_151(Pohon_2311102151 *node = root); digunakan untuk menampilkan traversal tree secara postOrder
- void HapusNodeTree_151(Pohon_2311102151 *node); digunakan untuk menghapus sebuah node pada tree
- void HapusSubTree_151(Pohon_2311102151 *node); digunakan untuk menghapus sub tree (kecuali node rootnya)
- void HapusTree_151(); digunakan untuk menghapus seluruh tree
- int CekSizeTree_151(Pohon_2311102151 *node = root); digunakan untuk mengecek jumlah node (size) pada tree
- int CekHeightTree_151(Pohon_2311102151 *node = root); digunakan untuk mengecek level atau aras (height) tree
- void KarakteristikTree_151(); digunakan untuk menampilkan karakteristik tree
- void TampilkanChildNode_151(Pohon_2311102151 *node); digunakan untuk menampilkan child suatu tree
- void TampilkanDescendantNode_151(Pohon_2311102151 *node); digunakan untuk menampilkan descendant node (node keturunan) suatu node
<br>Kemudian pada int main() terdapat beberapa menu dengan fungsinya masing-masing. Jika user memilih 1, maka masuk ke menu Buat Node Akar; jika user memilih 2, maka masuk ke menu Tambah Node Kiri; jika user memilih 3, maka masuk ke menu Tambah Node Kanan; jika user memilih 4, maka masuk ke menu Update Node; jika user memilih 5, maka masuk ke menu Retrieve (Tunjuk) Node; jika user memilih 6, maka masuk ke menu Cari Node; jika user memilih 7, maka masuk ke menu Tampilkan Child (Anak) Node; jika user memilih 8, maka masuk ke menu Tampilkan Descendant Node (Keturunan Node); jika user memilih 9, maka masuk ke menu Hapus Subtree; jika user memilih 10, maka masuk ke menu Hapus Tree; jika user memilih 11, maka masuk ke menu Tampilkan Karakteristik Tree; jika user memilih 12, maka masuk ke menu Tampilkan Traversal PreOrder; jika user memilih 13, maka masuk ke menu Tampilkan Traversal InOrder; jika user memilih 14, maka masuk ke menu Tampilkan Traversal PostOrder; dan jika user memilih 15, maka keluar dari program.

## Kesimpulan


## Referensi
[1] 