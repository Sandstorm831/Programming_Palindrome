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
                A[maxy-1] = temp;/*
                for (int i = 0; i < size; i++)
                {
                    cout<<A[i]<<" ";
                }
                cout<<"here"<<endl;*/
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
                A[maxy-1] = temp;/*
                for (int i = 0; i < size; i++)
                {
                    cout<<A[i]<<" ";
                }
                cout<<"there"<<endl;*/
                heapily(A,size,maxy,rpoint+1);
            }
            starter--;
            left_right_exist=true;
        }
    }
}
int main()
{
    vector<int> A = {4 ,12, 16 ,10, 11, 14, 15, 17, 2, 1, 6, 13, 7, 3, 8,9};
    int size = A.size();
    int point = size/2;
    for (int i = 0; i < size; i++)
    {
        cout<<A[i]<<" ";
    }
    cout<<endl; 
    heapily(A,size,point,0);

    for (int i = 0; i < size; i++)
    {
        cout<<A[i]<<" ";
    }
    
}