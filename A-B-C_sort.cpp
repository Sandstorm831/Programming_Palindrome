#include <bits/stdc++.h>
using namespace std;
bool sp_sorter(vector<int>& seq, bool od)
{
    if(od)
    {
        for(int i=1; i<seq.size(); i+=2)
        {
            if(seq[i]>seq[i+1])
            {
                int j = seq[i+1];
                seq[i+1] = seq[i];
                seq[i] = j;
            }
        }
    }
    else
    {
        for(int i=0; i<seq.size(); i+=2)
        {
            if(seq[i]>seq[i+1])
            {
                int j = seq[i+1];
                seq[i+1] = seq[i];
                seq[i] = j;
            }
        }
    }
    bool fin=true;
    for(int i=0; i<seq.size()-1; i++)
    {
        if(seq[i]>seq[i+1])
        {
            fin = false;
            break;
        }
    }
    return fin;
}
int main()
{
    int cases;
    cin>>cases;
    for(int i=0; i<cases; i++)
    {
        int n;
        int minn=INT_MAX;
        cin>>n;
        vector<int> seq;
        for(int j=0; j<n; j++)
        {
            int a;
            cin>>a;
            minn = min(minn, a);
            seq.push_back(a);
        }
        if(n%2!=0)
        {
            if(minn == seq[0])
            {
                if(sp_sorter(seq, true)) cout<<"YES"<<endl;
                else cout<<"NO"<<endl;
            }
            else cout<<"NO"<<endl;
        }
        else
        {
            if(sp_sorter(seq, false)) cout<<"YES"<<endl;
            else cout<<"NO"<<endl;
        }
    }
}