// Problem Link - https://www.interviewbit.com/problems/palindrome-list/
#include <bits/stdc++.h>
using namespace std;
class node{
    public:
    int N;
    node* next;
};
/*
void displayLL(node* head){
    cout<<"***********************************"<<endl;
    while(head != NULL)
    {
        cout<<head->N<<endl;
        head = head->next;
    }
    cout<<"***********************************"<<endl;
}*/
node* midfinder(node* head){
    node* slow = head;
    node* fast = head;
    while(fast != NULL && fast->next != NULL)
    {
        fast = fast->next->next;
        slow = slow->next;
    }

    return slow;
}
node* reverser(node** head){
    node* prely = *head;
    node* backly = NULL;
    while(prely != NULL)
    {
        node* tempo = prely->next;
        prely->next = backly;
        backly = prely;
        prely =  tempo;
    }
    return backly;
}
bool palindromefinder(node** head){
    node* starter = *head;
    node* midler = midfinder(*head);
    // displayLL(*head);
    node* laster = reverser(&midler);
    // displayLL(laster);
    // displayLL(*head);
    while(laster != NULL)
    {
        if(laster->N != starter->N) return false;
        laster = laster->next;
        starter = starter->next;
    }
    return true;
}
int main()
{
    node* head = new node();
    node* first = new node();
    node* second = new node();
    node* third = new node();
    head->N = 3;
    head->next=first;
    first->N = 1;
    first->next = second;
    second->N = 2;
    second->next = third;
    third->N = 3;
    third->next = NULL;
    cout<<palindromefinder(&head);
}