#include <bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    cin>>s;
    string num = "9223372036854775807";
    long long int nm = 9223372036854775807;
    long long int d=0;
    bool can = true;
    bool hav = true;
    if(s ==  num) cout<<"long"<<endl;
    else if(s.length()>19) cout<<"BigInteger"<<endl;
    else if(s.length()==19)
    {
        int index=0;
        while(hav)
        {
            long long int x = s[index] - '0';
            long long int y = num[index]-'0';
            index++;
            if(x>y) 
            {
                hav=false;
                can=false;
            }
            else if(x<y) hav=false;
        }
        if(can) cout<<"long"<<endl;
        else cout<<"BigInteger"<<endl;
    }
    else
    {
        int index=0;
        while(index<s.length())
        {
            int x = s[index]-'0';
            d = d*10+x;
            // cout<<d<<endl;
            index++;
        }
        if(d<128) cout<<"byte"<<endl;
        else if(d<32768) cout<<"short"<<endl;
        else if(d<2147483648) cout<<"int"<<endl;
        else if(d<=nm) cout<<"long"<<endl;
    }
}