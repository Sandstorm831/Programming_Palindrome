# GeeksForGeeks solution
# Link : https://www.geeksforgeeks.org/problems/flattening-a-linked-list/1

'''

class Node:
    def __init__(self, d):
        self.data=d
        self.next=None
        self.bottom=None

'''

class Solution:
    def flatten(self, root):
        #Your code here
        curr_nodes = []

        if root.next:
            curr_nodes.append(root.next)
        if root.bottom:
            curr_nodes.append(root.bottom)

        new_linked_list = Node(root.data)
        curr = new_linked_list
        while len(curr_nodes) > 0:
            minor = 100001
            holder = None
            iholder = None
            for index in range(len(curr_nodes)):
                if curr_nodes[index].data <= minor:
                    holder = curr_nodes[index]
                    minor = curr_nodes[index].data
                    iholder = index
            nst = Node(holder.data)
            curr.bottom = nst
            curr = curr.bottom
            del curr_nodes[iholder]
            if holder.next:
                curr_nodes.append(holder.next)
            if holder.bottom:
                curr_nodes.append(holder.bottom)
        return new_linked_list
