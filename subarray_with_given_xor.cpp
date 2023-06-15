// Question Link - https://www.interviewbit.com/problems/subarray-with-given-xor/
// Solution

int Solution::solve(vector<int> &A, int B) {
    unordered_map<int,vector<int>> mp;
    int xr = A[0];
    for(int i=1; i<A.size(); i++)
    {
        xr  = xr^A[i];
        int num = xr^B;
        mp[num].push_back(i);
    }
    int counter=0;
    xr = 0;
    for(int i=0; i<A.size(); i++)
    {
        xr = xr^A[i];
        if(mp.find(xr) != mp.end())
        {
            for(int j=0; j<mp[xr].size();j++)
            {
                if(i < mp[xr][j]) counter++;
            }
        }
        if(xr == B) counter++;
    }
    return counter;
}
