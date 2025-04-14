# Leetcode solution
# Link : https://leetcode.com/problems/copy-list-with-random-pointer/

"""
# Definition for a Node.
class Node:
    def __init__(self, x: int, next: 'Node' = None, random: 'Node' = None):
        self.val = int(x)
        self.next = next
        self.random = random
"""

def val_cleaner(new_val):
    return int(new_val.split(',')[1])

def get_index(new_val):
    return int(new_val.split(',')[0])

class Solution:
    def copyRandomList(self, head: 'Optional[Node]') -> 'Optional[Node]':
        if not head:
            return None
        curr = head
        index = 0
        while curr:
            val = str(curr.val)
            new_val = str(index)+","+val
            curr.val = new_val
            index+=1
            curr = curr.next
        new_head = Node(val_cleaner(head.val));
        curr = new_head
        old_curr = head.next
        holder = []
        holder.append(new_head)
        while old_curr:
            x = Node(val_cleaner(old_curr.val))
            curr.next = x
            curr = x
            holder.append(x)
            old_curr = old_curr.next
        curr = new_head
        old_curr = head
        while curr:
            if old_curr.random:
                curr.random = holder[get_index(old_curr.random.val)]
            else:
                curr.random = None
            old_curr = old_curr.next
            curr = curr.next
        return new_head
