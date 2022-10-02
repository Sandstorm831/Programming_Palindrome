// Problem Link - https://www.interviewbit.com/problems/smallest-multiple-with-0-and-1/
/*
You are given an integer N. You have to find smallest multiple of N which consists of digits 0 and 1 only. Since this multiple could be large, return it in form of a string.

Note:

Returned string should not contain leading zeroes.
For example,

For N = 55, 110 is smallest multiple consisting of digits 0 and 1.
For N = 2, 10 is the answer.
*/
string Solution::multiple(int N) {
    if(N==1) return "1";
    vector<int> p(N,-1);//parent state
    vector<int> s(N,-1);//step from parent to current
    //BFS
    int steps[2] = {0,1};
    queue<int> q;
    q.push(1);
    while(!q.empty()){
        int curr = q.front();
        q.pop();
        if(curr==0) break;
        for(int step: steps){
            int next = (curr*10+step)%N;
            if(p[next]==-1){
                p[next]=curr;
                s[next]=step;
                q.push(next);
            }
        }
    }
    //build reversed string
    string number="";
    for(int it=0; it!=1; it=p[it])
    {
        number.push_back('0'+s[it]);
        // cout<<s[it]<<endl;
    }
    number.push_back('1');
    //return the reverse if it
    return string(number.rbegin(), number.rend());
}