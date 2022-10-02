/*
Problem Link - https://www.interviewbit.com/problems/word-break/
//// This solution gives MLE in interview bit......
unordered_map<string, bool> dp;
bool partitiondp(string a, unordered_set<string> st, int starer, int ender)
{
    if(a.size()==0) return true;
    string filler = to_string(starer)+" "+to_string(ender);
    if(dp.find(filler) != dp.end()) return dp[filler];
    for(int i=1; i<=a.size(); i++)
    {
        string sub = a.substr(0,i);
        string part = a.substr(i);
        string finer = to_string(0)+" "+to_string(i);
        if(st.find(sub) != st.end())
        {
            dp[finer] = true;
        }
        else dp[finer]=false;
        if((st.find(sub) != st.end()) && partitiondp(part, st, i, ender-i)) return dp[filler] = true;
    }
    return dp[filler] = false;
}
int Solution::wordBreak(string A, vector<string> &B) {
    int size = A.size();
    unordered_set<string> st;
    for(int i=0; i<B.size(); i++)
    {
        st.insert(B[i]);
    }
    dp.clear();
    int n=A.size();
    return partitiondp(A, st, 0, n);
}
Accepted solution on interview bit...........
unordered_set<string> dict;
vector<bool> dp;
int topdown(string A)
{
    dp[A.size()] = 1;
    for(int i=A.size()-1; i>=0; i--)
    {
        string wrd = "";
        for(int j=i; j<A.size(); j++)
        {
            if(dp[i]) break;
            wrd+=A[j];
            if(dict.find(wrd) != dict.end()) dp[i] = dp[j+1];
        }
    }
    return dp[0]==1;
}
int Solution::wordBreak(string A, vector<string> &B) {
    dict.clear();
    dp.clear();
    dp.resize(A.size() + 1, 0);
    for (auto it : B) dict.insert(it);
    return topdown(A);
}

*/
#include <bits/stdc++.h>
using namespace std;
unordered_set<string> dict;
vector<bool> dp;
int topdown(string A)
{
    dp[A.size()] = 1;
    for(int i=A.size()-1; i>=0; i--)
    {
        string wrd = "";
        for(int j=i; j<A.size(); j++)
        {
            if(dp[i]) break;
            wrd+=A[j];
            if(dict.find(wrd) != dict.end()) dp[i] = dp[j+1];
        }
    }
    return dp[0]==1;
}
int main()
{
    string A = "myinterviewtrainer";
    vector<string> B = {"my", "interview", "trainer"};
    dict.clear();
    dp.clear();
    dp.resize(A.size() + 1, 0);
    for (auto it : B) dict.insert(it);
    return topdown(A);
}