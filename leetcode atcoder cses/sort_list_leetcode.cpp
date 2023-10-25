// Question Link - https://www.interviewbit.com/problems/sort-list/
// Solution 

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
void splitter(ListNode* head, ListNode** x, ListNode** y)
{
    ListNode* slow = head;
    ListNode* fast = slow->next;
    while(fast != NULL)
    {
        fast=fast->next;
        if(fast != NULL)
        {
            fast = fast->next;
            slow = slow->next;
        }
    }
    *x = head;
    *y = slow->next;
    slow->next = NULL;
}
ListNode* sortedmerge(ListNode* x, ListNode* y)
{
    if(x == NULL) return y;
    else if(y == NULL) return x;
    ListNode* fin=NULL;
    if(x->val <= y->val)
    {
        fin = x;
        fin->next = sortedmerge(x->next, y);
    }
    else
    {
        fin = y;
        fin->next = sortedmerge(x, y->next);
    }
    return fin;
}
void mergesort(ListNode** A)
{
    ListNode* head = *A;
    ListNode* x;
    ListNode* y;
    if(head == NULL || head->next == NULL) return;
    splitter(head, &x, &y);
    mergesort(&x);
    mergesort(&y);
    *A = sortedmerge(x, y);
}
ListNode* Solution::sortList(ListNode* A) {
    mergesort(&A);
    return A;
}
