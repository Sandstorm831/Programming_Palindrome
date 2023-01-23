// Problem Link - https://www.interviewbit.com/problems/occurence-of-each-number/
#include <bits/stdc++.h>
using namespace std;
vector<int> findOccurences(vector<int> &A) {
    
    map<int,int> mp;
    for(int i=0;i<A.size();i++)
    {
        if(mp.find(A[i]) == mp.end()) mp[A[i]] = 1;
        else mp[A[i]]++;
    }
    vector<int> ans;
    for(auto itr = mp.begin(); itr!=mp.end(); itr++)
    {
        ans.push_back(itr->second);
    }
    return ans;
}