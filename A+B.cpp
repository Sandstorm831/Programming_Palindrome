#include <bits/stdc++.h>
using namespace std;
int main()
{
    int tcases;
    cin>>tcases;
    vector<int> forensic;
    for(int i=0; i<tcases; i++)
    {
        string a;
        cin>>a;
        int inta = stoi(a.substr(0, 1));
        int intb = stoi(a.substr(1));
        int ans = inta + intb;
        forensic.push_back(ans);
    }
    for(int i=0; i<forensic.size(); i++)
    {
        cout<<forensic[i]<<endl;
    }
}