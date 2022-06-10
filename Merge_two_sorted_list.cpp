// Problem Link - https://www.interviewbit.com/problems/merge-two-sorted-lists/
/**Problem solution function-------------------------------------------+
 * Definition for singly-linked list.                                  | 
 * struct ListNode {                                                   | 
 *     int val;                                                        |     
 *     ListNode *next;                                                 | 
 *     ListNode(int x) : val(x), next(NULL) {}                         | 
 * };                                                                  | 
 *                                                                     | 
ListNode* Solution::mergeTwoLists(ListNode* A, ListNode* B) {     <====+ 
    ListNode* oner = A;
    ListNode* twoer = B;
    ListNode* prey = NULL;
    ListNode* original = NULL;
    if(oner->val < twoer->val) 
    {
        prey = oner;
        original = oner;
        oner = oner->next;
    }
    else
    {
        prey = twoer;
        original = twoer;
        twoer = twoer->next;

    } 
    while(oner != NULL || twoer != NULL)
    {
        if (oner == NULL)
        {
            prey->next = twoer;
            break;
        }
        else if (twoer == NULL)
        {
            prey->next = oner;
            break;
        }
        else
        {
            
            if (oner->val > twoer->val)
            {
                prey->next = twoer;
                prey = twoer;
                twoer = twoer->next;
            }
            else
            {
                prey->next = oner;
                prey = oner;
                oner = oner->next;
            }
        }

    }
    return original;
}

*/
#include <bits/stdc++.h>
using namespace std;
class node{
    public:
    int val;
    node* next;
};
node* merger(node** headone, node** headtwo){
    node* oner = *headone;
    node* twoer = *headtwo;
    node* prey = NULL;
    node* orginal = NULL;
    if(oner->val < twoer->val) 
    {
        prey = oner;
        orginal = oner;
        oner = oner->next;
    }
    else
    {
        prey = twoer;
        orginal = twoer;
        twoer = twoer->next;

    } 
    while(oner != NULL || twoer != NULL)
    {
        if (oner == NULL)
        {
            prey->next = twoer;
            break;
        }
        else if (twoer == NULL)
        {
            prey->next = oner;

            break;
        }
        else
        {
            
            if (oner->val > twoer->val)
            {
                prey->next = twoer;
                prey = twoer;
                twoer = twoer->next;
            }
            else
            {
                prey->next = oner;
                prey = oner;
                oner = oner->next;
            }
        }

    }
    return orginal;
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
int main(){
    node* head = new node();
    node* first = new node();
    node* second  = new node();
    node* third = new node();
    head->val = 4;
    head->next = NULL;
    first->val = 4;
    first->next = NULL;
    second->val =1;
    second->next = third;
    third->val = 1;
    third->next = NULL;
    node* ketm = merger(&head, &first);
    displayLL(ketm);


}
