// Problem Link - https://www.interviewbit.com/problems/max-distance/
#include <bits/stdc++.h>
using namespace std;
int maximumGap(vector<int> A)
{
    int n=A.size();
    vector<pair<int,int> >v;
    for(int i=0;i<n;i++){
        v.push_back(make_pair(A[i],i));
    }
    sort(v.begin(),v.end());
    int ans=0;
    int rmax=v[n-1].second;
    for(int i=n-2;i>=0;i--){
        ans=max(ans,rmax-v[i].second);
        rmax=max(rmax,v[i].second);
    }
    return ans;
}
int main()
{
    vector<int> A = {6,3,5,4,2,3,5};
    cout<<maximumGap(A);
}