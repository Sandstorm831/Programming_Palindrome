#include <bits/stdc++.h>
using namespace std;
int main()
{
    int cases;
    cin>>cases;
    for(int i=0;i<cases; i++)
    {
        int n;
        cin>>n;
        vector<int> v;
        vector<int> count(n+1,1);
        v.push_back(0);
        for(int j=0; j<n; j++)
        {
            int x;
            cin>>x;
            v.push_back(x);
        }
        int components=0;
        int index=1;
        int target=v[index];
        for(int j=1;j<=n; j++)
        {
            if(count[index] == 0)
            {
                while (count[index]!=1 && index<=n) index++;
            }
            if(target<index) 
            {
                components++;
                target = v[index];
            }
            if(v[j] > target) target=v[j];
            count[v[j]]=0;
        }
        cout<<components+1<<endl;
    }
}