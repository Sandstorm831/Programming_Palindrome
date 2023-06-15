// Question Link - https://www.interviewbit.com/problems/equal/
// Solution 

vector<int> Solution::equal(vector<int> &A) {
    unordered_map<int,vector<pair<int,int>>> mp;
    for(int i=0; i<A.size(); i++)
    {
        for(int j=i+1; j<A.size(); j++)
        {
            mp[A[i]+A[j]].push_back(make_pair(i,j));
        }
    }
    set<vector<int>> sv;
    for(int i=0; i<A.size(); i++)
    {
        for(int j=i+1; j<A.size(); j++)
        {
            int summ = A[i]+A[j];
            if(mp.find(summ) != mp.end())
            {
                for(int k=0; k<mp[summ].size(); k++)
                {
                    if(i != mp[summ][k].first && i != mp[summ][k].second && j != mp[summ][k].first && j != mp[summ][k].second)
                    {
                        vector<int>v;
                        if(i<min(mp[summ][k].first,mp[summ][k].second))
                        {
                            v.push_back(i);v.push_back(j);v.push_back(mp[summ][k].first);v.push_back(mp[summ][k].second);
                        }
                        else
                        {
                            v.push_back(mp[summ][k].first);v.push_back(mp[summ][k].second); v.push_back(i);v.push_back(j);
                        }
                        sv.insert(v);
                        vector<int> l = *sv.begin();
                        sv.clear();
                        sv.insert(l);
                        break;
                    }
                }
            }
        }
    }
    vector<vector<int>> v;
    for(auto itr=sv.begin(); itr!=sv.end(); itr++)
    {
        v.push_back(*itr);
    }
    return v[0];
}
