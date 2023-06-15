// Question LInk - https://www.interviewbit.com/problems/valid-bst-from-preorder/
//Solution 


int Solution::solve(vector<int> &A) {
    vector<int> x = A;
    set<int> xx;
    for(int i=0;i<A.size();i++) xx.insert(A[i]);
    if(xx.size()<A.size()) return 0;
    stack<int> s;
    int root = INT_MIN;
    for(int i=0;i<x.size(); i++)
    {
        if(x[i] < root) return false;
        while(!s.empty() && s.top()<x[i])
        {
            root = s.top();
            s.pop();
        }
        s.push(x[i]);
    }
    return true;
}