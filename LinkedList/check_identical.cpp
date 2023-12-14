#include <iostream>
using namespace std;

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

bool checkIdentical(Node* head1, Node* head2){
    Node* ptr1=head1;
    Node* ptr2=head2;
    while (ptr1&&ptr2)
    {
        if(ptr1->val!=ptr2->val){
            return false;
        }
        ptr1=ptr1->next;
        ptr2=ptr2->next;
    }
    return(!ptr1&&!ptr2);
    
}

int main(){
    LinkedList ll1;
    ll1.insertAtTail(1);
    ll1.insertAtTail(2);
    ll1.insertAtTail(3);
    ll1.insertAtTail(4);
    ll1.insertAtTail(5);

    LinkedList ll2;
    ll2.insertAtTail(1);
    ll2.insertAtTail(2);
    ll2.insertAtTail(39);
    ll2.insertAtTail(4);
    ll2.insertAtTail(5);

    cout<<checkIdentical(ll1.head,ll2.head);
}
