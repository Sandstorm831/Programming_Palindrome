// Problem Link - https://www.interviewbit.com/problems/sudoku/
#include <bits/stdc++.h>
using namespace std;
bool any_number(int row, int column, vector<vector<char>> sudoku)
{
    if (sudoku[row][column] == '.')
    {
        return false;
    }
    else
    {
        return true;
    }
}

vector<char> possible_number(int row, int column, vector<vector<char>> sudoku)
{
    vector<char> all = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};
    vector<char> copy_all = all;

    for (int i = 0; i < 9; i++)
    {
        if (i == row)
        {
            continue;
        }

        else if (sudoku[i][column] != '.')
        {
            copy_all.erase(remove(copy_all.begin(), copy_all.end(), sudoku[i][column]), copy_all.end()); // https://en.wikipedia.org/wiki/Erase%E2%80%93remove_idiom
        }
    }
    for (int i = 0; i < 9; i++)
    {
        if (i == column)
        {
            continue;
        }
        else if (sudoku[row][i] != '.')
        {
            copy_all.erase(remove(copy_all.begin(), copy_all.end(), sudoku[row][i]), copy_all.end()); // https://stackoverflow.com/questions/3385229/c-erase-vector-element-by-value-rather-than-by-position
        }
    }
    int row_block = row / 3;
    int column_block = column / 3;
    row_block = row_block * 3;
    column_block = column_block * 3;
    for (int i = row_block; i < row_block + 3; i++)
    {
        for (int j = column_block; j < column_block + 3; j++)
        {
            if (i == row && j == column)
            {
                continue;
            }
            else if (sudoku[i][j] != '.')
            {
                copy_all.erase(remove(copy_all.begin(), copy_all.end(), sudoku[i][j]), copy_all.end());
            }
        }
    }

    return copy_all;
}

bool sudokusolver(int rows, int columns, vector<vector<char>> &sudoku)
{
    vector<char> user = possible_number(rows, columns, sudoku);
    int size_incharge = user.size();
    if (rows == 8) // base case
    {
        if (any_number(rows, columns, sudoku))
        {
            if (columns == 8)
            {
                return true;
            }
            else
            {
                return sudokusolver(0, columns + 1, sudoku);
            }
        }

        else if (size_incharge == 0)
        {
            return false;
        }
        else
        {
            sudoku[rows][columns] = user[user.size() - 1];
            user.pop_back();
            if (columns == 8)
            {
                return true;
            }
            else
            {
                while (!sudokusolver(0, columns + 1, sudoku))
                {
                    if (user.size() == 0)
                    {
                        sudoku[rows][columns] = '.';
                        return false;
                    }
                    sudoku[rows][columns] = user[user.size() - 1];
                    user.pop_back();
                }
                return true;
            }
        }
    }
    if (any_number(rows, columns, sudoku))
    {
        return sudokusolver(rows + 1, columns, sudoku);
    }
    else
    {
        if (size_incharge != 0)
        {
            sudoku[rows][columns] = user[user.size() - 1];
            user.pop_back();
            while (!sudokusolver(rows + 1, columns, sudoku))
            {
                if (user.size() == 0)
                {
                    sudoku[rows][columns] = '.';
                    return false;
                }
                sudoku[rows][columns] = user[user.size() - 1];
                user.pop_back();
            }
        }
        else
        {
            return false;
        }
    }
    return true;
}
int main()
{
    // This vector has to be assumed
    vector<vector<char>> sudoku;
    for (int i = 0; i < 9; i++)
    {
        vector<char> ecu;
        for (int j = 0; j < 9; j++)
        {
            char apy;
            cout<<"enter matrix["<<i<<"]["<<j<<"]"<<endl;
            cin>>apy;
            ecu.push_back(apy);
        }
        sudoku.push_back(ecu);
        ecu.clear();
        
    }
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            if (j == 2 || j == 5)
            {
                cout << sudoku[i][j] << "|";
            }
            else
            {
                cout << sudoku[i][j] << " ";
            }
        }
        cout << endl;
        if (i == 2 || i == 5)
        {
            for (int k = 0; k < 10; k++)
            {
                cout << "..";
            }
            cout << endl;
        }
    }
    bool ary = sudokusolver(0, 0, sudoku);
    cout << endl;
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            if (j == 2 || j == 5)
            {
                cout << sudoku[i][j] << "|";
            }
            else
            {
                cout << sudoku[i][j] << " ";
            }
        }
        cout << endl;
        if (i == 2 || i == 5)
        {
            for (int k = 0; k < 10; k++)
            {
                cout << "..";
            }
            cout << endl;
        }
    }
}