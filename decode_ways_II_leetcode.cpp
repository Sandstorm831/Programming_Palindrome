// Question Link - https://leetcode.com/problems/decode-ways-ii/description/
// solution 

class Solution {
public:
    long long mod = 1e9+7;
    vector<int> dp;
    long long recursor(string& s, long long index)
    {
        if(s[index] == '0') return 0;
        else if(index == s.length()-1)
        {
            if(s[index] == '*') return 9;
            else return 1;
        }
        else if(index == s.length()) return 1;
        else if(dp[index] != -1) return dp[index];
        long long counter=0;
        if(s[index+1] != '0')
        {
            if(s[index] == '*')
            {
                counter = (counter%mod + (9*(recursor(s, index+1)%mod))%mod)%mod;
                if(s[index+1] == '*') counter = (counter%mod + (15*(recursor(s,index+2)%mod))%mod)%mod;
                else if(s[index+1]-'0' <= 6) counter = (counter%mod + (2*(recursor(s, index+2)%mod))%mod)%mod;
                else counter = (counter%mod + recursor(s, index+2)%mod)%mod;
            }
            else if(s[index]-'0' <= 2)
            {
                counter += recursor(s, index+1);
                if(s[index+1] == '*' && s[index] == '1') counter = (counter%mod +(9*(recursor(s, index+2)%mod))%mod)%mod;
                else if(s[index] == '1') counter = (counter%mod + recursor(s, index+2)%mod)%mod;
                else if(s[index+1] == '*' && s[index] == '2') counter   = (counter%mod + (6*(recursor(s, index+2)%mod))%mod)%mod;
                else if(s[index] == '2' && s[index+1]-'0' <= 6) counter = (counter%mod + recursor(s, index+2)%mod)%mod;
            }
            else
            {
                counter = (counter%mod + recursor(s, index+1)%mod)%mod;
            }
        }
        else
        {
            if(s[index] == '*') counter = (counter%mod + (2*(recursor(s, index+2)%mod))%mod)%mod;
            else if(s[index] == '1' || s[index] == '2') counter = (counter%mod + recursor(s, index+2)%mod)%mod;
        }
        return dp[index] = counter;
    }
    int numDecodings(string s) {
        dp.clear();dp.resize(s.length()+1, -1);
        return int(recursor(s, 0)%mod);
    }
};
// 9*15 + 15 + 9*15