// Question Link - https://www.interviewbit.com/problems/matrix-median/
// Solution 

// Here in this code you should learn the code, that is, should thoroughly remember the initricacies, 
int Solution::findMedian(vector<vector<int> > &matrix) {
    int r=matrix.size();
    int c=matrix[0].size();
    int k = (r * c + 1) / 2;  // remember that it is r*c+1/2 and not r*c/2;
    int a = INT_MAX;
    int b = INT_MIN;
    for(int i = 0; i < r; i++){
        a = min(a, matrix[i][0]);
        b = max(b, matrix[i][c-1]);
    }
    while(a < b){ // remember that here a<b and a<=b
        int m = (a + b) / 2;
        int count = 0;
        for(int i = 0; i < r; i++)
            count = count + upper_bound(matrix[i].begin(), matrix[i].end(), m) - matrix[i].begin();
        if(count < k) a = m + 1;
        else b = m; // remember here b = m and b = m-1;
    }
    return a;
}