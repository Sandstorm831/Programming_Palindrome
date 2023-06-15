// Questino Link - https://www.interviewbit.com/problems/amazing-subarrays/
// Solution 

int Solution::solve(string A) {
    int mod = 10003;
    int summ=0;
    for(int i=0; i<A.size(); i++)
    {
        if(A[i] == 'a' || A[i] == 'e' || A[i] == 'i' || A[i] == 'o' || A[i] == 'u' || A[i] == 'A' || A[i] == 'E' || A[i] == 'I' || A[i] == 'O' || A[i] == 'U')
        {
            summ = (summ%mod + (A.size()-i)%mod)%mod;
        }
        
    }
    return summ%mod;
}
