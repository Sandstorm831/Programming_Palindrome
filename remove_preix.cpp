#include <bits/stdc++.h>
using namespace std;
int main()
{
    int cases;
    cin>>cases;
    for(int i=0; i<cases; i++)
    {
        int n;
        cin>>n;
        vector<int> hell;
        for(int j=0; j<n; j++)
        {
            int a;
            cin>>a;
            hell.push_back(a);
        }
        reverse(hell.begin(), hell.end());
        set<int> holder;
        int counter=0;
        for(int j=0; j<n; j++)
        {
            holder.insert(hell[j]);
            if (holder.size()<j+1) break;
            counter++;
        }
        cout<<n-counter<<endl;
    }
}