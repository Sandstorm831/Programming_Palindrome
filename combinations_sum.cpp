// Question Link - https://www.interviewbit.com/problems/combination-sum/
// Solution 

vector<vector<int>> ans;
void recursor(vector<int> &A, vector<int>& comb, int summ, int target, int index)
{
    if(index >= A.size() || summ + A[index]> target) return;
    else if(summ + A[index] == target)
    {
        comb.push_back(A[index]);
        ans.push_back(comb);
        comb.pop_back();
        return;
    }
    else
    {
        int f=0;
        while(A[index+f]==A[index]) f++;
        recursor(A, comb, summ, target, index+f);
        comb.push_back(A[index]);
        recursor(A, comb, summ+A[index], target, index);
        comb.pop_back();
    }
    return ;
}
vector<vector<int> > Solution::combinationSum(vector<int> &A, int B) {
    sort(A.begin(), A.end());
    ans.clear();
    vector<int> comb;
    int summ=0;
    int index=0;
    recursor(A, comb, summ, B, index);
    sort(ans.begin(), ans.end());
    return ans;
}
