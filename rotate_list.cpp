//Problem Link - https://www.interviewbit.com/problems/rotate-list/
/** Problem Solution Function --------------------------------+
 * Definition for singly-linked list.                         |  
 * struct ListNode {                                          |   
 *     int val;                                               |          
 *     ListNode *next;                                        |  
 *     ListNode(int x) : val(x), next(NULL) {}                |  
 * };                                                         |  
 *                                                            |              
ListNode* Solution::rotateRight(ListNode* A, int B) {    <----+
    ListNode* counter = A;
    int count=0;
    while(counter->next != NULL)
    {
        counter = counter->next;
        count++;
    }
    if(count>=0) count++;
    if(B>=count) B = B%count;
    if(B==0) return A;
    int stopage = count-B;
    int helper = 0;
    ListNode* acounter = A;
    while(acounter != NULL)
    {
        helper++;
        if(helper == stopage)
        {
            counter->next = A;
            (A) = acounter->next;
            acounter->next = NULL;
            break;
        }
        acounter = acounter->next;
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
node* rotater(node** head, int B){
    node* counter = *head;
    int count=0;
    while(counter->next != NULL)
    {
        counter = counter->next;
        count++;
    }
    if(count>0) count++;
    if(B>=count) B = B%count;
    if(B==0) return *head;
    int stopage = count-B;
    int helper = 0;
    node* acounter = *head;
    while(acounter != NULL)
    {
        helper++;
        if(helper == stopage)
        {
            counter->next = *head;
            (*head) = acounter->next;
            acounter->next = NULL;
            break;
        }
        acounter = acounter->next;
    }
    return *head;
}
int main(){

}