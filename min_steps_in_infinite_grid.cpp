#include <bits/stdc++.h>
using namespace std;
int cover_points(vector<int> A, vector<int> B){
    int a,b;
    int steps = 0;
    for (int i = 0; i < A.size()-1; i++)
    {
        a = abs(A[i]-A[i+1]);
        b = abs(B[i]-B[i+1]);
        if (a<=b)
        {
            steps += b;
        }
        else
        {
            steps += a;
        }
        
    }
    return steps;
    
}
int main(){
    vector<int> A = {0,1,1};
    vector<int> B = {0,1,2};
    cout<<cover_points(A,B);

}