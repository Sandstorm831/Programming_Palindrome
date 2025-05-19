# GFG Solution
# Link : https://www.geeksforgeeks.org/problems/k-th-element-of-two-sorted-array1317/1

def setter(sm, lg, cutter_sm, cutter_lg, sm_i, sm_f, lg_i, lg_f):

    if cutter_sm != 0:
        sm_i = sm[cutter_sm - 1]
    if cutter_lg != 0:
        lg_i = lg[cutter_lg - 1]
    if cutter_sm < len(sm):
        sm_f = sm[cutter_sm]
    if cutter_lg < len(lg):
        lg_f = lg[cutter_lg]

    return sm_i, sm_f, lg_i, lg_f


def functor(sm, lg, k):
    miner_sm = max(k - len(lg), 0)
    maxer_sm = min(len(sm), k)
    holder = []
    while miner_sm <= maxer_sm:
        cutter_sm = miner_sm + (maxer_sm - miner_sm) // 2
        cutter_lg = k - cutter_sm
        sm_i = float('-inf')
        sm_f = float('inf')
        lg_i = float('-inf')
        lg_f = float('inf')
        # print(miner_sm, maxer_sm, cutter_sm, cutter_lg)
        sm_i, sm_f, lg_i, lg_f = setter(
            sm, lg, cutter_sm, cutter_lg, sm_i, sm_f, lg_i, lg_f)
        holder = [sm_i, lg_i]
        if sm_i <= lg_f and lg_i <= sm_f:
            return max(sm_i, lg_i)
        elif lg_i > sm_f:
            miner_sm = cutter_sm + 1
        else:
            maxer_sm = cutter_sm - 1

    cutter_sm = miner_sm + (maxer_sm - miner_sm) // 2
    cutter_lg = k - cutter_sm
    sm_i = float('-inf')
    sm_f = float('inf')
    lg_i = float('-inf')
    lg_f = float('inf')
    sm_i, sm_f, lg_i, lg_f = setter(
        sm, lg, cutter_sm, cutter_lg, sm_i, sm_f, lg_i, lg_f)
    holder = [sm_i, lg_i]
    return max(holder)


class Solution:

    def kthElement(self, a, b, k):
        if len(a) < len(b):
            return functor(a, b, k)
        else:
            return functor(b, a, k)


# {
 # Driver Code Starts
# Initial Template for Python 3


def main():

    T = int(input())

    while (T > 0):

        k = int(input())
        a = [int(x) for x in input().strip().split()]
        b = [int(x) for x in input().strip().split()]
        ob = Solution()
        print(ob.kthElement(a, b, k))
        print("~")
        T -= 1


if __name__ == "__main__":
    main()

# } Driver Code Ends
