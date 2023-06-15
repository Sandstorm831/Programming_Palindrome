// Question Link - https://www.interviewbit.com/problems/max-continuous-series-of-1s/
// Solution

vector<int> Solution::maxone(vector<int> &A, int B) {
    int zeros=0;
    int maxl = 0;
    int j=0;
    int index=0;
    for(int i=0; i<A.size(); i++)
    {
        // cout<<i<<endl;
        while(zeros>B && i<A.size())
        {
            if(A[i] == 0)
            {
                zeros--;
                i++;
            }
            else i++;
        }
        if(i>=A.size())break;
        if(j<i) j=i;
        for(; j<A.size() ; j++)
        {
            // cout<<i<<" "<<j<<" "<<zeros<<" "<<maxl<<endl;
            if(A[j] == 1)
            {
                // cout<<"here"<<endl;
                if(maxl<j-i+1)
                {
                    maxl = j-i+1;
                    index = j;
                }
                // maxl = max(maxl, j-i+1);
            }
            else if(A[j] == 0)
            {
                // cout<<"there"<<endl;
                zeros++;
                if(zeros<=B)
                {
                    if(maxl<j-i+1)
                    {
                        maxl = j-i+1;
                        index = j;
                    }
                    // maxl = max(maxl, j-i+1);
                }
                else
                {
                    zeros--;
                    break;
                }
            }
        }
        if(A[i] == 0)
        {
            // cout<<"der"<<endl;
            zeros--;
            if(zeros<0) zeros=0;
        }
        // cout<<i<<" "<<j<<" "<<zeros<<" | "<<maxl<<endl;
    }
    vector<int> v;
    while(maxl)
    {
        v.push_back(index);
        index--;
        maxl--;
    }
    reverse(v.begin(), v.end());
    return v;
    // return maxl;
}
// 38 0 0 1 1 0 1 0 1 0 1 0 1 0 1 0 0 1 1 0 0 1 0 0 1 1 1 0 0 0 0 1 0 1 0 1 1 0 0
// 0
