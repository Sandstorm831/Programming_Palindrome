// Question Link - https://www.interviewbit.com/problems/compare-version-numbers/
// Solution

int compt(string a, string b)
{
    int oinda=a.size();
    int oindb=b.size();
    for(int i=0; i<a.size(); i++)
    {
        if(a[i]!='0')
        {
            oinda = i;
            break;
        }
    }
    for(int i=0; i<b.size(); i++)
    {
        if(b[i]!='0')
        {
            oindb = i;
            break;
        }
    }
    if(a.size()-oinda > b.size()-oindb) return 1;
    else if(a.size()-oinda < b.size()-oindb) return -1;
    else
    {
        int i=oinda;
        int j=oindb;
        // cout<<"here"<<endl;
        while(i<a.size() && j<b.size())
        {
            // cout<<i<<" "<<a[i]-'0'<<" "<<j<<" "<<b[j]-'0'<<endl;
            if(a[i]-'0' > b[j]-'0')
            {
                // cout<<"here"<<endl;
                return 1;
            }
            else if(a[i]-'0' < b[j]-'0') 
            {
                // cout<<"there"<<endl;
                return -1;
            }
            i++, j++;
        }
        return 0;
    }
}
int subp(string a, int ind)
{
    for(int i=ind; i<a.size(); i++)
    {
        if(a[i] != '.' && a[i] != '0') return 1;
    }
    return 0;
}
int Solution::compareVersion(string A, string B) {
    int j=0; 
    int i=0;
    // int ret=0;
    int origa, origb;
    while(i<A.size() && j<B.size())
    {   
        origa = i;
        origb = j;
        for(; i<A.size(); i++) if(A[i] == '.') break;
        for(; j<B.size(); j++) if(B[j] == '.') break;
        // cout<<A.substr(origa, i-origa)<<" "<<B.substr(origb, j-origb)<<endl;
        int f = compt(A.substr(origa, i-origa),B.substr(origb, j-origb));
        if(f == 1) return 1;
        else if(f == -1) return -1;
        i++, j++;
    }
    if(i>=A.size() && j<B.size() && subp(B, j)) return -1;
    else if(i<A.size() && j>=B.size() && subp(A, i)) return 1;
    return 0;
    
    
}
