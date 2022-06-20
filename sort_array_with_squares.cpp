Problem Link - https://www.interviewbit.com/problems/sort-array-with-squares/;
#include <bits/stdc++.h>
using namespace std
vector<int> solve(vector<int> A)
{
    vector<int> negative; vector<int> possitive;
    for (int i = 0; i < A.size(); i++)
    {
        if(A[i]<=0) negative.push_back(pow(A[i],2));
        else possitive.push_back(pow(A[i],2));
    }
    reverse(negative.begin(), negative.end());
    int ipos = 0; int npos = 0; vector<int> final;
    while (ipos<possitive.size() || npos<negative.size())
    {
        if(ipos<possitive.size() && npos<negative.size())
        {
            final.push_back(min(possitive[ipos], negative[npos]));
            if(possitive[ipos] > negative[npos]) npos++;
            else ipos++;
        }
        else if(ipos==possitive.size())
        {
            final.push_back(negative[npos]);
            npos++;
        }
        else if(npos == negative.size())
        {
            final.push_back(possitive[ipos]);
            ipos++;
        }
    }
    return final;
    
}
int main()
{}