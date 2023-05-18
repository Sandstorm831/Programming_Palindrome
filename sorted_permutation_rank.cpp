//Question Link - https://www.interviewbit.com/problems/sorted-permutation-rank/
// Solution

const int mod = 1000003;
int factorial(int x)
{
    if(x == 0 || x == 1) return 1;
    return (x%mod * factorial(x-1)%mod)%mod;
}
int Solution::findRank(string A) {
    int n = A.size();
    vector<int> p(n, 0);
    string B =A;
    sort(B.begin(), B.end());
    int j=0;
    vector<int> count(n,0);
    vector<int> vis(n,0);
    for(int i=0; i<n; i++)
    {
        if(A[i] == B[j])
        {
            vis[j]=1;
            while(vis[j]==1) j++;
            continue;
        }
        int num=0;
        for(int k=j+1; k<n; k++)
        {
            if(!vis[k]) num++;
            if(A[i] == B[k])
            {
                count[i]=num;
                vis[k]=1;
            }
        }
    }
    int l=n-1;
    int summ=0;
    for(int i=0; i<n; i++)
    {
        if(count[i]!=0)
        {
            summ = (summ%mod + ((factorial(l)%mod)*(count[i]%mod))%mod)%mod;
        }
        l--;
    }
    return (summ%mod + 1)%mod;
}
////////
long long fac(int n){
    int mod=1000003;
    if(n==0)
    return 1;
    
    long long temp=fac(n-1);
    temp = (temp*n%mod)%mod;
    return temp;
}

int Solution::findRank(string A) {
    int n=A.size();
    int mod=1000003;
    
    long long ans=0;
    for(int i=0;i<n;i++){
        int cnt=0;
        for(int j=i+1;j<n;j++){
            if(A[j]<A[i])
            cnt++;
        }
        ans = (ans + ((long long)fac(n-i-1)%mod*cnt%mod) )%mod;
    }
    return (ans+1)%mod;
}