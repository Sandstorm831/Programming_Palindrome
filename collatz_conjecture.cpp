// Problem Link - https://www.interviewbit.com/problems/collatz-conjecture/
// Solution 

long Solution::solve(int A, int B) {
    long long a = 1ll*A;
    long long b =1ll*B;
    long long ans = a;
    long long counter=b-1;
    while(counter > 0 && ans !=1)
    {
        if(ans%2==0) ans/=2;
        else ans = ans*3+1;
        counter--;
    }
    // cout<<counter<<" "<<ans<<endl;
    if(counter==0) return ans;
    else
    {
        if(counter%3==1) return 4;
        else if(counter%3==2) return 2;
        else if(counter%3==0) return 1;
    }
}
