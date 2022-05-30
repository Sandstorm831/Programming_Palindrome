//Problem Link - https://www.interviewbit.com/problems/flip/
#include <bits/stdc++.h>
using namespace std;
vector<int> flip(string A)
{   
    string B = A;
    int length = A.size();
    int ion = 0;
    vector<int> rte;
    int low_index, high_index,jko=0, low_index_m, high_index_m, current_score = 0, max_score = 0;
    bool flok = false;
    while (ion < length)
    {
        if (A[ion] != '1')
        {
            break;
        }
        else
        {
            ion++;
        }
    }
    if (ion == length)
    {
        return rte;
    }

    else
    {
        for (int i = 0; i < length; i++)
        {
            if (A[i]=='0')
            {
                if (current_score == 0)
                {
                    current_score =1;
                    if (!flok)
                    {
                        low_index = i;
                    }
                    flok = false;
                    
                }
                else
                {
                    current_score +=1;
                    high_index = i;
                }            
                if (current_score>max_score)
                {
                    max_score = current_score;
                    low_index_m = low_index;
                    high_index_m = i;
                }

            }
            else
            {
                if (current_score == 0)
                {
                    continue;
                }
                current_score -=1;
                if (current_score == 0)
                {
                    if (A[i+1]=='0')
                    {
                        //cout<<i<<"and here is it "<<A[i-1]<<A[i]<<B[i+1]<<A[i+2]<<A[i+3]<<A[i+4]<<endl;
                        flok = true;
                    }
                    else
                    {
                        flok = false;
                    }
                }

            }


        }
        
        rte.push_back(low_index_m + 1);
        rte.push_back(high_index_m + 1);
        return rte;
    }
}
int main()
{
    string A = "10101000100010"; // This has to be assumed
    vector<int> hell = flip(A);
    for (int i = 0; i < hell.size(); i++)
    {
        cout << hell[i] << " ";
    }
}