#include <bits/stdc++.h>
using namespace std;
int main()
{
    int cases;
    cin>>cases;
    unordered_set<int> holder;
    vector<int> cml;
    vector<int> sum_holder;
    for(int i=0; i<cases; i++)
    {
        int n;
        cin>>n;
        int prev=0;
        holder.clear();
        cml.clear();
        sum_holder.clear();
        for(int j=0; j<n; j++)
        {
            int a;
            cin>>a;
            cml.push_back(prev+a);
            holder.insert(cml.back());
            prev=cml.back();
        }
        for(int j=0; j<cml.size(); j++)
        {
            for(int k=2; k<=cml.size(); k++)
            {
                if(holder.find(cml[j]*k)==holder.end()) 
                {
                    break;
                }
                else if(holder.find(cml[j]*k) != holder.end() && cml[j]*k != cml.back()) 
                {
                    continue;
                }
                else if(holder.find(cml[j]*k) != holder.end() && cml[j]*k == cml.back())
                {
                    sum_holder.push_back(cml[j]);
                    break;
                }
            }
        }
        if(sum_holder.empty()) 
        {
            cout<<cml.size()<<endl;
            continue;
        }
        int colt;
        int ans = INT_MAX;
        for(int j=0; j<sum_holder.size(); j++)
        {
            int init=-1;
            int mult=1;
            colt = INT_MIN;
            for(int k=0; k<cml.size(); k++)
            {
                if(mult*sum_holder[j] == cml[k])
                {
                    mult++;
                    colt = max(colt, k-init);
                    init = k;
                }
            }
            ans = min(ans, colt);
        }
        cout<<ans<<endl;
    }
}