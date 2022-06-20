// Problem Link - https://www.interviewbit.com/problems/longest-substring-without-repeat/
/* Problem Solution Function ---------------------------------+
int Solution::lengthOfLongestSubstring(string A) {      <-----+
    int maxy = 0;
    int curry = 0;
    int j = 0;
    unordered_map<char, int> decollector;
    for (int i = 0; i < A.size(); i++)
    {
        for (; j < A.size(); j++)
        {
            if(decollector.find(A[j]) != decollector.end()) 
            {
                break;
            }
            if(decollector.find(A[j]) == decollector.end()) decollector.insert({A[j], 1});
            // cout<<A[j];
            curry++;
            maxy = max(curry, maxy);
        }
        if(j == A.size()) break;
        if(decollector.find(A[j]) != decollector.end())
        {
            decollector.erase(decollector.find(A[i]));
            curry--;
            // if(decollector.find(A[j]) == decollector.end()) j++;
        }
        
    }
    return maxy;
}
*/
#include <bits/stdc++.h>
using namespace std;
int lengthOfLongestSubstring(string A)
{
    int maxy = 0;
    int curry = 0;
    int j = 0;
    unordered_map<char, int> decollector;
    for (int i = 0; i < A.size(); i++)
    {
        for (; j < A.size(); j++)
        {
            if(decollector.find(A[j]) != decollector.end()) 
            {
                break;
            }
            if(decollector.find(A[j]) == decollector.end()) decollector.insert({A[j], 1});
            // cout<<A[j];
            curry++;
            maxy = max(curry, maxy);
        }
        if(j == A.size()) break;
        if(decollector.find(A[j]) != decollector.end())
        {
            decollector.erase(decollector.find(A[i]));
            curry--;
            // if(decollector.find(A[j]) == decollector.end()) j++;
        }
        
    }
    return maxy;
    
}
int main(){
    string A = "abcefgdlemnop";
    cout<<lengthOfLongestSubstring(A);
}