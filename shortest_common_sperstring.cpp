#include <bits/stdc++.h>
using namespace std;
int overLapping(string s1,string s2, string &res)
{
    int max=INT_MIN,l1=s1.length(),l2=s2.length();
    for(int i=1;i<=min(l1,l2);i++)
    {
        if(s1.compare(l1-i,i,s2,0,i)==0) // checking suffix of s1 in prefix of s2
        {
            if(max<i)
            {
                max=i;
                res=s1+s2.substr(i);
            }
        }
        if(s1.compare(0,i,s2,l2-i,i)==0) // checking prefix of s1 in suffix of s2
        {
            if(max<=i)
            {
            max=i;
            res=s2+s1.substr(i);
            }
        }
    }
return max;
}
int solve(vector<string> &A) {
    while(A.size()!=1)
    {
        int max=INT_MIN;
        string res;
        vector<string>::iterator x1;
        vector<string>::iterator x2;
        for(int i=0;i<A.size();i++)
        {
            for(int j=i+1;j<A.size();j++)
            {
                string str;
                int mix=overLapping(A[i],A[j],str);
                if(mix>max)
                {
                    max=mix;
                    x1=(A.begin()+i);
                    x2=(A.begin()+j);
                    res=str;
                }
            }
        }
        if(max==INT_MIN)
        {
            res=A[0]+A[A.size()-1];
            x1=A.begin();
            x2=A.begin()+A.size()-1;
        }
        A.erase(x1);
        A.insert(A.begin(),res);
        A.erase(x2);
    }
    return A[0].size();
}