// Problem Link - https://www.interviewbit.com/problems/nqueens/
#include <bits/stdc++.h>
using namespace std;
bool is_safe(int row, int column, int size, vector<string> board)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            if (i == row && j == column)
            {
                continue;
            }
            else if (i == row)
            {
                if (board[j][i] == 'Q')
                {
                    return false;
                    break;
                }
                else
                {
                    continue;
                }
            }
            else if (j == column)
            {
                if (board[j][i] == 'Q')
                {
                    return false;
                    break;
                }
                else
                {
                    continue;
                }
            }
            else if (row - i == column - j || row + column == i + j)
            {
                if (board[j][i] == 'Q')
                {
                    return false;
                    break;
                }
                else
                {
                    continue;
                }
            }
        }
    }
    return true;
}

void queenposition(int size,vector<vector<string>>& holder, vector<string> sub_holder, int column)
{
    //column will be given 0
    if (column == size)
    {
        holder.push_back(sub_holder);
        return;
    }
    
    for (int i = 0; i < size; i++)
    {
        if (is_safe(i, column,size, sub_holder))
        {
            sub_holder[column][i] = 'Q';
            queenposition(size, holder, sub_holder, column+1);
            sub_holder[column][i] = '.';
        }
        else
        {
            continue;
        }
        
    }
    return;
}
int main()
{
    int size = 5; // This has to be assumed
    string s = "";
    vector<vector<string>> holder;
    vector<string> subholder;
    for (int i = 0; i < size; i++)
    {
        s += ".";
    }
        
    for (int i = 0; i < size; i++)
    {
        subholder.push_back(s);
    }
    queenposition(size, holder, subholder, 0);
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            cout<<holder[j][i]<<" ";
        }
        cout<<endl;
        
    }
    

}