// Problem Link - https://www.interviewbit.com/problems/anti-diagonals/hints/
#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> diagonal(vector<vector<int>> A){
    vector<vector<int>> giver;
    if(A.size() == 0) return giver;
    int ily = 0;
    while(ily<2*(A.size())-1)
    {

        vector<int> myvector;
        if(ily<A.size())
        {
            int a=ily;
            int b=0;
            for (int i = 0; i < ily+1; i++)
            {
                myvector.push_back(A[b][a]);
                a--;
                b++;
            }
        }
        else
        {
            int a = A.size()-1;
            int b = ily - A.size() + 1;
            for(int i =0; i < 2*(A.size())-1 - ily; i++)
            {
                myvector.push_back(A[b][a]);
                a--;
                b++;
            }
        }

        giver.push_back(myvector);
        ily++;
    }
    return giver;
}