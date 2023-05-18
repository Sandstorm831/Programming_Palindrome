// Question Link - https://www.interviewbit.com/problems/city-tour/
// Solution


#define MOD 1000000007
const long long int mod = 1e9+7;
long long int pow(long long int x, long long int y)
{
    if(x==0) return 0;
    else if(y==0) return 1;
    else if(y==1) return x%mod;
    long long int result;
    if(y%2==0)
    {
        result = pow(x, y/2)%mod;
        result = (result%mod * result%mod)%mod;
    }
    else
    {
        result = x%mod;
        result = (result%mod * pow(x, y-1)%mod)%mod;
    }
    return result%mod;
}
long long int fact(long long int N){
    long long int ans = 1;
    for(long long int i = 1; i <= N; i++){
        ans *= i;
        ans = ans%MOD;
    }
    return ans;
}

int Solution::solve(int A, vector<int> &B) {
    sort(B.begin(), B.end());
    //total number of unvisited city
    int N = A-int(B.size());
    // cout<<N<<endl;
    //calculate all the gaps ---start
    vector<int> temp;
    temp.push_back(B[0]-1);
    for(int i = 1; i < B.size(); i++){
        temp.push_back(B[i] - B[i-1] -1);
    }
    temp.push_back(A+1-B.back()-1);
    //calculate all the gaps ---end
    //first term of ans ---
    long long int ans;
    ans = fact(N);
    for(int i = 0; i < temp.size(); i++){
        ans *= (pow_a(fact(temp[i]), 1000000005)%MOD);//little fermat theorem
        ans = ans%MOD;
        // cout<<ans<<endl;
    }
    
    //number of ways to access internal gaps ----
    long long int z = 1;
    for(int i = 0; i < temp.size(); i++){
        if(i == 0 || i == int(temp.size()) -1) z *= 1;
        else{
            if(temp[i] < 2) continue;
            z *= pow_a(2, temp[i]-1);
            z = z%MOD;
        }
    }
    
    ans = (ans*z)%MOD;
    return ans%MOD;
}