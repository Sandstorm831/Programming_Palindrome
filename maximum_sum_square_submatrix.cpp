// Question Link - https://www.interviewbit.com/problems/maximum-sum-square-submatrix/
// Solution

int Solution::solve(vector<vector<int> > &A, int B) {
    int n = A.size();
    int f = n-B+1;
    vector<vector<int>> v(n, vector<int> (n, 0));
    for(int i=0; i<n; i++)
    {
        int summ=0;
        for(int j=0; j<f; j++)
        {
            if(j==0)
            {
                for(int k=0; k<B; k++)
                {
                    summ += A[i][k];            
                }
                v[i][j]=summ;
                continue;
            }
            summ += A[i][j+B-1]-A[i][j-1];
            v[i][j] = summ;
        }
    }
    for(int i=0; i<f; i++)
    {
        int summ=0;
        for(int j=0; j<f; j++)
        {
            if(j==0)
            {
                for(int k=0; k<B; k++)
                {
                    summ += v[k][i];            
                }
                A[j][i]=summ;
                continue;
            }
            summ += v[j+B-1][i]-v[j-1][i];
            A[j][i] = summ;
        }
    }
    int maxy = INT_MIN;
    for(int i=0;i<f; i++)
    {
        for(int j=0; j<f; j++)
        {
            // cout<<A[i][j]<<" ";
            maxy = max(maxy, A[i][j]);
        }
        // cout<<endl;
    }
    return maxy;
}