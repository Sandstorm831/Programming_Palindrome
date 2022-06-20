// Problem Link - https://www.interviewbit.com/problems/remove-nth-node-from-list-end/
/* Problem Solution Function -------------------------------------------------------+
 * Definition for singly-linked list.                                               |
 * struct ListNode {                                                                |
 *     int val;                                                                     |        
 *     ListNode *next;                                                              |
 *     ListNode(int x) : val(x), next(NULL) {}                                      |
 * };                                                                               |       
 *                                                                                  |                                                                                 
ListNode* Solution::removeNthFromEnd(ListNode* A, int B) {          <---------------+
    int size = 0;
    ListNode* counter = A;
    while(counter != NULL)
    {
        size++;
        counter = counter->next;
    }
    if(B >=size) return A->next;
    else
    {
        counter = A;
        int sizes = 1;
        while (sizes != size - B)
        {
            sizes++;
            counter = counter->next;
        }
        counter->next = counter->next->next;
    } 
    return A;
}
*/
#include <bits/stdc++.h>
using namespace std;
class ListNode{
    public:
    int val;
    ListNode* next;
};
ListNode* removeNthfromEnd(ListNode* A, int B)
{
    int size = 0;
    ListNode* counter = A;
    while(counter != NULL)
    {
        size++;
        counter = counter->next;
    }
    if(B >=size) return A->next;
    else
    {
        counter = A;
        int sizes = 1;
        while (sizes != size - B)
        {
            sizes++;
            counter = counter->next;
        }
        counter->next = counter->next->next;
    } 
    return A;
}
int main()
{

}