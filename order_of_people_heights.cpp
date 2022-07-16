// Problem Link - https://www.interviewbit.com/problems/order-of-people-heights/
/* Problem Solution Function ---------------------------------------------------------+
void build(int node, int start, int end, vector<int>& SegTree)      <-----------------+
{
    if(start==end)
        SegTree[node] = 1;
    else
    {
        int mid = (start+end)/2;
        build(2*node+1, start, mid, SegTree);
        build(2*node+2, mid+1, end, SegTree);
        SegTree[node] = SegTree[2*node+1] + SegTree[2*node+2];
    }
}
 
void update(int node, int start, int end, int ind, int val, vector<int>& SegTree)
{
    if(start==end)
        SegTree[node] = val;
    else
    {
        int mid = (start+end)/2;
        if(ind<=mid)
            update(2*node+1, start, mid, ind, val, SegTree);
        else
            update(2*node+2, mid+1, end, ind, val, SegTree);
        SegTree[node] = SegTree[2*node+1] + SegTree[2*node+2];
    }
}
int query(int node, int start ,int end, int spaces, vector<int>& SegTree)
{
    if(start>end)
        return -1;
    if(start==end)
        return start;
 
    int leftspace = SegTree[node*2+1];
    int rightspace = SegTree[node*2+2];
 
    int mid = (start+end)/2;
 
    if(leftspace >= spaces)
        return query(node*2+1, start, mid, spaces, SegTree);
    else
        return query(node*2+2, mid+1, end, spaces-leftspace, SegTree);
}
 
vector<int> Solution::order(vector<int> &A, vector<int> &B)
{
    vector<pair<int,int> > v;
    int n = A.size();
 
    for(int i=0;i<n;i++)
        v.push_back({A[i],B[i]});
 
    sort(v.begin(), v.end());
 
    vector<int> res(n);
    
    vector<int> SegTree(4*n,1);
    // SegTree = new int[4*n];
    // memset(SegTree,1,sizeof(SegTree));
    build(0,0,n-1, SegTree);
 
    for(int i=0;i<n;i++)
    {
        int ind = query(0,0,n-1,v[i].second+1, SegTree);
        res[ind] = v[i].first;
        update(0,0,n-1,ind,0, SegTree);
    }
 
    return res;
}
*/
#include <bits/stdc++.h>
using namespace std;
void build(int node, int start, int end, vector<int>& SegTree)
{
    if(start==end)
        SegTree[node] = 1;
    else
    {
        int mid = (start+end)/2;
        build(2*node+1, start, mid, SegTree);
        build(2*node+2, mid+1, end, SegTree);
        SegTree[node] = SegTree[2*node+1] + SegTree[2*node+2];
    }
}
 
void update(int node, int start, int end, int ind, int val, vector<int>& SegTree)
{
    if(start==end)
        SegTree[node] = val;
    else
    {
        int mid = (start+end)/2;
        if(ind<=mid)
            update(2*node+1, start, mid, ind, val, SegTree);
        else
            update(2*node+2, mid+1, end, ind, val, SegTree);
        SegTree[node] = SegTree[2*node+1] + SegTree[2*node+2];
    }
}
int query(int node, int start ,int end, int spaces, vector<int>& SegTree)
{
    if(start>end)
        return -1;
    if(start==end)
        return start;
 
    int leftspace = SegTree[node*2+1];
    int rightspace = SegTree[node*2+2];
 
    int mid = (start+end)/2;
 
    if(leftspace >= spaces)
        return query(node*2+1, start, mid, spaces, SegTree);
    else
        return query(node*2+2, mid+1, end, spaces-leftspace, SegTree);
}
 
vector<int> order(vector<int> &A, vector<int> &B)
{
    vector<pair<int,int> > v;
    int n = A.size();
 
    for(int i=0;i<n;i++)
        v.push_back({A[i],B[i]});
 
    sort(v.begin(), v.end());
 
    vector<int> res(n);
    
    vector<int> SegTree(4*n,1);
    build(0,0,n-1, SegTree);
 
    for(int i=0;i<n;i++)
    {
        int ind = query(0,0,n-1,v[i].second+1, SegTree);
        res[ind] = v[i].first;
        update(0,0,n-1,ind,0, SegTree);
    }
 
    return res;
}
int main()
{
    vector<int> A = {86, 77};
    vector<int> B = {0,1};
    vector<int> ans = order(A, B);
    for (int i = 0; i < ans.size(); i++)
    {
        cout<<ans[i]<<" ";
    }
    
    
}