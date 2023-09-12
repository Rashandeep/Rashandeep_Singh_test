// Online C++ compiler to run C++ program online
#include "question3.h"
using namespace std;

// A class for a node of doubly linked list
node::node (int _key, int _val){
    key = _key;
    val = _val;
}

// function to add a node after head of DLL
void addNode(node* newnode, node* head){
    node* temp;
    temp = head->next;
    newnode->prev = head;
    head->next = newnode;
    temp->prev = newnode;
    newnode->next = temp;
}

// function to delete a node in DLL
void delNode(node* newnode){
    node* prev1 = newnode->prev;
    node* next1 = newnode->next;
    prev1->next = next1;
    next1->prev = prev1;
}

// function to get a value of the key provided
int get(int key, unordered_map<int, node*> &m, node* head) {
    // it checks if value is present in DLL and correspondinly in map
    // if not then return -1
    if(m.find(key)!=m.end()){
        node* temp = m[key];
        delNode(temp);
        m.erase(key);
        addNode(temp, head);
        m[key] = temp;
        return temp->val;
    }
    return -1;
}

// function to add key-value pair in DLL
void put(int key, int value, node* tail, node* head, unordered_map<int, node*> &m, int cap) {
    // if the key is already present then update the value of it.
    // I am doing it by deleting the node first and removing it from map and then further adding to the front of DLL
    if(m.find(key)!=m.end()){
        delNode(m[key]);
        m.erase(key);
    } 
    // if size becomes equal to capacity then delete the last used cache that will be present one before the tail in DLL
    if(m.size()==cap){
        m.erase(tail->prev->key);
        delNode(tail->prev);
    }
    
    node* node1 = new node(key, value);
    m[key] = node1;
    addNode(node1, head);
}

// method to print the cache 
void print(unordered_map<int, node*> m){
    for(auto it:m){
        cout << it.first << " " << it.second->val << "\n";
    }
}

// main method
int main() {
    // initalizing DLL
    node* head = new node(-1,-1);
    node* tail = new node(-1,-1);
    head->next = tail;
    tail->prev = head;

    int cap;
    cout << "Enter the cap\n";
    cin >> cap;
    unordered_map<int, node*> m;
    
    while(true){
        int option;
        cout << "Enter 1 to push, 2 to get, 3 to print and 4 to exit\n";
        cin >> option;
        
        int key, value;
        int getKey;
        
        if(option==1){
            cout << "Enter key and value\n";
            cin >> key >> value;
        }
        
        if(option==2){
            cout << "Enter the key to get value\n";
            cin >> getKey;
        }
        
        switch(option) {
            case 1:
                put(key, value, tail, head, m, cap);
                break;
            case 2:
                int v;
                v = get(getKey, m, head);
                cout << v << "\n";
                break;
            case 3:
                print(m);
                break;
            case 4:
                return 0;
            default:
                cout << "invalid option";
        }
    }

    return 0;
}