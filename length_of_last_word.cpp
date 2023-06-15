// Question Link - https://www.interviewbit.com/problems/length-of-last-word/
// Solution

int Solution::lengthOfLastWord(const string A) {
    int last = -1;
    int first = -1;
    bool d = false;
    for(int i=A.size()-1; i>=0; i--)
    {
        if(A[i] != ' ' && !d)
        {
            last = i;
            d=true;
        }
        else if(A[i] == ' ' && d)
        {
            first=i;
            break;
        }
    }
    return last-first;
}
