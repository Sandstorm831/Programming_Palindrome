# Leetcode solution
# Link : https://leetcode.com/problems/linked-list-cycle-ii/

# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def detectCycle(self, head: Optional[ListNode]) -> Optional[ListNode]:
        while head:
            if head.val == 100001:
                return head
            else:
                head.val = 100001
                head = head.next
        return head
