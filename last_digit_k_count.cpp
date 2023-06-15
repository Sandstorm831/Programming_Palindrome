// Question Link - https://www.interviewbit.com/problems/last-digit-k-count/
// Solution 

int Solution::solve(int A, int B, int C) {
    int range = abs(A-B);
    int curr=A;
    while(curr%10 != C && range >0 ) range--, curr++;
    if(range == 0) 
    {
        if(curr%10 == C) return 1;
        return 0;
    }
    return range/10 + 1;
}
