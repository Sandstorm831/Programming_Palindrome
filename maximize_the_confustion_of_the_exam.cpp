// Question Link - https://leetcode.com/problems/maximize-the-confusion-of-an-exam/description/
// solution 

class Solution {
public:
    int maxConsecutiveAnswers(string answerKey, int k) {
        int ones=0, zeros=0;
        int i=0, j=0;
        int maxx = INT_MIN;
        for(; i<answerKey.size(); i++)
        {
            for(; j<answerKey.size() && min(ones, zeros)<=k; j++)
            {
                if(answerKey[j] == 'T') ones++;
                else zeros++;
                if(min(ones, zeros)<=k) maxx = max(maxx, j-i+1);
            }
            if(answerKey[i]=='T') ones--;
            else zeros--;
        }
        return maxx;
    }
};