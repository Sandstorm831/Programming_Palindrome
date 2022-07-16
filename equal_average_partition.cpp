//Problem Link - https://www.interviewbit.com/problems/equal-average-partition/
/* Complet solution Code ------------------------+
vector<vector<vector<bool>>> dp;  <--------------+
vector<int> res;
vector<int> original;
int total_size;
bool ispossible(int index, int current_sum, int current_size)
{
    if(current_size == 0) return (current_sum == 0);
    if(index >= total_size) return false;
    if(dp[index][current_sum][current_size] == false) return false;
    if(current_sum >= original[index])
    {
        res.push_back(original[index]);
        if(ispossible(index+1, current_sum-original[index], current_size-1)) return true;
        res.pop_back();
    }
    if(ispossible(index+1, current_sum, current_size)) return true;
    return dp[index][current_sum][current_size] = false;
}
vector<vector<int>> equalaveragevector(vector<int> vec)
{
    dp.clear(); original.clear();res.clear();
    sort(vec.begin(), vec.end());
    original = vec;
    total_size = vec.size();
    int total_sum=0;
    for (int i = 0; i < vec.size(); i++)
    {
        total_sum += vec[i];
    }
    dp.resize(original.size(), vector<vector<bool>> (total_sum+1, vector<bool> (total_size, true)));
    for (int i = 1; i < total_size; i++)
    {
        if((total_sum*i)%total_size != 0) continue;
        int curr_sum = (i*total_sum)/total_size;
        if(ispossible(0, curr_sum, i))
        {
            int ptr1=0, ptr2=0;
            vector<int> res1 =res;
            vector<int> res2;
            while(ptr1 < vec.size() || ptr2 < res.size())
            {
                if(ptr2 < res.size() && res[ptr2] == original[ptr1])
                {
                    ptr1++;
                    ptr2++;
                    continue;
                }
                res2.push_back(vec[ptr1]);
                ptr1++;
            }
            vector<vector<int>> ans;
            if(res2.size() > res1.size())
            {
                ans.push_back(res1);
                ans.push_back(res2);
            }
            else if(res2.size() < res1.size())
            {
                ans.push_back(res2);
                ans.push_back(res1);
            }
            else{
                for (int k = 0; k < res1.size(); k++)
                {
                    if(res1[k] > res2[k])
                    {
                        ans.push_back(res2);
                        ans.push_back(res1);  
                        break; 
                    }
                    else if(res1[k]<res2[k])
                    {
                        ans.push_back(res1);
                        ans.push_back(res2);
                        break;
                    }
                    continue;
                }
            }
            return ans;
        }
    }
    vector<vector<int>> ans;
    return ans;
}
vector<vector<int> > Solution::avgset(vector<int> &A) {
    vector<vector<int>> sol;
    sol = equalaveragevector(A);
    return sol;
}
*/
#include <bits/stdc++.h>
using namespace std;
vector<vector<vector<bool>>> dp;
vector<int> res;
vector<int> original;
int total_size;
bool ispossible(int index, int current_sum, int current_size)
{
    if(current_size == 0) return (current_sum == 0);
    if(index >= total_size) return false;
    if(dp[index][current_sum][current_size] == false) return false;
    if(current_sum >= original[index])
    {
        res.push_back(original[index]);
        if(ispossible(index+1, current_sum-original[index], current_size-1)) return true;
        res.pop_back();
    }
    if(ispossible(index+1, current_sum, current_size)) return true;
    return dp[index][current_sum][current_size] = false;
}
vector<vector<int>> equalaveragevector(vector<int> vec)
{
    dp.clear(); original.clear();res.clear();
    sort(vec.begin(), vec.end());
    original = vec;
    total_size = vec.size();
    int total_sum=0;
    for (int i = 0; i < vec.size(); i++)
    {
        total_sum += vec[i];
    }
    dp.resize(original.size(), vector<vector<bool>> (total_sum+1, vector<bool> (total_size, true)));
    for (int i = 1; i < total_size; i++)
    {
        if((total_sum*i)%total_size != 0) continue;
        int curr_sum = (i*total_sum)/total_size;
        if(ispossible(0, curr_sum, i))
        {
            int ptr1=0, ptr2=0;
            vector<int> res1 =res;
            vector<int> res2;
            while(ptr1 < vec.size() || ptr2 < res.size())
            {
                if(ptr2<res.size() && res[ptr2] == original[ptr1])
                {
                    ptr1++;
                    ptr2++;
                    continue;
                }
                res2.push_back(vec[ptr1]);
                ptr1++;
            }
            vector<vector<int>> ans;
            if(res2.size() > res1.size())
            {
                ans.push_back(res1);
                ans.push_back(res2);
            }
            else if(res2.size() < res1.size())
            {
                ans.push_back(res2);
                ans.push_back(res1);
            }
            else{
                for (int k = 0; k < res1.size(); k++)
                {
                    if(res1[k] > res2[k])
                    {
                        ans.push_back(res2);
                        ans.push_back(res1);  
                        break; 
                    }
                    else if(res1[k]<res2[k])
                    {
                        ans.push_back(res1);
                        ans.push_back(res2);
                        break;
                    }
                    continue;
                }
            }
            return ans;
        }
    }
    vector<vector<int>> ans;
    return ans;
}
int main()
{
    vector<int> A = {1,7,15,29,11,9};
    vector<vector<int>> sol = equalaveragevector(A);
    if(sol.empty()) return -1;
    sort(sol.begin(), sol.end());
    reverse(sol.begin(), sol.end());
    for (int i = 0; i < sol.size(); i++)
    {
        for (int j = 0; j < sol[i].size(); j++)
        {
            cout<<sol[i][j]<<" ";
        }
        cout<<endl;
    }
}