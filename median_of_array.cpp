// Question Link - https://www.interviewbit.com/problems/median-of-array/
// Solution

double  findMedian(const vector<int> &A,const vector<int> &B)
{
    int total = (A.size() + B.size());
    int half = (total+1)/2;
   
    int left = 0;
    int right = A.size();
   
    while(true)
    {
        int mid = (left + right)/2;
        int left1 = ((mid -1 >=0 and mid-1 <A.size())? A[mid-1]:INT_MIN);
        int left2 = (((half-mid-1)>=0 and half - mid -1 < B.size())?B[half -mid -1]:INT_MIN);
        int right1 = ((mid < A.size())?A[mid]:INT_MAX);
        int right2 = ((half -mid <B.size())?B[half - mid]:INT_MAX);
       
        if(left1 <= right2 and left2<=right1)
        {
            if(total%2 == 1)
            {
                double ans  = max(left1,left2);
                return ans;
            }
            else
            {
                double ans = ((double)max(left1,left2) + (double)min(right1,right2))/2;
                return ans;
            }
        }
        else if(left1 > right2)
        {
            right = mid - 1;
        }
        else if(left2 > right1)
        {
            left = mid + 1;
        }
    }
}
double Solution::findMedianSortedArrays(const vector<int> &A, const vector<int> &B) {
       
   if(A.size() <= B.size())
   {
       return findMedian(A,B);
   }  
   else
   {
       return findMedian(B,A);
   }
}