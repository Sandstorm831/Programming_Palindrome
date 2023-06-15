// Question Link - https://www.interviewbit.com/problems/all-possible-combinations/
// Solution 

void recursor(vector<string> &A, vector<string> &ans, string dum, int wrd)
{
    if(wrd >= A.size())
    {
        ans.push_back(dum);
        return;
    }
    for(int j=0;j<A[wrd].size(); j++)
    {
        dum += A[wrd][j];
        recursor(A, ans, dum, wrd+1);
        dum.pop_back();
    }
    return;
}
vector<string> Solution::specialStrings(vector<string> &A) {
    for(int i=0; i<A.size(); i++)
    {
        sort(A[i].begin(), A[i].end());
    }
    vector<string> ans;
    string dum = "";
    int wrd = 0;
    recursor(A, ans, dum, 0);
    return ans;
}
