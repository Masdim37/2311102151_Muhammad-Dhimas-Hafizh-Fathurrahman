#include<iostream>

using namespace std;

//deklarasi class node
class node{
    public:
    //node berisi data, pointer prev, dan pointer next
    int data;
    node* prev;
    node* next;
};

//deklarasi class doublelinkedist
class doublelinkedlist{
    public:
    node* head;
    node* tail;

    //inisialisasi head dan tail
    doublelinkedlist(){
        head == nullptr;
        tail = nullptr;
    }

    //prosedur menambah node
    void push(int data){
        node* newnode = new node;
        newnode->data = data;
        newnode->prev = nullptr;
        newnode->next = head;
        if(head != nullptr){
            head->prev = newnode;
        } else {
            tail = newnode;
        }
        head = newnode;
    }

    //prosedur menghapus node
    void pop(){
        if(head == nullptr){
            return;
        }
        node* temp = head;
        head = head->next;
        if(head != nullptr){
            head->prev = nullptr;
        } else {
            tail = nullptr;
        }
        delete temp;
    }

    //prosedur mengupdate atau mengubah data suatu node
    bool update(int olddata, int newdata){
        node* current = head;
        while(current != nullptr){
            if(current->data == olddata){
                current->data = newdata;
                return true;
            }
            current = current->next;
        }
        return false;
    }

    //prosedur menghapus semua node
    void deleteall(){
        node* current = head;
        while (current != nullptr) {
            node* temp = current;
            current = current->next;
            delete temp;
        }
        head = nullptr;
        tail = nullptr;
    }

    //prosedur menampilkan list
    void display(){
        node* current = head;
        while(current != nullptr){
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }
    
};

int main(){
    doublelinkedlist list;
    while(true){
        //menu manipulasi double linked list
        cout << "1. add data" << endl;
        cout << "2. Delete data" << endl;
        cout << "3. Update data" << endl;
        cout << "4. Clear data" << endl;
        cout << "5. Display data" << endl;
        cout << "6. Exit" << endl;
        int choice;
        cout << "Enter your choice: ";
        cin >> choice;

        switch(choice){
            case 1 : { //jika menginput 1, maka tambah node didepan
                int data;
                cout << "enter data to add : ";
                cin >> data;
                list.push(data);
                break;
            }
            case 2 : { //jika menginput 2, maka hapus node didepan
                list.pop();
                break;
            }
            case 3 : { //jika menginput 3, maka ubah node didepan
                int olddata, newdata;
                cout << "enter old data : ";
                cin >> olddata;
                cout << "enter new data : ";
                cin >> newdata;
                bool update = list.update(olddata, newdata);
                if(!update){
                    cout << "data not found" << endl;
                }
                break;
            }
            case 4 : { //jika memilih 4, maka hapus semua node
                list.deleteall();
                break;
            }
            case 5 : { //jika memilih 5, maka tampilkan list
                list.display();
                break;
            }
            case 6 : { //jika memilih 6, maka keluar dari program
                return 0;
            }
            default : { //output jika menginput selain 1-6
                cout << "invalid choice" << endl;
                break;
            }
        }
    }

    return 0;
}