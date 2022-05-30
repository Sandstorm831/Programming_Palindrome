//Problem LInk -https://www.interviewbit.com/problems/two-out-of-three/
#include <bits/stdc++.h>
using namespace std;
vector<int> twotothree(vector<int> A, vector<int> B, vector<int> C){
    unordered_set<int> ab, bc,ca,abc;
    vector<int> fnla;
    ab.insert(A.begin(), A.end());
    bc.insert(B.begin(), B.end());
    ca.insert(C.begin(), C.end());
    for (int i = 0; i < B.size(); i++)
    {
        if(ab.find(B[i]) != ab.end()) abc.insert(B[i]);
        else continue;
    }
    for (int i = 0; i < C.size(); i++)
    {
        if(bc.find(C[i]) != bc.end()) abc.insert(C[i]);
        else continue;
    }
    for (int i = 0; i < A.size(); i++)
    {
        if(ca.find(A[i]) != ca.end()) abc.insert(A[i]);
        else continue;
    }
    for (auto itr = abc.begin(); itr!=abc.end(); itr++)
    {
        fnla.push_back(*itr);
    }
    sort(fnla.begin(), fnla.end());
    return fnla;
}
int main(){
    vector<int> A,B,C; // These have to be assumed
    A = {1,2,3,1,5};
    B = {1,4,6,8};
    C = {1,2,6,8};
    vector<int> fnla =twotothree(A,B,C);
    for (int i = 0; i < fnla.size(); i++)
    {
        cout<<fnla[i]<<" ";
    }
    
}
