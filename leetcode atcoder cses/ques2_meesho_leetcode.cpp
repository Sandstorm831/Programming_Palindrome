#include <bits/stdc++.h>
using namespace std;
int main()
{
    string a,b;cin>>a>>b;
    unordered_map<char,vector<int>> ump;
    int x=0,y=0, z=0;
    for(int i=b.size()-1; i>=0; i--)
    {
        if(b[i] == a[2]) ump[b[i]].push_back(i);
        else if(b[i] == a[1]) ump[b[i]].push_back(i);
        else if(b[i] == a[0]) ump[b[i]].push_back(i);
    }
    vector<int> c(b.size()+2, 0);
    sort(ump[a[0]].begin(), ump[a[0]].end());
    sort(ump[a[1]].begin(), ump[a[1]].end());
    sort(ump[a[2]].begin(), ump[a[2]].end());
    int j  = b.size()-1;
    for(int i=ump[a[2]].size()-1; j>=0; j--)
    {
        if(j == ump[a[2]][i])
        {
            c[j] = ++z;
            i--;
        }
        else 
        {
            c[j] = z;
        }
    }
    int counter = 0;
    for(int i=0; i<ump[a[0]].size(); i++)
    {
        int index = ump[a[0]][i];
        int ind = lower_bound(ump[a[1]].begin(), ump[a[1]].end(), index+1)-ump[a[1]].begin();
        for(int j=ind; j<ump[a[1]].size();j++)
        {
            int lm = ump[a[1]][j];
            counter += c[lm+1];
        }   
    }
    cout<<counter<<endl;
}