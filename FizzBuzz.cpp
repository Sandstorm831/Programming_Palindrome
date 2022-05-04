// Problem Link - https://www.interviewbit.com/problems/fizzbuzz/
#include <bits/stdc++.h>
using namespace std;
int main(){
    int A = 23; // This is to be assumed
    vector<string> arr;
    for(int i=1; i<=A; i++){
        if(i%15 == 0){
            arr.push_back("FizzBuzz");
        }
        else if(i%5 == 0){
            arr.push_back("Buzz");
        }
        else if(i%3 == 0){
            arr.push_back("Fizz");
        }
        else{
            arr.push_back(to_string(i));
        }
    }
    
    for (int i = 0; i < arr.size(); i++)
    {
        cout<<arr[i]<<" ";
    }
    
}