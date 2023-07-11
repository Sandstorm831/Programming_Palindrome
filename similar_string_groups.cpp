// Question Link - https://leetcode.com/problems/similar-string-groups/description/?envType=study-plan-v2&envId=graph-theory
// Solution 

class Solution {
public:
    int summ;
    bool is_similar(string a, string b)
    {
        int counter=0;
        for(int i=0; i<a.size(); i++)
        {
            if(a[i] != b[i]) counter++;
            if (counter > 2) return false;
        }
        return counter<=2;
    }
    void unin(int nod, int node, vector<int>& elder, vector<int>& rank)
    {
        int x = finder(nod, elder);
        int y = finder(node, elder);
        if(x == y) return;
        else if(rank[x] > rank[y]) elder[y] = x;
        else if(rank[x] < rank[y]) elder[x] = y;
        else if(rank[x] == rank[y])
        {
            elder[x] = y;
            rank[y]++;
        }
        summ--;
    }
    int finder(int node, vector<int>& elder)
    {
        if (node == elder[node]) return node;
        else elder[node] = finder(elder[node], elder);
        return elder[node];
    }
    int numSimilarGroups(vector<string>& strs) {
        summ = strs.size();
        vector<int> elder;
        vector<int> rank(strs.size(),0);
        for(int i=0; i<strs.size();i++) elder.push_back(i);
        for(int i=0; i<strs.size(); i++)
        {
            for(int j=0; j<elder.size(); j++)
            {
                if(is_similar(strs[j], strs[i])) unin(i,j,elder,rank);
            }
        }
        return summ;
    }
};

/*An alternate solution for learning using dfs*/

class Solution {
private:
    bool isSimilar(string &s, string &t){
        int n = s.length();
        int count=0;
        for(int i=0;i<n;i++){
            if(s[i]!=t[i]) count++;
            if(count>2) return false;
        }
        return true;
    }
    void dfs(int currnode, vector<int> &vis, vector<int> adj[]){
        vis[currnode]=1;
        for(int &childnode:adj[currnode]){
            if(!vis[childnode]){
                dfs(childnode,vis,adj);
            }
        }
    }
public:
    int numSimilarGroups(vector<string>& strs) {
        int n = strs.size();
        vector<int> adj[n];

        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(isSimilar(strs[i],strs[j])){
                    adj[i].emplace_back(j);
                    adj[j].emplace_back(i);
                }
            }
        }

        vector<int> vis(n,0);
        int ans=0;
        for(int i=0;i<n;i++){
            if(!vis[i]){
                dfs(i,vis,adj);
                ans++;
            }
        }
        return ans;
    }
};