// Question Link - https://www.interviewbit.com/problems/egg-drop-problem/
// solution 

vector<vector<int>> dp(105, vector<int> (10005,-1));
int floorfinder(int eggs, int floors)
{
    if(eggs == 1) return floors;
    else if(floors==1 || floors==0) return floors;
    else if(dp[eggs][floors] != -1) return dp[eggs][floors];
    else
    {
        int low = 1, high = floors;
        int minn = INT_MAX;
        while(low<=high)
        {
            int mid = (low+high)/2;
            int breaks = floorfinder(eggs-1, mid-1);
            int notbreaks = floorfinder(eggs, floors-mid);
            if(breaks > notbreaks)
            {
                high = mid-1;
                minn = min(minn, breaks+1);
            }
            else
            {
                low = mid+1;
                minn = min(minn, notbreaks+1);
            }
            
        }
        return dp[eggs][floors] = minn;
    }

}
int Solution::solve(int A, int B) {
    return floorfinder(A, B);
}

// Another approach
// int f(int floors, int eggs,vector <vector <int>> &dp){
//     if(eggs == 1) return floors; //if we have only one egg left, we will start from bottom most floor.
//     if(floors == 0) return 0; //if we have no floors, we dont require any step.
    
//     if(dp[floors][eggs] != -1) return dp[floors][eggs]; // if we have already explored the floors with these many 
//                                                         //remaining eggs, we can reuse it to save time.
    
//     int low = 1, high = floors; 
//     int mini = INT_MAX; // to store minimum no of steps.
    
//     while(low <= high){
//         int mid = low + (high-low)/2;
        
//         int notBreak = f(floors-mid, eggs, dp); //if egg doesn't break, try from above floors.
//         int breaks = f(mid-1, eggs-1, dp); //if egg breaks, we will try from below floors.
        
//         if(breaks > notBreak){
//             mini = min(mini, breaks + 1);
//             high = mid - 1;
//         } else{
//             mini = min(mini, notBreak + 1);
//             low = mid + 1;
//         }
//     }
    
//     return dp[floors][eggs] = mini; // while returning the answer, store the ans so that we can use it again.
// }

// int Solution::solve(int eggs, int floors) {
//     vector <vector <int>> dp(floors+1, vector <int> (eggs+1, -1));
    
//     return f(floors, eggs, dp);
// }