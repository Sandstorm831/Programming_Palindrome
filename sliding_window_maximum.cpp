// Question Link - https://www.interviewbit.com/problems/sliding-window-maximum/
// Solution

vector<int> Solution::slidingMaximum(const vector<int> &A, int B) {
    deque<int> deq;
    for(int i=0; i<B; i++)
    {
        while((!deq.empty())&&(A[deq.back()]<=A[i])) deq.pop_back();
        deq.push_back(i);
    }
    vector<int> ans;
    for(int i=B; i<A.size(); i++)
    {
        ans.push_back(A[deq.front()]);
        while((!deq.empty())&&(deq.front()<=i-B)) deq.pop_front();
        while((!deq.empty())&&(A[deq.back()]<=A[i])) deq.pop_back();
        deq.push_back(i);
    }
    ans.push_back(A[deq.front()]);
    return ans;
}