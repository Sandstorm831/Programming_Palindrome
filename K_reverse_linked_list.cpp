// Question Link - https://www.interviewbit.com/problems/k-reverse-linked-list/
// Solution 

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::reverseList(ListNode* A, int B) {
    if(B==1) return A;
    ListNode* temp = A;
    ListNode* head = NULL;
    bool fist = true;
    ListNode* X = temp;
    while(temp != NULL)
    {
        ListNode* prev = NULL;
        if(fist)
        {
            fist = false;
            int count = B-1;
            while(count>=0)
            {
                temp = A->next;
                A->next = prev;
                prev = A;
                A = temp;
                count--;
            }
            A = prev;
            head = A;
            A = temp;
            prev = NULL;
            // cout<<(temp==NULL);
        }
        else
        {
            int count = B-1;
            ListNode* store = A;
            while(count>=0)
            {
                temp = A->next;
                A->next = prev;
                prev = A;
                A = temp;
                count--;
            }
            A = prev;
            X->next = A;
            X = store;
            A = temp;
            prev = NULL; 
        }
    }
    // cout<<"yea"<<endl;
    return head;
}
