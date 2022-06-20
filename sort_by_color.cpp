// Problem Link - https://www.interviewbit.com/problems/sort-by-color/
/* Problem Solution Function ------------------------------+
void Solution::sortColors(vector<int> &A) {         <------+
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    int z=0,o=0,t=0;
    int n=A.size()-1;
    vector<int>v(n);
    for(int i=0;i<A.size();i++){
        if(A[i]==0) z++;
        else if(A[i]==1) o++;
        else t++;
        }
    for(int  i=0;i<z;i++) A[i] = 0;
    for(int i=z;i<o+z;i++) A[i] = 1;
    for(int i=o+z;i<o+z+t;i++) A[i] = 2;
}
*/
#include <bits/stdc++.h>
using namespace std;
void sortColors(vector<int>& A)
{
    int z=0,o=0,t=0;
    int n=A.size()-1;
    vector<int>v(n);
    for(int i=0;i<A.size();i++){
        if(A[i]==0) z++;
        else if(A[i]==1) o++;
        else t++;
        }
    for(int  i=0;i<z;i++) A[i] = 0;
    for(int i=z;i<o+z;i++) A[i] = 1;
    for(int i=o+z;i<o+z+t;i++) A[i] = 2;
}
int main()
{

}