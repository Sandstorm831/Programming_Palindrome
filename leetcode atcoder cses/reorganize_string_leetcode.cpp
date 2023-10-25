// Question Link - class Solution {
public:
    string reorganizeString(string s) {
        unordered_map<char,int> ump;
        char maxy; int maxx = INT_MIN;
        for(int i=0; i<s.size(); i++)
        {
            ump[s[i]]++;
            if(ump[s[i]]>maxx)
            {
                maxx = ump[s[i]];maxy = s[i];
            }
        }
        if(maxx > (s.size()+1)/2) return "";
        int index=0;
        string ans(s.size(), '0');
        while(ump[maxy] > 0)
        {
            ans[index] = maxy; ump[maxy]--;
            index+=2;
        }
        for(auto itr = ump.begin(); itr != ump.end(); itr++)
        {
            while(itr->second > 0)
            {
                if(index >= s.length()) index = 1;
                ans[index] = itr->first;
                itr->second--;
                index+=2;
            }
        }
        return ans;
    }
};