# InterviewBit Solution
# Link : https://www.interviewbit.com/problems/repeat-and-missing-number-array/

class Solution:
    # @param A : list of integers
    # @return a list of integers
    def repeatedNumber(self, A):
        length = len(A)
        squareSum = (length * (length+1) * (2*length + 1)) // 6
        normalSum = (length * (length + 1)) // 2
        arraySquareSum = 0
        arrayNormalSum = 0
        for i in range(len(A)):
            arrayNormalSum += A[i]
            arraySquareSum += A[i]*A[i]
        ab = arrayNormalSum - normalSum
        ba = arraySquareSum - squareSum
        sm = ba//ab
        repeater = (ab + sm) // 2
        noRepeater = sm - repeater
        return [repeater, noRepeater]