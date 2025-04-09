# InterviewBit solution
# Link : https://www.interviewbit.com/problems/subarray-with-given-xor/
#

class Solution:
    # @param A : list of integers
    # @param B : integer
    # @return an integer
    def solve(self, A, B):
        xor_map = {}
        xor_map[0] = [-1]
        curr_xor = 0
        counter = 0
        for i in range(len(A)):
            curr_xor ^= A[i]
            comp = curr_xor ^ B
            if comp in xor_map:
                counter += len(xor_map[comp])
            if curr_xor in xor_map:
                xor_map[curr_xor].append(i)
            else:
                xor_map[curr_xor] = [i]

        return counter
