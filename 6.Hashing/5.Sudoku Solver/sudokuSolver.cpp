#include <bits/stdc++.h>
using namespace std;

// Lets solve Sudoku (9*9) in HORIZONTAL order

/*
For every empty cell we check
1.row
2.column
3.3*3 Grid
if element is not present in all three of them then yeah, that
element can be palced in that empty cell
*/

bool safe(vector<vector<int>> b, int row, int col, int dig)
{
    // check horizontally
    for (int i = 0; i < 9; i++)
    {
        if (b[row][i] == dig)
            return false;
    }
    // check verticcally
    for (int i = 0; i < 9; i++)
    {
        if (b[i][col] == dig)
            return false;
    }
    // check 3*3 Grid
    int srrow = (row / 3) * 3;
    int srcol = (col / 3) * 3;

    for (int i = srrow; i < 4; i++)
    {
        for (int j = srcol; j < 4; j++)
        {
            if (b[i][j] == dig)
                return false;
        }
    }

    return true;
}

bool solve(vector<vector<int>> &b, int row, int col)
{
    if (row == 9) // all 0 to 8 rows are filled
    {
        return true;
    }
    int nextcol = col + 1, nextrow = row; // last se phirefirst col pr jao
    if (nextcol == 9)
    {
        nextrow = row + 1;
        nextcol = 0;
    }
    if (b[row][col] != 0) // already number hai
    {
        return solve(b, nextrow, nextcol);
    }

    for (int i = 0; i < 10; i++)
    {
        if (safe(b, row, col, i))
        {
            b[row][col] = i;
            if (solve(b, nextrow, nextcol))
            {
                return true;
            }
            /*but agar saare recurssion mai kuch bhi galat ho
            and it returns false*/
            // We reset that digit and try again
            b[row][col] = 0;
        }
    }
    return false;
}

int main()
{
    vector<vector<int>> array = {
        {4, 0, 8, 6, 0, 7, 0, 0, 0},
        {0, 9, 7, 0, 0, 1, 0, 6, 8},
        {1, 5, 6, 0, 0, 0, 3, 0, 7},
        {0, 0, 0, 0, 2, 0, 0, 4, 0},
        {7, 4, 2, 0, 8, 5, 0, 0, 0},
        {9, 8, 0, 0, 0, 0, 0, 7, 0},
        {0, 6, 0, 8, 0, 3, 5, 9, 0},
        {0, 7, 9, 5, 4, 0, 2, 0, 3},
        {0, 0, 4, 0, 1, 2, 7, 8, 6}};

    solve(array, 0, 0);

    for(int i=0; i<9; i++)
    {
        for(int j=0; j<9; j++)
        {
            cout<<array[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}