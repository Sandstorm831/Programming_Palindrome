/* Problem Link - https://www.interviewbit.com/problems/file-search/

Problem Description
 

You are given an assignment to sort out the files of your department today.

A file contains various records. Each record has an (ID, Parent ID).

To make your task easier, you decided to separate records into different sets.

If a set contains a record with (ID, Parent ID) - (X, Y), then both X and Y must be present in the set.

There are A records. You are also given a 2D array B of dimensions N x 2,

where each row is record's (ID, Parent ID).



You have to find the maximum number of sets you can divide the records into.



Problem Constraints
1 <= A, N <= 105
1 <= B[i][0], B[i][1] <= A
There can be duplicate records.
There can be two records (X, Y) and (Y, X).


Input Format
The first argument is the integer A.
The second argument is the 2D integer array B.


Output Format
Return a single integer denoting the maximum number of sets you can break the record into.


Example Input
Input 1:
A = 4
B = [[1, 2], [3, 4]]
Input 2:

A = 4
B = [[1, 2], [3, 4], [2, 4]]


Example Output
Output 1:
2
Output 2:

1


Example Explanation
Explanation 1:
We can create two sets (1, 2), (3, 4). Since, (1, 2) need to be together and (3, 4).
Explanation 2:

We can only have 1 set because (1, 2) need to be together (2, 4) need to be together. 
Hence, (1, 2, 4) need to be together. Similarly, (1, 2, 3, 4) need to be together. Therefore, the answer is 1.

*/
#include <bits/stdc++.h>
using namespace std;
int find(vector<int>& dsu, int a)
{
    if(dsu[a] == a) return dsu[a];
    else dsu[a] = find(dsu, dsu[a]);
    return dsu[a];
}
void join(int a, int b, vector<int>& dsu, vector<int>& rank)
{
    int pa = find(dsu, a);
    int pb = find(dsu, b);
    if(pa == pb) return;
    else if(rank[pa] > rank[pb]) dsu[pb] = pa;
    else if(rank[pb] > rank[pa]) dsu[pa] = pb;
    else if(rank[pa] ==  rank[pb])
    {
        dsu[pa] = pb;
        rank[pa]++;
    }
}
int Solution::breakRecords(int A, vector<vector<int> > &B) {
    vector<int> dsu(A+1);
    vector<int> rank(A+1, 1);
    for(int i=1; i<=A; i++)
    {
        dsu[i]=i;
    }
    for(int i=0; i<B.size(); i++)
    {
        join(B[i][0], B[i][1], dsu, rank);
    }
    unordered_set<int> s;
    for(int i=1; i<=A; i++)
    {
        s.insert(find(dsu, i));
    }
    return s.size();
}