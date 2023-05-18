#include <bits/stdc++.h>
using namespace std;
int main()
{
    int cases;
    cin>>cases;
    for(int i=0; i<cases; i++)
    {
        int n,m,nr,mr,nd,md;
        cin>>n>>m>>nr>>mr>>nd>>md;
        int rows, cols;
        if(nr<=nd) rows = nd-nr;
        if(mr<=md) cols = md-mr;
        if(mr>md) cols = 2*(m-mr)+mr-md;
        if(nr>nd) rows = 2*(n-nr)+nr-nd;
        cout<<min(rows,cols)<<endl;
    }
}