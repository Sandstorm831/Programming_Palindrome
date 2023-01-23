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
        vector<int> A; 
        vector<int> B;
        int counta=0;
        int countb=0;
        int diff=0;
        for(int j=0; j<n; j++)
        {
            int a;
            cin>>a;
            if(a==1) counta++;
            A.push_back(a);
        }
        for(int j=0; j<n; j++)
        {
            int a;
            cin>>a;
            if(a==1) countb++;
            if(A[j] != a) diff++;
            B.push_back(a);
        }
        int count = abs(counta-countb);
        if(count<diff) cout<<count+1<<endl;
        else cout<<count<<endl; 
    }
}