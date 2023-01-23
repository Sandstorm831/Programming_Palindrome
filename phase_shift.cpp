#include <bits/stdc++.h>
using namespace std;
int circle_len(vector<vector<int>>& dp, int front, int back)
{
    int l=2;
    while(dp[1][front] != -1 && dp[1][front] != back)
    {
        front = dp[1][front];
        l++;
    }
    if(dp[1][front]==-1) return 0;
    else return l;
}
int main()
{
    int cases;
    cin>>cases;
    for(int i=0;i<cases; i++)
    {
        int n;
        cin>>n;
        string a;
        cin>>a;
        int circle=0;
        vector<vector<int>> dp(2, vector<int> (26, -1));
        int index = 0;
        vector<int> store(26,1);
        for(int j=0; j<a.length(); j++)
        {
            int curr = a[j]-'a';
            int curr_ind = index;
            bool blo=true;
            if(dp[0][curr] != -1) continue;
            while(blo)
            {
                while(curr == curr_ind || dp[1][curr_ind] != -1 || store[curr_ind] == 0)
                {
                    curr_ind++;
                    curr_ind %= 26;
                }
                store[curr_ind]=0;
                dp[0][curr] = curr_ind;
                dp[1][curr_ind] = curr;
                if(circle!=26) circle = circle_len(dp, curr, curr_ind);
                if(circle==26 || circle==0)
                {
                    // cout<<"h"<<endl;
                    blo=false;
                    if(curr_ind == index) index++;
                } 
                else
                {
                    store[curr_ind]=1;
                    dp[0][curr]=-1;
                    dp[1][curr_ind]=-1;
                    curr_ind++;
                    curr_ind %= 26;
                }
            } 
        }
        for(int j=0; j<a.length(); j++)
        {
            int dx = a[j]-'a';
            cout<<char(dp[0][dx]+'a');
        }
        cout<<endl;
    }
}