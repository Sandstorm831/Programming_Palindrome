// question link - https://www.interviewbit.com/problems/spiral-order-matrix-ii/

// solution
vector<vector<int> > Solution::generateMatrix(int A) {
    vector<vector<int>> v(A, vector<int> (A, 0));
    int num=1;
    for(int i=0; i<A; i++)
    {
        v[0][i] = num;
        num++;
    }
    int dir = 1;
    dir=dir%4;
    int y = A-1;
    int x = 0;
    int xx=A-1;
    while(xx>0)
    {
        for(int j=0; j<2; j++)
        {
           if(dir==0)
           {
               for(int i=0; i<xx; i++)
               {
                   y++;
                   v[x][y]=num;
                   num++;
               }
               dir++;
               dir = dir%4;
           }
           else if(dir==1)
           {
               for(int i=0; i<xx; i++)
               {
                   x++;
                   v[x][y]=num;
                   num++;
               }
               dir++;
               dir = dir%4;   
           }
           else if(dir==2)
           {
               for(int i=0; i<xx; i++)
               {
                   y--;
                   v[x][y]=num;
                   num++;
               }
               dir++;
               dir = dir%4;
           }
           else if(dir==3)
           {
               for(int i=0; i<xx; i++)
               {
                   x--;
                   v[x][y]=num;
                   num++;
               }
               dir++;
               dir = dir%4;
           }
        }
        xx--;
    }
    return v;
}
