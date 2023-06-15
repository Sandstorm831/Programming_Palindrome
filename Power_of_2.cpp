// Question Link - https://www.interviewbit.com/problems/power-of-2/
// Solution

bool checker(string s)
{
    int x=-1;
    for(int i=0; i<s.length();i++)
    {
        if(s[i] != '0')
        {
            x = i;
            break;
        }
    }
    if(s.length()-x<=5) return true;
    return false;
}
void divider(string& A)
{
    int rem=0;
    for(int i=0; i<A.size(); i++)
    {
        if(A[i] == '0' && rem == 0) continue;
        else if(A[i] == '1' || A[i] == '3' || A[i] == '5' || A[i] == '7' || A[i] == '9')
        {
            if(rem)
            {
                string s = "1";
                s += A[i];
                int xx = stoi(s);
                xx /= 2;
                A[i] = xx + '0';
                continue;
            }
            rem=1;
            int xx = A[i]-'0';
            xx /= 2;
            A[i] = xx + '0';
        }
        else if(A[i] == '0' || A[i] == '2' || A[i] == '4' || A[i] == '6' || A[i] == '8')
        {
            if(rem)
            {
                string s = "1";
                s += A[i];
                int xx = stoi(s);
                xx /= 2;
                A[i] = xx + '0';
                rem = 0;
                continue;
            }
            int xx = A[i]-'0';
            xx /= 2;
            A[i] = xx + '0';
        }
    }
}
int Solution::power(string A) {
    if(A.size()==1 && A[0] == '1') return 0;
    while(!checker(A))
    {
        if(A.back() == '1' || A.back() == '3' || A.back() == '5' || A.back() == '7' || A.back() == '9') return 0;
        divider(A);
    }
    int index=-1;
    for(int i=0; i<A.size(); i++)
    {
        if(A[i] != '0') 
        {
            index = i;
            break;
        }
    }
    string X = A.substr(index);
    int ll = stoi(X);
    while(ll != 1){
        if(ll%2 == 1) return 0;
        ll /= 2;
    }
    if(ll==1) return 1;

}
