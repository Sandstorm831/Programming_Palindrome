#include <bits/stdc++.h>
using namespace std;
int main()
{
    int cases;
    cin>>cases;
    for(int i=0;i<cases; i++)
    {
        bool f = true;
        string orig, rplc;
        cin>>orig>>rplc;
        if(rplc == "a") 
        {
            cout<<1<<endl;
            f = false;
            continue;
        }
        for(int j=0; j<rplc.size(); j++)
        {
            if(rplc[j] == 'a') 
            {
                cout<<-1<<endl;
                f = false;
                break;
            }
        }
        if(f)
        {
            long long gf = pow(2,orig.length());
            cout<<gf<<endl;
        }
    }
}