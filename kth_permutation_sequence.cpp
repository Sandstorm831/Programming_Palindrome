//Problem Link - https://www.interviewbit.com/problems/kth-permutation-sequence/
#include <bits/stdc++.h>
using namespace std;
int factorial(int n){
    if (n>12)   
        return INT_MAX;
    int f = 1;
    for (auto i = 2; i<=n; ++i)
        f *= i;
    return f;
}
vector<int> finder(int a, int b, vector<int> &ans){
    int d  = b/factorial(a-1);
    ans.push_back(d);
    a = a-1;
    if (a-1<=0)
    {
        return ans;
    }
    return finder(a, b-d*factorial(a), ans);
}

int main()
{
    string s = "";
    int a = 100, b=10000000; // These have to be assumed
    if (a==1)
    {
        s = s+to_string(1);
    }
    else{
    vector<int> nanum;
    for (int i = 1; i <= a; i++)
    {
        nanum.push_back(i);
    }
    vector<int> ans;
    ans = finder(a, b-1, ans);
    ans.push_back(0);
    for (int i = 0; i < ans.size(); i++)
    {
        s = s + to_string(nanum[ans[i]]);
        nanum.erase(nanum.begin()+ans[i]);
    }
    }
    cout<<s;
    
}