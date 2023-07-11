// Question Link - https://leetcode.com/problems/continuous-subarrays/description/
// solution 


class Solution {
public:
    long long continuousSubarrays(vector<int>& nums) {
        int n = nums.size();
        int head=0, tail=0;
        long long count = 0;
        deque<int> mx, mn;
        for(head=0; head<n; head++)
        {
            while(!mx.empty() && nums[head]>mx.back()) mx.pop_back();
            while(!mn.empty() && nums[head]<mn.back()) mn.pop_back();
            mx.push_back(nums[head]);
            mn.push_back(nums[head]);
            // front element will give you the max and min element in the current window
            while(mx.front() - mn.front() > 2)
            {
                if(nums[tail] == mx.front()) mx.pop_front();
                if(nums[tail] == mn.front()) mn.pop_front();
                tail++; 
            }
            count += head-tail+1;
        }
        return count;
    }
};