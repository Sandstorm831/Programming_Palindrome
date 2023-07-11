// Questoin LInk - https://leetcode.com/contest/weekly-contest-351/problems/number-of-beautiful-pairs/
// Solution 

class Solution {
public:
    bool checker(int x, int y)
    {
        int b = y%10;
        int a;
        int xx = x;
        // cout<<x<<" ";
        while(xx>0)
        {
            a =xx%10;
            xx= xx/10;
        }
        // cout<<x<<" "<<y<<" "<<a<<" "<<b<<endl;
        return __gcd(a,b) == 1;
    }
    int countBeautifulPairs(vector<int>& nums) {
        int counter=0;
        for(int i=0; i<nums.size();i++)
        {
            for(int j=i+1; j<nums.size();j++)
            {
                // cout<<i<<" "<<j<<endl;
                if(checker(nums[i], nums[j])) 
                {
                    // cout<<i<<" "<<j<<" "<<endl;
                    counter++;
                }
            }
        }
        return counter;
        
    }
};