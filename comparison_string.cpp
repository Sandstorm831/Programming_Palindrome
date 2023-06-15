#include <bits/stdc++.h>
using namespace std;
int main()
{
    int cases;
    cin>>cases;
    for(int i=0; i<cases; i++){
        int n; 
        cin>>n;
        string s;
        cin>>s;
        int maxup = INT_MIN;
        int strup = 0;
        int strdon = 0;
        for(int i=0; i<s.length(); i++)
        {
            if(s[i] == '<')
            {
                if(strdon==0) 
                {
                    strup++;
                    maxup = max(maxup, strup);
                }
                else
                {
                    strdon=0;
                    strup=1;
                    maxup = max(maxup, strup);
                }
            }
            else if(s[i] == '>')
            {
                if(strup==0)
                {
                    strdon++;
                    maxup = max(maxup, strdon);
                }
                else
                {
                    strup=0;
                    strdon = 1;
                    maxup = max(maxup, strdon);
                }
            }
        }
        cout<<maxup+1<<endl;
    }
}