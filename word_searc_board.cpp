/* Problem Link - https://www.interviewbit.com/problems/word-search-board/

Given a 2D board and a word, find if the word exists in the grid.

The word can be constructed from letters of sequentially adjacent cell, where "adjacent" cells are those horizontally or vertically neighboring. The cell itself does not count as an adjacent cell. 

The same letter cell may be used more than once.

Example :

Given board =

[
  ["ABCE"],
  ["SFCS"],
  ["ADEE"]
]
word = "ABCCED", -> returns 1,
word = "SEE", -> returns 1,
word = "ABCB", -> returns 1,
word = "ABFSAB" -> returns 1
word = "ABCD" -> returns 0
Note that 1 corresponds to true, and 0 corresponds to false.

*/
#include <bits/stdc++.h>
using namespace std;
vector<int> dx = {1,0,-1,0};
vector<int> dy = {0,-1,0,1};
bool checker(int i, int j, int a, int b)
{
    if(i<0 || j<0 || i>a || j>b) return false;
    return true;
}
int recursor(int a, int b, string B, vector<string>& A, int counter, int l, int h)
{
    if(counter == B.size()) return 1;
    for(int i=0; i<4; i++)
    {
        int aa = a+dx[i];
        int bb = b+dy[i];
        int dans;
        if(checker(aa,bb,l-1,h-1) && B[counter] == A[aa][bb]) 
        {
            dans = recursor(aa,bb,B,A,counter+1, l,h);
            if(dans == 1) return 1;
        }
    }
    return 0;
}
int dfs(vector<string> A, string B)
{
    int a = A.size();
    int b = A[0].size();
    for(int i=0; i<a; i++)
    {
        for(int j=0; j<b; j++)
        {
            int mat=0;
            if(A[i][j] == B[mat])
            {
                int ans = recursor(i,j,B,A,1, a,b);
                if(ans == 1) return 1;
            }
        }
    }
    return 0;
}
int Solution::exist(vector<string> &A, string B) {
    return dfs(A,B);
}