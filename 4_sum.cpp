// Question Link - https://www.interviewbit.com/problems/4-sum/
// solution 

vector<vector<int> > Solution::fourSum(vector<int> &A, int B) {
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
            int summ = B-A[i]-A[j];
            if(mp.find(summ) != mp.end())
            {
                for(int k=0; k<mp[summ].size(); k++)
                {
                    if(i != mp[summ][k].first && i != mp[summ][k].second && j != mp[summ][k].first && j != mp[summ][k].second)
                    {
                        vector<int>v;
                        v.push_back(A[i]);v.push_back(A[j]);v.push_back(A[mp[summ][k].first]);v.push_back(A[mp[summ][k].second]);
                        sort(v.begin(),v.end());
                        sv.insert(v);
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
    return v;
}
