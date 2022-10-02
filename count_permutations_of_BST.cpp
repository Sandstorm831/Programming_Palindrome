/*
Problem Link - https://www.interviewbit.com/problems/count-permutations-of-bst/
#define MOD 1000000007ll
typedef long long LL;
void add(int &x, int y){
    x += y;
    if(x>=MOD)x-=MOD;
}
vector<vector<int>> choose,dp;
void build(int N){
    choose[0][0]=1;
    for(int i=1; i<=2*N; i++){
        choose[i][0]=1;
        for(int j=1; j<=i; j++){
            choose[i][j]=choose[i-1][j];
            add(choose[i][j], choose[i-1][j-1]);
        }
    }
}
int rec(int n, int h){ 
    if(n<=1)return (h==0);
    if(h<0)return 0;
    if(dp[n][h]!=-1)return dp[n][h];
    int ret=0;
    int x, y;
    for(int i=1; i<=n; i++){
        x=i-1;
        y=n-x-1;
        int sum1=0,sum2=0,ret1=0;
        for(int j=0; j<=h-2; j++){
            add(sum1, rec(x, j));
            add(sum2, rec(y, j));
        }
        add(ret1, ((LL)sum1*(LL)rec(y, h-1))%MOD);
        add(ret1, ((LL)sum2*(LL)rec(x, h-1))%MOD);
        add(ret1, ((LL)rec(x, h-1)*(LL)rec(y, h-1))%MOD);
        ret1 = ((LL)ret1*(LL)choose[x+y][y])%MOD;
        add(ret, ret1);
    }
    return dp[n][h]=ret;
}

int Solution::cntPermBST(int A, int B) {
    int n=50;
    choose.clear();
    dp.clear();
    choose.resize(2*n+1,vector<int>(2*n+1, 0));
    dp.resize(n+1,vector<int>(n+1, -1));
    build(n);
    return rec(A, B);
}
*/
#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007ll
typedef long long LL;
void add(int &x, int y){
    x += y;
    if(x>=MOD)x-=MOD;
}
vector<vector<int>> choose,dp;
void build(int N){
    choose[0][0]=1;
    for(int i=1; i<=2*N; i++){
        choose[i][0]=1;
        for(int j=1; j<=i; j++){
            choose[i][j]=choose[i-1][j];
            add(choose[i][j], choose[i-1][j-1]);
        }
    }
}
int rec(int n, int h){ 
    if(n<=1)return (h==0);
    if(h<0)return 0;
    if(dp[n][h]!=-1)return dp[n][h];
    int ret=0;
    int x, y;
    for(int i=1; i<=n; i++){
        x=i-1;
        y=n-x-1;
        int sum1=0,sum2=0,ret1=0;
        for(int j=0; j<=h-2; j++){
            add(sum1, rec(x, j));
            add(sum2, rec(y, j));
        }
        add(ret1, ((LL)sum1*(LL)rec(y, h-1))%MOD);
        add(ret1, ((LL)sum2*(LL)rec(x, h-1))%MOD);
        add(ret1, ((LL)rec(x, h-1)*(LL)rec(y, h-1))%MOD);
        ret1 = ((LL)ret1*(LL)choose[x+y][y])%MOD;
        add(ret, ret1);
    }
    return dp[n][h]=ret;
}
int main()
{
    int A = 14;
    int B = 5;
    int n=50;
    choose.clear();
    dp.clear();
    choose.resize(2*n+1,vector<int>(2*n+1, 0));
    dp.resize(n+1,vector<int>(n+1, -1));
    build(n);
    return rec(A, B);
}