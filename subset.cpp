// Question Link - https://www.interviewbit.com/problems/subset/
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
        recursor(A, v, index+1);
        v.push_back(A[index]);
        recursor(A, v, index+1);
        v.pop_back();
    }
    return;
}
vector<vector<int> > Solution::subsets(vector<int> &A) {
    sort(A.begin(), A.end());
    // vector<vector<int>> ans;
    ans.clear();
    vector<int> v;
    recursor(A, v, 0);
    sort(ans.begin(), ans.end());
    return ans;
}