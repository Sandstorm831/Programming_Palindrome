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
        string calc;
        cin>>calc;
        int counter=0;
        char prev = calc[0];
        bool verdict=false;
        for(int j=0; j<n; j++)
        {
            if(calc[j] == '1' && !verdict) 
            {
                verdict=true;
                prev = calc[j];
                continue;
            }
            if(verdict)
            {
                if(prev != calc[j]) 
                {
                    counter++;
                    prev = calc[j];
                }
            }
        }
        cout<<counter<<endl;
    }
}