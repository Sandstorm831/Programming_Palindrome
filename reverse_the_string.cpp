// Problem Link - https://www.interviewbit.com/problems/reverse-the-string/
/*Problem Solution Function ------------------------+
string Solution::solve(string A) {          <-------+
    vector<string> vecy;
    string word = "";
    for (int i = 0; i < A.size(); i++)
    {
        if(A[i] != 32) word += A[i];
        else{
            if(word.empty()) continue;
            else
            {
                vecy.push_back(word);
                word.clear();
            }
        }
    }
    vecy.push_back(word);
    string finaler = vecy[vecy.size()-1];
    for (int i = vecy.size()-2; i >= 0; i--)
    {
        finaler += " ";
        finaler += vecy[i];
    }
    if(finaler[0] == 32) finaler.erase(0,1);
    return finaler;
}
*/
#include <bits/stdc++.h>
using namespace std;
string solver(string A)
{
    vector<string> vecy;
    string word = "";
    for (int i = 0; i < A.size(); i++)
    {
        if(A[i] != 32) word += A[i];
        else{
            if(word.empty()) continue;
            else
            {
                vecy.push_back(word);
                word.clear();
            }
        }
    }
    vecy.push_back(word);
    for (int i = 0; i < vecy.size(); i++)
    {
        cout<<vecy[i]<<" ";
    }
    cout<<endl;
    string finaler = vecy[vecy.size()-1];
    cout<<finaler;
    for (int i = vecy.size()-2; i >= 0; i--)
    {
        finaler += " ";
        finaler += vecy[i];
    }
    return finaler;
}   
int main()
{
    string A = "Hello World";
    cout<<solver(A);
}