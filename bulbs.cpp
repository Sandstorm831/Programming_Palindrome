//Question Link - https://www.interviewbit.com/problems/interview-questions/
// Solution 

int Solution::bulbs(vector<int> &A) {
    int counter=0;
    int target=0;
    for(int i=0; i<A.size(); i++)
    {
        if(A[i]==target)
        {
            counter++;
            target ^=1;
        }
    }
    return counter;
}
