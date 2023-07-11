// Question Link = https://leetcode.com/problems/prime-pairs-with-target-sum/description/
// solution

class Solution {
public:
    vector<vector<int>> findPrimePairs(int n) {
        vector<int> v(n+1,0);
        for(int i=2; i*i<=n; i++)
        {
            if(v[i]==0)
            {
                for(int j=2*i; j<n; j+=i)
                {
                    if(v[j]==0) v[j]=1;
                }
            }
        }
        vector<vector<int>> ans;
        if(n<=3) return ans;
        for(int i=2; 2*i<=n; i++)
        {
            vector<int> x;
            if(!v[i]&&!v[n-i])
            {
                ans.push_back({i,n-i});
            }
        }
        return ans;
    }
};