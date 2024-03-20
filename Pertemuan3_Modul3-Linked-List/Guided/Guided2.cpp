#include<iostream>

using namespace std;

class node{
    public:
    int data;
    node* prev;
    node* next;
};

class doublelinkedlist{
    public:
    node* head;
    node* tail;
    doublelinkedlist(){
        head == nullptr;
        tail = nullptr;
    }
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
    void display(){
        node* current = head;
        while(current != nullptr){
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }
    void deleteall(){
        Node* current = head;
        while (current != nullptr) {
            Node* temp = current;
            current = current->next;
            delete temp;
        }
        head = nullptr;
        tail = nullptr;
        }
    }
};

int main(){
    doublelinkedlist list;
    while(true){
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
            case 1 : 
                int data;
                cout << "enter data to add : ";
                cin >> data;
                list.push(data);
                break;
            case 2 :
                list.pop();
                break;
            case 3 :
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
            case 4 :
                list.deleteall();
                break;
            case 5 : 
                list.display();
                break;
            case 6 : 
                return 0;
            default : 
                cout << "invalid choice" << endl;
                break;
        }
    }

    return 0;
}