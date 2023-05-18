#include <bits/stdc++.h>
using namespace std;
vector<int> cml;
int main()
{
    cml.clear();
    int cases;
    cin>>cases;
    int N = 1e9;
    long long ans=0;
    int counter=0;
    int latest=0;
    while(ans<N)
    {
        if(counter%3==0)
        {
            counter++;
            latest += 0;
        }
        else
        {
            counter++;
            latest += 2;
        }
        ans += latest;
        cml.push_back(ans);
    }
    for(int i=0; i<cases; i++)
    {
        int n;
        cin>>n;
        cout<<lower_bound(cml.begin(), cml.end(), n)-cml.begin()+1<<endl;
    }
}