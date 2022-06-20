// Problem Link - https://www.interviewbit.com/problems/prettyprint/
#include <bits/stdc++.h>
using namespace std;
vector<vector<int> > prettyPrint(int A) {
    int n=2*A-1;
    
    vector<vector<int>> v(n, vector<int>(n,0));
    
    for(int i=0; i<A; i++)
    {
        for(int j=i; j<n-i; j++)
        {        
                v[i][j]= A-i;
            
                v[j][n-1-i]= A-i;
            
                v[n-1-j][i]= A-i;
                
                v[n-1-i][n-1-j]= A-i;          
        }
    }    
    return v;
}
int main()
{}