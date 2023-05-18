// Question Link - https://www.interviewbit.com/problems/numbers-of-length-n-and-value-less-than-k/
// Solution

int Solution::solve(vector<int> &A, int B, int C) {
    if(B==0 || A.size()==0) return 0;
    vector<int> v;
    int orig = C;
    while(orig > 0)
    {
        int x = orig%10;
        v.push_back(x);
        orig = orig/10;
    }
    reverse(v.begin(), v.end());
    int n = v.size();
    if(n<B) return 0;
    else if(n>B)
    {
        if(A[0]==0) {
            int ans = (A.size()-1)*pow(A.size(), B-1);
            if(B==1) ans++;
            return ans;
        }
        else return pow(A.size(), B);
    }
    else
    {
        int num = v[0];
        int count=0, ans=0;
        bool flag=false;
        for(int i=0;i<A.size(); i++)
        {
            if(A[i]>0 && A[i]<num) count++;
            if(A[i]==num) flag=true;
        }
        ans +=  count * pow(A.size(), B-1);
        if(!flag)
        {
            if(B==1 and v[0] == 0) ans++;
            return ans;
        }
        for(int i=1; i<n; i++)
        {
            int count=0, num =v[i];
            bool flag=false;
            for(int j=0; j<A.size();j++)
            {
                if(A[j]<num)count++;
                if(A[j] ==  num) flag=true;
            }
            ans+=count * pow(A.size(), B-1-i);
            if(!flag) return ans;
        }
        if(B==1 and v[0] == 0) ans++;
        return ans;
        
    }
}