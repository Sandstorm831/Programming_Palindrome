#include<bits/stdc++.h>
using namespace std;
int main()
{
    int days, maxs, mins;
    cin>>days;
    int rdr = days%7;
    //cout<<rdr; 

    switch (rdr)
    {
        case 0:
            maxs = mins = 2*(days/7);
            break;
        case 1:
            maxs = 2*(days/7) + 1;
            mins = 2*(days/7);
            break;
        case 2:
           maxs = 2*(days/7) + 2;
            mins = 2*(days/7);
            break;
        case 3:
            maxs = 2*(days/7) + 2;
            mins = 2*(days/7);
        case 4:
            maxs = 2*(days/7) + 2;
            mins = 2*(days/7);
            break;
        case 5:
            maxs = 2*(days/7) + 2;
            mins = 2*(days/7);
            break;
        case 6:
            maxs = 2*(days/7) + 2;
            mins = 2*(days/7) + 1;
            break;
        default:
            break;
    }
    cout<<mins<<" "<<maxs;

}