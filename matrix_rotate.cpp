// Link of Problem - https://www.interviewbit.com/problems/rotate-matrix/
#include <bits/stdc++.h>
using namespace std;
void rotate(vector<vector<int>>& A){
    int n = A[0].size();
    int half = n/2;
    for (int i = 0; i < half; i++)
    {
        if (n%2 == 0)
        {
            for (int j = i; j < n-i; j++)
            {
                int temp = A[j][n-1-i];
                A[j][n-1-i] = A[i][j];
                A[i][j] = A[n-1-j][i];
                A[n-1-j][i] = A[n-1-i][n-1-j];
                A[n-1-i][n-1-j] = temp;
            }
        }
        else
        {
            for (int j = i; j < n-i; j++)
            {
                int temp = A[j][n-1-i];
                A[j][n-1-i] = A[i][j];
                A[i][j] = A[n-1-j][i];
                A[n-1-j][i] = A[n-1-i][n-1-j];
                A[n-1-i][n-1-j] = temp;
            }
        }
    }
    
    
}
int main()
{
    vector<vector<int>> A = {{1,2},{3,4}}; // This has to be assumed
    for (int i = 0; i < A.size(); i++)
    {
        for (int j = 0; j < A.size(); j++)
        {
            cout<<A[i][j]<<" ";
        }
        cout<<endl;
        
    }
    rotate(A);
    cout<<endl;
    for (int i = 0; i < A.size(); i++)
    {
        for (int j = 0; j < A.size(); j++)
        {
            cout<<A[i][j]<<" ";
        }
        cout<<endl;
        
    }

}