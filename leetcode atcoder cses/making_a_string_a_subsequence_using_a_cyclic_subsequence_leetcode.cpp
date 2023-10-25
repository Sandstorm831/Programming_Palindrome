// question Link - https://leetcode.com/problems/make-string-a-subsequence-using-cyclic-increments/description/
// solution

class Solution {
public:
    bool canMakeSubsequence(string str1, string str2) {
        int index=0;
        for(int i=0; i<str1.size(); i++)
        {
            if(index >= str2.size()) return true;
            if(str2[index] == str1[i])index++;
            else if(str2[index] == 'a' && str1[i] == 'z') index++;
            else if(str2[index] != 'a' && str2[index]-1== str1[i]) index++;
        }
        if(index>=str2.size()) return true;
        return false;
    }
};