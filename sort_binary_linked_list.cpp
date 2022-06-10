// Problem Link : https://www.interviewbit.com/problems/sort-binary-linked-list/
/* Solution function:-
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 *
ListNode* Solution::solve(ListNode* A) {
    ListNode* homer = A;
    ListNode* prev = NULL;
    while(homer != NULL)
    {
        if(homer->val == 1) 
        {
            prev = homer;
            homer = homer->next;
        }
        else
        {
            if(prev == NULL)
            {
                homer = homer->next;
                continue;
            }
            ListNode* tempo = homer->next;
            homer->next = A;
            prev->next =  tempo;
            A = homer;
            homer = tempo;

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
node* sorter(node** head){
    node* homer = *head;
    node* prev = NULL;
    while(homer != NULL)
    {
        if(homer->n == 1){
            prev = homer;
            homer = homer->next;
        }
        else
        {
            if(prev == NULL) 
            {
                homer = homer->next;
                continue;
            }
            node* tempo = homer->next;
            homer->next = *head;
            prev->next =  tempo;
            *head = homer;
            homer = tempo;

        }
    }
    return *head;
}
void displayLL(node* head){
    while(head != NULL)
    {
        cout<<head->n<<endl;
        head = head->next;
    }
}

int main()
{
    node* head = new node();
    node* first = new node();
    node* second = new node();
    node* third = new node();
    head->n = 0;
    head->next = first;
    first->n = 1;
    first->next = NULL;
    displayLL(head);
    node* nodhd = sorter(&head);
    displayLL(nodhd);

}