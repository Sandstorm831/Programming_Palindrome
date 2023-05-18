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
        string s;
        cin>>s;
        string t="";
        if(s[0]-'0' != 9)
        {
            for(int j=0; j<n; j++)
            {
                t+=(9-(s[j]-'0'))+'0';
            }
            cout<<t<<endl;
        }
        else
        {
            int prev=1;
            int curr=1;
            for(int j=n-1; j>=0; j--)
            {
                if(s[j]-'0'<=curr) 
                {
                    // cout<<j<<" "<<(curr-(s[j]-'0'))+'0'<<"if"<<endl;
                    t+= (curr-(s[j]-'0'))+'0';
                }
                else 
                {
                    curr=prev*10+curr;
                    prev=0;
                    // cout<<j<<" "<<(curr-(s[j]-'0'))+'0'<<endl;
                    t+=(curr-(s[j]-'0'))+'0';
                }
                curr = prev;
                prev=1;
            }
            reverse(t.begin(), t.end());
            cout<<t<<endl;
        }

    }
}