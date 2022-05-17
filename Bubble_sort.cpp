// Bubble Sort algorithm
#include <bits/stdc++.h>
using namespace std;
void bubble_sort(vector<int>& arr){
    int size = arr.size();
    cout<<endl;
    for (int i = 0; i < size; i++)
    {
        int swaps = 0;
        for (int j = 0; j < size-i-1 ; j++)
        {
            if (arr[j]>arr[j+1])
            {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
                swaps++;
            }

        }
        if (swaps == 0)
        {
            break;
        }
    }
    
}
int main(){
    vector<int> arr = {1,2,3,0,3,6,1,9};
    int size = arr.size();
    bubble_sort(arr);
    for (int i = 0; i < size; i++)
    {
        cout<<arr[i];
    }
    
}