// Question Link - https://www.interviewbit.com/problems/addition-without-summation/
// Solution

int Solution::addNumbers(int A, int B) {
    if(B == 0)
    {
        return A;
    }
    return addNumbers(A^B, (A&B)<<1);
}
