// Question Link - https://www.interviewbit.com/problems/stringoholics/
// Solution 

// Need to learn KPMG algorithm and how to compute LCM of a array of numbers modulo m

typedef long long ll;
const int mod = 1000000007;
#define F first
#define S second
#define MAX 10000003
vector<int> prime(MAX);
unordered_map<int, int> max_map;
 
int checker(string X)
{
    int n = X.length();  // Using KMP algorithm
    vector<int> lps(n, 0); // Computing lps array
    for(int i=1; i<n; ++i)
    {
        int j = lps[i-1];
        while(j>0 && X[i] != X[j]) j = lps[j-1];
        if(X[i] == X[j]) ++j;
        lps[i] = j;
    }
    int l = lps[n-1];
    // cout<<l<<endl;
    if(l==0 || l%(n-l) != 0) return n; // represent, that string need to be repeated completely to repeat
    else return n-l; // return how much position it is to be turned that the string repeat itself
}
// Function to return a^n
int power(int a, int n)
{
    if (n == 0) return 1;
    int p = power(a, n / 2) % mod;
    p = (p * p) % mod;
    if (n & 1) p = (p * a) % mod;
    return p;
}
 
// Function to find the smallest prime factors
// of numbers upto MAX
void sieve()
{
    prime[0] = prime[1] = 1;
    for (int i = 2; i < MAX; i++) {
        if (prime[i] == 0) {
            for (int j = i * 2; j < MAX; j += i) {
                if (prime[j] == 0) {
                    prime[j] = i;
                }
            }
            prime[i] = i;
        }
    }
}
 
// Function to return the LCM modulo M
ll lcmModuloM(vector<int> ar, int n)
{
 
    for (int i = 0; i < n; i++) 
    {
        int num = ar[i];
        unordered_map<int, int> temp;
 
        // Temp stores mapping of prime factor to
        // its power for the current element 125405280
        while (num > 1) {
 
            // Factor is the smallest prime factor of num
            // int factor = 2; //////////////
            // cout<<num<<" "<<prime[num]<<endl;
            int factor = prime[num];
            // cout<<factor<<" "<<num<<" "<<endl;
            // Increase count of factor in temp
            temp[factor]++;
 
            // Reduce num by its prime factor
            num /= factor;
        }
 
        for (auto it : temp) {
 
            // Store the highest power of every prime
            // found till now in a new map max_map
            max_map[it.first] = max(max_map[it.first], it.second);
        }
    }
 
    ll ans = 1;
 
    for (auto it : max_map) {
 
        // LCM is product of primes to their highest powers modulo M 989217554
        ans = (ans * power(it.F, it.S)) % mod;
        // cout<<ans<<endl;
    }
 
    return ans;
}
int Solution::solve(vector<string> &A) {
    prime.clear();
    max_map.clear();
    sieve();
    vector<int> v;
    for(int i=0; i<A.size(); i++)
    {
        int x = checker(A[i]);
        bool tt = true;
        int k=1;
        while(tt)
        {
            if((k*(k+1)/2)%x == 0)
            {
                v.push_back(k);
                tt = false;
            }
            k++;
        }
    }    
    return lcmModuloM(v, v.size());
    
}
/////////
