// Question Link - https://leetcode.com/problems/number-of-ways-to-reorder-array-to-get-same-bst/description/
// Solution 

class Solution {
public:
    const int mod = 1e9+7;
    long long power(long long x, long long y)
    {
        long long result = 1;
        while(y>0)
        {
            if(y&1) result = (result * 1ll * x)%mod;
            x = (x * 1ll * x)%mod;
            y >>=1;
        }
        return result;
    }
    long long fact(long long a)
    {
        if(a==0 || a==1) return 1;
        else return ((a%mod) * (fact(a-1)%mod))%mod;
    }
    long long recursor(vector<long long>& nums)
    {
        if(nums.size()==0) return 1;
        vector<long long> low, high;
        long long root = nums[0];
        for(long long i=1;i<nums.size();i++)
        {
            if(nums[i]>root) high.push_back(nums[i]);
            else low.push_back(nums[i]);
        }
        long long a=low.size(),b=high.size();
        long long up = fact(a+b);
        long long dl = fact(a);
        long long dr = fact(b);
        long long d = ((dl%mod) * (dr%mod))%mod;
        long long f = ((up%mod)*(power(d,mod-2)%mod))%mod;
        // cout<<f<<endl;
        f = ((f%mod) * (recursor(low)%mod))%mod;
        f = ((f%mod) * (recursor(high)%mod))%mod;
        return f;
    }
    int numOfWays(vector<int>& nums) {
        vector<long long> nm;
        for(long long i=0; i<nums.size();i++) nm.push_back(1ll*nums[i]);
        // cout<<nm.size()<<endl;
        long long l = recursor(nm);
        l--;
        return (l+mod)%mod;
    }
};