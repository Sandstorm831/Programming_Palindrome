// Problem Link - https://www.interviewbit.com/problems/gray-code/
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n = 5;  // This has to be assumed
    vector<int> storage;
    for (int i = 0; i < pow(2,n); i++)
    {
        string s = "";
        for (int j = 0; j < n; j++)
        {
            int k = (i-pow(2,j))/pow(2,j+1) ;
            if (i+1<=pow(2,j))
            {
                s += "0";
            }
            else if (k%2 == 0)
            {
                s+="1";
            }
            else if (k%2 == 1)
            {
                s += "0";
            }
        }
        int a = stoi(s, nullptr, 2);
        storage.push_back(a);
    }

    // A better solution
    vector<int> storage_two;
    for (long long i = 0; i < pow(2,n); i++)
    {
        int j = i/2;
        storage_two.push_back(i^j);
    }
    
}