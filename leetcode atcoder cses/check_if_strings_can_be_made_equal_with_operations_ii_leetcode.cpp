// Question Link - https://leetcode.com/contest/biweekly-contest-112/problems/check-if-strings-can-be-made-equal-with-operations-ii/
// solution 

class Solution {
public:
    bool checkStrings(string s1, string s2) {
        multiset<char> m1, m2;
        for(int i=0; i<s1.size(); i+=2) m1.insert(s1[i]), m2.insert(s2[i]);
        if(m1 != m2) return false;
        m1.clear(), m2.clear();
        for(int i=1; i<s2.size(); i+=2) m1.insert(s1[i]), m2.insert(s2[i]);
        return m1 == m2;
    }
};