// Question Link - https://leetcode.com/problems/single-number-ii/description/
// Solution

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        vector<long long> numsp, numsn;
        for(long long i=0; i<nums.size(); i++)
        {
            if(nums[i]>=0)numsp.push_back(1ll*nums[i]);
            else numsn.push_back(abs(1ll*nums[i]));
        }
        vector<long long> bits(64,0);
        for(long long i=0; i<numsp.size(); i++)
        {
            long long j=0;
            long long x = 1;
            long long byt = numsp[i];
            while(byt>0)
            {
                bits[j] += byt&1;
                byt = byt>>1;j++;
            }
        }
        long long ans1 = 0;
        for(long long j=0; j<bits.size(); j++)
        {
            if(bits[j]%3) ans1 += (1<<j);
        }
        bits.clear();
        bits.resize(64,0);
        for(long long i=0; i<numsn.size(); i++)
        {
            long long j=0;
            long long x = 1;
            long long byt = numsn[i];
            while(byt>0)
            {
                bits[j] += byt&1;
                byt = byt>>1;j++;
            }
        }
        long long ans2 = 0;
        for(long long j=0; j<bits.size(); j++)
        {
            if(bits[j]%3) ans2 += (1<<j);
        }
        if(ans1==0) return -ans2;
        else if(ans2==0) return ans1;
        else return 0;
    }
};

/// Both solutions are important

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        vector<long long> numsp, numsn;
        for(long long i=0; i<nums.size(); i++)
        {
            if(nums[i]>=0)numsp.push_back(1ll*nums[i]);
            else numsn.push_back(abs(1ll*nums[i]));
        }
        long long a=LLONG_MAX, b=0, c=0;
        for(int i=0; i<numsp.size(); i++)
        {
            long long aa = numsp[i]&a;
            long long bb = numsp[i]&b;
            long long cc = numsp[i]&c;

            a = a|cc;
            a = a & (~aa);
            b = b|aa;
            b = b & (~bb);
            c = c|bb;
            c = c & (~cc);
        }
        // return b;
        long long x = b;
        a=LLONG_MAX, b=0, c=0;
        for(long long i=0; i<numsn.size(); i++)
        {
            long long aa = numsn[i]&a;
            long long bb = numsn[i]&b;
            long long cc = numsn[i]&c;

            a = a|cc;
            a = a & (~aa);
            b = b|aa;
            b = b & (~bb);
            c = c|bb;
            c = c & (~cc);
        }
        // cout<<x<<" "<<b<<endl;
        if(x == 0 && b != 0) return -b;
        else if(b == 0 && x != 0) return x;
        else return 0;
    }
};

// For understanding follow https://www.youtube.com/watch?v=3gJxLkPPW6M
