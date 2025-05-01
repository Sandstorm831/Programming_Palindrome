# Naukri.com solution
# Link : https://www.naukri.com/code360/problems/min-heap-implementation_5480527

class MinHeap:
    def __init__(self, n):
        # Constructor
        self.heap = []

    def heapify(self, ind):
        lc, rc = 2*ind + 1, 2*ind+2
        sm = ind
        if lc < len(self.heap) and self.heap[lc] < self.heap[sm]:
            sm = lc
        if rc < len(self.heap) and self.heap[rc] < self.heap[sm]:
            sm = rc

        if sm != ind:
            self.heap[ind], self.heap[sm] = self.heap[sm], self.heap[ind]
            self.heapify(sm)

    def extractMinElement(self):
        # Implement the function to remove the minimum element
        if len(self.heap) == 0:
            return -1
        min_ele = self.heap[0]
        self.heap[0], self.heap[-1] = self.heap[-1], self.heap[0]
        self.heap.pop()
        self.heapify(0)
        return min_ele

    def deleteElement(self, ind):
        # Implement the function to delete an element
        ind = ind-1
        if ind >= len(self.heap):
            return None
        self.heap[ind], self.heap[-1] = self.heap[-1], self.heap[ind]
        self.heap.pop()
        if ind<len(self.heap):
            self.heapify(ind)

    def insert(self, val):
        # Implement the function to insert 'val' in the heap
        self.heap.append(val)
        curr = len(self.heap) -1
        while curr > 0:
            par = (curr - 1) // 2
            if self.heap[curr] < self.heap[par]:
                self.heap[curr], self.heap[par] = self.heap[par], self.heap[curr]
                curr = par
            else:
                break
