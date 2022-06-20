// Problem Link - https://www.interviewbit.com/problems/pascal-triangle/
// Problem Solution function 
#include <bits/stdc++.h>                    
using namespace std;                            
vector<vector<int>> solvent(int A)              
{
    vector<int> rowed = {1};
    vector<vector<int>> dough;
    if(A == 0) return dough;
    dough.push_back(rowed);
    if(A == 1)return dough;
    int number = 0;
    int counter = 1;
    while(counter != A)
    {
        for (int i = 0; i < counter; i++)
        {
            if(i == counter-1) rowed.push_back(rowed[0]);
            else rowed.push_back(dough[number][i] + dough[number][i+1]);
        }
        dough.push_back(rowed);
        rowed.clear();
        rowed.push_back(1);
        number++;
        counter++;
    }
    return dough;
}
