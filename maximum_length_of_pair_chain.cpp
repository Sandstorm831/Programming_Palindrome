// Question lINk - https://leetcode.com/problems/maximum-length-of-pair-chain/description?envType=study-plan-v2&envId=dynamic-programming
// solution 

class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(), pairs.end());
        int prev = pairs[0][1];
        int counter=1;
        for(int i=1; i<pairs.size(); i++)
        {
            if(pairs[i][0] > prev)
            {
                prev = max(pairs[i][1], prev);
                counter++;
            }
            else prev = min(pairs[i][1], prev);
        }
        return counter;
    }
};

/*Both solutions are important*/

bool comp(vector<int> a, vector<int> b)
{
    if(a[0] < b[0]) return true;
    else if(a[0] == b[0] && a[1] < b[1]) return true;
    return false;
}
class Solution {
public:
    vector<vector<int>> dp;
    int buff=1001;
    int recursor(vector<vector<int>>& pairs, int index, int prev)
    {
        if(index == pairs.size()-1)
        {
            if(pairs[index][0] > prev) return 1;
            else return 0;
        }
        else if(dp[index][prev+buff] != -1) return dp[index][prev+buff];
        else
        {
            if(pairs[index][0] > prev)
            {
                int a = 1+recursor(pairs, index+1, pairs[index][1]);
                int b = recursor(pairs, index+1, prev);
                return dp[index][prev+buff] = max(a,b);
            }
            else return dp[index][prev+buff] = recursor(pairs, index+1, prev);
        }
    }
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(), pairs.end(), comp);
        dp.clear();
        dp.resize(pairs.size(), vector<int> (2002, -1));
        return recursor(pairs, 0, -1001);
    }
};