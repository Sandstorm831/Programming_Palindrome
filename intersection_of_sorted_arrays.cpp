// Problem Link - https://www.interviewbit.com/problems/intersection-of-sorted-arrays/
/* Problem Solution Function --------------------------------------------------------------------+
vector<int> Solution::intersect(const vector<int> &A, const vector<int> &B) {       <------------+
    int j = 0;
    vector<int> midler;
    for (int i = 0; i < A.size(); i++)
    {
        for (; j < B.size(); j++)
        {
            if(A[i]<B[j]) break;
            else if(B[j]<A[i]) continue;
            else{
                j++;
                midler.push_back(A[i]);
                break;
            }
        }
    }
    return midler;
}
*/
#include <bits/stdc++.h>
using namespace std;
vector<int> intersect(vector<int> A, vector<int> B)
{
    int j = 0;
    vector<int> midler;
    for (int i = 0; i < A.size(); i++)
    {
        for (; j < B.size(); j++)
        {
            if(A[i]<B[j]) break;
            else if(B[j]<A[i]) continue;
            else{
                j++;
                midler.push_back(A[i]);
                break;
            }
        }
    }
    return midler;
}
int main()
{}