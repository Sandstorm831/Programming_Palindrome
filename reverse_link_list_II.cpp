// Question Link - https://www.interviewbit.com/problems/reverse-link-list-ii/
// Solution 

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::reverseBetween(ListNode* A, int B, int C) {
    if(B==C) return A;
    ListNode* prev;
    ListNode* temp=A;
    int count=0;
    while(B-1-count>0)
    {
        prev = temp;
        temp=temp->next;
        count++;
    }
    ListNode* X = prev;
    ListNode* L = temp;
    ListNode* orig = temp;
    prev = NULL;
    count=0;
    while(C-B-count>=0)
    {
        temp = orig->next;
        orig->next = prev;
        prev = orig;
        orig = temp;
        count++;
    }
    if(B==1) 
    {
        A->next = temp;
        A = prev;
        return A;
    }
        // A = prev;
    X->next = prev;
    L->next = temp;
    return A;
}
