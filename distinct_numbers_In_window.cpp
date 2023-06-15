// Question Link - https://www.interviewbit.com/problems/distinct-numbers-in-window/
// Solution 

vector<int> Solution::dNums(vector<int> &A, int B) {
    unordered_map<int,int> mp;
    int dist=0;
    for(int i=0; i<B; i++)
    {
        if(mp.find(A[i]) == mp.end()) 
        {
            mp[A[i]]=1;
            dist++;
        }
        else mp[A[i]]++;
    }
    vector<int> ans;
    ans.push_back(dist);
    for(int i=B; i<A.size(); i++)
    {
        if(mp[A[i-B]]==1)
        {
            dist--;
            mp.erase(A[i-B]);
        }
        else mp[A[i-B]]--;
        if(mp.find(A[i]) == mp.end())
        {
            mp[A[i]]=1;
            dist++;
        }
        else mp[A[i]]++;
        ans.push_back(dist);
    }
    return ans;
}
