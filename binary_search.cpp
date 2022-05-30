<bits/stdc++.h>
using namespace std;
int binary_search(vector<int> A, int key){
    int size = A.size();
    int low = 0, high = size-1;
    int mid = (low+high)/2;
    while (high>=low)
    {
        mid=(high+low)/2;
        if(A[mid]==key)return mid;
        else if(A[mid]<key) low = mid+1;
        else high = mid-1;
    }
    return -1;
    

}

int main(){
    vector<int> A = {1,2,3,4,5, 45, 56,67,6768,3456, 8907};
    cout<<binary_search(A,14);

}