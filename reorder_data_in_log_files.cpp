// Question Link -https://www.interviewbit.com/problems/reorder-data-in-log-files/
// Solution

bool compare(string a, string b)
{
    int j=0,i=0;
    while(a[j] != '-') j++;
    while(b[i] != '-') i++;
    j++, i++;
    while(i<b.size() && j<a.size())
    {
        if(a[j]=='-' && b[i]=='-')
        {
            i++,j++;continue;
        }
        else if(a[j]=='-' && b[i] != '-') return true;
        else if(a[j] != '-' && b[i] == '-') return false;
        if(a[j]<b[i])return true;
        else if(a[j]>b[i]) return false;
        i++,j++;
    }
    i=0, j=0;
    while(a[j] != '-' && b[i] != '-')
    {
        if(a[j]<b[i]) return true;
        else if(a[j]>b[i]) return false;
        i++, j++;
    }
    return true;
    
}
vector<string> Solution::reorderLogs(vector<string> &A) {

    vector<string> dig;
    vector<string> let;
    for(int i=0; i<A.size(); i++)
    {
        int j=0;
        while(A[i][j] != '-') j++;
        j++;
        if(A[i][j]-'0'>=0 && A[i][j]-'0'<=9) 
        {
            dig.push_back(A[i]);
            continue;
        }
        else
        {
            let.push_back(A[i]);
        }
    }
    sort(let.begin(), let.end(), compare);
    vector<string> v(let);
    v.insert(v.end(), dig.begin(), dig.end());
    return v;
    
}