// Question Link - https://leetcode.com/problems/h-index/description/?envType=study-plan-v2&envId=top-interview-150
// Solution 

class Solution {
public:
    int hIndex(vector<int>& citations) {
        sort(citations.begin(), citations.end());
        if(citations.back()==0) return 0;
        int prev=0;
        int j=0;
        for(int i=1; i<=citations.back() && j<citations.size();i++)
        {
            while(j<citations.size() && citations[j]<i) j++;
            if(j>=citations.size()) break;
            if(citations.size()-j>=i) prev=i;
        }
        return prev;
    }
};