#include <bits/stdc++.h>
using namespace std;
const int  N =  200100;
vector<int> tree1(N), tree2(N);
vector<int> r(N), c(N);
int lowbit(int x)
{
    return (x)&(-x);
}
void add1(int x, int y)
{
    for(int j=x; j<N; j+=lowbit(j))
    {
        tree1[j]+=y;
    }   
}
void add2(int x, int y)
{
    for(int j=x; j<N; j+=lowbit(j))
    {
        tree2[j]+=y;
    }   
}
int sum1(int x)
{
    int summ=0;
    for(int j=x; j; j-=lowbit(j))
    {
        summ += tree1[j];
    }
    return summ;
}
int sum2(int x)
{
    int summ=0;
    for(int j=x; j; j-=lowbit(j))
    {
        summ += tree2[j];
    }
    return summ;
}
void solve()
{
    int n,q;
    cin>>n>>q;
    for(int i=0; i<q; i++)
    {
        int t;
        cin>>t;
        if(t==1)
        {
            int x,y;
            cin>>x>>y;
            if(r[x]==0) add1(x,1);
            if(c[y]==0) add2(y,1);
            r[x]++;
            c[y]++;
        }
        else if(t==2)
        {
            int x,y;
            cin>>x>>y;
            if(r[x]==1) add1(x,-1);
            if(c[y]==1) add2(y,-1);
            r[x]--;
            c[y]--;
        }
        else
        {
            int x1,y1,x2,y2;
            cin>>x1>>y1>>x2>>y2;
            int xr = sum1(x2)-sum1(x1-1);
            int yc = sum2(y2)-sum2(y1-1);
            if(xr == x2-x1+1) cout<<"Yes"<<endl;
            else if(yc == y2-y1+1) cout<<"Yes"<<endl;
            else cout<<"No"<<endl;
        }
    }
}
int main()
{
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
        solve() ;
    return 0 ;
}