/*
Given a boolean expression S of length N with following symbols.
Symbols
    'T' ---> true
    'F' ---> false
and following operators filled between symbols
Operators
    &   ---> boolean AND
    |   ---> boolean OR
    ^   ---> boolean XOR
Count the number of ways we can parenthesize the expression so that the value of expression evaluates to true. Input is given in the form of string.
*/
#include <bits/stdc++.h>
using namespace std;
int recursor(string A, int i, int j, bool istrue, vector<vector<vector<int>>>& map)
{
    if(i>j) return false;
    if(i==j)
    {
        if(istrue == true) return A[i]=='T';
        else return A[i]=='F';
    }
    if(map[i][j][istrue] != -1) return map[i][j][istrue];
    int value=0;
    for (int k = i+1; k <= j-1 ; k+=2)
    {
        int left_t = recursor(A, i, k-1, true, map);
        int left_f = recursor(A, i, k-1, false, map);
        int right_t = recursor(A,k+1, j, true, map);
        int right_f = recursor(A, k+1, j, false, map);
        if(A[k] == '^')
        {
            if(istrue == true) value += (left_f*right_t)+(left_t*right_f);
            else value += (left_t*right_t)+(left_f*right_f);
        }
        else if(A[k] == '|')
        {
            if(istrue == true) value += (left_t*right_t)+(left_t*right_f)+(left_f*right_t);
            else value += (left_f*right_f);
        }
        else if(A[k] == '&')
        {
            if(istrue == true) value += (left_t*right_t);
            else value += (left_f*right_f)+(left_t*right_f)+(left_f*right_t);
        }
        cout<<value<<"||";
    }
    return map[i][j][istrue] = value;
}
int boolParen(string A)
{
    int a = A.size();
    int i = 0;
    int j = a-1;
    vector<vector<vector<int>>> map(101, vector<vector<int>> (101, vector<int>(2,-1)));
    return recursor(A, i, j, true, map);
}
int main()
{
    string A = "T|F^F&T|F^F^F^T|T&T^T|F^T^F&F^T|T^F";
    cout<<boolParen(A);   
}