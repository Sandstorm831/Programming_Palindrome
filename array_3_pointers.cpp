// Question Link - https://www.interviewbit.com/problems/array-3-pointers/
// Solution 

int Solution::minimize(const vector<int> &A, const vector<int> &B, const vector<int> &C) {
    vector<pair<int,int>> v;
    for(int i=0; i<A.size(); i++) v.push_back(make_pair(A[i], 0));
    for(int i=0; i<B.size(); i++) v.push_back(make_pair(B[i],1));
    for(int i=0; i<C.size(); i++) v.push_back(make_pair(C[i],2));
    sort(v.begin(), v.end());
    int minn = INT_MAX;
    set<int> sety;
    int miner=INT_MAX;
    for(int i=0; i<v.size(); i++)
    {
        sety.clear();
        sety.insert(v[i].second);
        int j=i+1;
        for(; j<v.size(); j++)
        {
            if(v[j].second == v[i].second)
            {
                i = max(i+1, j-1);
            }
            else if(v[j].second != v[i].second && sety.size()==1) 
            {
                sety.insert(v[j].second);
            } 
            else if(v[j].second != v[i].second && sety.size()==2)
            {
                sety.insert(v[j].second);
                if(sety.size()==3)
                {
                    minn = min(minn, v[j].first - v[i].first);
                    sety.erase(sety.find(v[i].second));
                    i = j-1;
                }
            }
        }
    }
    return minn;
}