#include <bits/stdc++.h>
using namespace std;
int main()
{
    int cases;
    cin>>cases;
    vector<string> ans;
    for(int i=0; i<cases; i++)
    {
        int a, b, c, d;
        cin>>a>>b>>c>>d;
        if((a<b) == (c<d) && (a<c) == (b<d))
        {
            ans.push_back("YES");
        }
        else ans.push_back("NO");
    }
    for(int i=0; i<ans.size(); i++)
    {
        cout<<ans[i]<<endl;
    }
}