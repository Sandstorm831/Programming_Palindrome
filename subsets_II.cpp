// Question Link - https://www.interviewbit.com/problems/subsets-ii/
// Solution

vector<vector<int>> ans;
void recursor(vector<int> &A, vector<int> &v, int index)
{
    if(index >= A.size()) 
    {
        ans.push_back(v);
        return;
    }
    else
    {
        int f=0;
        while(A[index+f]==A[index]) f++;
        recursor(A, v, index+f);
        v.push_back(A[index]);
        recursor(A, v, index+1);
        v.pop_back();
    }
    return;
}
vector<vector<int> > Solution::subsetsWithDup(vector<int> &A) {
    sort(A.begin(), A.end());
    ans.clear();
    vector<int> v;
    recursor(A, v, 0);
    sort(ans.begin(), ans.end());
    return ans;
}