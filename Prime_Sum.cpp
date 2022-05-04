// Problem Link - https://www.interviewbit.com/problems/prime-sum/
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int A = 344; // This to be assumed
    // Here to first we create a list of prime numbers with sieve of eratosthenes 
    bool prime[A + 1];
    memset(prime, true, sizeof(prime));
 
    for (int p = 2; p * p <= A; p++) {
        // If prime[p] is not changed, then it is a prime
        if (prime[p] == true) {
            // Update all multiples of p greater than or
            // equal to the square of it numbers which are
            // multiple of p and are less than p^2 are
            // already been marked.
            for (int i = p * p; i <= A; i += p)
                prime[i] = false;
        }
    }
 
    vector<int> d;

    for(int i=2; i<=A; i++){
        if(prime[i]==true && prime[A-i]==true){
            d.push_back(i);
            d.push_back(A-i);
            break;
        }
    }
    for (int i = 0; i < d.size(); i++)
    {
        cout<<d[i]<<" ";
    }
    
}