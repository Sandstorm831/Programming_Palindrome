#include <bits/stdc++.h>
using namespace std;
int main()
{
    int cases;
    cin>>cases;
    for(int k=0; k<cases; k++)
    {
        int n;
        cin>>n;
        string s;
        cin>>s;
        int ford = 0;
        int bakd = 0;
        vector<int> v;
        set<int> ss;
        for(int i=0; i<s.length(); i++)
        {
            if(s[i] == '(')
            {
                if(bakd>ford)
                {
                    v.push_back(2);
                    ford++;
                    ss.insert(2);
                }
                else
                {
                    ford++;
                    v.push_back(1);
                    ss.insert(1);
                }
            }
            else if(s[i] == ')')
            {
                if(ford>bakd)
                {
                    v.push_back(1);
                    bakd++;
                    ss.insert(1);
                }
                else
                {
                    bakd++;
                    v.push_back(2);
                    ss.insert(2);
                }
            }
        }
        if(ford != bakd) cout<<-1<<endl;
        else 
        {
            if(ss.size()==1)
            {
                cout<<1<<endl;
                for(int j=0; j<v.size(); j++) cout<<1<<" ";
                cout<<endl;
            }
            else
            {
                cout<<2<<endl;
                for(int j=0; j<v.size(); j++) cout<<v[j]<<" ";
                cout<<endl;
            }
        }
    }
}