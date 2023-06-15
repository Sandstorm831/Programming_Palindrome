// Question Link - https://www.interviewbit.com/problems/ways-to-form-max-heap/
// Solution 

const long long mod = 1e9+7;
long long findbelow(long long x, long long A)
{
    if(x>A) return 0;
    else return findbelow(2*x, A)+findbelow(2*x+1, A)+1;
}
long long power(long long a, long long p)
{
    long long result = 1;
    while(p>0)
    {
        if(p&1) result = (result * 1ll * a) % mod;
        a = (a * 1ll * a) % mod;
        p = p>>1;
    }
    return result;
}
long long fact(long long a)
{
    if(a==0 || a==1) return 1;
    else return ((a%mod)*(fact(a-1)%mod))%mod;
}
long long calculator(long long curr, long long A)
{
    if(curr > A) return 0;
    long long left = findbelow(2*curr, A);
    long long right = findbelow(2*curr+1,A);
    long long whole =  left+right;
    if(whole+1==1) return 1;
    else if(whole+1==2) return 1;
    else if(whole+1==3) return 2;
    whole = fact(whole)%mod;
    left = fact(left)%mod;
    right = fact(right)%mod;
    long long den = (left * right)%mod;
    whole =  ((whole%mod) * ((power(den,mod-2)%mod)%mod))%mod;
    long long next = calculator(2*curr, A)%mod;
    long long nxtnxt = calculator(2*curr+1, A)%mod;
    return (whole * ((next * nxtnxt)%mod)) % mod;
    
}
int Solution::solve(int A) {
    long long a = 1ll*A;
    if(A==1) return 1;
    else if(A==2) return 1;
    else if(A==3) return 2;
    long long curr = 1;
    long long summ =0;
    summ += calculator(curr, a);
    return summ;
}
