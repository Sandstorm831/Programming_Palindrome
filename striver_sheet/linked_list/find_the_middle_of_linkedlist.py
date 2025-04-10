# Leetcode solution
# Link : https://leetcode.com/problems/middle-of-the-linked-list/
#
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def middleNode(self, head: Optional[ListNode]) -> Optional[ListNode]:
        arr = []
        slow = head
        fast = head
        while slow:
            if fast.next:
                fast = fast.next
                slow = slow.next
            else:
                return slow
            if fast.next:
                fast = fast.next
            else:
                return slow
