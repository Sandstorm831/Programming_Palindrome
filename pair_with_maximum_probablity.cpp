// Question Link - https://leetcode.com/problems/path-with-maximum-probability/description/
// Solution 

class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        vector<vector<pair<int,double>>> graph(n, vector<pair<int,double>> ());
        for(int i=0; i<edges.size(); i++)
        {
            graph[edges[i][0]].push_back(make_pair((int)edges[i][1], succProb[i]));
            graph[edges[i][1]].push_back(make_pair((int)edges[i][0], succProb[i]));
        }
        priority_queue<pair<double,int>> pq;
        vector<double> final(n, 0);
        final[start] = 1.0;
        pq.push(make_pair(1,start));
        vector<bool> vis(n, false);
        while(!pq.empty())
        {
            pair<double,int> p=pq.top();
            pq.pop();
            // cout<<p.second<<" "<<p.first<<endl;
            vis[p.second]=true;
            if(final[p.second]<p.first) final[p.second] = p.first;
            for(int i=0; i<graph[p.second].size(); i++)
            {
                if(!vis[graph[p.second][i].first])
                {
                    pq.push(make_pair(p.first*graph[p.second][i].second,graph[p.second][i].first));
                }
            }
        }
        return final[end];
    }
};