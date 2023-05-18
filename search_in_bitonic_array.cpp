// question Link - https://www.interviewbit.com/problems/search-in-bitonic-array/
// Solution

int Solution::solve(vector<int> &A, int B) {
    int low = 0;
    int high = A.size()-1;
    int mid = (low+high)/2;
    while(low<=high)
    {
        if(A[mid]>A[mid+1] && A[mid]>A[mid-1]) break;
        else if(A[mid]>A[mid+1] && A[mid]<A[mid-1]) high = mid-1;
        else if(A[mid] < A[mid+1] && A[mid]>A[mid-1]) low = mid+1;
        mid = (low+high)/2;
    }
    int found=-1;
    int ini = 0;
    int fin = mid;
    int mi = (ini + fin)/2;
    while(ini<=fin)
    {
        if(A[mi] == B) 
        {
            found = mi;
            break;
        }
        else if(A[mi] > B) fin = mi-1;
        else if(A[mi] < B) ini = mi+1;
        mi = (ini+fin)/2;
    }
    if(found != -1) return mi;
    ini = mi+1;
    fin = A.size()-1;
    mi = (ini+fin)/2;
    while(ini<=fin)
    {
        if(A[mi] == B) 
        {
            found = mi;
            break;
        }
        else if(A[mi] > B) ini = mi+1;
        else if(A[mi] < B) fin = mi-1;
        mi = (ini+fin)/2;
    }
    return found;
}
