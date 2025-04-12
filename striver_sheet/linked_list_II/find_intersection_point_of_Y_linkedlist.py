# Leetcode solution
# Link : https://leetcode.com/problems/intersection-of-two-linked-lists/

# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def getIntersectionNode(self, headA: ListNode, headB: ListNode) -> Optional[ListNode]:
        curr1 = headA
        curr2 = headB
        while curr1 and curr2:
            curr1 = curr1.next
            curr2 = curr2.next
        while curr1:
            curr1 = curr1.next
            headA = headA.next
        while curr2:
            curr2 = curr2.next
            headB = headB.next
        while headA or headB:
            if headA == headB:
                return headA
            headA = headA.next
            headB = headB.next
        return None
