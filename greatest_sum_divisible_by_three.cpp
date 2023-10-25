// Question Link - https://leetcode.com/problems/greatest-sum-divisible-by-three/
// solution 

class Solution {
public:
    int maxSumDivThree(vector<int>& nums) {
        int summ = accumulate(nums.begin(), nums.end(),0);
        sort(nums.begin(), nums.end());
        if(summ%3 == 0) return summ;
        else if(summ%3 == 1)
        {
            int a = 1,sa=0, b = 2, sb=0;
            int i = 0;
            while(i<nums.size() && (a != 0 || b != 0))
            {
                if(nums[i]%3 == 1 && a>0) a--,sa+=nums[i];
                else if(nums[i]%3 == 2 && b>0) b--,sb+=nums[i];
                i++;
            }
            if(sa == 0) sa = INT_MAX;if(sb == 0) sb=INT_MAX;
            if(a == 0 && b == 0) return summ - min(sa,sb);
            else if(a == 0) return summ - sa;
            else if(b == 0) return summ-sb;
            else return 0;
        }
        else
        {
            int a = 2,sa=0, b = 1, sb=0;
            int i = 0;
            while(i<nums.size() && (a != 0 || b != 0))
            {
                if(nums[i]%3 == 1 && a>0) a--,sa+=nums[i];
                else if(nums[i]%3 == 2 && b>0) b--,sb+=nums[i];
                i++;
            }
            if(sa == 0) sa = INT_MAX;if(sb == 0) sb=INT_MAX;
            if(a == 0 && b == 0) return summ - min(sa,sb);
            else if(a == 0) return summ - sa;
            else if(b == 0) return summ-sb;
            else return 0;
        }
    }
};