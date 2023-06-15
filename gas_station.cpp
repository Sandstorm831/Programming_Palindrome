// Question Link - https://www.interviewbit.com/problems/gas-station/
// Solution

int Solution::canCompleteCircuit(const vector<int> &A, const vector<int> &B) {
    vector<int>a=A;
    vector<int>b=B;
    int n=a.size();
    int asum=0 , bsum=0;
    for(int i=0; i<n ; i++){
        asum+=a[i];
        bsum+=b[i];
    }
    if(bsum>asum){
        return -1;
    }
    int tank=0 , index=0;
    for(int i=0; i<n ; i++){
        int c=a[i]-b[i];
        tank+=c;
        if(tank<0){
            index=i+1;
            tank=0;
        }
   }
   return index;
}