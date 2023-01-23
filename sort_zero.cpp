#include <bits/stdc++.h>
using namespace std;
int oper(vector<int>& v, vector<int>& s, int index)
{
    int c=0;
    for(int i=index; i>=0; i--)
    {
        if(s[v[i]]>0)
        {
            c++;
            s[v[i]]=0;
        }
    }
    return c;
}
int main()
{
    int cases;
    cin>>cases;
    for(int i=0;i<cases;i++)
    {
        int n;
        cin>>n;
        vector<int> v;
        vector<int> s(n+1, 0);
        for(int j=0;j<n;j++)
        {
            int a;
            cin>>a;
            v.push_back(a);
            s[a]++;
        }
        int counter=0;
        for(int j=n-1; j>0; j--)
        {
            if(s[v[j]] > 1 && v[j-1]!=v[j]) 
            {
                counter += oper(v,s,j);
                break;
            }
            else if(s[v[j]]>1)
            {
                s[v[j]]--;
                continue;
            }
            else if(v[j-1]>v[j])
            {
                counter += oper(v,s,j-1);
                break;
            }
        }
        cout<<counter<<endl;
    }
}