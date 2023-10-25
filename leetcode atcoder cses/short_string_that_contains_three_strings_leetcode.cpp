// Question Link - https://leetcode.com/contest/weekly-contest-356/problems/shortest-string-that-contains-three-strings/
// solution 

class Solution {
public:
    string func(string a, string b)
    {
        int index=-1;
        string ans1=a+b, ans2=b+a;
        for(int i=0;i<a.size();i++)
        {
            if(a[i] == b[0])
            {
                index = i;
                int j = 0;
                while(index<a.size() && j<b.size() && a[index] == b[j]) index++,j++;
                if(index < a.size() && j < b.size() && a[index] != b[j])
                {
                    index = -1;
                    continue;
                }
                else if(j >= b.size()) {ans1 = a;break;}
                else if(index >= a.size()) {ans1 = a+b.substr(j);break;}
            }
        }
        index = -1;
        for(int i=0;i<b.size();i++)
        {
            if(b[i] == a[0])
            {
                index = i;
                int j = 0;
                while(index<b.size() && j<a.size() && b[index] == a[j]) index++,j++;
                if(index < b.size() && j < a.size() && b[index] != a[j])
                {
                    index = -1;
                    continue;
                }
                else if(j >= a.size()) {ans2 = b;break;}
                else if(index >= b.size()) {ans2 = b+a.substr(j);break;}
            }
        }
        if(ans1.size() > ans2.size()) return ans2;
        else if(ans2.size() > ans1.size()) return ans1;
        else return min(ans1, ans2);
    }
    string minimumString(string a, string b, string c) {
        vector<string> s = {a, b, c};
        sort(s.begin(), s.end());
        string ans = s[0]+s[1]+s[2];
        string comb;
        for(int i=0; i<3; i++)
        {
            for(int j=i+1; j<3; j++)
            {
                comb = func(s[i], s[j]);
                if(i==0 && j==1) comb = func(comb, s[2]);
                else if(i==0 && j==2) comb = func(comb, s[1]);
                else if(i==1 && j==2) comb = func(comb, s[0]);
                if(comb.length() < ans.length()) ans = comb;
                else if(comb.length() == ans.length() && min(comb, ans) == comb) ans = comb;
            }
        }
        return ans;
    }
};