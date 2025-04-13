# Leetcode solution:
# Link : https://leetcode.com/problems/palindrome-linked-list/

# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def isPalindrome(self, head: Optional[ListNode]) -> bool:
        if not head.next:
            return True
        f = head
        s = head
        while f.next:
            f = f.next
            if f.next:
                s = s.next
                f = f.next
        prev = s
        curr = s.next
        temp = curr
        prev.next = None
        while curr:
            temp = curr.next
            curr.next = prev
            prev = curr
            curr = temp
        l = prev
        curr = head
        while curr and l:
            if curr.val != l.val:
                return False
            curr = curr.next
            l = l.next
        return True
