// Question Link - https://www.interviewbit.com/problems/largest-continuous-sequence-zero-sum/
// Solution

vector<int> Solution::lszero(vector<int> &A) {
    int maxl=INT_MIN;
    pair<int,int> holder = {-1,-1};
    unordered_map<int,vector<int>> mp;
    int summ = 0;
    for(int i=0; i<A.size(); i++)
    {
        summ += A[i];
        mp[summ].push_back(i);
    }
    summ=0;
    for(int i=0; i<A.size(); i++)
    {
        summ += A[i];
        if(mp.find(summ)!=mp.end())
        {
            for(int j=0; j<mp[summ].size(); j++)
            {
                if(mp[summ][j]<i && mp[summ][j]!=i)
                {
                    int len = i - mp[summ][j]-1;
                    if(len>maxl)
                    {
                        maxl = len;
                        holder.first = mp[summ][j]+1;
                        holder.second = i;
                    }
                }
            }
        }
        if(summ == 0)
        {
            if(i+1 > maxl)
            {
                maxl = i+1;
                holder.first = 0;
                holder.second = i;
            }
        }
    }
    vector<int> ans;
    if(holder.first == -1) return ans;
    for(int j=holder.first; j<=holder.second; j++)
    {
        ans.push_back(A[j]);
    }
    return ans;
    
}
