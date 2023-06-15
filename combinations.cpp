// Question link - https://www.interviewbit.com/problems/combinations/
// Solution

vector<vector<int>> ans;
void recurosr(int n, int k, int index, int num, vector<int>& v)
{
    if(index>n || num>k) return;
    else if(num == k)
    {
        ans.push_back(v);
        return;
    } 
    else
    {

        recurosr(n, k, index+1, num, v);
        v.push_back(index+1);
        recurosr(n, k, index+1, num+1, v);
        v.pop_back();
    }
    return;
}
vector<vector<int> > Solution::combine(int A, int B) {
    vector<int> v;
    ans.clear();
    recurosr(A, B, 0, 0, v);
    sort(ans.begin(), ans.end());
    return ans;
}
