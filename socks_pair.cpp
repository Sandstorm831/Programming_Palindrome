// Problem Link -   https://www.interviewbit.com/problems/socks-pair/
#include <bits/stdc++.h>
using namespace std;
int solve(vector<int> &A) {
    unordered_set<int> setty;
    int answer = 0;
    for(int i = 0; i<A.size(); i++)
    {
        if(setty.find(A[i]) !=  setty.end()) 
        {
            setty.erase(setty.find(A[i]));
            answer++;
        }
        else setty.insert(A[i]);
    }
    return answer;
}
int main(){}