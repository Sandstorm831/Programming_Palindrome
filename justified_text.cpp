// Question Link - https://www.interviewbit.com/problems/justified-text/
// Solution

vector<string> Solution::fullJustify(vector<string> &A, int B) {
    vector<string> ans;
    int count=0;
    int n = A.size();
    while(count<n)
    {
        string s="";
        int tot=0;
        int fin, ini = count;
        while(tot<B && count<n)
        {
            if(tot != 0) tot++;
            tot+=A[count].size();
            count++;
        }
        // cout<<tot<<" "<<count<<endl;
        if(tot == B) 
        {
            tot++;
            fin = count-1;
        }
        else if(tot > B)
        {
            tot -= A[count-1].size();
            fin = count-2;
            count--;
        }
        else if(count >= n)
        {
            fin = count-1;
            tot++;
        }
        int nom = fin-ini+1;
        tot -= nom;
        int sp = (B-tot)/max(nom-1,1);
        int ext = (B-tot)%max(nom-1,1);
        // cout<<fin<<" "<<ini<<" "<<nom<<" "<<tot<<" "<<sp<<" "<<ext<<" "<<count<<endl;
        while(s.size()<B && count<n)
        {
            if(ext>0)
            {
                s += A[ini];
                for(int j=0; j<=sp && s.size()<B; j++) s+=' ';
                ext--;
                ini++;
            }
            else
            {
                s += A[ini];
                // cout<<s.size()<<endl;
                for(int j=0; j<sp && s.size()<B; j++) s+=' ';
                ini++;
            }
        }
        // cout<<s<<endl;
        while(s.size()<B && count >= n)
        {
            if(ini > fin)
            {
                s += ' ';
                continue;
            }
            if(s.size()!=0) s+=' ';
            s += A[ini];
            ini++;
            // cout<<s<<" | "<<endl;
        }
        ans.push_back(s);
    }
    return ans;
}
// What must be ## shall be.    ## 