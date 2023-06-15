// Question LInk - https://www.interviewbit.com/problems/minimum-characters-required-to-make-a-string-palindromic/
// Solution

int kmp(string A)
{
    int n = A.length();
    vector<int> lps(n, 0);
    for(int i=1; i<n; i++)
    {
        int j = lps[i-1];
        while(j>0 && A[j] != A[i]) j = lps[j-1];
        if(A[i] == A[j]) j++;
        lps[i] = j;
    }
    return lps[n-1];
}
int Solution::solve(string A) {
    string t = A;
    reverse(A.begin(), A.end());
    t += '&';
    t += A;
    int x = kmp(t);
    return A.size()-x;
}