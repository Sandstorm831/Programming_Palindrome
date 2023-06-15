#include <bits/stdc++.h>
using namespace std;
int main()
{
    int cases;
    cin>>cases;
    while(cases--)
    {
        int n,m;
        cin>>n>>m;
        vector<vector<int>> v(n, vector<int> (m));
        if(m%2 == 0)
        {
            int num=1;
            for(int i=0; i<n; i++)
            {
                for(int j=0; j<m; j++) cout<<(num++)<<" ";
                cout<<endl;
            }
            continue;
        }
        else if(n%2==0)
        {
            int num=1;
            for(int i=0; i<m; i++)
            {
                for(int j=0; j<n; j++) v[j][i] = num++;
            }
        }
        else
        {
            int num=1;
            int count = n;
            int i=0;
            while(count>0)
            {
                count--;
                for(int j=0; j<m; j++)
                {
                    v[i][j] = num++;
                }
                i = (i+2)%(n);
            }
        }
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++) cout<<v[i][j]<<" ";
            cout<<endl;
        }
    }
}