// Question Link - https://www.interviewbit.com/problems/pair-with-given-difference/
// Solution

int Solution::solve(vector<int> &A, int B) {
    if(A.size()==1) return 0;
    else if(A.size()==2) return abs(A[0]-A[1]) == abs(B);
    sort(A.begin(), A.end());
    int lo = 0, hi = 1;
    bool gotit = false;
    while(hi<A.size())
    {
        if(hi == lo+1)
        {
            if(A[hi] - A[lo] == abs(B)) return 1;
            hi++;
            continue;
        }
        if(A[hi] - A[lo] == abs(B)) return 1;
        else if(A[hi]-A[lo] < abs(B)) hi++;
        else if(A[hi]-A[lo] > abs(B)) lo++;
    }
    return gotit;
}
