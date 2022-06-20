// Problem Link - https://www.interviewbit.com/problems/longest-common-prefix/
/* Problem Solution Function --------------------------------------+
string Solution::longestCommonPrefix(vector<string> &A) {     <----+
    unordered_map<char, int> kua;
    unordered_map<char, int> balti;
    for (int i = 0; i < A[0].size(); i++)
    {
        if(kua.find(A[0][i]) == kua.end()) kua.insert({A[0][i], 1});
        else kua[A[0][i]]++;
    }
    for (int i = 1; i < A.size(); i++)
    {
        for (int j = 0; j < A[i].size(); j++)
        {
            if(kua.find(A[i][j]) != kua.end()) 
            {
                if(balti.find(A[i][j]) == balti.end()) balti.insert({kua.find(A[i][j])->first, 1});
                else
                {
                    if(balti.find(A[i][j])->second < kua.find(A[i][j])->second) balti.find(A[i][j])->second++;
                }
            }
        }
        kua.clear();
        kua = balti;
        balti.clear();
    }
    string finalizer = "";
    for (auto itr = kua.begin(); itr != kua.end(); itr++)
    {
        for (int j = 0; j < itr->second; j++)
        {
            finalizer += itr->first;
        }
    }
    sort(finalizer.begin(), finalizer.end());
    return finalizer;
}
*/
#include <bits/stdc++.h>
using namespace std;
string longestCommonPrefix(vector<string>A)
{
    unordered_map<char, int> kua;
    unordered_map<char, int> balti;
    for (int i = 0; i < A[0].size(); i++)
    {
        if(kua.find(A[0][i]) == kua.end()) kua.insert({A[0][i], 1});
        else kua[A[0][i]]++;
    }
    for (int i = 1; i < A.size(); i++)
    {
        for (int j = 0; j < A[i].size(); j++)
        {
            if(kua.find(A[i][j]) != kua.end()) 
            {
                if(balti.find(A[i][j]) == balti.end()) balti.insert({kua.find(A[i][j])->first, 1});
                else
                {
                    if(balti.find(A[i][j])->second < kua.find(A[i][j])->second) balti.find(A[i][j])->second++;
                }
            }
        }
        kua.clear();
        kua = balti;
        balti.clear();
    }
    string finalizer = "";
    for (auto itr = kua.begin(); itr != kua.end(); itr++)
    {
        for (int j = 0; j < itr->second; j++)
        {
            finalizer += itr->first;
        }
    }
    sort(finalizer.begin(), finalizer.end());
    return finalizer;
}
int main()
{
    vector<string> A = {"aaaabbbbccccddd", "aaabbbbbbccd"};
    cout<<longestCommonPrefix(A);
}