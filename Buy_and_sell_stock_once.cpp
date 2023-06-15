#include <bits/stdc++.h>
using namespace std;
int buy_and_sell_stock(int arry[],int size){
    int current_profit = 0;
    int max_profit = 0;
    for (int i = 0; i < size-1; i++)
    {
        if (arry[i+1]>=arry[i])
        {
            current_profit += arry[i+1]-arry[i];
        }
        else if(A[i]-A[i+1]<current_profit)
        {

            current_profit += A[i+1]-A[i];
            
        }
        else
        {

            current_profit = 0;
            
        }
        if (max_profit < current_profit)
        {
            max_profit = current_profit;
        }

        
    }
    return max_profit;
}
int main(){
    int arry[8] = {1,2,3,0,3,6,1,9};
    int size = sizeof(arry)/sizeof(arry[0]);
    cout<<buy_and_sell_stock(arry, size);

}