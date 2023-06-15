// Question LInk - https://www.interviewbit.com/problems/magician-and-chocolates/
// Solution

int Solution::nchoc(int A, vector<int> &B) {
    int mod = 1e9+7;
    priority_queue<int> pq;
    for(int i=0;i<B.size();i++) pq.push(B[i]);
    int tm = A;
    int choc = 0;
    while(tm>0)
    {
        int x = pq.top();
        pq.pop();
        choc = (choc%mod + x%mod)%mod;
        x /= 2;
        pq.push(x);
        tm--;
    }
    return choc%mod;
}
