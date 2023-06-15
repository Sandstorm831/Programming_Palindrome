//Question Link - https://www.interviewbit.com/problems/longest-palindromic-substring/
// Solution 

// For learning read this solution
#include <bits/stdc++.h>
using namespace std;
bool ispalindrome(string A, int index, int len)
{
    bool x = true;
    int i = index-len+1;
    int f = index;
    while(i<=f && x)
    {
        if(A[i]!=A[f]) x = false; 
        i++,f--;
    }
    return x;

}
string deep(string A, string B)
{
    int a = A.size();
    int b = B.size();
    int maxx = INT_MIN;
    int imax = -1;
    vector<vector<int>> dpp(a+1, vector<int>(b+1));
    for (int i = 0; i <= a; i++)
    {
        for (int j = 0; j <= b; j++)
        {
            if(i == 0 || j == 0) dpp[i][j] = 0;
            else if(A[i-1] == B[j-1])
            {
                    dpp[i][j] = 1+dpp[i-1][j-1];
                    // maxx = max(maxx, dpp[i][j]);
                    if(maxx<dpp[i][j])
                    {
                        maxx = dpp[i][j];
                        imax = i-1;
                        // cout<<maxx<<endl;
                    }
            }
            else 
            {
                dpp[i][j] = 0;
            }
        }
    }
    string s="";
    for(int i=1; i<=a; i++)
    {
        for(int j=1; j<=b; j++)
        {
            if(dpp[i][j] > s.size() && ispalindrome(A, i-1, dpp[i][j]))
            {
                s = A.substr(i-dpp[i][j], dpp[i][j]);
            }
        }
    }
    return s;
}
int main()
{
    string A = "aaaabaaa";
    string B = A;
    reverse(A.begin(), A.end());
    cout<<deep(B,A);
}  


// For accepting at interview bit, follow it

string Solution::longestPalindrome(string A) {
    int ans = 1;
    int maxSize = -1;
    if(A.size() == 0) return 0;
    char res = A[0];
    for(int i = 0;i<A.size();i++){
        int l = i , r = i + 1;
        int size = 0;
        while(l>=0 && r < A.size() && A[l] == A[r]){           
            size+=2;
            l--;
            r++;
        }
        if(size > maxSize){           
            ans = l + 1;
            maxSize = size;
        }
        l = i, r = i,size = 1;
        while(l>=0 && r < A.size() && A[l] == A[r]){
            if(l != r){
                size += 2;
            }
            l--;
            r++;
        }
        if(size > maxSize){
            maxSize = size;
            ans = l + 1;
        }      
    }
    return A.substr(ans,maxSize);
}