#include <bits/stdc++.h>
using namespace std;
int main()
{
    int cases;
    cin>>cases;
    for(int i=0;i<cases;i++)
    {
        string s;
        cin>>s;
        vector<int> al;

        for(int j=0;j<s.length();j++)
        {
            al.push_back(s[j]-'0');
        }
        vector<int> nw;
        vector<int>::iterator c;
        int prev_ind=0;
        for(int j=0; j<9; j++)
        {
            for(int k=prev_ind; k<s.length(); k++)
            {
                if(al[k] == j)
                {
                    nw.push_back(j);
                    prev_ind = k;
                    al[k]=10;
                }
            }
        }
        // cout<<prev_ind<<endl;
        sort(al.begin(), al.end());
        int b=0,d=0;
        // for(int l=0; l<al.size(); l++) cout<<al[l];
        // cout<<endl;
        while(b+d<s.length())
        {
            if(b == al.size())
            {
                cout<<nw[d];
                d++;
            }
            else if(d == nw.size())
            {
                cout<<min(al[b]+1,9);
                b++;
            }
            else if(min(al[b]+1,9)>nw[d]) 
            {
                cout<<nw[d];
                d++;
            }
            else 
            {
                cout<<al[b]+1;
                b++;
            }
        }
        cout<<endl;
    }
}