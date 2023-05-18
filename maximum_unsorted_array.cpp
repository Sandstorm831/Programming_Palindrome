//  Question Link - https://www.interviewbit.com/problems/maximum-unsorted-subarray/
// Solution

vector<int> Solution::subUnsort(vector<int> &A) {
    vector<int> s = A;
    sort(A.begin(), A.end());
    int st=-1, fh=-1;
    for(int i=0; i<s.size(); i++)
    {
        if(s[i] != A[i])
        {
            st = i;
            break;
        }
    }
    for(int i=s.size()-1; i>=0; i--)
    {
        if(s[i] != A[i])
        {
            fh = i;
            break;
        }
    }
    vector<int> v;
    if(st==-1) v.push_back(-1);
    else
    {
        v.push_back(st);
        v.push_back(fh);
    }
    return v;
}