// Question Link - https://www.interviewbit.com/problems/merge-two-sorted-lists-ii/
// Solution

void Solution::merge(vector<int> &A, vector<int> &B) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    vector<int> mergd;
    int i=0, j=0;
    while(i<A.size() && j<B.size())
    {
        if(A[i]<B[j])
        {
            mergd.push_back(A[i]);
            i++;
        }
        else
        {
            mergd.push_back(B[j]);
            j++;
        }
    }
    while(i<A.size())
    {
        mergd.push_back(A[i]);
        i++;
    }
    while(j<B.size())
    {
        mergd.push_back(B[j]);
        j++;
    }
    A = mergd;
}
