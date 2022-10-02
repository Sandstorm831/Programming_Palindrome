/* Problem Link - https://www.interviewbit.com/problems/sum-of-fibonacci-numbers/

How many minimum numbers from fibonacci series are required such that sum of numbers should be equal to a given Number N?
Note : repetition of number is allowed.
Example:
N = 4
Fibonacci numbers : 1 1 2 3 5 .... so on
here 2 + 2 = 4 
so minimum numbers will be 2

*/
#include <bits/stdc++.h>
using namespace std; 
vector<int> fibvec(int A)
{
    vector<int> fib;
    fib.push_back(1); fib.push_back(1);
    int i=2;
    int checker=fib[i-1]+fib[i-2];
    while(checker<=A)
    {
        fib.push_back(checker);
        i++;
        checker = fib[i-1]+fib[i-2];
    }
    return fib;
}
int Solution::fibsum(int A) {
    vector<int> fibo = fibvec(A);
    int count=0;
    int reacher=0;
    while(reacher != A)
    {
        while(A-reacher >= fibo.back())
        {
            count++;
            reacher+=fibo.back();
        }
        fibo.pop_back();
    }
    return count;
}