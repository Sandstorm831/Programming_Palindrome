#include <bits/stdc++.h>
using namespace std;
int XORed(vector<int> A, int B){
    int size = A.size();
    int soln=0;
    for (int i = 0; i < size; i++)
    {
        int d=0;
        for (int j = i; j < size; j++)
        {
            d = d^A[j];
            if(d == B) soln++;
            else continue;
        }
    }
    return soln;
}