// Que link -n https://www.interviewbit.com/problems/maximum-sum-triplet/
// solution
int Solution::solve(vector<int> &A) {
    int n = A.size();
    vector<int> right(n, -1);
    int maxer = INT_MIN;
    for(int j=n-1; j>=0; j--)
    {
        maxer = max(maxer, A[j]);
        right[j] = maxer;
    }
    multiset<int> ms;
    vector<int> vm;
    for(int j=0; j<n; j++)
    {
        ms.insert(A[j]);
        auto itr = ms.lower_bound(A[j]);
        if(itr == ms.begin()) vm.push_back(INT_MAX);
        else vm.push_back(*(--itr));
    }
    maxer = INT_MIN;
    for(int j=0; j<n; j++)
    {
        if(right[j]>A[j] && vm[j]<A[j])
        {
            maxer = max(right[j]+A[j]+vm[j], maxer);
        }
    }
    return maxer;
}