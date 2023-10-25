// Question Link - https://leetcode.com/problems/sliding-window-maximum/description/
// solution 

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        if(k == 1) return nums;
        deque<int> dq;
        for(int i=0;i<k; i++)
        {
            if(dq.empty()) dq.push_front(nums[i]);
            else if(dq.front()>=nums[i]) dq.push_front(nums[i]);
            else
            {
                while(!dq.empty() && dq.front()<nums[i]) 
                {
                    dq.pop_front();
                    if(dq.empty() || dq.front() >= nums[i]) {dq.push_front(nums[i]);break;}
                }
            }
        }
        vector<int> ans;
        ans.push_back(dq.back());
        for(int i=0; i+k<nums.size(); i++)
        {
            if(dq.back() == nums[i]) dq.pop_back();
            if(dq.front()>=nums[i+k]) dq.push_front(nums[i+k]);
            else
            {
                while(!dq.empty() && dq.front()<nums[i+k]) 
                {
                    dq.pop_front();
                    if(dq.empty() || dq.front() >= nums[i+k]) 
                    {
                        dq.push_front(nums[i+k]);
                        break;
                    }
                }
            }
            ans.push_back(dq.back());
        }
        return ans;
    }
};