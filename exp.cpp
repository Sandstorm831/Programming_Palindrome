#include <bits/stdc++.h>
using namespace std;
int main()
{
    // string t = "0003840";
    // cout<<stoll(t)<<endl;s
    set<int> s;
    s.insert(1);s.insert(2); s.insert(3); s.insert(4); s.insert(5);
    set<int>::iterator ii = s.begin();
    set<int>::iterator dd = s.begin();
    // s.erase(ii);
    // ii = ++dd;
    // cout<<*ii<<endl;
    // s.erase(ii);
    // ii = ++dd;
    // ii++;
    // s.erase(ii);
    // ii++;
    // s.erase(ii);
    // ii++;
    // s.erase(ii);
    while(ii != s.end())
    // for(; ii!=s.end(); ++ii)
    {
        cout<<*ii<<endl;
        cout<<s.size()<<"|"<<endl;
        // ii = itr;
        ii = s.erase(ii);
        // advance(ii,1);
        cout<<*(ii)<<endl;
    }
}