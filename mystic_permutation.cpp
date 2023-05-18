#include <bits/stdc++.h>
using namespace std;
void swap(vector<int>& s, int x, int y)
{
    int a = s[x];
    s[x] = s[y];
    s[y] = a;
}
int main()
{
    int cases;
    cin>>cases;
    for(int i=0; i<cases; i++)
    {
        int n;
        cin>>n;
        vector<int> s;
        vector<int> v;
        for(int j=1; j<=n; j++)
        {
            int x;
            cin>>x;
            v.push_back(x);
            s.push_back(j);
        }
        if(n==1)
        {
            cout<<-1<<endl;
            continue;
        }
        for(int j=0; j<n-1;j++)
        {
            if(s[j]==v[j])
            {
                swap(s, j, j+1);
            }
        }
        if(s.back()==v.back()) swap(s,n-2,n-1);
        for(int j=0;j<n; j++)
        {
            cout<<s[j]<<" ";
        }
        cout<<endl;
    }
}