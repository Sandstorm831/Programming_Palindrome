# Leetcode solution
# Link : https://leetcode.com/problems/reverse-linked-list/
#
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def reverseList(self, head: Optional[ListNode]) -> Optional[ListNode]:
        prev = None
        if not head:
            return head
        temp = head.next
        curr = head
        while curr.next:
            curr.next = prev
            prev = curr
            curr = temp
            temp = curr.next
        curr.next = prev
        head = curr
        return head
