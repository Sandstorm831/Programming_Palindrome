//Question Link - https://www.interviewbit.com/problems/find-permutation/
//Solution

vector<int> Solution::findPerm(const string A, int B) {
    vector<int> v;
    for(int i=0;i<B; i++)
    {
        v.push_back(i+1);
    }
    int s=-1, f=-1;
    for(int i=0; i<v.size(); i++)
    {
        if(A[i] == 'D')
        {
            if(s==-1) s=i;
        }
        else if(A[i] == 'I' && s != -1)
        {
            f=i;
        }
        if(s != -1 && f != -1)
        {
            int num = v[f];
            for(int j=s; j<=f; j++)
            {
                v[j] = num--;
            }
            s=-1; f=-1;
        }
    }
    if(s!=-1)
    {
        int num = v.back();
        for(int j=s; j<v.size(); j++)
        {
            v[j] = num--;
        }
    }
    return v;
}