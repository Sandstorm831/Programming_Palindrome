#include <bits/stdc++.h>
using namespace std;
/* Problem Link - https://www.interviewbit.com/problems/knight-on-chess-board/
Given any source point, (C, D) and destination point, (E, F) on a chess board, we need to find whether Knight can move to the destination or not.

Knight's movements on a chess board

The above figure details the movements for a knight ( 8 possibilities ).

If yes, then what would be the minimum number of steps for the knight to move to the said point.

If knight can not move from the source point to the destination point, then return -1.

Note: A knight cannot go out of the board.



Input Format:

The first argument of input contains an integer A.
The second argument of input contains an integer B.
    => The chessboard is of size A x B.
The third argument of input contains an integer C.
The fourth argument of input contains an integer D.
    => The Knight is initially at position (C, D).
The fifth argument of input contains an integer E.
The sixth argument of input contains an integer F.
    => The Knight wants to reach position (E, F).
Output Format:

If it is possible to reach the destination point, return the minimum number of moves.
Else return -1.
Constraints:

1 <= A, B <= 500
Example

Input 1:
    A = 8
    B = 8
    C = 1
    D = 1
    E = 8
    F = 8
    
Output 1:
    6

Explanation 1:
    The size of the chessboard is 8x8, the knight is initially at (1, 1) and the knight wants to reach position (8, 8).
    The minimum number of moves required for this is 6.
*/

/*
///////////////////   Alternate solution    ////////////////////////
bool checker(int x, int y, int xl, int yl)
{
    if(x<=0 || y<=0 || x>xl || y>yl) return false;
    return true;
}
int Solution::knight(int A, int B, int C, int D, int E, int F) {
    vector<vector<int>> graph(A*B+1);
    vector<int> dx = {2, 2, -1, 1, -2, -2, -1, 1};
    vector<int> dy = {-1, 1, -2, -2, -1, 1, 2, 2};
    for(int i=1; i<=A; i++)
    {
        for(int j=1; j<=B; j++)
        {
            for(int k=0; k<8; k++)
            {
                int xx = i+dx[k];
                int yy = j+dy[k];
                int l = (i-1)*B+j;
                int midn = (xx-1)*B+yy;
                if(checker(xx,yy, A, B)) 
                {
                    // cout<<midn<<" ";
                    graph[l].push_back(midn);
                }
            }
        }
    }
    int start = B*(C-1)+D;
    int ender = B*(E-1)+F;
    int counter=0;
    if(start==ender) return counter;
    counter++;
    queue<int> q;
    q.push(start);
    q.push(INT_MAX);
    vector<bool> visited(A*B+1, false);
    while(!q.empty())
    {
        int front = q.front();
        q.pop();
        if(front == INT_MAX && !q.empty())
        {
            counter++;
            q.push(INT_MAX);
            continue;
        }
        cout<<front<<" ";
        // visited[front]=true;
        for(int i=0;i<graph[front].size(); i++)
        {
            if(graph[front][i] == ender) return counter;
            // cout<<graph[front][i]<<" ";
            if(!visited[graph[front][i]]) q.push(graph[front][i]);
        }
    }
    return -1;
}
*/
vector<int> x ({1, 2, 2, 1, -1, -2, -1, -2});
vector<int> y ({2, 1, -1, -2, 2, 1, -2, -1});

bool isSafe(int i , int j ,int N, int M){
    if(i >= 0 && i < N && j >= 0 && j < M)return true;
    
    return false;
}

int explore(queue<pair<int, pair<int, int> > >& q, int A, int B, int C, int D, int E, int F, vector<vector<int> >& visited, int &count){
    while(!q.empty()){
        int distance = q.front().first;
        int c = q.front().second.first;
        int d = q.front().second.second;
        q.pop();
        if ( c == E && d == F)return distance;
        visited[c][d] = 1;

        for(int i = 0; i < x.size(); i++){
            int first = c + x[i];
            int second = d + y[i];
            if(isSafe(first, second, A, B)){
                if(visited[first][second] == 0){
                    visited[first][second] = 1;
                    q.push({distance+1, {first, second}});
                }
            }
        }
    }
    return -1;
}

int Solution::knight(int A, int B, int C, int D, int E, int F) {
    vector<vector<int> > visited (A, vector<int> (B, 0));
    
    int count  = 0;
    queue<pair<int, pair<int, int> > > q;
    q.push({0, {C-1, D-1}});
    return explore(q, A, B, C-1, D-1, E-1, F-1, visited, count);
}