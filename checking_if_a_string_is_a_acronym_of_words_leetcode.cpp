// Question Link - https://leetcode.com/contest/weekly-contest-359/problems/check-if-a-string-is-an-acronym-of-words/
// Solution 

class Solution {
public:
    bool isAcronym(vector<string>& words, string s) {
        string d="";
        for(int i=0;i<words.size();i++) d+=words[i][0];
        return d == s;
    }
};