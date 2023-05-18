#include <bits/stdc++.h>
using namespace std;
int main()
{
    int cases;
    cin>>cases;
    for(int i=0; i<cases; i++)
    {
        string s;
        cin>>s;
        int n = s.size();
        set<char> dif;
        for(int i=0; i<n; i++)
        {
            if(n%2==1 && i == n/2) continue;
            dif.insert(s[i]);
        }
        if(n%2==0 && dif.size()>=2) cout<<"Yes"<<endl;
        else if(n%2==1 && dif.size()>=2) cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }
}