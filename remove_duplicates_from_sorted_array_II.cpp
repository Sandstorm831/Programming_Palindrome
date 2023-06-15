// Question LInk - https://www.interviewbit.com/problems/remove-duplicates-from-sorted-array-ii/
// Solution

int Solution::removeDuplicates(vector<int> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    int count=1;
    int curr=A[0];
    int num=1;
    for(int i=1; i<A.size(); i++)
    {
        
        if(curr != A[i])
        {
            A[count] = A[i];
            count++;num=1;
            curr = A[i];
        }
        else if(curr == A[i] && num<2)
        {
            A[count]=A[i];
            count++;num++;
        }
    }
    vector<int>::iterator it1 = A.end();
    vector<int>::iterator it2 = A.begin()+count;
    A.erase(it2, it1);
    return count;
}
