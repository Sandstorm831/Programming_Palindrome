# Leetcode solution
# Link : https://leetcode.com/problems/rotate-list/

# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def rotateRight(self, head: Optional[ListNode], k: int) -> Optional[ListNode]:
        nodes = 0
        curr = head
        prev = None
        while curr:
            nodes+=1
            prev = curr
            curr = curr.next
        if nodes == 0:
            return head
        k = k%nodes
        last = prev
        if k == 0:
            return head
        comp_k = nodes - k
        curr = head
        curr_node = 1
        while curr_node < comp_k:
            curr_node += 1
            curr = curr.next
        last.next = head
        head = curr.next
        curr.next = None
        return head
