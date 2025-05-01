# Leetcode solution
# Link : https://leetcode.com/problems/lru-cache/

class Node:
    def __init__(self, key = -1, val = -1, next = None, prev = None):
        self.key = key
        self.val = val
        self.next = next
        self.val = val

class LRUCache:

    def __init__(self, capacity: int):
        self.head = Node()
        self.tail = Node()
        self.mapper = {}
        self.sizer = 0
        self.capacity = capacity
        self.head.next = self.tail
        self.tail.prev = self.head

    def insert_ahead(self, node):
        temp_next = self.head.next
        self.head.next = node
        node.next = temp_next
        temp_next.prev = node
        node.prev = self.head

    def print_list(self):
        pointer = self.head
        print("<-- printing list -->")
        while not pointer is None:
            print(pointer.key, pointer.val)
            pointer = pointer.next
        print("<-- printing list ends -->")


    def delete_node(self, node):
        # print(node.key, node.val, self.sizer)
        # self.print_list()
        node_behind = node.prev
        node_behind.next = node.next
        node.next.prev = node_behind
        node.next = None
        node.prev = None

    def get(self, key: int) -> int:
        if key in self.mapper:
            noder = self.mapper[key]
            self.delete_node(noder)
            self.insert_ahead(noder)
            return noder.val
        else:
            return -1

    def put(self, key: int, value: int) -> None:
        if key in self.mapper:
            noder = self.mapper[key]
            if noder.val == value:
                self.delete_node(noder)
                self.insert_ahead(noder)
            else:
                noder.val = value
                self.delete_node(noder)
                self.insert_ahead(noder)
        else:
            if self.sizer == self.capacity:
                last_node = self.tail.prev
                del self.mapper[last_node.key]
                self.delete_node(last_node)
                new_node = Node(key, value)
                self.mapper[key] = new_node
                self.insert_ahead(new_node)
            else:
                self.sizer += 1
                new_node = Node(key, value)
                self.mapper[key] = new_node
                self.insert_ahead(new_node)




# Your LRUCache object will be instantiated and called as such:
# obj = LRUCache(capacity)
# param_1 = obj.get(key)
# obj.put(key,value)
