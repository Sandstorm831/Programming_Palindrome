// Question Link - https://www.interviewbit.com/problems/string-and-its-frequency/
// Solution 

string Solution::solve(string A) {
    vector<int> alp(26, 0);
    vector<int> vis(26, 0);
    for(int i=0; i<A.size(); i++)
    {
        alp[A[i]-'a']++;
    }
    string l = "";
    for(int i=0; i<A.size(); i++)
    {
        if(!vis[A[i]-'a'])
        {
            vis[A[i]-'a'] = 1;
            l+=A[i];
            l+=to_string(alp[A[i]-'a']);
        }
    }
    return l;
}
