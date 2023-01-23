#include <bits/stdc++.h>
using namespace std;
int main()
{
    int cases;
    cin>>cases;
    for(int i=0;i<cases;i++)
    {
        int a;
        cin>>a;
        int maxi=9;
        vector<int> holder;
        unordered_set<int> sety;
        if(a<10) 
        {
            cout<<a<<endl;
            continue;
        }
        else
        {
            int diff = a;
            while(diff>0)
            {
                if(diff<10 && sety.find(diff) == sety.end())
                {
                    holder.push_back(diff);
                    sety.insert(diff);
                    diff=0;
                }
                else
                {
                    holder.push_back(maxi);
                    sety.insert(maxi);
                    diff = diff-maxi;
                    maxi--;
                }
            }
        }
        reverse(holder.begin(), holder.end());
        for(int j=0;j<holder.size(); j++)
        {
            cout<<holder[j];
        }
        cout<<endl;

    }
}