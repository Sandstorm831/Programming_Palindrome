#include <bits/stdc++.h>
using namespace std;
int main()
{
    int cases;
    cin>>cases;
    for(int i=0;i<cases; i++)
    {
        vector<int> holder;
        int n;
        cin>>n;
        for(int j=0; j<n; j++)
        {
            int a;
            cin>>a;
            holder.push_back(a);
        }
        if(n==1)
        {
            cout<<0<<endl;
            continue;
        }
        reverse(holder.begin(), holder.end());
        int held = holder[0];
        if(held == 0)
        {
            cout<<-1<<endl;
            continue;
        }
        int counter=0;
        for(int j=1; j<n; j++)
        {
            if(holder[j]<held)
            {
                if(holder[j] == 0 && j != n-1)
                {
                    cout<<-1<<endl;
                    break;
                }
                if(j == n-1)
                {
                    cout<<counter<<endl;
                    continue;
                }
                held = holder[j];
                continue;
            }
            else
            {
                holder[j] /= 2;
                j--;
                counter++;
            }
        }

    }
}