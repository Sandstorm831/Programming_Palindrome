// Question Link - https://leetcode.com/problems/reconstruct-itinerary/description/?envType=study-plan-v2&envId=google-spring-23-high-frequency
// solution 

class Solution {
public:
    vector<string> ans;
    unordered_map<string, multiset<string>> graph;
    void recursor(string node)
    {
        while(graph[node].size())
        {
            string nxt = *graph[node].begin();
            graph[node].erase(graph[node].begin());
            recursor(nxt);
        }
        ans.push_back(node);
    }
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        graph.clear();
        for(int i=0; i<tickets.size(); i++) 
        {
            graph[tickets[i][0]].insert(tickets[i][1]);
        }
        ans.clear();
        string ini = "JFK";
        recursor(ini);
        return vector<string>(ans.rbegin(), ans.rend());
    }
};
// Explanation - https://leetcode.com/problems/reconstruct-itinerary/solutions/78768/short-ruby-python-java-c/?envType=study-plan-v2&envId=google-spring-23-high-frequency