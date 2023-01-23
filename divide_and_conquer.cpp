#include <bits/stdc++.h>
using namespace std;
int decider(int a)
{
    int counter=0;
    if(a%2==0)
    {
        while(a%2 != 1)
        {
            a=floor(a/2);
            counter++;
        }
    }
    else
    {
        while(a%2 != 0)
        {
            a=floor(a/2);
            counter++;
        }
    }
    return counter;
}
int main()
{
    int cases;
    cin>>cases;
    for(int i=0; i<cases; i++)
    {
        int n;
        cin>>n;
        vector<int> hd;
        int summ=0;
        for(int j=0; j<n; j++)
        {
            int a;
            cin>>a;
            summ+=a;
            hd.push_back(a);
        }
        if(summ%2==0) cout<<0<<endl;
        else
        {
            int minn = INT_MAX;
            for(int j=0; j<n; j++)
            {
                int x = decider(hd[j]);
                minn = min(minn, x);
            }
            cout<<minn<<endl;
        }
    }
}