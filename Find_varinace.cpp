#include<bits/stdc++.h>
using namespace std;
#include <sstream>
#include <iomanip>
string Solution::solve(vector<int> &A) {
    int normal_sum = 0, squared_sum = 0;
    for(int i = 0; i<A.size(); i++)
    {
        normal_sum += A[i];
        squared_sum += pow(A[i], 2);
    }
    int size = A.size();
    long double mean = (long double)normal_sum/(long double)size;
    long double ater = (long double)squared_sum/(long double)size;
    long double mean_sq = pow(mean, 2);
    long double answer = ater - mean_sq;
    stringstream stream;
    stream<<fixed<<setprecision(2)<<answer;
    string s = stream.str();
    return s;
}