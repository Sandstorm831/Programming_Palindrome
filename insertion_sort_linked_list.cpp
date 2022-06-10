// Problem Link - https://www.interviewbit.com/problems/insertion-sort-list/
/** Solution function of Problem---------------------------
 * Definition for singly-linked list.                     |  
 * struct ListNode {                                      |
 *     int val;                                           |  
 *     ListNode *next;                                    |
 *     ListNode(int x) : val(x), next(NULL) {}            |  
 * };                                                     |  
 *                                                        |  
ListNode* Solution::insertionSortList(ListNode* A) {     <   
    ListNode* nowe = A->next;
    ListNode* owly = A;
    while (nowe != NULL)
    {
        ListNode* owen = A;
        while (owen->val != nowe->val)
        {
            if((A)->val > nowe->val)
            {
                owly->next = nowe->next;
                nowe->next = A;
                A = nowe;
                break;
                
            }
            if(owen->val < nowe->val){
                if (owen->next->val > nowe->val)
                {
                    owly->next = nowe->next;
                    nowe->next = owen->next;
                    owen->next = nowe;
                    break;
                }
                else
                {
                    owen = owen->next;
                }
            }
            else
            {
                owen = owen->next;
            }
            
        }
        if(nowe != owly->next ) nowe = owly->next;
        else
        {
            owly = nowe;
            nowe = nowe->next;
        }
        
    }
    return A;
}
*/
#include <bits/stdc++.h>
using namespace std;
class node{
    public:
    int n;
    node* next;
};
node* insertionlistsorter(node** head){
    node* nowe = (*head)->next;
    node* owly = *head;
    bool current = true;
    while (nowe != NULL)
    {
        node* owen = *head;
        while (owen->n != nowe->n)
        {
            if((*head)->n > nowe->n)
            {
                owly->next = nowe->next;
                nowe->next = *head;
                *head = nowe;
                break;
                
            }
            if(owen->n < nowe->n){
                if (owen->next->n > nowe->n)
                {
                    owly->next = nowe->next;
                    nowe->next = owen->next;
                    owen->next = nowe;
                    break;
                }
                else
                {
                    owen = owen->next;
                }
            }
            else
            {
                owen = owen->next;
            }
            
        }
        if(current)
        {
            owly = nowe;
            nowe = nowe->next;
            current = false;

        }
        else if(nowe != owly->next) nowe = owly->next;
        else
        {
            owly = nowe;
            nowe = nowe->next;
        }
        
    }
    return *head;
    
}
void displayLL(node* head){
    cout<<"***********************************"<<endl;
    while(head != NULL)
    {
        cout<<head->n<<endl;
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
    head->n = 4;
    head->next = first;
    first->n = 3;
    first->next = second;
    second->n = 2;
    second->next = third;
    third->n = 1;
    third->next = NULL;
    displayLL(head);
    node* newer = insertionlistsorter(&head);
    displayLL(newer);

}