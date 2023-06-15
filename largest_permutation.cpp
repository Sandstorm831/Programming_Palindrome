// Question Link - https://www.interviewbit.com/problems/largest-permutation/
// Solution 

vector<int> Solution::solve(vector<int> &A, int B) {
    unordered_map<int,int> mp;
    int target = A.size();
    int swaps = B;
    vector<int> ans(A.size(),-1);
    for(int i=0; i<A.size(); i++)
    {
        mp[A[i]]=i;
    }
    int index = 0;
    while(swaps > 0 && index<A.size())
    {
        if(mp[target] == index)
        {
            ans[index] = target;
            target--;index++;
        }
        else
        {
            ans[index]=target;
            ans[mp[target]] = A[index];
            swaps--;
            A[index] = ans[index];
            A[mp[target]]=ans[mp[target]];
            mp[ans[mp[target]]]=mp[target];
            mp[target]=index;
            index++, target--;
        }
    }
    for(int i=0; i<ans.size(); i++)
    {
        if(ans[i] == -1) ans[i] = A[i];
    }
    return ans;
}