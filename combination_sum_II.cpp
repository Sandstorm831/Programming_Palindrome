// Problem Link - https://www.interviewbit.com/problems/combination-sum-ii/
/* Problem Solution Function ---------------------------------------------------------------------+
void recursor(set<vector<int>>& collector, vector<int>&A, int sum, int target)      <-------------+
{
    if(sum < target || A.empty()) return;
    else if(sum == target)
    {
        vector<int> alter = A;
        sort(alter.begin(), alter.end());
        collector.insert(alter);
    }
    else
    {
        for (int i = 0; i < A.size(); i++)
        {
            int alterego = A[0];
            A.erase(A.begin());
            recursor(collector, A, sum-alterego, target);
            A.push_back(alterego);
        }
    }
}
vector<vector<int> > Solution::combinationSum(vector<int> &A, int B) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    vector<int> alter;
    int sum = 0;
    for (int i = 0; i <A.size(); i++)
    {
        if(A[i]<=B)
        {
            alter.push_back(A[i]);
            sum += A[i];
        } 
    }
    set<vector<int>> collector;
    recursor(collector, alter, sum, B);
    vector<vector<int>> alger;
    for (auto i = collector.begin(); i != collector.end(); i++)
    {
        alger.push_back(*i);
    }
    return alger;
}
*/
#include <bits/stdc++.h>
using namespace std;
void recursor(set<vector<int>>& collector, vector<int>&A, int sum, int target)
{
    if(sum < target || A.empty()) return;
    else if(sum == target)
    {
        vector<int> alter = A;
        sort(alter.begin(), alter.end());
        collector.insert(alter);
    }
    else
    {
        for (int i = 0; i < A.size(); i++)
        {
            int alterego = A[0];
            A.erase(A.begin());
            recursor(collector, A, sum-alterego, target);
            A.push_back(alterego);
        }
    }
}
vector<vector<int>> combinatinoSum(vector<int>& A ,int B)
{
    vector<int> alter;
    int sum = 0;
    for (int i = 0; i <A.size(); i++)
    {
        if(A[i]<=B)
        {
            alter.push_back(A[i]);
            sum += A[i];
        } 
    }
    set<vector<int>> collector;
    recursor(collector, alter, sum, B);
    vector<vector<int>> alger;
    for (auto i = collector.begin(); i != collector.end(); i++)
    {
        alger.push_back(*i);
    }
    return alger;
}