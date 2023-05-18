// Question link - https://www.interviewbit.com/problems/triplets-with-sum-between-given-range/
// Solution

int Solution::solve(vector<string> &A) {
    // Bucket sort
    long long n = A.size();
    if(n<3) return 0;
    vector<vector<float>> v(3, vector<float> ());
    for(long long i=0; i<n; i++)
    {
        float x = stof(A[i]);
        if(x>=0 && x<0.667) v[0].push_back(x);
        else if(x>=0.667 && x<1) v[1].push_back(x);
        else if(x>=1 && x<2) v[2].push_back(x);
    }
    int n1=v[0].size(),n2=v[1].size(),n3=v[2].size();
    if(n1==0) return 0;
    bool t1=false,t2=false,t3=false,t4=false,t5=false;
    if(n1>=3)
    {
        float ammm=INT_MIN, amm=INT_MIN, am=INT_MIN;
        for(int j=0; j<v[0].size(); j++)
        {
            float xx = v[0][j];
            if(xx>ammm)
            {
                am = amm;
                amm = ammm;
                ammm = xx;
            }
            else if(xx>amm)
            {
                am = amm;
                amm = xx;
            }
            else if(xx>am)
            {
                am=xx;
            }
        }
        if(ammm+amm+am > 1 && ammm+amm+am<2) t1=true;
    }
    if(t1) return 1;
    if(n1>=2)
    {
        float amm=INT_MAX, am=INT_MAX;
        float ammx = INT_MIN, amx = INT_MIN;
        for(int j=0; j<v[0].size(); j++)
        {
            float xx = v[0][j];
            if(xx<amm)
            {
                am = amm;
                amm = xx;
            }
            else if(xx<am)
            {
                am = xx;
            }
            if(xx>ammx)
            {
                amx = ammx;
                ammx = xx;
            }
            else if(xx>amx)
            {
                amx = xx;
            }
        }
        if(n2>=1)
        {
            for(int k=0; k<v[1].size(); k++)
            {
                if(ammx+amx+v[1][k]>1 && ammx+amx+v[1][k]<2)
                {
                    t2=true;
                    break;
                }
            }
        }
        if(n3>=1)
        {
            for(int k=0; k<v[2].size(); k++)
            {
                if(amm+am+v[2][k]>1 && amm+am+v[2][k]<2)
                {
                    t3=true;
                    break;
                }
            }
        }
    }
    if(t2 || t3 || t1) return 1;
    if(n1>=1)
    {
        if(n2>=2)
        {
            float bmm=INT_MAX, bm=INT_MAX;
            for(int k=0; k<v[1].size(); k++)
            {
                float xx = v[1][k];
                if(xx<bmm)
                {
                    bm = bmm;
                    bmm = xx;
                }
                else if(xx<bm)
                {
                    bm=xx;
                }
            }
            for(int k=0; k<v[0].size(); k++)
            {
                if(bmm+bm+v[0][k]>1 && bmm+bm+v[0][k]<2)
                {
                    t4=true;
                    break;
                }
            }
        }
        if(n3>=1 && n2>=1)
        {
            float am=INT_MAX, bm=INT_MAX, cm=INT_MAX;
            for(int k=0;k<v[0].size(); k++)
            {
                am=min(am,v[0][k]);
            }
            for(int k=0; k<v[1].size(); k++)
            {
                bm=min(bm, v[1][k]);
            }
            for(int k=0; k<v[2].size(); k++)
            {
                cm=min(cm, v[2][k]);
            }
            if(am+bm+cm>1 && am+bm+cm<2) t5=true;
        }
    }
    if(t1||t2||t3||t4||t5) return 1;
    return 0;
}