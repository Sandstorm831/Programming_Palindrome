// Problem Link - https://www.interviewbit.com/problems/pairs-with-given-xor/
#include <bits/stdc++.h>
using namespace std;
int XORed(vector<int> A, int B){
    int size = A.size();
    int x = 0;
    unordered_set<int> sety;
    sety.insert(A.begin(), A.end());
    for (auto i = sety.begin(); i != sety.end(); i++)
    {
        int temp = (*i)^B;
        if(sety.find(temp) != sety.end()) x++;
        else continue;
    }
    return x/2;
}
int main(){
    vector<int> A = {5,4,10,15,7,6};// This has to be assumed
    cout<<XORed(A,5);
}