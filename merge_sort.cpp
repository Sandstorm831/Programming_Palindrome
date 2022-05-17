//Merge sort
#include <bits/stdc++.h>
using namespace std;
vector<int> merge(vector<int> vel, vector<int> del){
    int i=0,j=0;
    vector<int> merged;
    while (i<=vel.size()-1 && j<=del.size()-1)
    {
        if (vel[i]<del[j])
        {
            merged.push_back(vel[i]);
            i++;
        }
        else
        {
            merged.push_back(del[j]);
            j++;
        }   
    }
    if (i<=vel.size()-1)
    {
        while (i<=vel.size())
        {
            merged.push_back(vel[i]);
            i++;
        }
    }
    else
    {
        while (j<=del.size()-1)
        {
            merged.push_back(del[j]);
            j++;
        }
        
    }
    return merged;
    
}
vector<int> merge_sort(vector<int> arr, int l, int h){
    vector<int> vel, del;
    if (l<h)
    {
        int mid = (l+h)/2;
        vel = merge_sort(arr, l, mid);
        del = merge_sort(arr, mid+1, h);
        return merge(vel, del);
    }
    else
    {
        vel.push_back(arr[l]);
        return vel;
    }
}
int main(){
    vector<int> arr = {1,2,3,0,3,6,1,9};
    int size = arr.size();
    vector<int> arry;
    arry = merge_sort(arr, 0, size-1);
    for (int i = 0; i < size; i++)
    {
        cout<<arry[i];
    }


}