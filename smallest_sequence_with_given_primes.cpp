// Problem Link - https://www.interviewbit.com/problems/smallest-sequence-with-given-primes/
/*
vector<int> turner(int A, int B, int C, int D)
{
    int a=0;
    int b=0;
    int c=0;
    vector<int> finer;
    finer.push_back(1);
    while(finer.size()<=D)
    {
        int x = min({A*finer[a], B*finer[b], C*finer[c]});
        finer.push_back(x);
        if(x == A*finer[a]) a++;
        if(x == B*finer[b]) b++;
        if(x == C*finer[c]) c++;
    }
    finer.erase(finer.begin());
    return finer;
}
vector<int> Solution::solve(int A, int B, int C, int D) {
    return turner(A,B,C,D);
}
*/
#include <bits/stdc++.h>
using namespace std;
vector<int> turner(int A, int B, int C, int D)
{
    int a=0;
    int b=0;
    int c=0;
    vector<int> finer;
    finer.push_back(1);
    while(finer.size()<=D)
    {
        int x = min({A*finer[a], B*finer[b], C*finer[c]});
        finer.push_back(x);
        if(x == A*finer[a]) a++;
        if(x == B*finer[b]) b++;
        if(x == C*finer[c]) c++;
    }
    finer.erase(finer.begin());
    return finer;
}
int main()
{
    int A = 2, B=3, C=5, D=4;
    cout<<turner(A, B, C, D);
}