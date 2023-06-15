// Question Link - https://www.interviewbit.com/problems/bulls-and-cows/
// Solution 

string Solution::solve(string A, string B) {
    unordered_map<char,int> mapy;
    int bull = 0;
    int cow = 0;
    for(int i=0; i<A.length(); i++)
    {
        if(A[i] == B[i])
        {
            bull++;
            B[i] = 'a';
        }
        else{
            if(mapy.find(A[i]) == mapy.end())
            {
                mapy[A[i]]=1;
            }
            else mapy[A[i]]++;
        }
    }
    for(int i=0; i<B.size(); i++)
    {
        if(mapy.find(B[i]) != mapy.end())
        {
            cow++;
            if(mapy[B[i]] == 1) mapy.erase(B[i]);
            else mapy[B[i]]--;
        }
    }
    string t="";
    t += to_string(bull);
    t += 'A';
    t += to_string(cow);
    t += 'B';
    return t;
}
