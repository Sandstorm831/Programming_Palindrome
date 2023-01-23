#include <bits/stdc++.h>
using namespace std;
int main()
{
    int cases;
    cin>>cases;
    for(int i=0; i<cases; i++)
    {
        vector<int> cap(10, -1);
        int de=0;
        int x;
        cin>>x;
        string s;
        int counter=0;
        cin>>s;
        bool ans=true;
        int maxx = INT_MIN;
        for(int j=0; j<x; j++)
        {
            ans=true;
            maxx = INT_MIN;
            de = 0;
            int looper=0;
            fill(cap.begin(), cap.end(), -1);
            for(int k=j; k<x; k++)
            {
                looper++;
                if(looper>100) break;
                int a = s[k]-'0';
                if(cap[a] == -1)
                {
                    de++;
                    cap[a]=1;
                    maxx = max(maxx, cap[a]);
                    if(maxx>de) ans=false;
                    else ans=true;
                }
                else
                {
                    cap[a]++;
                    maxx = max(maxx, cap[a]);
                    if(maxx>de) ans = false;
                    else ans=true;
                }
                if(ans) 
                {
                    counter++;
                }
            }
        }
        cout<<counter<<endl;
    }
}