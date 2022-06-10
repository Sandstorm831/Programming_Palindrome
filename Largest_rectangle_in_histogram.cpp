//Problem Link - https://www.interviewbit.com/problems/largest-rectangle-in-histogram/
/* Problem solution function -----------------------+
vector<int> nextSmallElement(vector<int> A){   <----+
    stack<int> holder;
    vector<int> retriever;
    for (int i = 0; i < A.size(); i++)
    {
        while(!holder.empty())
        {
            if(A[i]>A[holder.top()])
            {
                retriever.push_back(holder.top());
                holder.push(i);
                break;
            } 
            else holder.pop();
        }
        if(holder.empty()){
            retriever.push_back(-1);
            holder.push(i);
        }
    }
    return retriever;
    
}
vector<int> prevSmallElement(vector<int> A){
    stack<int> holder;
    vector<int> retriever;
    for (int i = A.size()-1; i >= 0; i--)
    {
        while(!holder.empty())
        {
            if(A[i]>A[holder.top()])
            {
                retriever.push_back(holder.top());
                holder.push(i);
                break;
            } 
            else holder.pop();
        }
        if(holder.empty()){
            retriever.push_back(A.size());
            holder.push(i);
        }
    }
    reverse(retriever.begin(),retriever.end());
    return retriever;
    
}
int Solution::largestRectangleArea(vector<int> &A) {
    if(A.size() == 1) return A[0];
    vector<int> versed = nextSmallElement(A);
    vector<int> reverb = prevSmallElement(A);
    for (int i = 0; i < A.size(); i++)
    {
        // cout<<versed[i]<<" ";
    }
    // cout<<endl;
    for (int i = 0; i < A.size(); i++)
    {
        // cout<<reverb[i]<<" ";
    }
    // cout<<endl;

    
    int maxy =0 ;
    for (int i = 0; i < A.size(); i++)
    {
        int current = (reverb[i]-versed[i]-1)*A[i];
        maxy = maxy>current?maxy:current;
    }
    return maxy;
}

*/
#include <bits/stdc++.h>
using namespace std;
vector<int> nextSmallElement(vector<int> A){
    stack<int> holder;
    vector<int> retriever;
    for (int i = 0; i < A.size(); i++)
    {
        while(!holder.empty())
        {
            if(A[i]>A[holder.top()])
            {
                retriever.push_back(holder.top());
                holder.push(i);
                break;
            } 
            else holder.pop();
        }
        if(holder.empty()){
            retriever.push_back(-1);
            holder.push(i);
        }
    }
    return retriever;
    
}
vector<int> prevSmallElement(vector<int> A){
    stack<int> holder;
    vector<int> retriever;
    for (int i = A.size()-1; i >= 0; i--)
    {
        while(!holder.empty())
        {
            if(A[i]>A[holder.top()])
            {
                retriever.push_back(holder.top());
                holder.push(i);
                break;
            } 
            else holder.pop();
        }
        if(holder.empty()){
            retriever.push_back(A.size());
            holder.push(i);
        }
    }
    reverse(retriever.begin(),retriever.end());
    return retriever;
    
}

int maximarea(vector<int> A){
    vector<int> versed = nextSmallElement(A);
    vector<int> reverb = prevSmallElement(A);
    for (int i = 0; i < A.size(); i++)
    {
        cout<<versed[i]<<" ";
    }
    cout<<endl;
    for (int i = 0; i < A.size(); i++)
    {
        cout<<reverb[i]<<" ";
    }
    cout<<endl;

    
    int maxy =0 ;
    for (int i = 0; i < A.size(); i++)
    {
        int current = (reverb[i]-versed[i]-1)*A[i];
        maxy = maxy>current?maxy:current;
    }
    return maxy;
}
int main(){
    vector<int> A = {4,2,1,5,6,3,2,4,2};
    cout<<maximarea(A);

}