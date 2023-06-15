//Question Link - https://www.interviewbit.com/problems/disjoint-intervals/
// Solution 

int Solution::solve(vector<vector<int> > &A) {
    sort(A.begin(),A.end());
    int ans=1;
    int prev=A[0][1];
    for(int i=1;i<A.size();i++){
        if(A[i][0]>prev) {
            prev=A[i][1];
            ans++;
        }
        else{
            prev=min(A[i][1],prev);
        }
    }
    return ans;
}