#include <bits/stdc++.h>
using namespace std;
void heapily(vector<int>& A, int size,int point, int rpoint){
    if(point*2>size && rpoint>0) return;
    else if(point*2 == size && rpoint>0)
    {
        if(A[point*2-1] <= A[point-1]) return;
    }
    else if(rpoint>0 && point*2<size)
    {
        int lefty = A[2*point-1];
        int righty = A[2*point];
        int maxy = lefty>righty?2*point:2*point+1;
        if(A[maxy-1]<=A[point-1]) return;
    }
    int starter = point;
    bool left_right_exist;
    if(2*starter == size) left_right_exist = false;
    else left_right_exist=true;
    while(starter>0)
    {
        if(left_right_exist)
        {
            int lefty = A[2*starter-1]; 
            int righty = A[2*starter+1-1];
            int maxy = lefty>righty ? 2*starter:2*starter+1;
            if(A[maxy-1]>A[starter-1])
            {
                int temp = A[starter-1];
                A[starter-1] = A[maxy-1];
                A[maxy-1] = temp;
                heapily(A,size,maxy,rpoint+1);
            }
            starter--;
        }
        else
        {
            int maxy = 2*starter;
            if(A[maxy-1]>A[starter-1])
            {
                int temp = A[starter-1];
                A[starter-1] = A[maxy-1];
                A[maxy-1] = temp;
                heapily(A,size,maxy,rpoint+1);
            }
            starter--;
            left_right_exist=true;
        }
    }
}
vector<int> heapysorty(vector<int> A){
    vector<int> B = A,sorted;
    while(B.size()>0)
    {
        int size = B.size();
        int point = size/2;
        heapily(B,size,point,0);
        //cout<<B[0]<<" ";
        sorted.push_back(B[0]);
        B[0] = B[B.size()-1];
        B.pop_back();
    }
    return sorted;
}
int main()
{
    vector<int> A = {1,2,3,6,7,4,8,9,23,12,21,15};
    vector<int> L = heapysorty(A);
    for (int i = 0; i < L.size(); i++)
    {
        cout<<L[i]<<" ";
    }
    
}