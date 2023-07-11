// Question LInk - https://leetcode.com/problems/buddy-strings/description/
// Solution 

class Solution {
public:
    bool buddyStrings(string s, string goal) {
        if(s.length() != goal.length()) return false;
        vector<int> v(26,0);
        vector<int> g(26,0);
        int counter=0;
        int it=0;
        for(int i=0; i<s.length(); i++)
        {
            v[s[i]-'a']++;
            g[goal[i]-'a']++;
            if(v[s[i]-'a']>=2) it=1;
            if(s[i] != goal[i]) counter++;
        }
        if(g != v) return false;
        if((counter==0 && it) || counter==2) return true;
        return false;
    }
};