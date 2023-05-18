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
        string s;
        cin>>s;
        int counter=0;
        for(int j=0; j<n; j++)
        {
            char x = s[j];
            if(x == '1') counter++;
        }
        if(counter==0 || counter%2==1)
        {
            cout<<"No"<<endl;
            continue;
        }
        vector<pair<int,int>> v;
        int index;
        bool t=true;
        for(int j=0; j<n; j++)
        {
            int x = s[j]-'0';
            v.push_back(make_pair(x,j+1));
            if(x == 1 && t) 
            {
                index = j+1;
                t=false;
            }
        }
        vector<pair<int,int>> b;
        for(int j=index; j<n; j++)
        {
            b.push_back(make_pair(v[j].first,v[j].second));
        }
        for(int j=0; j<index; j++)
        {
            b.push_back(make_pair(v[j].first, v[j].second));
        }
        vector<pair<int,int>> ans;
        bool con=false;
        bool one=false;
        for(int j=1; j<b.size()-1; j++)
        {
            if(b[j].first == 1)
            {
                if(!con)
                {
                    if(b[j+1].first == 1) 
                    {
                        ans.push_back(make_pair(b[j].second, b[0].second));
                        con=false;
                        one=false;
                    }
                    else 
                    {
                        ans.push_back(make_pair(b[j].second, b[j+1].second));
                        con = true;
                        one=true;
                    }
                }
                else
                {
                    con=false;
                    one =false;
                }
            }
            else if(b[j].first == 0)
            {
                if(!con)
                {
                    ans.push_back(make_pair(b[j].second, b[0].second));
                    ans.push_back(make_pair(b[j].second, b[j+1].second));
                    con=true;
                    one=false;
                }
                else
                {
                    if(one)
                    {
                        if(b[j+1].first==1) 
                        {
                            ans.push_back(make_pair(b[j].second, b[0].second));
                            con=false;
                            one=false;
                        }
                        else ans.push_back(make_pair(b[j].second, b[j+1].second));
                    }
                    else
                    {
                        ans.push_back(make_pair(b[j].second, b[j+1].second));
                    }
                }
            }
        }
        if(!con) ans.push_back(make_pair(b[b.size()-1].second, b[0].second));
        cout<<"Yes"<<endl;
        for(int j=0; j<ans.size(); j++)
        {
            cout<<ans[j].first<<" "<<ans[j].second<<endl;
        }
    }
}