// Question Link - https://www.interviewbit.com/problems/simple-queries/
// Problem Description

// You are given an array A having N integers.

// You have to perform the following steps in a given order.

// 1) generate all subarrays of A.

// 2) take the maximum element from each subarray of A and insert it into a new array G.

// 3) replace every element of G with the product of their divisors mod 1e9 + 7.

// 4) sort G in descending order

// You now need to perform Q queries

// In each query, you are given an integer K, where you have to find the Kth element in G.

// NOTE : Your solution will run on multiple test cases so do clear global variables after using them.
//  The question involves a lot of mathematics. The first observation required is to calculate the maximum numbers
//  in all subarrays. This could be done most optimally using a stack and two arrays in O(N), You can find the 
//  explanation here https://www.geeksforgeeks.org/sum-of-maximum-elements-of-all-possible-sub-arrays-of-an-array/
//  Before that we have already calculated the number of divisors of a number using modified form of sieve. After all 
//  this we can store frequency of each number and then calculate product of divisors. The product of divisors 
//  of a number N is nothing but N^(D/2) where D is the number of divisors of N. Thus now using binary 
//  exponentiation we can calculate N^(D/2) in about Log(N) time. After this we can sort all numbers in 
//  decreasing order and then form the prefix sum array. Now we can easily apply binary search for each query
//  over prefix sum array to see where our P.O.D lies (product of divisors) and store it in the answer array.



long long binexp(long long x,long long y){

    long long mod = 1e9+7;

    long long ans = 1; long long u = x,v = y;

    if(v%2){

        ans = ans*sqrt(u);

        ans%=mod;

        ans+=mod;

        ans%=mod;

    }

    v/=2;

    while(v){

        if(v&1){

            ans*=u;

            ans%=mod;

            ans+=mod;

            ans%=mod;

        }

        u = u*u;

        u%=mod;

        u+=mod;

        u%=mod;

        v>>=1;

    }

    return ans;

}

vector<int> Solution::solve(vector<int> &A, vector<int> &B) {

    vector<long long>divisors(1000005,0);

    for(long long i = 1; i<1000005; i++){

        for(long long j = 1; i*j<1000005; j++){

            divisors[i*j]++;

        }

    }

    long long n = A.size();

    vector<long long>leftcnt(n,0),rightcnt(n,0);

    stack<long long>st;

    for(int i = 0; i<n; i++){

        while(!st.empty() && A[st.top()]<=A[i]){

            leftcnt[i]+=(leftcnt[st.top()]+1);

            st.pop();

        }

        st.push(i);

    }

    while(!st.empty()){

        st.pop();

    }

    for(int i = n-1; i>=0; i--){

        while(!st.empty() && A[st.top()]<A[i]){

            rightcnt[i]+=(rightcnt[st.top()]+1);

            st.pop();

        }

        st.push(i);

    }

    map<long long,long long>mp;

    long long mod = 1e9+7;

    for(int i = 0; i<n; i++){

        long long val = (leftcnt[i]+1)*(rightcnt[i]+1);

        if(mp.find(A[i])==mp.end()){

            mp[A[i]] = val;

        }

        else{

            mp[A[i]]+=val;

        }

    }

    vector<pair<long long,long long>>nums;

    for(auto it : mp){

        long long ans = binexp(it.first,divisors[it.first]);

        nums.push_back({ans,it.second});

    }

    sort(nums.rbegin(),nums.rend()); 

    for(int i = 1; i<nums.size(); i++){

        nums[i].second+=nums[i-1].second;

    }

    int m = B.size();

    vector<int>answ(m);

    for(int i = 0; i<m; i++){

        int start = 0,end = nums.size()-1,mid = 0,ans = 0;

        while(start<=end){

            mid = start+(end-start)/2;

            if(nums[mid].second>=B[i]){

                ans = mid;

                end = mid-1;

            }

            else{

                start = mid+1;

            }

        }

        answ[i] = (int)nums[ans].first; 

    }
    return answ;
}