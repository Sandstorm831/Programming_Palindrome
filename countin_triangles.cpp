// Question Link - https://www.interviewbit.com/problems/counting-triangles/
// Solution

int Solution::nTriang(vector<int> &A) {
    int mod = 1e9+7;
    sort(A.begin(), A.end());
    int count=0;
    for(int i=A.size()-1; i>1; i--)
    {
        int l=0, r = i-1;
        while(l<r)
        {
            if(A[l]+A[r]>A[i])
            {
                count = (count%mod + (r-l)%mod)%mod;
                r--;
            }
            else
            {
                l++;
            }
        }
    }
    return count;
}
