/* Problem Link - https://www.interviewbit.com/problems/stepping-numbers/

Problem Description

Given A and B you have to find all stepping numbers in range A to B.

The stepping number:

A number is called as a stepping number if the adjacent digits have a difference of 1.

e.g. 123 is stepping number, but 358 is not a stepping number



Input Format
First argument is an integer A.

Second argument is an integer B.



Output Format
Return a integer array sorted in ascending order denoting the stepping numbers between A and B.



Example Input
Input 1:

 A = 10
 B = 20


Example Output
Output 1:

 [10, 12]


Example Explanation
Explanation 1:

 All stepping numbers are 10 , 12 
*/
//Problem Solution
#include <bits/stdc++.h>
using namespace std;
set<int> ans;
void recursor(int dor, int l_limit, int h_limit)
{
    if(dor > h_limit) return;
    if(dor>=l_limit && dor<=h_limit)
    {
        ans.insert(dor);
        if(dor%10 == 9) recursor(dor*10+8, l_limit, h_limit);
        else if(dor%10 == 0) recursor(dor*10+1, l_limit, h_limit);
        else
        {
            recursor(dor*10+(dor%10-1), l_limit, h_limit);
            recursor(dor*10+(dor%10+1), l_limit, h_limit);
        }
    }
    else 
    {
        if(dor%10 == 9) recursor(dor*10+8, l_limit, h_limit);
        else if(dor%10 == 0) recursor(dor*10+1, l_limit, h_limit);
        else
        {
            recursor(dor*10+(dor%10-1), l_limit, h_limit);
            recursor(dor*10+(dor%10+1), l_limit, h_limit);
        }
    }
}
void helper(int A, int B)
{
    vector<int> a;
    vector<int> b;
    int aa=A;
    int bb=B;
    while(aa>0)
    {
        int c = aa%10;
        a.push_back(c);
        aa/=10;
    }
    while(bb>0)
    {
        int c = bb%10;
        b.push_back(c);
        bb/=10;
    }
    for(int i=1; i<=9; i++)
    {
        recursor(i, A, B);
    }
    
}
vector<int> Solution::stepnum(int A, int B) {
    ans.clear();
    helper(A, B);
    vector<int> turner;
    if( A == 0) turner.push_back(0);
    for(auto itr=ans.begin(); itr!=ans.end(); itr++)
    {
        turner.push_back(*itr);
    }
    return turner;
}
