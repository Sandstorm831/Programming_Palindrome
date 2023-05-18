// Question Link - https://www.interviewbit.com/problems/next-permutation/
// Solution

vector<int> Solution::nextPermutation(vector<int> &A) {
    int cnt=-1, nt=-1;
    for(int i=A.size()-2; i>=0; i--)
    {
        if(A[i+1]>A[i])
        {
            cnt=i;
            break;
        }
    }
    if(cnt ==-1)
    {
        reverse(A.begin(), A.end());
        return A;
    }
    for(int i=A.size()-1; i>cnt; i--)
    {
        if(A[i]>A[cnt])
        {
            nt = i;
            break;
        }
    }
    swap(A[cnt],A[nt]);
    reverse(A.begin()+cnt+1, A.end());
    return A;
}