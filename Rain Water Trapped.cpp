// Problem Link - https://www.interviewbit.com/problems/rain-water-trapped/
#include <bits/stdc++.h>
using namespace std;
int rain_water_trapped(int arr[], int size){
    int left[size], right[size];
    for (int i = 0; i < size; i++)
    {
        if (i==0)
        {
            left[i] = arr[i];
            right[size-1] = arr[size - 1];
            continue;
        }
        else
        {
            if (left[i-1]<arr[i])
            {
                left[i] = arr[i];
            }
            else
            {
                left[i] = left[i-1];
            }
            if (right[size-i]<arr[size-i-1])
            {
                right[size-i-1] = arr[size-i-1];
            }
            else
            {
                right[size-i-1] =right[size-i];
            }
            
        }
    }
    int rain_water =0;
    for (int i = 0; i < size; i++)
    {
        rain_water += min(left[i],right[i]) - arr[i];
    }
    return rain_water;
    
}
int main(){
    int arry[8] = {4,2,3,0,3,6,1,9}; // This has to be assumed
    int size = sizeof(arry)/sizeof(arry[0]);
    cout<<rain_water_trapped(arry, size);
}