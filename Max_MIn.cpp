#include <bits/stdc++.h>
using namespace std;
int solve(vector<int> A){
    int mini = A[0], maxi=A[0];
    for (int i = 1; i < A.size(); i++)
    {
        if (mini > A[i])
        {
            mini = A[i];
        }
        if (maxi<A[i])
        {
            maxi = A[i];
        }
        
        
    }
    return mini+maxi;
    
}
int main(){
    vector<int> A = {1,2,3,4,2,3,4,4,3,4,5,9,9,99};
    cout<<solve(A);

}