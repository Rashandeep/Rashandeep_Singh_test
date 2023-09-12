#ifndef __QUESTION3_H__
#define __QUESTION3_H__
#include <iostream>
#include <map>

using namespace std;

class node {
        public:
            int key;
            int val;
            node* next;
            node* prev;
            node(int _key, int _val);
};

// function to get a value of the key provided
int get(int key, unordered_map<int, node*> &m, node* head);

// function to add key-value pair in DLL
void put(int key, int value, node* tail, 
node* head, unordered_map<int, node*> &m, int cap);

// method to print the cache 
void print(unordered_map<int, node*> m);

#endif