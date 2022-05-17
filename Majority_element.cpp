// Problem link - https://www.interviewbit.com/problems/majority-element/
#include <bits/stdc++.h>
using namespace std;
int moore_voting_algo(int arr[], int size){
    int stored_value = arr[0];
    int count = 0;
    for (int i = 0; i < size; i++)
    {
        if (stored_value == arr[i])
        {
            count++;
        }
        else
        {
            count--;
            if (count == 0)
            {
                stored_value = arr[i];
                count++;
            }
            
        }
    }
    if (count>0)
    {
        return stored_value;
    }
    else
    {
        return -9999999;
    }
    
    
}
int main()
{
    int arr[9] = {6,7,6,6,8,2,6,6,8}; // This has to be assumed
    int size = sizeof(arr)/sizeof(arr[0]);
    cout<<moore_voting_algo(arr, size);

}