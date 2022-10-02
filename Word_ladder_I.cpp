// Problem Link - https://www.interviewbit.com/problems/word-ladder-i/
/*
Given two words A and B, and a dictionary, C, find the length of shortest transformation sequence from A to B, such that:

You must change exactly one character in every transformation.
Each intermediate word must exist in the dictionary.
Note:

Return 0 if there is no such transformation sequence.
All words have the same length.
All words contain only lowercase alphabetic characters.


Input Format:

The first argument of input contains a string, A.
The second argument of input contains a string, B.
The third argument of input contains an array of strings, C.
Output Format:

Return an integer representing the minimum number of steps required to change string A to string B.
Constraints:

1 <= length(A), length(B), length(C[i]) <= 25
1 <= length(C) <= 5e3
Example :

Input 1:
    A = "hit"
    B = "cog"
    C = ["hot", "dot", "dog", "lot", "log"]

Output 1:
    5

Explanation 1:
    "hit" -> "hot" -> "dot" -> "dog" -> "cog"
*/
#include <bits/stdc++.h>
using namespace std;
bool checker(string x, string y)
{
    int n = x.length();
    int counter=0;
    for(int i=0; i<n; i++)
    {
        if(x[i] != y[i]) counter++;
        if(counter>1) return false;
    }
    return true;
}
int Solution::solve(string A, string B, vector<string> &C) {
    int n = C.size();
    queue<pair<int,string>> q;
    q.push(make_pair(1, A));
    vector<bool> visited(n+1, false);
    while(!q.empty())
    {
        string ts = q.front().second;
        int ti = q.front().first;
        q.pop();
        if(ts == B) return ti;
        else if(checker(ts, B)) return ti+1;
        for(int i=0; i<n; i++)
        {
            if(!visited[i] && checker(ts, C[i]))
            {
                visited[i]=true;
                q.push(make_pair(ti+1, C[i]));
            }
        }
    }
    return 0;
}

///////////////// Interview bit Solution accepted

int Solution::solve(string start, string end, vector<string> &dictV) {
    unordered_set<string> dict(dictV.begin(), dictV.end());
    unordered_map<string, int> distance; // store the distancetance from start to the current word
    queue<string> q; // FIFO for bfs purpose
    distance[start] = 1;
    q.push(start);
    dict.erase(start);
    while (!q.empty()) {
        string word = q.front(); 
        q.pop();
        if (word == end) break;
        for (int i = 0; i < word.size(); i++) {
            for (int j = 0; j < 26; j++) {
                string newWord = word;
                newWord[i] = 'a' + j;
                if (dict.find(newWord) != dict.end() && distance.find(newWord) == distance.end()) {
                    distance[newWord] = distance[word] + 1;
                    q.push(newWord);
                    dict.erase(newWord);
                }
            }
        }
    }
    if (distance.find(end) == distance.end()) return 0; // not found
    return distance[end];
}