// Problem link - https://www.interviewbit.com/problems/diffk-ii/
#include <bits/stdc++.h>
using namespace std;
int diffpossible(vector<int> A, int B){
    unordered_set<int> sety;
    sety.insert(A.begin(), A.end());
    if (B == 0)
    {
        if (A.size() == sety.size()) return 0;
        else return 1;
        
    }
    
    for ( auto itr = sety.begin(); itr != sety.end(); ++itr)
    {
        if (sety.find(*itr+B) != sety.end() || sety.find(*itr -B) != sety.end())
        {
            return 1;
            break;
        }
        
    }
    return 0;
    
}
int main(){
    vector<int> A = {1,5,3,4,2,6};int B = 0; // These has to be assumed
    cout<<diffpossible(A,B);
}