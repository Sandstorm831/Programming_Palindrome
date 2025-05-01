# Leetcode solution
# Link : https://leetcode.com/problems/online-stock-span/

class StockSpanner:

    def __init__(self):
        self.st = []

    def next(self, price: int) -> int:
        counter = 1
        while len(self.st) > 0 and self.st[-1][0] <= price:
            x = self.st.pop()
            counter += x[1]
        self.st.append((price, counter))
        return counter


# Your StockSpanner object will be instantiated and called as such:
# obj = StockSpanner()
# param_1 = obj.next(price)
