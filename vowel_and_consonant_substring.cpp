// Question Link - https://www.interviewbit.com/problems/vowel-and-consonant-substrings/
// Solution

int Solution::solve(string A) {
    int mod = 1e9+7;
    int vow=0, con = 0;
    for(int i=0; i<A.size(); i++)
    {
        if(A[i] == 'a' || A[i] == 'e' || A[i] == 'i' || A[i] == 'o' || A[i] ==  'u') vow++;
        else con ++;
    }
    return (vow%mod * con%mod)%mod;
}
