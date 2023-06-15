// Question Link - https://www.interviewbit.com/problems/3-sum/
// Solution

int Solution::threeSumClosest(vector<int> &A, int B) {
    if(A.size()<=3)
    {
        int summ=0;
        for(int i=0; i<A.size(); i++) summ+=A[i];
        return summ;
    }
    sort(A.begin(), A.end());
    int n = A.size();
    int minn = INT_MAX;
    int store;
    for(int i=0; i<n-2; i++)
    {
        int lo = i+1, hi = n-1;
        while(lo<hi)
        {
            int summ = A[i]+A[lo]+A[hi];
            if(B == summ)
            {
                return summ;
            }
            else if(summ > B)
            {
                hi--;
                if(minn>summ-B)
                {
                    store = summ;
                    minn = summ-B;
                }
            }
            else if(summ < B)
            {
                lo++;
                if(minn>B-summ)
                {
                    store=summ;
                    minn = B-summ;
                }
            }
        }
    }
    return store;
}
