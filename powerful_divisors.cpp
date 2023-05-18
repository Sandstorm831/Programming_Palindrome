// Question Link - https://www.interviewbit.com/problems/powerful-divisors/
// Solution

vector<int> Solution::powerfulDivisors(vector<int> &A) {
    int maxy=INT_MIN;
    for(int i=0;i<A.size(); i++) maxy = max(maxy, A[i]);
    int n = maxy;
    vector<int> v(n+1, 0);
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j*i<=n; j++)
        {
            v[j*i]++;
        }
    }
    for(int i=1; i<v.size(); i++)
    {
        int x = log(v[i])/log(2);
        if(pow(2,x) == v[i]) v[i]=1;
        else v[i] = 0;
    }
    for(int i=1; i<v.size(); i++)
    {
        v[i] += v[i-1];
    }
    vector<int> b;
    for(int i=0;i<A.size(); i++)
    {
        b.push_back(v[A[i]]);
    }
    return b;
}
