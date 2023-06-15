// Question Link - https://www.interviewbit.com/problems/counting-subarrays/
// Solution
int Solution::solve(vector<int> &A, int B) {
    int n=A.size(),count=0,sum=0,j=0;

    for(int i=0;i<n;i++)
    {
        sum+=A[i];
        while(sum>=B)
        {
            sum-=A[j];
            j++;
        }
        count+=i-j+1;
    }
    return count;
}

