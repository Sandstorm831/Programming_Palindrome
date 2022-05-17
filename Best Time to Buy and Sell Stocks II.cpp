//Problem Link - https://www.interviewbit.com/problems/best-time-to-buy-and-sell-stocks-ii/
#include <bits/stdc++.h>
using namespace std;
int buy_and_sell_stock(int arry[],int size){
    int max_profit = 0;
    for (int i = 0; i < size-1; i++)
    {
        if (arry[i+1]>arry[i])
        {
            max_profit += arry[i+1]-arry[i];
        }
        
    }
    return max_profit;
    
}
int main(){
    int arry[8] = {1,2,3,0,3,6,1,9}; // This has to be assumed
    int size = sizeof(arry)/sizeof(arry[0]);
    cout<<buy_and_sell_stock(arry, size);

}