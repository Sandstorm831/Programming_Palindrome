// Problem Link - https://www.interviewbit.com/problems/swap-list-nodes-in-pairs/
/** Problem Solution function -------------------------------------+
 * Definition for singly-linked list.                              | 
 * struct ListNode {                                               | 
 *     int val;                                                    | 
 *     ListNode *next;                                             | 
 *     ListNode(int x) : val(x), next(NULL) {}                     |              
 * };                                                              | 
 *                                                                 | 
ListNode* Solution::swapPairs(ListNode* A) {      <================+
    ListNode* tempo = A;
    ListNode* owly = NULL;
    while(tempo != NULL && tempo->next !=NULL )
    {
        if (tempo == A)
        {
            (A) = tempo->next;
            tempo->next = tempo->next->next;
            (A)->next = tempo;
            owly = tempo;
            tempo = tempo->next;
        }
        else
        {
            owly->next = tempo->next;
            tempo->next = tempo->next->next;
            owly->next->next = tempo;
            owly = tempo;
            tempo = tempo->next;
        }
        
    }
    return A;
}
*/
#include <bits/stdc++.h>
using namespace std;
class node{
    public:
    int val;
    node* next;
};
node* swapper(node** head){
    node* tempo = *head;
    node* owly = NULL;
    while(tempo != NULL && tempo->next !=NULL)
    {
        // cout<<"here"<<endl;
        if (tempo == *head)
        {
            (*head) = tempo->next;
            tempo->next = tempo->next->next;
            (*head)->next = tempo;
            owly = tempo;
            tempo = tempo->next;
            // cout<<"here"<<endl;
        }
        else
        {
            // cout<<tempo->next->val<<" "<<tempo->val<<" "<<owly->val<<endl;
            owly->next = tempo->next;
            tempo->next = tempo->next->next;
            owly->next->next = tempo;
            owly = tempo;
            tempo = tempo->next;
            // cout<<"here"<<endl;
        }
        
    }
    return *head;
}
void displayLL(node* head){
    cout<<"***********************************"<<endl;
    while(head != NULL)
    {
        cout<<head->val<<endl;
        head = head->next;
    }
    cout<<"***********************************"<<endl;
}
int main()
{
    node* head = new node();
    node* first = new node();
    node* second  = new node();
    node* third = new node();
    head->val = 1;
    head->next = first;
    first->val = 2;
    first->next = second;
    second->val =3;
    second->next = third;
    third->val = 4;
    third->next = NULL;
    displayLL(head);
    node* ketm = swapper(&head);
    displayLL(ketm);

}