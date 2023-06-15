// Question Link - https://www.interviewbit.com/problems/chips-factory/
// solution 

vector<int> Solution::solve(vector<int> &A) {
    vector<int> ans;
    int i=0;
    while(ans.size() != A.size())
    {
        if(i>=A.size())
        {
            ans.push_back(0);
            continue;
        }
        if(A[i] > 0) 
        {
            ans.push_back(A[i]);
            i++;
        }
        else i++;
    }
    return ans;
}
