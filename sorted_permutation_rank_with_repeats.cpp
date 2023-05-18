// Question Link - https://www.interviewbit.com/problems/sorted-permutation-rank-with-repeats/
// Solution

////////////////////
// long long int power(long long int A,long long int B)
// {    
//     int MOD=1000003;
//     if(A==0) return 0;
//     if(B==0) return 1;
//     long result;
//     if(B%2==0)
//     {
//         result=power(A,B/2);
//         result=(result*result)%MOD;
//     }
//     else
//     {
//         result=A%MOD;
//         result=(result%MOD * power(A,B-1)%MOD)%MOD;
//     }
//     return result%MOD;
// }
// int Solution::findRank(string A)
// {
//     int MOD=1000003;
//     int count=1;
//     for(int i=0;i<A.size()-1;i++)
//     {
//         int c=0;
//         for(int j=i+1;j<A.length();j++) if(A[i]>A[j]) c++;
//         map<char,int>m;
//         for(int j=i;j<A.size();j++) m[A[j]]++;
//         long long d=1;
//         for(auto y:m) d=((d%MOD)*(factorial(y.second)%MOD))%MOD;
//         int k=factorial(A.size()-i-1)%1000003;
//         count= ( count + c * ( k * power(d,MOD-2)%MOD )%MOD ) %MOD;
//     }
//     return count;
// }

//////////

int mod = 1000003;

long long power(long long x, long long y)
{
    long long res = 1;
    while (y > 0) {
        if (y & 1ll)
            res = (res * x) % mod;
        y = y >> 1;
        x = (x * x) % mod;
    }
    return res;
}
int inverse(int a)
{
    return power(a, mod - 2);
}

int Solution::findRank(string A) {
    
    multiset<char> s(A.begin(), A.end());
    long long ans = 0;

    map<char,int> f;
    for(char c : A) f[c]++;

    int n = A.size();
    vector<int> fact(n+1, 1);

    for(int i = 1; i<=n; i++) fact[i] = fact[i-1] * i, fact[i] %= mod;
    for(int i = 0; i<n; i++)
    {
        char smallest = *s.begin();
        char curr = A[i];
        for(char c = smallest; c < curr; c++)
        {
            if(f[c])
            {
                f[c]--;
                long long sum = 0;
                long long temp = 1;
                for(auto [c1, freq] : f)
                {
                    sum += freq;
                    temp *= inverse(fact[freq]), temp %= mod;
                }
                temp *= fact[sum];
                temp %= mod;
                ans += temp;
                ans %= mod;
                f[c]++;
            }
        }
        f[curr]--;
        s.erase(s.find(curr));
    }

    return (ans+1) % mod;
}

