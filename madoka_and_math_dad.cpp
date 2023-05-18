#include <bits/stdc++.h>
using namespace std;
int main()
{
    int cases;
    cin>>cases;
    for(int i=0; i<cases;i++)
    {
        int n;
        cin>>n;
        if(n==1) cout<<1;
        else if(n==2) cout<<2;
        else if(n%3==1)
        {
            int sum=0;
            int digits=0;
            while(sum<n)
            {          
                if(digits%2==0)
                {
                    cout<<1;
                    sum+=1;
                    digits++;
                }
                else
                {
                    cout<<2;
                    sum+=2;
                    digits++;
                }
            }
        }
        else
        {
            int sum=0;
            int digits=0;
            while(sum<n)
            {          
                if(digits%2==1)
                {
                    cout<<1;
                    sum+=1;
                    digits++;
                }
                else
                {
                    cout<<2;
                    sum+=2;
                    digits++;
                }
            }
        }
        cout<<endl;
    }
}