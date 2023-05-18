#include <bits/stdc++.h>
using namespace std;
vector<long long> ad;
long long gcd(long long a, long long b) {
   if (b == 0)
   return a;
   return gcd(b, a % b);
}
long long lcm(long long a, long long b)
{
    return (a*b)/(gcd(a,b));
}
void pdiff(long long bd, long long cd)
{
    for(long long i=1; i*i<=cd; i++)
    {
        if(cd%i == 0)
        {
            if(lcm(i,bd)==cd) ad.push_back(i); 
            if(i*i!=cd && lcm(cd/i,bd) == cd) ad.push_back(cd/i);
        }
    }
}
void solve() 
{
    long long mod = 1e9+7;
    long long b, bd, bn, c, cd, cn;
    cin>>b>>bd>>bn>>c>>cd>>cn;
    long long e = b+bd*(bn-1);
    long long f = c+cd*(cn-1);
    if(c<b || c>e || f<b || f>e || cd%bd!=0 || (c-b)%bd!=0) 
    {
        cout<<0<<endl;
        return;
    }
    else if(c-cd<b || f+cd>e)
    {
        cout<<-1<<endl;
        return;
    }
    ad.clear();
    pdiff(bd, cd);
    long long lwr = c-cd+1;
    long long upr = c;
    long long counter=0;
    for(long long k=0; k<ad.size(); k++)
    {
        long long pr = (1 + ((cd-1)%mod/ad[k]%mod)%mod)%mod;
        counter = ((counter%mod)+((pr%mod)*(pr%mod))%mod)%mod;
    }
    cout<<counter<<endl;

}
int main(){
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	long long T;
	cin >> T;
	while(T--) solve();
}