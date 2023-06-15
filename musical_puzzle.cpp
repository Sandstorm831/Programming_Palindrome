#include <bits/stdc++.h>
using namespace std;
int main()
{
    int cases;
    cin>>cases;
    for(int i=0;i<cases; i++)
    {
        int n;
        cin>>n;
        string s;
        cin>>s;
        set<string> st;
        for(int j=0; j<s.length()-1; j++)
        {
            string t="";
            for(int k=0; k<2; k++)
            {
                t += s[k+j];
            }
            st.insert(t);
        }
        cout<<st.size()<<endl;
    }
}