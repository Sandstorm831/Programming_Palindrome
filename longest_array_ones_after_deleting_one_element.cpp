// Question Link - https://leetcode.com/problems/longest-subarray-of-1s-after-deleting-one-element/description/
// Solution 

class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int maxx = INT_MIN;
        int p1=0, p2=0, zero=0, curr=0;
        bool ok=false;
        int i=0; while(i<nums.size() && nums[i]==0) 
        {
            i++,zero++;
        }
        if(i>=nums.size()) return 0;
        for(; i<nums.size(); i++)
        {
            if(nums[i] == 0)
            {
                ok=false;
                if(curr == 0)
                {
                    if(p1 != 0 && p2 != 0)
                    {
                        maxx = max(p1+p2, maxx);
                        p1=p2, p2=0;
                    }
                    else maxx = max(p1, maxx);
                }
                curr++, zero++;
            }
            else
            {
                if(curr==1)
                {
                    curr=0;
                    ok=true;
                }
                if(curr==0)
                {
                    if(ok)p2++;
                    else p1++;
                }
                if(curr>1)
                {
                    p1=0, p2=0,curr=0;
                    p1++;
                }
            }
        }
        if(zero==0) return p1-1;
        if(p1 != 0 && p2 != 0) maxx = max(maxx, p1+p2);
        else maxx = max(maxx, p1);
        return maxx;
    }
};