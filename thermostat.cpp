#include <bits/stdc++.h>
using namespace std;
int main()
{
    int cases;
    cin>>cases;
    for(int i=0; i<cases; i++)
    {
        int l, r, diff, init, fin;
        cin>>l>>r>>diff>>init>>fin;
        if(init == fin) cout<<0<<endl;
        else if(abs(init-fin) >= diff) cout<<1<<endl;
        else if(r-max(init, fin)>= diff || min(init, fin)-l>=diff) cout<<2<<endl;
        else if(max(init, fin)-l>=diff && r-min(init, fin)>=diff) cout<<3<<endl;
        else cout<<-1<<endl;
    }
}