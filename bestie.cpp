#include <bits/stdc++.h>
using namespace std;
int gcd(int A, int B){
    if(B==0){

        return A;
    }
    return gcd(B, A%B);
}
int main()
{
    int cases;
    cin>>cases;
    for(int i=0; i<cases; i++)
    {
        int n;
        cin>>n;
        vector<int> ary;
        for(int j=0; j<n; j++)
        {
            int x;
            cin>>x;
            ary.push_back(x);
        }
        if(n==1)
        {
            if(ary[0] == 1) cout<<0<<endl;
            else cout<<1<<endl;
            continue;
        }
        else if(n==2)
        {
            int x = gcd(ary[0], ary[1]);
            if(x == 1) cout<<0<<endl;
            else
            {
                int l = gcd(2,ary[1]);
                if(gcd(l,ary[0])==1) cout<<1<<endl;
                else cout<<2<<endl;
            }
            continue;
        }
        else if(n==3)
        {
            int x = gcd(ary[0],gcd(ary[1], ary[2]));
            if(x==1) cout<<0<<endl;
            else
            {
                int b = gcd(3,ary[2]);
                if(gcd(ary[0], gcd(ary[1], b)) == 1) cout<<1<<endl;
                else
                {
                    b = gcd(2, ary[1]);
                    if(gcd(ary[0], gcd(b,ary[2])) == 1) cout<<2<<endl;
                    else cout<<3<<endl;
                }
            }
            continue;
        }
        else
        {
            int gcdd=ary[0];
            for(int j=1; j<n-2; j++)
            {
                gcdd = gcd(gcdd, ary[j]);
            }
            int x = gcd(gcdd, gcd(ary[n-1], ary[n-2]));
            if(x==1) cout<<0<<endl;
            else
            {
                int b = gcd(n,ary[n-1]);
                if(gcd(gcdd, gcd(ary[n-2], b)) == 1) cout<<1<<endl;
                else
                {
                    b = gcd(n-1, ary[n-2]);
                    if(gcd(gcdd, gcd(b,ary[n-1])) == 1) cout<<2<<endl;
                    else cout<<3<<endl;
                }
            }
            continue;
        }

    }
}