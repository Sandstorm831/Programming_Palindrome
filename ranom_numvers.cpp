#include <bits/stdc++.h>
using namespace std;
vector<long long> dict = {1,10,100,1000, 10000};
long long func(string s)
{
    long long ans=0;
    long long maxx=0;
    for(long long i=s.length()-1; i>=0; i--)
    {
        if(s[i]-'A' >= maxx)
        {
            ans += dict[s[i]-'A'];
            maxx = s[i]-'A';
        }
        else ans -= dict[s[i]-'A'];
    }
    return ans;
}
int main()
{
    long long cases;
    cin>>cases;
    while(cases--)
    {
        string s; cin>>s;
        long long ai=-1, bi=-1, ci=-1, di=-1, ei=-1;
        long long af=-1, bf=-1, cf=-1, df=-1, ef=-1;
        for(long long i=0; i<s.length(); i++)
        {
            if(s[i]=='A' && ai == -1)
            {
                ai = i, af=i;
            }
            else if(s[i]=='A') af=i;
            if(s[i]=='B' && bi == -1)
            {
                bi = i, bf=i;
            }
            else if(s[i]=='B') bf=i;
            if(s[i]=='C' && ci == -1)
            {
                ci = i, cf=i;
            } 
            else if(s[i]=='C') cf=i;
            if(s[i]=='D' && di == -1)
            {
                di = i, df=i;
            }
            else if(s[i]=='D') df=i;
            if(s[i]=='E' && ei == -1)
            {
                ei = i, ef=i;
            } 
            else if(s[i]=='E') ef=i;
        }
        long long maxer = func(s);
        string orig = s;
        if(ef != -1)
        {
            s[ef]='D';
            maxer =  max(maxer,func(s));
            s[ef]='C';
            maxer =  max(maxer,func(s));
            s[ef]='B';
            maxer =  max(maxer,func(s));
            s[ef]='A';
            maxer =  max(maxer,func(s));
            s[ef]='E';
        }
        if(df != -1)
        {
            s[df]='C';
            maxer =  max(maxer,func(s));
            s[df]='B';
            maxer =  max(maxer,func(s));
            s[df]='A';
            maxer =  max(maxer,func(s));
            s[df]='D';
        }
        if(cf != -1)
        {
            s[cf]='B';
            maxer =  max(maxer,func(s));
            s[cf]='A';
            maxer =  max(maxer,func(s));
            s[cf]='C';   
        }
        if(bf != -1)
        {
            s[bf]='A';
            maxer =  max(maxer,func(s));
            s[bf]='B'; 
        }
        if(di != -1)
        {
            s[di]='E';
            maxer =  max(maxer,func(s));
            s=orig;
        }
        if(ci != -1)
        {
            s[ci]='E';
            maxer =  max(maxer,func(s));
            s=orig;
        }
        if(bi != -1)
        {
            s[bi]='E';
            maxer =  max(maxer,func(s));
            s=orig;
        }
        if(ai != -1)
        {
            s[ai]='E';
            maxer =  max(maxer,func(s));
            s=orig;
        }
        cout<<maxer<<endl;
    }
}