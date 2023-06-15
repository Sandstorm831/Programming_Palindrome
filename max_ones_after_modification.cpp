// Question Link - https://www.interviewbit.com/problems/maximum-ones-after-modification/
// solution

int Solution::solve(vector<int> &A, int B) {
    int zeros=0;
    int maxl = 0;
    int j=0;
    for(int i=0; i<A.size(); i++)
    {
        while(zeros>B && i<A.size())
        {
            if(A[i] == 0)
            {
                zeros--;
                i++;
            }
            else i++;
        }
        if(i>=A.size())break;
        if(j<i) j=i;
        for(; j<A.size() ; j++)
        {
            if(A[j] == 1)
            {
                maxl = max(maxl, j-i+1);
            }
            else if(A[j] == 0)
            {
                zeros++;
                if(zeros<=B)
                {
                    maxl = max(maxl, j-i+1);
                }
                else
                {
                    zeros--;
                    break;
                }
            }
        }
        if(A[i] == 0)
        {
            zeros--;
            if(zeros<0) zeros=0;
        }
    }
    return maxl;
}
