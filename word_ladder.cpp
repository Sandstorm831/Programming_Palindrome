// Question Link - https://leetcode.com/problems/word-ladder/description
// Solution 

class Solution {
public:
    bool checker(string a, string b)
    {
        int counter=0;
        for(int i=0; i<a.size(); i++) if(a[i] != b[i]) counter++;
        if(counter == 1) return true;
        return false;
    }
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        if(beginWord == endWord) return 0;
        unordered_set<string> mp;
        unordered_map<string,bool> vis;
        for(int i=0; i<wordList.size();i++) 
        {
            mp.insert(wordList[i]);
            vis[wordList[i]]=false;
        }
        vis[beginWord] = false;
        vis[endWord] = false;
        queue<string> q;
        q.push(beginWord);
        q.push("__NULL__");
        int dist = 0;
        while(!q.empty())
        {
            string s = q.front();
            q.pop();
            // cout<<s<<endl;
            if(s == "__NULL__")
            {
                if(q.empty())continue;
                else
                {
                    dist++;
                    q.push("__NULL__");
                }
            }
            else
            {
                if(s == endWord) return 1+dist;
                else
                {
                    for(int i=0; i<s.size(); i++)
                    {
                        int orig = s[i]-'a';
                        for(int j=0; j<26; j++)
                        {
                            if(j == orig) continue;
                            s[i] = j+'a';
                            // cout<<s<<endl;
                            if(s == endWord && mp.find(s) != mp.end()) return 2+dist;
                            if(mp.find(s) != mp.end() && !vis[s])
                            {
                                q.push(s);
                                vis[s]=true;
                            }
                            s[i] = orig+'a';

                        }
                    }
                }
            }
        }
        return 0;

    }
};