// Problem Link-  https://www.interviewbit.com/problems/sliding-window-maximum/
/* Problem solution function -------------------------------------------------------+
vector<int> Solution::slidingMaximum(const vector<int> &A, int B) {    <------------+
    deque<int> holder;
    vector<int> maxy;
    int count =0;
    while(count < B) // insert usefull elements in the deque till window size
    {
        if(holder.empty()) holder.push_back(count);
        else if(A[holder.back()] < A[count]) 
        {
            while(!holder.empty() && A[holder.back()]< A[count]) // remove indices whose elements are smaller than current element
            {
                holder.pop_back();
            }
            holder.push_back(count);
        }
        else{
            holder.push_back(count);
        }
        count++; // increase the count with every pass
    }
    maxy.push_back(A[holder.front()]); // deque always have the max element indice at the front
    while(count < A.size())  // traverse the vector after the window size
    {
        if(A[holder.front()] == A[count - B] && !holder.empty()) holder.pop_front(); // remove the front element if not in window
        if(A[holder.back()] < A[count])
        {
            while(!holder.empty() && A[holder.back()]< A[count])
            {
                holder.pop_back();
            }
            holder.push_back(count);
        }
        else
        {
            holder.push_back(count);
        }
        count++;
        maxy.push_back(A[holder.front()]);
    }
    return maxy;
}

*/
#include <bits/stdc++.h>
using namespace std;
vector<int> slidingmax(vector<int> A, int B)
{
    deque<int> holder;
    vector<int> maxy;
    int count =0;
    while(count < B)
    {
        if(holder.empty()) holder.push_back(count);
        else if(A[holder.back()] < A[count]) 
        {
            while(!holder.empty() && A[holder.back()]< A[count])
            {
                holder.pop_back();
            }
            holder.push_back(count);
        }
        else{
            holder.push_back(count);
        }
        count++;
    }
    maxy.push_back(A[holder.front()]);
    while(count < A.size())
    {
        if(A[holder.front()] == A[count - B] && !holder.empty()) holder.pop_front();
        if(A[holder.back()] < A[count])
        {
            while(!holder.empty() && A[holder.back()]< A[count])
            {
                holder.pop_back();
            }
            holder.push_back(count);
        }
        else
        {
            holder.push_back(count);
        }
        count++;
        maxy.push_back(A[holder.front()]);
    }
    return maxy;
}
int main(){
    vector<int> A = {4,1,3,5,1,2,3,2,1,1,5};
    int B = 3;
    vector<int> hell = slidingmax(A,B);
    for (int i = 0; i < hell.size(); i++)
    {
        cout<<hell[i]<<" ";
    }
    

}
