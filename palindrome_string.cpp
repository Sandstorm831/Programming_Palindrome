// Question Link - https://www.interviewbit.com/problems/palindrome-string/
// Solution

int Solution::isPalindrome(string A) {
    string t="";
    for(int i=0; i<A.size(); i++)
    {
        if(A[i] - '0' >= 0 && A[i] - '0' <=9) t += A[i];
        else if(A[i] - 'A' >= 0 && A[i] - 'A' <= 25) t+=A[i]+32;
        else if(A[i] - 'a' >= 0 && A[i] - 'a' <= 25) t+=A[i];
    }
    // cout<<t<<endl;
    string x = t;
    reverse(t.begin(), t.end());
    return x == t;
}
