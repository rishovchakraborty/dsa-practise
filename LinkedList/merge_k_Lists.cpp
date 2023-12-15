#include <iostream>
#include<vector>
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
Node* mergeLinkedList(Node* &head1, Node* &head2){
    Node* dummy_head= new Node(-1);
    Node* ptr1=head1;
    Node* ptr2=head2;
    Node* ptr3=dummy_head;

    while(ptr1 && ptr2){
        if(ptr1->val<ptr2->val){
            ptr3->next=ptr1;
            ptr1=ptr1->next;
        }else{
            ptr3->next=ptr2;
            ptr2=ptr2->next;
        }
        ptr3=ptr3->next;
    }
    if(ptr1){
        ptr3->next=ptr1;
    }else{
        ptr3->next=ptr2;
    }
    return dummy_head->next;
}

Node* merge_k_Lists(vector<Node*>&lists){
    if(lists.size()==0){
        return NULL;
    }
    while (lists.size()>1)
    {
        Node* mergeHead=mergeLinkedList(lists[0],lists[1]);
        lists.push_back(mergeHead);
        lists.erase(lists.begin());
        lists.erase(lists.begin());
    }
    return lists[0];
}


int main(){
    LinkedList ll1;
    ll1.insertAtTail(1);
    ll1.insertAtTail(4);
    ll1.insertAtTail(5);
    ll1.display();
    LinkedList ll2;
    ll2.insertAtTail(2);
    // ll2.insertAtTail(4);
    ll2.display();
    LinkedList ll3;
    ll3.insertAtTail(9);
    ll3.insertAtTail(12);
    LinkedList ll4;
    ll4.insertAtTail(0);
    // ll3.head=mergeLinkedList(ll1.head,ll2.head);
    ll3.display();
    ll4.display();
    vector<Node*>lists;
    lists.push_back(ll1.head);
    lists.push_back(ll2.head);
    lists.push_back(ll3.head);
    lists.push_back(ll4.head);

    LinkedList ans;
    ans.head=merge_k_Lists(lists);
    ans.display();
    return 0;
}
    