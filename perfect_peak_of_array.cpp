// que link - https://www.interviewbit.com/problems/perfect-peak-of-array/

// solution

int Solution::perfectPeak(vector<int> &A) {
    int n = A.size();
    vector<int> maxy;
    vector<int> miny;
    int maxer=INT_MIN, miner=INT_MAX;
    for(int i=0;i<A.size(); i++)
    {
        maxer = max(maxer, A[i]);
        miner = min(miner, A[n-1-i]);
        maxy.push_back(maxer);
        miny.push_back(miner);
    }
    bool t=false;
    reverse(miny.begin(), miny.end());
    for(int i=1; i<A.size()-1; i++)
    {
        if(A[i] == maxy[i] && A[i] == miny[i])
        {
            if(maxy[i]!=maxy[i-1] && miny[i]!=miny[i+1])
            {
                t=true;
                break;
            }
        }
    }
    if(t) return 1;
    return 0;
}