#include <bits/stdc++.h>
using namespace std;
int main()
{
    int cases;
    cin>>cases;
    for(int i=0; i<cases; i++)
    {
        int full, ach;
        cin>>full>>ach;
        string holder;
        cin>>holder;
        int counter = 0;
        for(int j=0; j<ach; j++)
        {
            if(holder[j] == 'B') counter++;
        }
        if(counter==ach)
        {
            cout<<0<<endl;
            continue;
        }
        int maxer=counter;
        for(int j=1; j<=full-ach; j++)
        {
            if(holder[j+ach-1] == 'B') counter++;
            if(holder[j-1] == 'B') counter--;
            maxer=max(counter, maxer); 
        }
        cout<<ach-maxer<<endl;
    }
}