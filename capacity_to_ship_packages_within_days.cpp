// Question Link - https://www.interviewbit.com/problems/capacity-to-ship-packages-within-b-days/
// Solution 
bool feasible(vector<int>& A, int B, int C)
{
    int f = 0;
    int days=0;
    for(int i=0; i<A.size(); i++)
    {
        if(A[i]>C) return false;
        f += A[i];
        if(f > C)
        {
            f = A[i];
            days++;
        }
    }
    if(f<=C) days++;
    if(days<=B) return true;
    return false;
}
int Solution::solve(vector<int> &A, int B) {
    int ini = 1;
    int fin = 0;
    vector<int> aa;
    for(int i=0; i<A.size(); i++)
    {
        fin += A[i];
        aa.push_back(fin);
    }
    int m;
    while(ini<=fin)
    {
        m = (ini + fin)/2;
        if(feasible(A, B, m)) fin = m-1;
        else ini = m+1;
    }
    if(feasible(A, B,m)) return m;
    return m+1;
}
