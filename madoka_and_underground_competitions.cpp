#include <bits/stdc++.h>
using namespace std;
int main()
{
    int cases;
    cin>>cases;
    for(int i=0;i<cases;i++)
    {
        int n,k,r,c;
        cin>>n>>k>>r>>c;
        // vector<vector<char>> space(n, vector<char> (n, '.'));
        for(int j=1;j<=n; j++)
        {
            for(int l=1; l<=n; l++)
            {
                if(abs(l-(c-(r-j)))%k == 0) cout<<'X';
                else cout<<'.';
            }
            cout<<endl;
        }
        // cout<<endl;
    }
}