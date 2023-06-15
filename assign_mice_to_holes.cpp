// Question Link - https://www.interviewbit.com/problems/assign-mice-to-holes/
// Solution 

int Solution::mice(vector<int> &A, vector<int> &B) {
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    int maxx = INT_MIN;
    for(int i=0;i<A.size();i++)
    {
        maxx = max(maxx, abs(A[i]-B[i]));
    }
    return maxx;
}
