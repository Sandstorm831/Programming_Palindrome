//Problem Solution Function - https://www.interviewbit.com/problems/merge-k-sorted-arrays/
#include <bits/stdc++.h>
using namespace std;
vector<int> jodkar(vector<int> pehla, vector<int> doosra)
{
    vector<int> akhiri;
    int pailda = 0;
    int doolda = 0;
    int size_pehla = pehla.size();
    int size_doosra = doosra.size();
    while(pailda < size_pehla && doolda < size_doosra)
    {
        if(pehla[pailda] < doosra[doolda])
        {
            akhiri.push_back(pehla[pailda]);
            pailda++;
        }
        else
        {
            akhiri.push_back(doosra[doolda]);
            doolda++;
        }
    }
    while(pailda < size_pehla)
    {
        akhiri.push_back(pehla[pailda]);
        pailda++;
    }
    while(doolda < size_doosra)
    {
        akhiri.push_back(doosra[doolda]);
        doolda++;
    }
    return akhiri;
}
vector<int> recursor(vector<vector<int>> A, int dharti, int akaash)
{
    if(dharti<akaash)
    {
        int beechka = (dharti+akaash)/2;
        vector<int> pehla = recursor(A, dharti, beechka);
        vector<int> doosra = recursor(A, beechka+1, akaash);
        return jodkar(pehla, doosra);
    }
    return A[akaash];
}
vector<int> Solution::solve(vector<vector<int> > &A) {
    int dharti = 0;
    int akaash = A.size()-1;
    return recursor(A, dharti, akaash);
}