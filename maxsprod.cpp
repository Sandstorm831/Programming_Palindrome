// Question Link - https://www.interviewbit.com/problems/maxspprod/
// Solution

int Solution::maxSpecialProduct(vector<int> &A) {
    long long mod = 1e9+7;
    stack<long long> lg;
    stack<long long> rg;
    vector<long long> l;
    vector<long long> r;
    for(long long i=0; i<A.size(); i++)
    {
            while(!lg.empty() && A[lg.top()]<=A[i]) lg.pop();
            if(lg.empty())
            {
                l.push_back(-1);
                lg.push(i);
            } 
            else
            {
                l.push_back(lg.top());
                lg.push(i);
            }
    }
    for(long long i=A.size()-1; i>=0; i--)
    {
            while(!rg.empty() && A[rg.top()]<=A[i]) rg.pop();
            if(rg.empty())
            {
                r.push_back(-1);
                rg.push(i);
            } 
            else
            {
                r.push_back(rg.top());
                rg.push(i);
            }
    }
    reverse(r.begin(), r.end());
    long long maxx = 0;
    for(long long i=0; i<A.size(); i++)
    {
        if(l[i]==-1 || r[i] == -1) continue;
        maxx = max(maxx, (l[i]*1LL*r[i]));
    }
    return maxx%mod;
}

//