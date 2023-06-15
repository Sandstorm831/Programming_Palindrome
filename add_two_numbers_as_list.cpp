// Question Link - https://www.interviewbit.com/problems/add-two-numbers-as-lists/
// Solution 

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::addTwoNumbers(ListNode* A, ListNode* B) {
    // ListNode* prev = NULL;
    // ListNode* temp = A;
    ListNode* headA = A;
    // while(A != NULL)
    // {
    //     temp = A->next;
    //     A->next = prev;
    //     prev = A;
    //     A = temp;
    // }
    // headA = prev;
    // prev = NULL;
    // temp = B;
    ListNode* headB = B;
    // while(B != NULL)
    // {
    //     temp = B->next;
    //     B->next = prev;
    //     prev = B;
    //     B = temp;
    // }
    // headB = prev;
    ListNode* headC=NULL;
    ListNode* orig;
    int rem = 0;
    while(headA != NULL && headB != NULL)
    {
        int summ = headA->val + headB->val+rem;
        rem = summ/10;
        ListNode* nu = new ListNode(summ%10);
        if(headC == NULL)
        {
            headC = nu;
            orig = nu;
        }
        else
        {
            orig->next = nu;
            orig = nu;
        }
        headA = headA->next;
        headB = headB->next;
    }
    while(headA != NULL)
    {
        int summ = headA->val + rem;
        rem = summ/10;
        ListNode* nu = new ListNode(summ%10);
        if(headC == NULL)
        {
            headC = nu;
            orig = nu;
        }
        else{
            orig->next = nu;
            orig = nu;
        }
        headA = headA->next;
    }
    while(headB != NULL)
    {
        int summ =  headB->val + rem;
        rem = summ/10;
        ListNode* nu = new ListNode(summ%10);
        if(headC == NULL)
        {
            headC = nu;
            orig = nu;
        }
        else
        {
            orig->next = nu;
            orig = nu;
        }
        headB = headB->next;
    }
    if(rem !=0) 
    {
        ListNode* nu = new ListNode(rem);
        orig->next = nu;
        orig = nu;
    }
    orig->next = NULL;
    return headC;
    
}
