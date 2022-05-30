// Problem link - https://www.interviewbit.com/problems/check-palindrome/
#include <bits/stdc++.h>
using namespace std;
int solve(string A){
    unordered_map<char, int> mappy;
    int ones=0,k=0;
    for (int i = 0; i < A.size(); i++)
    {
        if(mappy.find(A[i]) != mappy.end()) mappy[A[i]]++;
        else mappy[A[i]]=1;
    }
    for (auto itr = mappy.begin(); itr != mappy.end(); ++itr)
    {
        if((itr->second)%2 == 1) ones++;
        else continue;
    }
    if(ones == 1 || ones == 0) return 1;
    else return 0;
}
int main(){
    string A = "asddsa"; // This has to be assumed
    cout<<solve(A);
}