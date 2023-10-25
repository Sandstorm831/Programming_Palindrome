// Question LInk - https://leetcode.com/problems/excel-sheet-column-title/description/
// solution 

class Solution {
public:
    string convertToTitle(int columnNumber) {
        string ans="";
        while(columnNumber>0)
        {
            ans += ((columnNumber-1)%26 + 'A');
            columnNumber = (columnNumber-1)/26;
        }
        reverse(ans.begin(), ans.end());
        return ans;

    }
};