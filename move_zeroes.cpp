#include <bits/stdc++.h>
using namespace std;
vector<int> moveZeros(vector<int>& A)
{
    int size = A.size();
    int j = 0;
    for (int i = 0; i < A.size(); i++)
    {
        if(A[i] != 0)
        {
            A[j++] = A[i];
        }
    }
    while (j<size)
    {
        A[j++] = 0;
    }
    return A;
    
}
int main()
{
    vector<int> A = {0, 0, 9, 4, 0, 10, 3, 8, 6, 2, 6};
    vector<int> hel = moveZeros(A);
}