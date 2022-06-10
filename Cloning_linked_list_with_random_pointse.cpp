/** Problem Link - https://www.interviewbit.com/problems/copy-list/
 * Definition for singly-linked list.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 
Interview bit solution function
RandomListNode* Solution::copyRandomList(RandomListNode* A) {
    if(A == NULL) return NULL;
    RandomListNode* cont = A;
    while(cont != NULL)
    {
        RandomListNode* helo = new RandomListNode(cont->label);
        // helo->label = cont->label;
        helo->next = cont->next;
        cont->next = helo;
        cont = cont->next->next;
    }
    RandomListNode* acont = A;
    while(acont != NULL)
    {
        acont->next->random = acont->random?acont->random->next:acont->random;
        acont = acont->next->next;
    }
    
    RandomListNode* new_head = (A)->next;
    RandomListNode* locale =  (A);
    while (locale->next != NULL)
    {
        RandomListNode* tempo = locale->next;
        locale->next = locale->next->next;
        locale = tempo;
    }
    return new_head;
}
*/

#include <bits/stdc++.h>
using namespace std;
class node{
    public:
    int val;
    node* next;
    node* random;
};
node* randomaker(node** head){
    if(*head == NULL) return NULL;
    node* cont = *head;
    while(cont != NULL)
    {
        node* helo = new node();
        helo->val = cont->val;
        helo->next = cont->next;
        cont->next = helo;
        cont = cont->next->next;
    }
    node* acont = *head;
    while(acont != NULL)
    {
        acont->next->random = acont->random?acont->random->next:acont->random;
        acont = acont->next->next;
    }
    
    node* new_head = (*head)->next;
    node* locale =  (*head);
    while (locale->next != NULL)
    {
        node* tempo = locale->next;
        locale->next = locale->next->next;
        locale = tempo;
    }
    return new_head;
}
void randomdisplay(node* head)
{
    node* helo = head;
    cout<<"******************************************"<<endl;
    while(helo != NULL)
    {
        cout<<helo->val<<endl;
        helo = helo->random;
    }   
}
void displayLL(node* head)
{
    node* helo = head;
    cout<<"******************************************"<<endl;
    while(helo != NULL)
    {
        cout<<helo->val<<endl;
        helo = helo->next;
    }
}
int main(){
    node* head = new node();
    node* first = new node();
    node* second  = new node();
    node* third = new node();
    head->val = 1;
    head->next = first;
    head->random = second;
    first->val = 2;
    first->next = second;
    first->random = third;
    second->val = 3;
    second->next = third;
    second->random = first;
    third->val = 4;
    third->next = NULL;
    third->random = NULL;
    //displayLL(head);
    randomdisplay(head);
    node* nayasa = randomaker(&head);
    displayLL(nayasa);
    randomdisplay(nayasa);

}