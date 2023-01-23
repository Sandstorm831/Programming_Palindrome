#include <bits/stdc++.h>
using namespace std;
int main()
{
    int cases;
    cin>>cases;
    for(int i=0; i<cases; i++)
    {
        int n;
        cin>>n;
        string encod;
        cin>>encod;
        int counter=n-1;
        string btw="";
        string founder="";
        while(counter>=0)
        {
            char mn = encod[counter];
            if(mn == '0') 
            {
                btw = encod.substr(counter-2, 2);
                counter-= 3;
            }
            else 
            {
                btw = encod.substr(counter,1);
                counter-=1;
            }
            founder+=stoi(btw)+'a'-1;
        }
        reverse(founder.begin(), founder.end());
        cout<<founder<<endl;
    }
}