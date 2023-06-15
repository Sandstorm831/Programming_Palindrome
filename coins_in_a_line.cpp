// Question LInk - https://www.interviewbit.com/problems/coins-in-a-line/
// Solution 

vector<vector<int>> dp;
int recursor(vector<int> &A, int ini, int fin)
{
    if(fin - ini == 1) return max(A[ini], A[fin]);
    else if(dp[ini][fin]!=-1) return dp[ini][fin];
    else
    {
        return dp[ini][fin] = max(min(recursor(A, ini+2, fin)+A[ini], recursor(A, ini+1, fin-1)+A[ini]), min(recursor(A, ini, fin-2)+A[fin], recursor(A, ini+1, fin-1)+A[fin]));
    }
}
int Solution::maxcoin(vector<int> &A) {
    dp.clear();
    dp.resize(A.size(), vector<int> (A.size(),-1));
    return recursor(A, 0, A.size()-1);
}

// learn from here https://www.ics.uci.edu/~goodrich/teach/cs260P/notes/GameStrategies.pdf