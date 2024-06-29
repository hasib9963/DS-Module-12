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

void print_list(Node* head)
{
    Node* tmp = head;
    while(tmp != NULL)
    {
        cout<< tmp->val << " ";
        tmp = tmp->next;
    }
}

void reverse(Node* &head, Node* cur)
{
    if(cur->next==NULL)
    {
        head = cur;
        return;
    }
    reverse(head, cur->next);
    cur->next->next = cur;
    cur->next = NULL;
}

bool isPalindrome(Node* head)
{
    Node* newHead = NULL;
    Node* newTail = NULL;
    Node* tmp = head;
    while(tmp != NULL)
    {
        insert_tail(newHead, newTail, tmp->val);
        tmp = tmp->next;
    }
    reverse(newHead, newHead);
    tmp = head;
    Node* tmp2 = newHead;
    while(tmp != NULL)
    {
        if(tmp->val != tmp2->val)
        {
            return false;
        }
        tmp = tmp->next;
        tmp2 = tmp2->next;
    }
    return true;
}
 int main()
 {
    Node* head = NULL;
    Node* tail = NULL;
    int val;
    while(true)
    {
        cin>>val;
        if(val==-1) break;
        insert_tail(head,tail,val);
    }
    if(isPalindrome(head))
    {
        cout<<"YES";
    }
    else
    {
        cout<<"NO";
    }
    return 0;
 }