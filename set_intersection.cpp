// Question Link - https://www.interviewbit.com/problems/set-intersection/
// Solution

bool compare(vector<int> &a, vector<int> &b)
{
    // cout<<a.size()<<" "<<b.size()<<endl;
    // if(a[1]<b[1]) return true;
    // else if(a[1]>b[1]) return false;
    // else if(a[0] < b[0]) return true;
    if(a[1] != b[1]){
       return a[1]<b[1];
    }
    return a[0]>b[0];
    
}
int Solution::setIntersection(vector<vector<int> > &A) {
    sort(A.begin(), A.end(), compare);
    vector<int> v;
    v.push_back(A[0][1]-1);v.push_back(A[0][1]);
    for(int i=1; i<A.size(); i++)
    {
        int counter=0;
        if(v[v.size()-1]>=A[i][0] && v[v.size()-1]<=A[i][1]) counter++;
        if(v[v.size()-2]>=A[i][0] && v[v.size()-2]<=A[i][1]) counter++;
        if(counter==0)
        {
            v.push_back(A[i][1]-1);v.push_back(A[i][1]);
        }
        else if(counter==1)
        {
            v.push_back(A[i][1]);
        }
    }
    return v.size();    
}