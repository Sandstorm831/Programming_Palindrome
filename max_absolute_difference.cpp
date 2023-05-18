// Que link - https://www.interviewbit.com/problems/maximum-absolute-difference/

// solution
int Solution::maxArr(vector<int> &A) {
    vector<int> vp, vn;
    for(int i=0; i<A.size(); i++)
    {
        vp.push_back(A[i]+i);
        vn.push_back(A[i]-i);
    }
    int maxp=INT_MIN, minp=INT_MAX, maxn=INT_MIN, minn=INT_MAX;
    for(int i=0; i<A.size(); i++)
    {
        maxp = max(maxp, vp[i]);
        minp = min(minp, vp[i]);
        maxn = max(maxn, vn[i]);
        minn = min(minn, vn[i]);
    }
    return max(maxp-minp, maxn-minn);
}