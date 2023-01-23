#include <bits/stdc++.h>
using namespace std;
int main()
{
    int cases;
    cin>>cases;
    for(int j=0; j<cases; j++)
    {
        int n, x, y;
        cin>>n>>x>>y;
        if(x!=0 && y!=0) cout<<-1<<endl;
        else if(x==0 && y==0) cout<<-1<<endl;
        else if((n-1)%(x+y) != 0) 
        {
            cout<<-1<<endl;
            // cout<<"why"<<endl;
        }
        else
        {
            int t = (n-1)/(x+y);
            int counter=0;
            int winer=1;
            for(int i=1; i<=n-1; i++)
            {
                if(counter<(x+y)) 
                {
                    cout<<winer<<" ";
                    counter++;
                }
                else
                {
                    winer = i+1;
                    cout<<winer<<" ";
                    counter=1;
                }
            }
            cout<<endl;
        }
    }
}