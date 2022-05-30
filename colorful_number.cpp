// Problem Link - https://www.interviewbit.com/problems/colorful-number/
#include <bits/stdc++.h>
using namespace std;
int colorful(int A)
{
    vector<int> atat;
    int B = A;
    while (B>0)
    {
        int c = B%10;
        atat.push_back(c);
        B = B/10;
    }
    int n = atat.size();
    unordered_set<int> sety;
    for (int i = 1; i <= n; i++)
    {
        int c=1;
        for (int j = 0; j <=n-i; j++)
        {
            c *= atat[j+i-1];
            sety.insert(c);
        }
    }
    if (sety.size() == n*(n+1)/2) return 1;
    else return 0;
}
int main(){
    int A = 14325; // This has to be assumed
    cout<<colorful(A);
}