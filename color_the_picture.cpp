#include <bits/stdc++.h>
using namespace std;
int main()
{
    long long cases;
    cin>>cases;
    for(long long i=0; i<cases;i++)
    {
        long long row, col, clr;
        cin>>row>>col>>clr;
        vector<long long> v;
        long long summer=0;
        for(long long j=0; j<clr; j++)
        {
            long long a;
            cin>>a;
            v.push_back(a);
            summer+=a;
        }
        if(row*col > summer)
        {
            cout<<"No"<<endl;
            continue;
        }
        else if(clr == 1)
        {
            cout<<"Yes"<<endl;
            continue;
        }
        vector<long long> rower, columner;
        bool row_od = false;
        bool col_od = false;
        long long row_sum=0;
        long long col_sum=0;
        for(long long j=0; j<clr; j++)
        {
            long long x = floor(double(v[j]/col));
            if(x>=2) row_sum+=x;
            if(x>=3) row_od=true;
            long long y = floor(double(v[j]/row));
            if(y>=2) col_sum+=y;
            if(y>=3) col_od=true;
        }
        if(row%2==1)
        {
            if(row_sum >= row && row_od)
            {
                cout<<"Yes"<<endl;
                continue;
            }
        }
        else
        {
            if(row_sum>=row)
            {
                cout<<"Yes"<<endl;
                continue;
            }
        }
        if(col%2==1)
        {
            if(col_sum>=col && col_od)
            {
                cout<<"Yes"<<endl;
                continue;
            }
            else
            {
                cout<<"No"<<endl;
                continue;
            }
        }
        else{
            if(col_sum>=col)
            {
                cout<<"Yes"<<endl;
                continue;
            }
            else 
            {
                cout<<"No"<<endl;
                continue;
            }
        }
    }
}