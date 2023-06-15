// Question Link - https://www.interviewbit.com/problems/an-increment-problem/
// Solution 

vector<int> Solution::solve(vector<int> &A) {
    unordered_map<int,set<int>> mp;
    for(int i=0; i<A.size(); i++)
    {
        int x = A[i];
        if(mp.find(x) != mp.end())
        {
            if(!mp[x].empty()) 
            {
            mp[x].insert(i);
            int ll = *mp[x].begin();
            mp[x].erase(mp[x].begin());
            A[ll]++;
            mp[x+1].insert(ll);   
            }
            else mp[x].insert(i);
        }
        else mp[x].insert(i);
    }
    return A;
}
