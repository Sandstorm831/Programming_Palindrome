// Question link - https://www.interviewbit.com/problems/best-time-to-buy-and-sell-stock-atmost-b-times/
// Solution

int Solution::solve(vector<int> &a, int b)
{
    if(b > a.size()) b = a.size();
    int day = a.size() + 1;
    int t = b + 1;
    int ans[a.size() + 1][b + 1];
   
    for(int i = 0 ; i < day; i++)ans[i][0] = 0;
    for(int i = 0 ; i < t; i++)
    {
        ans[0][i] = 0;
        ans[1][i] = 0;
    }
   
    for(int j = 1; j < t; j++)
    {
        int mm = INT_MIN;
        for(int i = 2; i < day; i++)
        {
            mm = max(mm, ans[i - 1][j - 1] - a[i - 2]);
            ans[i][j] = max(ans[i-1][j] , mm + a[i - 1]);
        }
    }
    return ans[day - 1][t - 1];
}