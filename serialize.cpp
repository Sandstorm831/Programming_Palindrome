// Question Link - https://www.interviewbit.com/problems/serialize/
// Solution 

string Solution::serialize(vector<string> &A) {
    string fig="";
    for(int i=0; i<A.size(); i++)
    {
        int n = A[i].size();
        fig += A[i];
        fig += to_string(n);
        fig += '~';
    }
    return fig;
}