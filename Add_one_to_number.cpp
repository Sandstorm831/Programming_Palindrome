#include <bits/stdc++.h>
using namespace std;
vector<int> plusone(vector<int> A){
    int size = A.size();
    vector<int> B;
    int a=1;
    int i;
    for (i = 0; i < a; i++)
    {
        
        if(i<A.size()){

            if(A[size-1-i]==9){
                B.push_back(0);
                a++;
                
            }
            else
            {
                B.push_back(A[A.size()-i-1]+1);
            }
            
        }
        else
        {
            B.push_back(1);
        }
        
    }

    
    for (int j = i; j < A.size(); j++)
    {
        B.push_back(A[A.size()-j-1]);
    }   
    while (B[B.size()-1]==0)
    {
        B.pop_back();        
    }
    
    
    reverse(B.begin(), B.end());
    return B;
    
        
}
int main(){
    vector<int> A = {0,3,7,6,4,0,5,5,6};
    vector<int> B = plusone(A);
    for (int i = 0; i < B.size(); i++)
    {
        cout<<B[i]<<" ";
    }
    


}