// Problem Link - https://www.interviewbit.com/problems/remove-duplicates-from-sorted-list/
/** Problem Solution function ----------------------------+
 * Definition for singly-linked list.                     |  
 * struct ListNode {                                      |
 *     int val;                                           |      
 *     ListNode *next;                                    |  
 *     ListNode(int x) : val(x), next(NULL) {}            |      
 * };                                                     |  
 *                                                        |      
ListNode* Solution::deleteDuplicates(ListNode* A) {   <---+
    ListNode* helr = (A)->next;
    ListNode* saver = A;
    while(helr !=NULL){
        if(saver->val!=helr->val){
            saver->next = helr;
            saver = helr;
        }
        if(helr->next == NULL)
        {
            saver->next = NULL;
        }
        helr = helr->next;
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
node* duplicaterremover(node** head)
{
    node* helr = (*head)->next;
    node* saver = *head;
    while(helr!=NULL){
        if(saver->val!=helr->val){
            saver->next = helr;
            saver = helr;
        }
        if(helr->next == NULL)
        {
            saver->next = NULL;
        }
        helr = helr->next;
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
    head->val = 4;
    head->next = first;
    first->val = 4;
    first->next = second;
    second->val =1;
    second->next = third;
    third->val = 1;
    third->next = NULL;
    displayLL(head);
    node* newe = duplicaterremover(&head);
    displayLL(newe);
}