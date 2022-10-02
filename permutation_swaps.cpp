/* Problem Link - https://www.interviewbit.com/problems/permutation-swaps/ 

Problem Description

Rishabh has a permutation A of N integers 1, 2, ... N but he doesn't like it. Rishabh wants to get a permutation B.

Also, Rishabh has some M good pairs given in a form of 2D matrix C of size M x 2  where (C[i][0], C[i][1]) denotes that two indexes of the permutation A.

In one operation he can swap Ax and Ay only if (x, y) is a good pair.

You have to tell whether Rishabh can obtain permutation B by performing the above operation any number of times on permutation A.

If the permutation B can be obtained return 1 else return 0.



Problem Constraints
2 <= N <= 105
1 <= M <= 105
1 <= A[i], B[i] <= N
A[i] and B[i] are all distinct.
1 <= C[i][0] < C[i][1] <= N


Input Format
First arguement is an integer array A of size N denoting the permutation A.

Second arguement is an integer array B of size N denoting the permutation B.

Third argument is an 2D integer array C of size M x 2 denoting the M good pairs.



Output Format
If the permutation B can be obtained return 1 else return 0.



Example Input
Input 1:

 A = [1, 3, 2, 4]
 B = [1, 4, 2, 3]
 C = [ 
        [3, 4]
     ]
Input 2:

 A = [1, 3, 2, 4]
 B = [1, 4, 2, 3]
 C = [
        [2, 4]
     ] 


Example Output
Output 1:

 0
Output 2:

 1


Example Explanation
Explanation 1:

 As A != B you have to perform operations on A but there is only good pair available i,e (3, 4) so if you swap
 A3 with A4 you get A = [1, 3, 4, 2] which is not equal to B so we will return 0.
Explanation 2:

 As A != B you have to perform operations on A but there is only good pair available i,e (2, 4) so if you swap
 A2 with A4 you get A = [1, 4, 2, 3] which is equal to B so we will return 1.
*/
#include <bits/stdc++.h>
using namespace std;
int find(vector<int>& rank, vector<int>& dsu, int a)
{
    if(dsu[a] == a) return dsu[a];
    else dsu[a] = find(rank, dsu, dsu[a]);
    return dsu[a];
}
void join(vector<int>& rank, vector<int>& dsu, int a, int b)
{
    int pra = find(rank, dsu, a);
    int prb = find(rank, dsu, b);
    if(pra == prb) return;
    else if(rank[pra] > rank[prb]) dsu[prb] = pra;
    else if(rank[prb] > rank[pra]) dsu[pra] = prb;
    else if(rank[pra] == rank[prb])
    {
        dsu[pra] = prb;
        rank[pra]++;
    }
}
int solve(vector<int> &A, vector<int> &B, vector<vector<int> > &C) {
    int a = A.size();
    vector<int> rank(a+1,0);
    vector<int> dsu(a+1);
    for(int i=0; i<a; i++)
    {
        dsu[A[i]] = A[i];
        rank[A[i]] = 1;
    }
    for(int i=0; i<C.size(); i++)
    {
        join(rank, dsu, A[C[i][0]-1], A[C[i][1]-1]);
    }
    for(int i=0; i<A.size(); i++)
    {
        if(A[i] != B[i] && find(rank, dsu, A[i]) != find(rank, dsu, B[i])) return 0;
    }
    return 1;
}