/*
We can scramble a string s to get a string t using the following algorithm:

If the length of the string is 1, stop.
If the length of the string is > 1, do the following:
Split the string into two non-empty substrings at a random index, i.e., if the string is s, divide it to x and y where s = x + y.
Randomly decide to swap the two substrings or to keep them in the same order. i.e., after this step, s may become s = x + y or s = y + x.
Apply step 1 recursively on each of the two substrings x and y.
Given two strings s1 and s2 of the same length, return true if s2 is a scrambled string of s1, otherwise, return false.

{{{{[[[[((((Example 1:))))]]]]}}}}

Input: s1 = "great", s2 = "rgeat"
Output: true
Explanation: One possible scenario applied on s1 is:
"great" --> "gr/eat" // divide at random index.
"gr/eat" --> "gr/eat" // random decision is not to swap the two substrings and keep them in order.
"gr/eat" --> "g/r / e/at" // apply the same algorithm recursively on both substrings. divide at random index each of them.
"g/r / e/at" --> "r/g / e/at" // random decision was to swap the first substring and to keep the second substring in the same order.
"r/g / e/at" --> "r/g / e/ a/t" // again apply the algorithm recursively, divide "at" to "a/t".
"r/g / e/ a/t" --> "r/g / e/ a/t" // random decision is to keep both substrings in the same order.
The algorithm stops now, and the result string is "rgeat" which is s2.
As one possible scenario led s1 to be scrambled to s2, we return true.
*/#include <bits/stdc++.h>
using namespace std;
bool isScrambled(string A, string B, unordered_map<string, bool>& dp)
{
    if(A.compare(B) == 0) return true;
    if(A.length()<=1) return false;
    bool flag=false;
    string time = (A+"_"+B);
    if(dp.find(time) != dp.end()) return dp[time];
    for (int i = 1; i <= A.size()-1; i++)
    {
        if((isScrambled(A.substr(0,i), B.substr(0,i),dp)&&isScrambled(A.substr(i,A.size()-i),B.substr(i,B.size()-i), dp))||(isScrambled(A.substr(0,i), B.substr(B.size()-i, i), dp)&&isScrambled(A.substr(i,A.size()-i), B.substr(0,B.size()-i), dp)))
        {
            cout<<"here"<<endl;
            flag  = true; 
            break;
        } 
    }
    return dp[time] = flag;
}
int main()
{
    string A = "abc";
    string B = "bca";
    unordered_map<string, bool> dp;
    dp.clear();
    if(A.length()!=B.length()) return false;
    cout<<isScrambled(A,B, dp);

}