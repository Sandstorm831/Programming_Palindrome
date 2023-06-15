// Question Link - https://www.interviewbit.com/problems/self-permutation/
// Solution 

int Solution::permuteStrings(string A, string B) {
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    return A == B;
}
