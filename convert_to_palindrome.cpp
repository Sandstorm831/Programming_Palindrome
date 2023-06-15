// Question Link - https://www.interviewbit.com/problems/convert-to-palindrome/
// Solution

int Solution::solve(string A) {
    string B = A;
    reverse(B.begin(), B.end());
    if(A == B) return 1;
    bool x = true;
    bool onc = true;
    int ini = 0, fin = A.size()-1;
    while(ini<=fin && x)
    {
        if(A[ini] !=  A[fin])
        {
            if(A[ini+1] == A[fin] && onc) ini++;
            else x = false;
            onc = false;
        } 
        ini++;
        fin--;
    }
    if(x) return 1;
    ini = 0, fin = A.size()-1;
    x=true;
    onc=true;
    while(ini<=fin && x)
    {
        if(A[ini] !=  A[fin])
        {
            if(A[ini] == A[fin-1] && onc) fin--;
            else x = false;
            onc = false;
        } 
        ini++;
        fin--;
    }
    return x;
}
