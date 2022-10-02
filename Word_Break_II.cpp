// Problem Link - https://www.interviewbit.com/problems/word-break-ii/
/* Problem Solution
vector<string> rec(string& sentence, unordered_set<string>& dict, unordered_map<string, vector<string>>& finder)
{
    if(finder.find(sentence) != finder.end()) return finder[sentence];
    int n=sentence.size();
    vector<string> result;
    for(int i=1; i<=n; i++)
    {
        string word = sentence.substr(0,i);
        string rem = sentence.substr(i);
        if(dict.find(word) !=dict.end())
        {
            if(rem.empty()) result.push_back(word);
            else
            {
                for(auto& s: rec(rem, dict, finder))
                {
                    result.push_back(word+" "+s);
                }
            }
        }
    }
    finder[sentence] = result;
    return result;
}
vector<string> Solution::wordBreak(string A, vector<string> &B) {
    unordered_set<string> count;
    for(int i=0; i<B.size(); i++)
    {
        count.insert(B[i]);
    }
    unordered_map<string, vector<string>> dp;
    return rec(A,count, dp);
}
*/
#include <bits/stdc++.h>
using namespace std;
vector<string> rec(string& sentence, unordered_set<string>& dict, unordered_map<string, vector<string>>& finder)
{
    if(finder.find(sentence) != finder.end()) return finder[sentence];
    int n=sentence.size();
    vector<string> result;
    for(int i=1; i<=n; i++)
    {
        string word = sentence.substr(0,i);
        string rem = sentence.substr(i);
        if(dict.find(word) !=dict.end())
        {
            if(rem.empty()) result.push_back(word);
            else
            {
                for(auto& s: rec(rem, dict, finder))
                {
                    result.push_back(word+" "+s);
                }
            }
        }
    }
    finder[sentence] = result;
    return result;
}
int main()
{
    string A = "catsanddog";
    vector<string> B = {"cat", "cats", "and", "sand", "dog"};
    unordered_set<string> count;
    for(int i=0; i<B.size(); i++)
    {
        count.insert(B[i]);
    }
    unordered_map<string, vector<string>> dp;
    rec(A,count, dp);
}