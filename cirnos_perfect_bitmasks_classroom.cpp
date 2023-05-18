#include <bits/stdc++.h>
using namespace std;
int main()
{
    int cases;
    cin>>cases;
    for(int i=0;i<cases;i++)
    {
        int n;
        cin>>n;
        int w = n&(-n);
        while(!(w^n)||!(w&n)) w++;
        cout<<w<<endl;
    }
}