// Question Link - https://www.interviewbit.com/problems/connect-ropes/
// Solution

int Solution::solve(vector<int> &A) {
    // if(A.size()==1) return 0;
    // else if(A.size()==2) return A[0]+A[1]; 
    priority_queue<int, vector<int>, greater<int>> pq;
    for(int i=0; i<A.size(); i++) pq.push(A[i]);
    int cost=0;
    while(pq.size()>1)
    {
        int a = pq.top();pq.pop();
        int b = pq.top();pq.pop();
        cost += a+b;
        pq.push(a+b);
    }
    return cost;
}
