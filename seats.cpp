// Question Link - https://www.interviewbit.com/problems/seats/
// Solution 
int Solution::seats(string A) {
    int mod=1e7+3;
    int lc=0,rc=0,moves=0;
    int i=0, j=A.size()-1;
    while(i<=j)
    {
        while(A[i]!='.'&& i<A.size())
        {
            lc++;
            i++;
        }   
        while(A[j]!='.' && j>=0)
        {
            rc++;
            j--;
        }
        if(i>j) break;
        else
        {
            if(lc>rc)
            {
                j--;
                moves= (moves%mod + rc%mod)%mod;
                // cout<<moves<<"rc"<<rc<<endl;
            }
            else if(rc>lc)
            {
                i++;
                moves = (moves%mod + lc%mod)%mod;
                // cout<<moves<<"lc"<<lc<<endl/;
            }
            else
            {
                i++;
                moves = (moves%mod + lc%mod)%mod;
                // cout<<moves<<"="<<rc<<" "<<lc<<endl;
            }
        }
    }
    return moves;
}
