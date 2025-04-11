# Leetcode solution
# Link : https://leetcode.com/problems/remove-nth-node-from-end-of-list/


# O(n) -> optimal solution
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def removeNthFromEnd(self, head: Optional[ListNode], n: int) -> Optional[ListNode]:
        fp = head
        sp = None
        for i in range(n):
            fp = fp.next
        while fp:
            fp = fp.next
            if not sp:
                sp = head
            else:
                sp = sp.next
        if not sp:
            head = head.next
            return head
        else:
            sp.next = sp.next.next
            return head


#-----------------------------------------------------------------------------------------
# O(2n) solution -> not optimal
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def removeNthFromEnd(self, head: Optional[ListNode], n: int) -> Optional[ListNode]:
        total_nodes = 0
        curr = head
        while curr:
            total_nodes+=1
            curr = curr.next
        from_front = total_nodes + 1 - n
        curr = head
        cn = 1
        if from_front == 1:
            head = head.next
            return head

        while cn < from_front-1:
            curr = curr.next
            cn+=1
        curr.next = curr.next.next
        return head
