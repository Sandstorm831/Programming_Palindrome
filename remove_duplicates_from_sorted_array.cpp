// Question Link - https://www.interviewbit.com/problems/remove-duplicates-from-sorted-array/
// Solution

int Solution::removeDuplicates(vector<int> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    // if(A.size()==1) return 1;
    int count=1;
    for(int i=1; i<A.size(); i++)
    {
        if(A[count-1] != A[i])
        {
            A[count] = A[i];
            count++;
        }
    }
    return count;
}
