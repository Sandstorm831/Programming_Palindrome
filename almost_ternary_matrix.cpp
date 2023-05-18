#include <bits/stdc++.h>
using namespace std;
int main()
{
    int cases;
    cin>>cases;
    vector<int> v={1,0,0,1};
    vector<int> d={0,1,1,0};
    for(int i=0; i<cases; i++)
    {
        int r, c;
        cin>>r>>c;
        for(int j=0; j<r; j++)
        {
            for(int k=0;k<c; k++)
            {
                if(j%4==0 || j%4 == 3)
                {
                    cout<<v[k%4]<<" ";
                }
                else
                {
                    cout<<d[k%4]<<" ";
                }
            }
            cout<<endl;
        }
    }
}