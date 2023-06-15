// Question Link - https://www.interviewbit.com/problems/count-total-set-bits/
// Solution

int Solution::solve(int A) {
    long long mod = 1e9+7;
    long long summ=0;
    long long k=1;
    while(k<32)
    {
        long long q = A / (1<<k);
        long long r = A % (1<<k);
        summ = ((summ%mod) + (((1<<(k-1))%mod)*(q%mod))%mod + max(r-((1<<(k-1))-1), 0ll)%mod)%mod;
        k++;
    }
    return summ;
}
