#include <bits/stdc++.h>
using namespace std;
int main()
{
    int cases;
    cin>>cases;
    for(int i=0; i<cases;i++)
    {
        // cout<<"her"<<endl;
        int n, m;
        cin>>n>>m;
        int maxx = INT_MIN;
        int ii, jj;
        for(int j=1; j<=n; j++)
        {
            for(int k=1; k<=m; k++)
            {
                // cout<<"fer"<<endl;
                int a;
                cin>>a;
                if(maxx<a)
                {
                    maxx = a;
                    ii = j;
                    jj = k;
                }
            }
        }
        int row = max(ii, n-ii+1);
        int col = max(jj, m-jj+1);
        cout<<row*col<<endl;
    }
}