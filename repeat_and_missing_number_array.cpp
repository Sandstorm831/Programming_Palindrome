// Problem Link - https://www.interviewbit.com/problems/repeat-and-missing-number-array/
#include <bits/stdc++.h>
using namespace std;
vector<int> repeatedNumber(vector<int> A)
{
    long long int size = A.size();
    // long long int greater_sum = size*(size+1)/2;
    // long long int squared_sum = size*(size+1)*(2*size+1)/6;
    long long int difference = 0;
    long long int squared_difference = 0;
    // cout<<" greater sum = "<<greater_sum<<" squared_sum = "<<squared_sum<<endl;
    for (long long int i = 0; i < size; i++)
    {
        difference += (long long int)A[i]-(i+1);
        squared_difference += (long long int)A[i]*(long long int)A[i]-(i+1)*(i+1);
    }
    // cout<<" actual sum = "<<actual_sum<<" square_sum = "<<square_sum<<endl;
    // long long int difference = actual_sum-greater_sum;
    // long long int squared_difference = square_sum-squared_sum;
    vector<int> answer;
    long long int missingone = ((squared_difference/difference)+difference)/2;
    long long int missingtwo = missingone - difference;
    answer.push_back(missingone);
    answer.push_back(missingtwo);
    cout<<answer[0]<<" "<<answer[1];
    return answer;
}
int main()
{
    vector<int> A = {3,2,3,1,5};
    vector<int> B = repeatedNumber(A);
}