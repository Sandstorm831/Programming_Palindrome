// Problem Link - https://www.interviewbit.com/problems/permutations/
/* Problem Solution Function ----------------------------------------------------------------------------------------+
void recursor(vector<vector<int>>& collector, vector<int>& data, vector<int>& retriever, int target)    <------------+
{
    for (int i = 0; i < target-retriever.size(); i++)
    {
        retriever.push_back(data[0]);
        data.erase(data.begin());
        recursor(collector, data, retriever, target);
        data.push_back(retriever.back());
        retriever.pop_back();
    }
    if(retriever.size() == target) collector.push_back(retriever); 
    return;
}
vector<vector<int> > Solution::permute(vector<int> &A) {
    vector<int> data = A;
    vector<vector<int>> collector;
    vector<int> retriever;
    int target = A.size();
    recursor(collector, data, retriever, target);
    return collector;
}
*/
#include <bits/stdc++.h>
using namespace std;
void recursor(vector<vector<int>>& collector, vector<int>& data, vector<int>& retriever, int target)
{
    for (int i = 0; i < target-retriever.size(); i++)
    {
        retriever.push_back(data[0]);
        data.erase(data.begin());
        recursor(collector, data, retriever, target);
        data.push_back(retriever.back());
        retriever.pop_back();
    }
    if(retriever.size() == target) collector.push_back(retriever); 
    return;
}
vector<vector<int>> permute(vector<int>& A)
{
    vector<int> data = A;
    vector<vector<int>> collector;
    vector<int> retriever;
    int target = A.size();
    recursor(collector, data, retriever, target);
    return collector;
}
int main()
{
    vector<int> A = {1,2,3};
    vector<vector<int>> rg = permute(A);
    for (int i = 0; i < rg.size(); i++)
    {
        for (int j = 0; j < rg[i].size(); j++)
        {
            cout<<rg[i][j]<<" ";
        }
        cout<<endl;
    }
    
}