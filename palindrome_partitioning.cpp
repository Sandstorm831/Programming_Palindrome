// Question Link - https://www.interviewbit.com/problems/palindrome-partitioning/
// Solution 

bool ispalindrome(string A)
{
    int ans=true;
    int x=0, y=A.length()-1;
    while(x<=y)
    {
        if(A[x] != A[y]) return false;
        x++;y--;
    }
    return ans;
}
void recursor(vector<vector<string>>& ans, vector<string> &temp, string A, int idx)
{
    if(idx >=A.length())
    {
        ans.push_back(temp);
        return;
    }
    string s = "";
    for(int i=idx; i<A.length(); i++)
    {
        s+=A[i];
        if(ispalindrome(s))
        {
            temp.push_back(s);
            recursor(ans, temp, A, i+1);
            temp.pop_back();
        }
    }
    return;
}
vector<vector<string> > Solution::partition(string A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    vector<vector<string>> ans;
    vector<string> temp;
    recursor(ans, temp, A, 0);
    return ans;
}
