# Leetcode solution
# Link : https://leetcode.com/problems/add-two-numbers/
#
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def addTwoNumbers(self, l1: Optional[ListNode], l2: Optional[ListNode]) -> Optional[ListNode]:
        curr1 = l1
        curr2 = l2
        summer = ListNode()
        sumcur = summer
        ini = True
        carry = 0
        while curr1 or curr2:
            if curr1 and curr2:
                sm = curr1.val + curr2.val + carry
                carry = sm // 10
                sm = sm%10
                if ini:
                    sumcur.val = sm
                    ini = False
                else:
                    sumcur.next = ListNode()
                    sumcur.next.val = sm
                    sumcur = sumcur.next
                curr1 = curr1.next
                curr2 = curr2.next
            elif curr1:
                sm = curr1.val + carry
                carry = sm // 10
                sm = sm%10
                sumcur.next = ListNode()
                sumcur.next.val = sm
                sumcur = sumcur.next
                curr1 = curr1.next
            elif curr2:
                sm = curr2.val + carry
                carry = sm // 10
                sm = sm%10
                sumcur.next = ListNode()
                sumcur.next.val = sm
                sumcur = sumcur.next
                curr2 = curr2.next
        if carry>0:
            sm = carry
            sumcur.next = ListNode()
            sumcur.next.val = sm
            sumcur = sumcur.next
        return summer
