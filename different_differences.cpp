#include <bits/stdc++.h>
using namespace std;
int main()
{
    int cases;
    cin>>cases;
    vector<int> difs;
    vector<int> origs;
    for(int i=0; i<cases; i++)
    {
        int a, b;
        cin>>a>>b;
        origs.push_back(a);
        int diff = a-1;
        int sum = (diff*a/2)+1;
        if(sum<=b) difs.push_back(diff);
        else
        {
            int j;
            for(j=diff-1; j>0; j--)
            {
                if(sum>b) sum -= j;
                else break;
            }
            difs.push_back(j+1);
        }
    }
    vector<int> nw;
    for(int i=0; i<difs.size(); i++)
    {
        nw.clear();
        nw.push_back(1);
        for(int k=0; k<difs[i]; k++)
        {
            nw.push_back(nw[k]+k+1);
        }
        for(int k=0; k<origs[i]-difs[i]-1; k++)
        {
            nw.push_back(nw.back()+1);
        }
        for(int k=0; k<nw.size(); k++)
        {
            cout<<nw[k]<<" ";
        }
        cout<<endl;
    }
}