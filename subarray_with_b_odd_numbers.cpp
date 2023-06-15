// QUestion Link - https://www.interviewbit.com/problems/subarray-with-b-odd-numbers/
// Solution 

int Solution::solve(vector<int> &A, int B) {
    unordered_map<int,pair<int,int>> mp;
    int nods=0;
    int count=0;
    for(int i=0; i<A.size(); i++)
    {
        if(A[i]%2==1) 
        {
            nods++;
            mp[nods] = make_pair(count,0);
            if(nods!=1) mp[nods-1].second += count;
            count=0;
        }
        else count++;
    }
    mp[nods].second += count;
    int summer=0;
    if(B==0)
    {
        if(nods == 0) return (A.size())*(A.size()+1)/2;
        for(int i=1; i<=nods; i++)
        {
            summer += (mp[i].first)*(mp[i].first+1)/2;
        }
        summer += (mp[nods].second)*(mp[nods].second+1)/2;
        return summer;
    }
    for(int i=1; i+B-1<=nods; i++)
    {
        summer += (mp[i].first+1)*(mp[i+B-1].second+1);
    }
    return summer;
}
