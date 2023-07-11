// Question Link - https://leetcode.com/problems/minimum-number-of-vertices-to-reach-all-nodes/description
// Solution 

class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        vector<vector<int>> graph(n, vector<int> ());
        vector<int> ans;
        for(int i=0;i<edges.size();i++)
        {
            graph[edges[i][1]].push_back(edges[i][0]);
        }
        for(int i=0; i<graph.size(); i++)
        {
            if(graph[i].empty()) ans.push_back(i);
        }
        return ans;
    }
};