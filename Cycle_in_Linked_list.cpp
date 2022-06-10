// Problem Link - https://www.interviewbit.com/problems/list-cycle/
#include <bits/stdc++.h>
using namespace std;
class node{
    public:
    int N;
    node* next;
};
node* finder(node* head, node* slow){
    node* men = head;
    node* den = slow;
    while(men->N != den->N)
    {
        den = den->next;
        men = men->next;
    }
    return den;
}
node* cyclefinder(node* head){
    node* slow = head->next;
    node* fast = head->next->next;
    while (fast != NULL && fast->next != NULL)
    {
        if(fast->N == slow->N) return finder(head, slow);
        fast = fast->next->next;
        slow = slow->next;
    }
    return NULL;
}

int main()
{
    node* head = new node();
    node* first = new node();
    head->N = 1;
    head->next = first;
    first->N = 2;
    first->next = NULL;
    node* prost = cyclefinder(head);
    if(prost != NULL) cout<<"Cycle starts from the number = "<<prost->N;
    else cout<<"NO CYCLE FORMATION";


}