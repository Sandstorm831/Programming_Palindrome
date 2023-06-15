// Question LInk - https://www.interviewbit.com/problems/longest-valid-parentheses/
// solution 

int Solution::longestValidParentheses(string A) {
    int ans = 0;
    stack<int>sk;
    sk.push(-1);
    for(int i=0;i<A.size();i++)
    {
        if(A[i]=='(') sk.push(i);
        else
        {
            if(!sk.empty())
            {
                sk.pop();
                if(!sk.empty()) ans  = max(ans,i-sk.top());
                else sk.push(i);
            }
        }
    }
    return ans;
}