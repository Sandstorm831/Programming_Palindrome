// Question Link - https://www.interviewbit.com/problems/next-similar-number/
// Solution

string Solution::solve(string A) {
    int h=-1, l=-1;
    for(int i = A.size()-1; i>0; i--)
    {
        if(A[i]>A[i-1])
        {
            l = i-1;
            break;
        }
    }
    if(l==-1) return "-1";
    for(int i=A.size()-1; i>0; i--)
    {
        if(A[i]>A[l]) 
        {
            h=i;
            break;
        }
    }
    char x = A[l];
    A[l] = A[h];
    A[h] = x;
    sort(A.begin()+l+1, A.end());
    return A;
}
