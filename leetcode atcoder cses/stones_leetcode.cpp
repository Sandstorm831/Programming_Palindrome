// Question Link -

#include <bits/stdc++.h>
using namespace std;
int recursor(vector<pair<int,int>> & dfi, vector<pair<int,int>>& sup, vector<bool>& vis, vector<bool>& sip)
{

    int minn = INT_MAX;
    for(int i=0; i<dfi.size(); i++)
    {
        int counter;
        for(int j=0; j<sup.size(); j++)
        {
            if(!vis[i] && !sip[j])
            {
                vis[i]=true, sip[j]=true;
                int dist = abs(sup[j].first - dfi[i].first)+abs(sup[j].second - dfi[i].second);
                counter = recursor(dfi, sup, vis, sip);
                minn = min(minn, counter+dist);
                vis[i]=false, sip[j]=false;
            }
        }
    }
    if(minn == INT_MAX) return 0;
    else return minn;

    return minn;
}
int solution(vector<vector<int>>& A)
{
    vector<pair<int,int>> dfi, sup;
    for(int i=0; i<A.size(); i++)
    {
        for(int j=0; j<A[0].size(); j++)
        {
            if(A[i][j]<1) dfi.push_back(make_pair(i,j));
            else if(A[i][j] > 1) 
            {
                while(A[i][j]>1)
                {
                    sup.push_back(make_pair(i,j));A[i][j]--;
                }
            }
        }
    }
    vector<bool> vis(dfi.size()+1, false), sip(sup.size()+1, false);
    return recursor(dfi, sup, vis, sip);
}
int main()
{
    vector<vector<int>> A = {{1,0,1},{1,3,0}, {2,0,1}};
    cout<<solution(A)<<endl;
}