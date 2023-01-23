#include <bits/stdc++.h>
using namespace std;
int main()
{
    int cases;
    cin>>cases;
    for(int i=0; i<cases; i++)
    {
        string num;
        cin>>num;
        int sz = num.size()-1;
        int minor = pow(10,sz);
        int orig = stoi(num);
        cout<<orig-minor<<endl;
    }
}