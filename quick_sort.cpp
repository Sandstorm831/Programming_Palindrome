// Quick sort Algorithm
#include <bits/stdc++.h>
using namespace std;
int sorter(vector<int>& arr ,int lower ,int higher){
    int l = lower; int h = higher;
    int pivot = arr[l];
    while (l<=h)
    {
        if (arr[l]> pivot && arr[h] < pivot)
        {
            int temp = arr[l];
            arr[l] = arr[h];
            arr[h] = temp;
            l++;h--;
        }
        else if (arr[l]> pivot)
        {
            h--;
        }
        else if (arr[h] < pivot)
        {
            l++;
        }
        else
        {
            l++;h--;
        }
    }
    if (l>h)
    {
        int temp = arr[h];
        arr[h] = arr[lower];
        arr[lower] = temp; 
    }
    return h;
}
void quick_sort(vector<int>& arr, int l, int h){
    if (l<h)
    {
        int higher = sorter(arr, l , h);
        quick_sort(arr, l, higher-1);
        quick_sort(arr, higher+1, h);
    }
}
int main(){
    vector<int> arr = {1,2,3,0,3,6,1,9};
    int size = arr.size();
    quick_sort(arr, 0, size-1);
    for (int i = 0; i < size; i++)
    {
        cout<<arr[i];
    }

}