// Que link - https://www.interviewbit.com/problems/maximum-area-of-triangle/

// solution

char alt(char a, char b)
{
    if(a=='r' && b=='b') return 'g';
    else if(b=='r' && a=='b') return 'g';
    else if(a=='r' && b=='g') return 'b';
    else if(b=='r' && a=='g') return 'b';
    else if(a == 'b' && b == 'g') return 'r';
    else if(b == 'b' && a == 'g') return 'r';
}
int Solution::solve(vector<string> &A) {
    int max_area = INT_MIN;
    int least_r=-1, least_g=-1, least_b=-1, most_r=-1, most_g=-1, most_b=-1;
    int cols=0;
    while((least_b == -1 || least_g==-1 || least_r == -1 ) && cols<A[0].size()) 
    {
        for(int i=0; i<A.size(); i++)
        {
            if(A[i][cols] == 'r' && least_r==-1) least_r = cols;
            else if(A[i][cols] == 'g' && least_g==-1) least_g = cols;
            else if(A[i][cols] == 'b' && least_b==-1) least_b = cols;
        }
        cols++;
    }
    if(least_b == -1 || least_g == -1 || least_r == -1) return 0;
    cols = A[0].size()-1;
    while((most_b == -1 || most_g==-1 || most_r == -1 ) && cols>=0) 
    {
        for(int i=0; i<A.size(); i++)
        {
            if(A[i][cols] == 'r' && most_r==-1) most_r = cols;
            else if(A[i][cols] == 'g' && most_g==-1) most_g = cols;
            else if(A[i][cols] == 'b' && most_b==-1) most_b = cols;
        }
        cols--;
    }
    if(most_b==-1 || most_r==-1 || most_g==-1) return 0;
    for(int i=0; i<A[0].size(); i++)
    {
        int f=-1, sf=-1, sl=-1, t=-1;
        char fc, sfc, slc, tc;
        for(int j=0; j<A.size(); j++)
        {
            if(j==0)
            {
                f=0;fc=A[j][i];continue;
            }
            else if(sf==-1 && A[j][i] != fc)
            {
                sf=j;sfc = A[j][i];sl=j;slc = sf;continue;
            }
            else if(sf != -1 && A[j][i] == sfc)
            {
                sl=j;slc = sf;continue;
            }
            else if(sf != -1 && A[j][i] != sfc && A[j][i] != fc)
            {
                t=j;tc=A[j][i];continue;
            }
        }
        int A1=-1, A2=-1, A3=-1;
        if(t != -1)
        {
            char tg = alt(fc, tc);
            char sg = alt(tc, sfc);
            if(tg == 'g') A2 = ceil(max(most_g-i+1, 1+i-least_g)*(t-f+1)*0.5);
            else if(tg == 'r') A2 = ceil(max(most_r-i+1,1+ i-least_r)*(t-f+1)*0.5);
            else if(tg == 'b') A2 = ceil(max(most_b-i+1,1+ i-least_b)*(t-f+1)*0.5);
            if(sg == 'g') A3 = ceil(max(most_g-i+1,1+ i-least_g)*(t-sf+1)*0.5);
            else if(sg == 'r') A3 = ceil(max(most_r-i+1,1+ i-least_r)*(t-sf+1)*0.5);
            else if(sg == 'b') A3 = ceil(max(most_b-i+1,1+ i-least_b)*(t-sf+1)*0.5);
        }
        if(sf != -1)
        {
            char sfg = alt(fc, sfc);
            if(sfg == 'g') A1 = ceil(max(most_g-i+1,1+ i-least_g)*(sl-f+1)*0.5);
            else if(sfg == 'r') A1 = ceil(max(most_r-i+1,1+ i-least_r)*(sl-f+1)*0.5);
            else if(sfg == 'b') A1 = ceil(max(most_b-i+1,1+ i-least_b)*(sl-f+1)*0.5);
        }
        max_area = max(max_area, max(A1, max(A2, A3)));
    }
    return max_area;
}