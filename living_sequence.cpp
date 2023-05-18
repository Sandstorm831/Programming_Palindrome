#include <bits/stdc++.h>
using namespace std;
long long fourfinder(long long x)
{
    vector<long long> v;
    while(x>0)
    {
        long long k = x%10;
        x = x/10;
        v.push_back(k);
    }
    reverse(v.begin(), v.end());
    long long s = v.size();
    long long tot=0;
    long long c = s;
    for(long long i=0; i<v.size(); i++)
    {
        c--;
        long long m = v[i];
        if(m<=4)
        {
            tot += m*pow(9,c); 
        }
        else if(m>4)
        {
            tot += (m-1)*pow(9,c);
        }
        if(m == 4) 
        {   
            tot--;
            break;
        }
    }
    return tot;
}
int main()
{
    long long cases;
    cin>>cases;
    for(long long i=0;i<cases; i++)
    {
        long long n;
        cin>>n;
        // cout<<fourfinder(n)<<endl;
        long long l = n;
        long long h = 10*n;
        long long mid = (h+l)/2;
        // cout<<h<<" "<<mid<<" "<<l<<endl;
        while(l<=h)
        {
            long long xx = fourfinder(mid);
            // cout<<xx<<" "<<mid<<endl;
            if(xx == n) 
            {
                break;
            }
            else if(xx>n) h = mid-1;
            else if(xx<n) l = mid+1;
            mid = (h+l)/2;
            // cout<<h<<" "<<mid<<" "<<l<<endl;
        }
        long long mider = mid;
        vector<long long> v;
        while(mid>0)
        {
            long long k = mid%10;
            mid = mid/10;
            v.push_back(k);
        }
        reverse(v.begin(), v.end());
        bool cot = false;
        for(long long j=0; j<v.size(); j++)
        {
            if(cot)
            {
                cout<<9;
                continue;
            }
            if(v[j] == 4) 
            {
                cout<<v[j]-1;
                cot=true;
            }
            else cout<<v[j];
        }
        cout<<endl;
    }
}