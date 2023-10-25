#include <bits/stdc++.h>
using namespace std;
int main()
{
    int cases;cin>>cases;
    while(cases--)
    {
        string x;cin>>x;
        reverse(x.begin(), x.end());
        int n = x.size();
        int rount = INT_MIN;
        for(int i=0; i<x.size();i++)
        {
            if(i == n-1 && x[i]-'0' >= 5) 
            {
                x += "1"; rount = i;
                }
            else if(x[i]-'0' >= 5) 
            {
                if(x[i+1] != '9') x[i+1] += 1, rount = i;
                else
                {
                    while( i+1 < x.size() && x[i+1] != '9')
                    {
                        x[i+1] = '0';i++;
                    }
                    if(i+1 < x.size())x[i+1] += 1, rount = i;
                    else x+='1';
                }
            }
        }
        int i = 0;
        while(i <= rount) {x[i] = '0';i++;}
        reverse(x.begin(), x.end());
        cout<<x<<endl;
    }
}