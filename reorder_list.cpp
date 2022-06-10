// Problem Link - https://www.interviewbit.com/problems/reorder-list/
/** Problem Solution function----------------------------+
 * Definition for singly-linked list.                    |   
 * struct ListNode {                                     |   
 *     int val;                                          |
 *     ListNode *next;                                   |    
 *     ListNode(int x) : val(x), next(NULL) {}           |       
 * };                                                    |   
 *                                                       |
ListNode* Solution::reorderList(ListNode* A) {     <_----+   
    vector<ListNode*> ceculy;
    ListNode* count = A;
    while(count!= NULL){
        ceculy.push_back(count);
        count = count->next;
    }
    int counter=0;
    int size = ceculy.size();
    while(counter<=size-counter){
        if(counter == size-1-counter)
        {
            ceculy[counter]->next = NULL;
            break;
        }
        if (counter +1 == size - 1 - counter)
        {
            ceculy[size-1-counter]->next = NULL;
            break;
        }
        ceculy[counter]->next = ceculy[size-1-counter];
        ceculy[size-counter-1]->next = ceculy[counter+1];
        counter++;

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
node* reorderer(node** head){
    vector<node*> ceculy;
    node* count = *head;
    while(count!= NULL){
        ceculy.push_back(count);
        count = count->next;
    }
    int counter=0;
    int size = ceculy.size();
    while(counter <= size-counter){
        if(counter == size-1-counter)
        {
            ceculy[counter]->next = NULL;
            break;
        }
        if (counter +1 == size - 1 - counter)
        {
            ceculy[size-1-counter]->next = NULL;
            break;
        }
        //cout<<ceculy[counter]<<endl;
        ceculy[counter]->next = ceculy[size-1-counter];
        ceculy[size-counter-1]->next = ceculy[counter+1];
        counter++;

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
    node* ketm = reorderer(&head);
    displayLL(ketm);
}