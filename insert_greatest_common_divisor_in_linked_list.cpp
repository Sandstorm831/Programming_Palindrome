// Question Link - https://leetcode.com/contest/biweekly-contest-110/problems/insert-greatest-common-divisors-in-linked-list/
// solution 

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        if(head == NULL || head->next ==NULL) return head;
        ListNode* orig = head;
        while(head->next != NULL)
        {
            int x = __gcd(head->val, head->next->val);
            ListNode* l = new ListNode(x);
            ListNode* temp = head->next;
            head->next = l;
            l->next = temp;
            head = temp;
        }
        return orig;
        
    }
};