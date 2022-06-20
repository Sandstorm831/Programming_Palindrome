// Problem Link - https://www.interviewbit.com/problems/matrix-search/
#include <bits/stdc++.h>
using namespace std;
int searchMatrix(vector<vector<int>>& A, int B)
{
    int size = A.size();
    int zameen = 0;
    int asmaan = size-1;
    while(asmaan-zameen > 0)
    {
        int beechka = (asmaan+zameen)/2;
        if(A[beechka][0] == B) return 1;
        else if(A[beechka][0] < B && A[beechka].back() > B)
        {
            zameen = beechka;
            asmaan = beechka;
        }
        else if(A[beechka].back()<B) zameen = beechka+1;
        else if(A[beechka][0] > B) asmaan = beechka-1;
    }
    int dharti = 0;
    int akaash = A[zameen].size()-1;
    while (dharti<= akaash)
    {
        int beechka = (dharti+akaash)/2;
        if(A[zameen][beechka] == B) return 1;
        else if(A[zameen][beechka] > B) akaash = beechka-1;
        else dharti = beechka+1;
    }
    return 0;
}