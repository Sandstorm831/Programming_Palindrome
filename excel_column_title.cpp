// Question Link - https://www.interviewbit.com/problems/excel-column-title/
// Solution

string Solution::convertToTitle(int n) {
    string ans="";
    while(n){
        int rem=n%26;
        if(rem){
            char c=rem-1+'A';
            string s;
            s.push_back(c);
            ans.insert(0,s);
            n=n/26;
        }
        else{
            ans.insert(0,"Z");
            n=n/26-1;
        }
    }
    return ans;
}