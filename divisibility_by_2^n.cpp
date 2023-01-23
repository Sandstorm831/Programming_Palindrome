#include <bits/stdc++.h>
using namespace std;
int main()
{
    vector<int> a;
    vector<int> orig;
    int n;
    cin>>n;
    for(int i=1; i<=n; i++)
    {
        int b;
        cin>>b;
        a.push_back(log2(b&(~(b-1))));
        orig.push_back(log2(i&(~(i-1))));
    }
    sort(a.begin(), a.end(), greater<int>());
    sort(orig.begin(), orig.end(), greater<int>());
    int sum=0;
    int alt_sum=0;
    for(int i=0; i<a.size(); i++)
    {
        sum+=a[i];
        alt_sum+=orig[i];
    }
    int counter=0;
    if(sum >= n) cout<<0;
    else if(sum + alt_sum < n) cout<<-1;
    else
    {
        while(sum < n)
        {
            sum += orig[counter];
            counter++;
        }
        cout<<counter;
    }
}