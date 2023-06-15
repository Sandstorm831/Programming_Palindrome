// Question Link - https://www.interviewbit.com/problems/different-bits-sum-pairwise/
// Solution

// TLE 
int poww(int x)
{
    int count=0;
    while(x>0)
    {
        if(x&1) count++;
        x = x>>1;
    }
    return count;
}
int Solution::cntBits(vector<int> &A) {
    vector<int> store;
    int counter=0;
    for(int i=0; i<A.size(); i++)
    {
        for(int j=0; j<A.size(); j++)
        {
            counter+= poww(A[i]^A[j]);
        }
    }
    return counter;
}
//////////////////////////////////////////////////
int Solution::cntBits(vector<int> &A){
    long long mod=1e9+7;
    long long summ=0;
    long long n = A.size();
    for(long long i=0; i<32; i++)
    {
        long long zs = 0;
        for(long long j=0; j<A.size(); j++)
        {
            if(((1<<i)&A[j]) == 0) zs++;
        }
        summ = ((summ%mod) + (2l*(zs%mod*(n-zs)%mod)%mod)%mod)%mod;
    }
    return summ;
}
