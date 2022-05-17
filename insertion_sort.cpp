// Insertion sort algorithm
#include <bits/stdc++.h>
using namespace std;
void insertion_sort(vector<int>& trd){
    int size = trd.size();
    for (int i = 1; i < size; i++)
    {
        int j;
        int temp = trd[i];
        for (j = i-1; j >=0  ; j--)
        {
            if (trd[j]>temp)
            {
                trd[j+1] = trd[j];
            }
            else
            {
                break;
            }
            
        }
        trd[j+1] = temp;

    }
    
}
int main(){
    vector<int> trd = {1,2,3,0,3,6,1,9};
    int size = trd.size();
    insertion_sort(trd);
    for (int i = 0; i < size; i++)
    {
        cout<<trd[i];
    }
    

}