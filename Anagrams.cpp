// Problem Link - https://www.interviewbit.com/problems/anagrams/
#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> anagrams(vector<string> A)
{
    vector<vector<int>> vecy;
    unordered_map<string,vector<int>> mappy;
    for (int i = 0; i < A.size(); i++)
    {
        sort(A[i].begin(), A[i].end());
        mappy[A[i]].push_back(i+1);
    }
    auto itr = mappy.begin();
    while (itr != mappy.end())
    {
        vecy.push_back(itr->second);
        itr++;
    }
    return vecy;
    
    
}
int main()
{
    vector<string> A = {"cat","dog","god","tca"}; // This has to be assumed
    vector<vector<int>> B = anagrams(A);
    for (int i = 0; i < B.size(); i++)
    {
        for (int j = 0; j < B[i].size(); j++)
        {
            cout<<B[i][j]<<" ";
        }
        cout<<endl;
        
    }
    
}