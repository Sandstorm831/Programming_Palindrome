#include <bits/stdc++.h>
using namespace std;
int gcd(int a, int b)
{
    if(b==0)
    {
        return a;
    }
    else return gcd(b,a%b);
}
int lcm(int a, int b)
{
    return (a*b)/gcd(a,b);
}
int main()
{
    int cases;
    cin>>cases;
    for(int i=0; i<cases; i++)
    {
        int n;
        cin>>n;
        vector<int> df;
        vector<int> orig;
        int prev = 1;
        for(int j=0; j<n; j++)
        {
            int a;
            cin>>a;
            orig.push_back(a);
            df.push_back(lcm(prev,a));
            prev=a;
        }
        df.push_back(prev);
        vector<int> gc;
        bool check=true;
        for(int j=0; j<n; j++)
        {
            gc.push_back(gcd(df[j],df[j+1]));
            if(gc[j] != orig[j])
            {
                cout<<"NO"<<endl;
                check=false;
                break;
            }
        }
        if(check) cout<<"YES"<<endl;
    }
}