#include <bits/stdc++.h>
using namespace std;
int main()
{
    int cases;
    cin>>cases;
    for(int i=0; i<cases; i++)
    {
        int num, sum;
        int maxx=INT_MIN;
        cin>>num>>sum;
        for(int j=0; j<num; j++)
        {
            int a;
            cin>>a;
            maxx = max(maxx, a);
            sum+=a;
        }
        int sm=0, cnt=0;
        for(int j=1; j<=sum; j++)
        {
            if(sm>=sum) break;
            sm += j;
            cnt = j;
        }
        if(sm != sum || cnt < maxx || cnt <= num) cout<<"NO";
        else cout<<"YES";
    }
}