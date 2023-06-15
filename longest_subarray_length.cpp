// Question Link - https://www.interviewbit.com/problems/longest-subarray-length/
// Solution

int Solution::solve(vector<int> &A) {
    unordered_map<int,vector<int>> mp;
    int diff = -1;
    int zeros=0;
    int ones=0;
    for(int i=0; i<A.size(); i++)
    {
        if(A[i]==0) zeros++;
        else ones++;
        diff = ones-zeros;
        mp[diff].push_back(i);
    }
    diff=-1;
    zeros=0;
    ones=0;
    int maxl = INT_MIN;
    for(int i=0; i<A.size(); i++)
    {
        if(A[i]==0) zeros++;
        else ones++;
        diff = ones-zeros;
        if(mp.find(diff-1) != mp.end())
        {
            for(int j=0;j<mp[diff-1].size(); j++)
            {
                if(mp[diff-1][j] < i)
                {
                    int len = i-mp[diff-1][j];
                    maxl = max(len,maxl);
                }
                break;
            }
        }
        if(diff==1)
        {
            maxl = max(maxl, i+1);
        }
    }
    return maxl;
}
