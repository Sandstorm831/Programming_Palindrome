#include <bits/stdc++.h>
using namespace std;
int main()
{
    int cases;
    cin>>cases;
    for(int j=0; j<cases; j++)
    {
        int n;
        cin>>n;
        vector<int> k;
        vector<pair<int,int>> pb;
        for(int i=0; i<n;i++)
        {
            int a;
            cin>>a;
            k.push_back(a);
        }
        int counter = 0;
        if((k[0]+k.back())%2==0 && k[0]!=k.back()) 
        {
            k[0] = k.back();
            pb.push_back(make_pair(1, k.size()));
            counter++;
        }
        else if((k[0]+k.back())%2==1 && k[0]!=k.back())
        {
            k[k.size()-1] = k[0];
            pb.push_back(make_pair(1, k.size()));
            counter++;
        } 
        for(int i=1; i<n-1; i++)
        {
            if((k[0]+k[i])%2 == 1) pb.push_back(make_pair(1,i+1));
            else pb.push_back(make_pair(i+1, k.size()));
            counter++;
        }
        cout<<counter<<endl;
        for(int i=0; i<pb.size(); i++)
        {
            cout<<pb[i].first<<" "<<pb[i].second<<endl;
        }
        cout<<endl;
    }
}