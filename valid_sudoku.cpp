// Question Link - https://www.interviewbit.com/problems/valid-sudoku/
// Solution 

int Solution::isValidSudoku(const vector<string> &A) {
    unordered_set<char> st;
    for(int i=0;i<A.size(); i++)
    {
        st.clear();
        for(int j=0; j<A[0].size(); j++)
        {
            if(A[i][j]=='.') continue;
            else if(st.find(A[i][j]) != st.end()) return false;
            else st.insert(A[i][j]);
        }
    }
    for(int i=0;i<A[0].size(); i++)
    {
        st.clear();
        for(int j=0; j<A.size(); j++)
        {
            if(A[j][i]=='.') continue;
            else if(st.find(A[j][i]) != st.end()) return false;
            else st.insert(A[j][i]);
        }
    }
    for(int i=0; i<=6; i+=3)
    {
        for(int j=0; j<=6; j+=3)
        {
            st.clear();
            for(int k=i; k<i+3; k++)
            {
                for(int l=j; l<j+3; l++)
                {
                    if(A[k][l]=='.')continue;
                    else if(st.find(A[k][l]) != st.end()) return false;
                    else st.insert(A[k][l]);
                }
            }
        }
    }
    return true;
}
