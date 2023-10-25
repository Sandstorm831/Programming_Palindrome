#include <bits/stdc++.h>
using namespace std;
void gogo()
{
    long long n, k;
    cin>>n>>k;
    vector<long long> a(n+1, 0);
    for(long long i=1; i<=n;i++) cin>>a[i];
    a[0]=0;
    long long l=1,r=n*k+INT_MAX;
    while(l<r){
        long long mid2=(l+r)>>1,mid=mid2;
        long long cnt=0;
        for(long long i=0;i<k;i++){
            long long u=(upper_bound(a.begin(), a.end(),mid)-a.begin());
            mid-=u-1;
        }
        if(mid<=0){
            l=mid2+1;
        }else{
            r=mid2;
        }
    }
    cout<<l<<endl;

}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    long long t;
    cin>>t;
    while(t--){
        gogo();
    }
}