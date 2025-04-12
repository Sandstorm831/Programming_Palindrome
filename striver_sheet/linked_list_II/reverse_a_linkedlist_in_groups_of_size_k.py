# Leetcode solution
# Link : https://leetcode.com/problems/reverse-nodes-in-k-group/

# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def reverseKGroup(self, head: Optional[ListNode], k: int) -> Optional[ListNode]:
        nodes = 0
        if k == 1:
            return head
        curr = head
        while curr:
            nodes+=1
            curr = curr.next
        rg = nodes // k
        fh = head
        pl = head
        curr = head
        nodes_counter = 1
        prev = head
        first = True
        while rg > 0:
            if nodes_counter == 1:
                fh = curr
                prev = curr
                curr = curr.next
                temp = curr
                nodes_counter += 1
            elif nodes_counter == k:
                # code
                temp = curr.next
                curr.next = prev
                prev = curr
                curr = temp
                fh.next = curr
                nodes_counter = 1
                if first:
                    head = prev
                    first = False
                else:
                    pl.next = prev
                pl = fh
                prev = pl
                fh = curr
                rg -= 1
            else:
                print(prev.val, rg)
                temp = curr.next
                curr.next = prev
                prev = curr
                curr = temp
                nodes_counter += 1
        return head
