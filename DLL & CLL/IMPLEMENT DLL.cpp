#include<iostream>
using namespace std;

class Node{
    public:
    int val;
    Node* prev;
    Node* next;
    Node(int data){
        val=data;
        prev=NULL;
        next=NULL;
    }
};

class DoublyLinkedList{
    public:
    Node* head=NULL;
    Node* tail=NULL;
    DoublyLinkedList(){
        head=NULL;
        tail=NULL;
    }
};