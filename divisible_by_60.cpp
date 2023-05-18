// Question Link - https://www.interviewbit.com/problems/divisible-by-60/
// Solution

int Solution::divisibleBy60(vector<int> &A) {
    if(A.size()==1 && A[0]==0) return 1;
    int summ =0 ;
    int zero=0;
    int even=0;
    for(int i=0; i<A.size(); i++)
    {
        summ += A[i];
        if(A[i] == 0) zero=1;
        else if(A[i]%2==0) even=1;
    }
    if(summ%3 == 0 && zero && even) return 1;
    return 0;
}