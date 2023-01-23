#include <bits/stdc++.h>
using namespace std;
int main()
{
    int cases;
    cin>>cases;
    for(int i=0; i<cases; i++)
    {
        int friends;
        cin>>friends;
        vector<int> spend, have;
        for(int j=0; j<friends; j++)
        {
            int a;
            cin>>a;
            spend.push_back(a);
        }
        for(int j=0; j<friends; j++)
        {
            int b;
            cin>>b;
            have.push_back(b);
        }
        vector<int> remain;
        for(int j=0; j<friends; j++)
        {
            remain.push_back(have[j]-spend[j]);
        }
        sort(remain.begin(), remain.end());
        int k=0, count=0;
        for(int j=friends-1; j>=0; j--)
        {
            while(j>k && remain[k]+remain[j] < 0) k++;
            if(j<=k)break;
            count++, k++;
        }
        cout<<count<<endl;
    }
}