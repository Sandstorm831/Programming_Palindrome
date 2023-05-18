// Question Link - https://www.interviewbit.com/problems/smaller-or-equal-elements/
// Solution 

int Solution::solve(vector<int> &A, int B) {
    int ini = 0;
    int fin = A.size()-1;
    int mi = (ini + fin )/2;
    int found = -1;
    while(ini<=fin)
    {
        if(A[mi]<=B && A[mi+1]>B) 
        {
            break;
        }
        else if(A[mi]<=B && A[mi+1]<=B) ini = mi+1;
        else if(A[mi]>B) fin = mi-1;
        mi = (ini + fin)/2;
    }
    if(mi == 0) 
    {
        if(A[0] <= B) return mi+1;
        else return mi;
    }
    else return mi+1;
}
