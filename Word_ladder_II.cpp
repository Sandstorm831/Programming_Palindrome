/*
Problem Link - https://www.interviewbit.com/problems/word-ladder-ii/
Given two words (start and end), and a dictionary, find the shortest transformation sequence from start to end, such that:

Only one letter can be changed at a time
Each intermediate word must exist in the dictionary
If there are multiple such sequence of shortest length, return all of them. Refer to the example for more details.

Note:

All words have the same length.
All words contain only lowercase alphabetic characters.
Input Format

The first argument is string start.
The second argument is string end.
The third argument is an array of strings dict
Output Format

Return all transformation sequences such that first word of each sequence is start and last word is end, all intermediate words belongs to dictionary(dict) and consecutive words had atmost 1 difference.  
Example :

:

start = "hit"
end = "cog"
dict = ["hot","dot","dog","lot","log"]
Return

  [
    ["hit","hot","dot","dog","cog"],
    ["hit","hot","lot","log","cog"]
  ]
*/
#include <bits/stdc++.h>
using namespace std;
vector<vector<string> > ans;
int min_dist;
string dest;
bool isAdjacent(string A,string B)
{
    int count=0;
    for(int i=0;i<A.length();i++)
    {
        if(A[i]!=B[i])
            count++;
        if(count>1)
            return false;
    }
    return count==1;
}
void dfs(vector<string> path,string vertex,int dist,unordered_set<string> dict)
{
    if(dist>min_dist)
        return;
    if(vertex==dest)
    {
        if(dist==min_dist)
            ans.push_back(path);
        return;
    }
    dict.erase(vertex);
    for(auto it=dict.begin();it!=dict.end();++it)
    {
        if(isAdjacent(vertex,*it))
        {
            path.push_back(*it);
            dfs(path,*it,dist+1,dict);
            path.pop_back();
        }
    }
    dict.insert(vertex);
}
vector<vector<string> > Solution::findLadders(string start, string end, vector<string> &dict) {
    min_dist=INT_MAX;dest=end;ans.clear();
    unordered_set<string> dictMap(dict.begin(),dict.end());
    dictMap.insert(end);
    queue<pair<string,int> > bfs_queue;
    unordered_map<string,bool> visited;
    visited[start]=true;
    bfs_queue.push(make_pair(start,0));
    while(!bfs_queue.empty())
    {
        pair<string,int> vertex=bfs_queue.front();
        bfs_queue.pop();
        if(vertex.first==end)
        {
            min_dist=vertex.second;
            break;
        }
        dictMap.erase(vertex.first);
        for(auto it=dictMap.begin();it!=dictMap.end();++it)
            if(isAdjacent(vertex.first,*it))
                bfs_queue.push(make_pair(*it,vertex.second+1));
    }
    if(min_dist==INT_MAX)
        return ans;
    vector<string> path;
    path.push_back(start);
    dictMap.clear();
    dictMap.insert(dict.begin(),dict.end());
    dictMap.insert(end);
    dfs(path,start,0,dictMap);
    return ans;
}