#include <bits/stdc++.h>
using namespace std;
int main()
{
    int cases;
    cin>>cases;
    for(int i=0; i<cases;i++)
    {
        int n, m;
        cin>>n>>m;
        string str;
        char t = 'B';
        str.append(m, t);
        set<int> v;
        for(int j=0; j<n; j++)
        {
            int a;
            cin>>a;
            int x = min(a,m+1-a);
            int y = max(a, m+1-a);
            if(v.find(x) == v.end())
            {
                v.insert(x);
                str[x-1]='A';
            }
            else if(v.find(y) == v.end())
            {
                v.insert(y);
                str[y-1]='A';
            }
        }
        cout<<str<<endl;
    }
}