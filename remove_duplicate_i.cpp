#include<bits/stdc++.h>
using namespace std;
class Node
{
    public:
        int val;
        Node* next;
    Node(int val)
    {
        this->val=val;
        this->next=NULL;
    }
};

void insert_tail(Node *&head, Node *&tail, int val)
{
    Node* newNode = new Node(val);
    if(head==NULL)
    {
        head = newNode;
        tail = newNode;
        return;
    }
    tail->next = newNode;
    tail = newNode;
}

void rmvdup(Node* head) {
    if (head == NULL) {
        return;
    }
    
    Node* cnode = head;
    while (cnode != NULL) {
        Node* newNode = cnode;
        while (newNode->next != NULL) {
            if (newNode->next->val == cnode->val) {
                Node* tmp = newNode->next;
                newNode->next = newNode->next->next;
                delete tmp;
            } else {
                newNode = newNode->next;
            }
        }
        cnode = cnode->next;
    }
}

void print_recursion(Node* n)
{
    // base case
    if(n==NULL) return;
    cout<<n->val<<" ";
    print_recursion(n->next);
}
int main() {
    Node* head = NULL;
    Node* tail = NULL;
    int val;
    while(true)
    {
        cin>>val;
        if(val==-1) break;
        insert_tail(head,tail,val);
    }
    
    rmvdup(head);
    for(Node* i = head; i->next !=NULL; i=i->next)
{
    for(Node* j = i->next; j !=NULL; j=j->next)
    {
        if(i->val > j->val)
        {
            swap(i->val,j->val);
        }
    }
}
    print_recursion(head);
    
    return 0;
}