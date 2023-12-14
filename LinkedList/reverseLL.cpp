#include<iostream>
using namespace std;

//***************** iterative method*******************


class Node
{
public:
    int val;
    Node *next;

    Node(int data)
    {
        val = data;
        next = NULL;
    }
};

class LinkedList
{
public:
    Node *head;
    LinkedList()
    {
        head = NULL;
    }

    void insertAtTail(int val)
    {
        Node *new_node = new Node(val);
        if (!head)
        {
            head = new_node;
            return;
        }
        Node *temp = head;
        while (temp->next)
        {
            temp = temp->next;
        }
        temp->next = new_node;
    }

    void display()
    {
        Node *temp = head;
        while (temp)
        {
            cout << temp->val << "-->";
            temp = temp->next;
        }
        cout << "null" << endl;
    }
};


Node* reversal(Node* &head){
    Node* prev = NULL;
    Node* curr=head;
    while(curr){
        Node* next=curr->next;
        curr->next=prev;
        prev=curr;
        curr=next;
    }
    //prev pointing to the last node...which is new head
    Node* new_head=prev;
    return new_head;
}


//*********************** recursive mthod****************

Node* reversal_recursive(Node* head){
    //base case
    if(head==NULL || head->next==NULL){
        return head;
    }

    Node* new_head= reversal_recursive(head->next);
    head->next->next=head;
    head->next=NULL;
    return new_head;
}

int main(){
     LinkedList ll;
    ll.insertAtTail(1);
    ll.insertAtTail(2);
    ll.insertAtTail(3);
    ll.insertAtTail(4);
    ll.insertAtTail(5);
    ll.display();
    // ll.head= reversal(ll.head);
    ll.head=reversal_recursive(ll.head);
    ll.display();
}