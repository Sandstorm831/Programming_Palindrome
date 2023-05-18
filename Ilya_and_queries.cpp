#include<bits/stdc++.h>
using namespace std;

main(){
    int m,l,r,cnt=0;

    int dp[100005];
    string s;

    cin>>s>>m;

    for(int i=1;i<s.size();i++){

        if(s[i]==s[i-1])
            cnt++;

        dp[i]= cnt;

    }

    while(m--){
        cin>>l>>r;
        cout<<dp[r-1]-dp[l-1]<<endl;
    }

}

// Time Limit exceeded in the following code
/*
#include<bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    getline(cin, s);
    int a;
    cin>>a;
    for (int j = 0; j < a; j++)
    {
        int c,d,i=0;
        cin>> c>>d;
        for (int l = 0; l < d-c; l++)
        {
            if (s[c+l-1] == s[c+l])
            {
                ++i;
            }
            
        }
        cout<<i<<endl;
        
    }
    
}
*/