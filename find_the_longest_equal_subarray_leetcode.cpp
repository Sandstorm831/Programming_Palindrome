// Question Link - https://leetcode.com/problems/find-the-longest-equal-subarray/description/
// solution 

class Solution {
public:
    int longesttEqualSubarray(vector<int>& nums, int k) {
        unordered_map<int,set<int>> ump;
        int maxx = INT_MIN;
        for(int i=0; i<nums.size();i++) ump[nums[i]].insert(i);
        for(auto itr=ump.begin(); itr!=ump.end(); itr++)
        {
            queue<pair<int,int>> q; int prev = -1; int clp = k;int curr=0;
            int chain=0;
            for(auto iit = (itr->second).begin(); iit!=(itr->second).end(); iit++)
            {
                if(prev == -1)
                {
                    prev = *iit;
                    chain++;
                    curr++;
                    continue;
                }
                int x = *iit - prev-1;
                if(x == 0)
                {
                    curr++,chain++;
                    prev = *iit;
                }
                else if(clp>=x)
                {
                    q.push(make_pair(chain, x));
                    prev = *iit;
                    curr++;
                    clp-=x;
                    chain=1;
                }
                else if(x <= k)
                {
                    maxx = max(maxx, curr);
                    while(clp<x)
                    {
                        pair<int,int> p = q.front();q.pop();
                        curr -= p.first;
                        clp += p.second;
                    }
                    curr++;
                    q.push(make_pair(chain, x));
                    prev = *iit;
                    clp-=x;
                    chain=1;
                }
                else if(x > k)
                {
                    while(!q.empty()) q.pop();
                    maxx = max(curr, maxx);
                    chain=1;curr=1;clp=k;
                    prev = *iit;
                }
                maxx = max(maxx,curr);
            }
        }
        return max(maxx,1);
    }

    // Below solution is better
    
    int longestEqualSubarray(vector<int>& nums, int k) {
        int maxf = INT_MIN,i=0,j=0;
        unordered_map<int,int> ump;
        for(;j<nums.size();j++)
        {
            maxf = max(maxf, ++ump[nums[j]]);
            if(j-i+1-maxf > k)--ump[nums[i++]];
        }
        return maxf;
    }
    // Solution Explanation - https://leetcode.com/problems/find-the-longest-equal-subarray/solutions/3934172/java-c-python-one-pass-sliding-window-o-n/
};