# Leetcode solution
# Link : https://leetcode.com/problems/merge-two-sorted-lists/

# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def mergeTwoLists(self, list1: Optional[ListNode], list2: Optional[ListNode]) -> Optional[ListNode]:
        if not list1:
            return list2
        elif not list2:
            return list1
        head = ListNode()
        curr = ListNode()
        if list1.val > list2.val:
            head = list2
            list2 = list2.next
        elif list1.val <= list2.val:
            head = list1
            list1 = list1.next
        curr = head
        while list1 and list2:
            if list1.val > list2.val:
                curr.next = list2
                curr = list2
                list2 = list2.next
            elif list1.val <= list2.val:
                curr.next = list1
                curr = list1
                list1 = list1.next
        while list1:
            curr.next = list1
            curr = list1
            list1 = list1.next
        while list2:
            curr.next = list2
            curr = list2
            list2 = list2.next
        return head
