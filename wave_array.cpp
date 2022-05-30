// Link of Problem  - https://www.interviewbit.com/problems/wave-array/
#include <bits/stdc++.h>
using namespace std;
vector<int> wave(vector<int> A){
    vector<int> B = A;
    sort(B.begin(), B.end());
    for (int i = 0; i < B.size()-1; i++)
    {
        if (i%2==0)
        {
            int temp = B[i+1];
            B[i+1] = B[i];
            B[i] = temp;
        }
        else
        {
            continue;
        }
        
    }
    return B;
    
}
int main(){
    vector<int> A = {13,345,2,46,7,3,1}; // This has to be assumed
    vector<int> B = wave(A);
    for (int i = 0; i < B.size(); i++)
    {
        cout<<B[i]<<" ";
    }
    

}