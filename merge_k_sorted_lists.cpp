/** Problem Solution Function -----------------------------------------------+
 * Definition for singly-linked list.                                        |
 * struct ListNode {                                                         |
 *     int val;                                                              |   
 *     ListNode *next;                                                       |
 *     ListNode(int x) : val(x), next(NULL) {}                               |
 * };                                                                        |       
 *                                                                           |    
ListNode* jodkar(ListNode* &pehla, ListNode* &doosra)       <----------------+
{
    ListNode* head;
    ListNode* pailda;
    ListNode* doolda;
    ListNode* abhivala;
    if(pehla->val > doosra->val) 
    {
        head = doosra;
        pailda = pehla;
        doolda = doosra->next;
        abhivala = head;
    }
    else
    {
        head = pehla;
        pailda = pehla->next;
        doolda = doosra;
        abhivala = head;
    }
    while(pailda != NULL && doolda != NULL)
    {
        if(pailda->val > doolda->val) 
        {
            abhivala->next = doolda;
            abhivala = doolda;
            doolda = doolda->next;
        }
        else
        {
            abhivala->next = pailda;
            abhivala = pailda;
            pailda = pailda->next;
        }
    }
    if(pailda == NULL)
    {
        while(doolda != NULL)
        {
            abhivala->next = doolda;
            abhivala = doolda;
            doolda = doolda->next;
        }
    }
    else if(doolda == NULL)
    {
        while(pailda != NULL)
        {
            abhivala->next = pailda;
            abhivala = pailda;
            pailda = pailda->next;
        }
    }
    return head;
}
ListNode* recursor(vector<ListNode*> &A, int dharti, int akaash)
{
    if(dharti<akaash)
    {
        int beechka = (dharti+akaash)/2;
        ListNode* pehla = recursor(A, dharti, beechka);
        ListNode* doosra = recursor(A, beechka+1, akaash);
        return jodkar(pehla, doosra);
    }
    return A[dharti];
}
ListNode* Solution::mergeKLists(vector<ListNode*> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    int dharti = 0;
    int akaash = A.size()-1;
    return recursor(A, dharti, akaash);
}
*/