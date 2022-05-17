#include <bits/stdc++.h>
using namespace std;
void selection_sort(vector<int>& arr){
    int size = arr.size();
    for (int i = 0; i < size; i++)
    {
        int min_index = i;
        for (int j = i; j < size-1; j++)
        {
            if (arr[j]<arr[min_index])
            {
                min_index = j;
            }
            
        }
        int temp = arr[min_index];
        arr[min_index] = arr[i];
        arr[i] = temp;
        
    }
    
}
int main(){
    vector<int> arr = {1,2,3,0,3,6,1,9};
    int size = arr.size();
    selection_sort(arr);
    for (int i = 0; i < size; i++)
    {
        cout<<arr[i];
    }
}