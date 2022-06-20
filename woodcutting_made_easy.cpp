// problem Link - https://www.interviewbit.com/problems/woodcutting-made-easy/
#include <bits/stdc++.h>
using namespace std;
int woodcutter(vector<int> &A, int B)
{
    long int mina = INT_MAX;long int maxa = INT_MIN;
    for (int i = 0; i < A.size(); i++)
    {
        maxa = max((long int)A[i], maxa);
        mina = min((long int)A[i], mina);
    }
    while (mina <= maxa)
    {
        long int difference=0;
        long int mida = (mina+maxa)/2;
        for (int i = 0; i < A.size(); i++)
        {
            if(A[i]>mida) difference += (long int)A[i]-mida;
        }
        if(difference == B) return mida;
        else if(difference > B) mina = mida+1;
        else maxa = mida-1;
    }
    return maxa;  
}
int main()
{
    vector<int> A = { 114, 55, 95, 131, 77, 111, 141 };
    int B = 95;
    cout<<woodcutter(A,B);
}