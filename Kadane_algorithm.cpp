#include <bits/stdc++.h>
using namespace std;
int kadanes_algorithm(int numb[],int size){
    int current_sum = 0;
    int max_sum = 0 ;
    for (int i = 0; i < size; i++)
    {
        current_sum += numb[i];
        if (current_sum < 0)
        {
            current_sum = 0;
        }
        else if(current_sum > max_sum)
        {
            max_sum = current_sum;
        }
        
        
    }
    return max_sum;
}
int main(){
    int numbb[8] = {1,2,-3,-5,-7, -8, -1,-5};
    int size = sizeof(numbb)/sizeof(numbb[0]);
    cout<<kadanes_algorithm(numbb, size);
}