// Problem link - https://www.interviewbit.com/problems/sum-of-pairwise-hamming-distance/
#include <bits/stdc++.h>
using namespace std;
int main()
{
    vector<int> A = {2, 4, 6, 8 ,34, 5}; // This is to be assumed

    /*
    Time limit Exceeded
    int n =0;
    for(int i=0 ; i< A.size(); i++){
        for(int j=i+1; j < A.size(); j++){
            for(int l=0; l<32; l++){
                if(((1<<l)&A[i])==((1<<l)&A[j])){
                    n+=0;
                }          
                else{
                    n+=2;
                }
            }
        }
    }
    */

    vector<long int> x,y;
    int mod = 1000000007;
    for (int i = 0; i < 32; i++)
    {
        long int a =0, b=0;
        for (int l = 0; l < A.size(); l++)
        {
            if (((1<<i)&A[l]) == 0)
            {
                a+=1;
            }
            else
            {
                b+=1;
            }
            
            
         } 
         x.push_back(a);
         y.push_back(b);
     }
    long int c=0;
    for (int i = 0; i < x.size(); i++)
    {
        c+=2*x[i]*y[i];
    }

    cout<<c%mod;
}