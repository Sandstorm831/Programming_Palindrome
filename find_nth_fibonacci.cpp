// Problem Link - https://www.interviewbit.com/problems/find-nth-fibonacci/
#include <bits/stdc++.h>
using namespace std;
vector<vector<long long int>> multiply(vector<vector<long long int>> v1, vector<vector<long long int>> v2)
{
    int mod = pow(10,9)+7;
    vector<vector<long long int>> temp(2, vector<long long int> (2));
    temp[0][0] = ((v1[0][0]*v2[0][0])%mod+(v1[0][1]*v2[1][0])%mod)%mod;
    temp[0][1] = ((v1[0][0]*v2[0][1])%mod+(v1[0][1]*v2[1][1])%mod)%mod;
    temp[1][0] = ((v1[1][0]*v2[0][0])%mod+(v1[1][1]*v2[1][0])%mod)%mod;
    temp[1][1] = ((v1[1][0]*v2[0][1])%mod+(v1[1][1]*v2[1][1])%mod)%mod;
    return temp;
}
vector<vector<long long int>> helper(vector<vector<long long int>> &v, int n)
{
    if(n==1) return v;
    vector<vector<long long int>> temp = helper(v, n/2);
    vector<vector<long long int>> ans = multiply(temp,temp);
    if(n&1) return multiply(ans,v);
    return ans;
}
int solver(int A) {
    int n = A;
    vector<vector<long long int>> v = {{1,1},{1,0}};
    vector<vector<long long int>> ans = helper(v,A);
    return ans[0][0];
}
int main()
{
    cout<<solver(10);
}