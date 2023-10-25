// Question Link - https://www.interviewbit.com/problems/partition-list/
// Solution

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::partition(ListNode* A, int B) {
    ListNode* hii = NULL;
    ListNode* loi = NULL;
    ListNode* h = NULL;
    ListNode* l = NULL;
    ListNode* curr = A;
    while(curr != NULL)
    {
        if(curr->val < B)
        {
            if(loi == NULL) loi = curr;
            if(l == NULL)
            {
                l = curr;
                curr =  curr->next;
            }
            else
            {
                l->next = curr;
                l = curr;
                curr = curr->next;
            }
        }
        else
        {
            if(hii == NULL) hii = curr;
            if(h == NULL)
            {
                h = curr;
                curr = curr->next;
            }
            else{
                h->next = curr;
                h = curr;
                curr = curr->next;
            }
        }
    }
    h->next = NULL;
    if(l == NULL) return hii;
    else
    {
        l->next = hii;
    }
    return loi;
}
