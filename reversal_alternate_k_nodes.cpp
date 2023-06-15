// Question Link - https://www.interviewbit.com/problems/reverse-alternate-k-nodes/
// Solution

 /**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::solve(ListNode* A, int B) {
    if(B==1) return A;
    ListNode* temp = A;
    ListNode* head = NULL;
    bool fist = true;
    ListNode* X = temp;
    int alt = 0;
    while(temp != NULL)
    {
        ListNode* prev = NULL;
        if(alt%2 == 1)
        {
            X->next = A;
            int count = B-1;
            // cout<<(A==NULL)<<endl;
            // cout<<(A->next->val)<<endl;
            while(count>=0)
            {
                // A = A->next;
                prev = temp;
                temp = temp->next;
                // prev = A;
                // A = temp;
                // cout<<count<<" | ";
                count--;
            }
            // cout<<prev->val<<" | ";//<<temp->val<<" | ";
            // A = prev;
            X = prev;
            A = temp;
            // prev = NULL;
            alt++;
            continue;
        }
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
            alt++;
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
            alt++;
        }
    }
    // cout<<"yea"<<endl;
    return head;
}
