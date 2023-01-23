#include <bits/stdc++.h>
using namespace std;
int main()
{
    int cases;
    cin>>cases;
    for(int i=0; i<cases; i++)
    {
        string qn;
        cin>>qn;
        int counter=0;
        for(int j=0; j<qn.length(); j++)
        {
            if(qn[j] == '0') 
            {
                counter++;
                break;
            }
            else if(qn[j] == '1')
            {
                counter=1;
                continue;
            }
            else
            {
                counter++;
                continue;
            }
        }
        cout<<counter<<endl;
    }
}