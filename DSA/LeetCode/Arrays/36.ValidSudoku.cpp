#include <iostream>
#include <vector>
#include <set>
class Solution
{
public:
    bool isValidSudoku(std::vector<std::vector<char>> &board)
    {

        // Each row must contain the digits 1-9 without repetition.
        // Each column must contain the digits 1-9 without repetition.
        // Each of the nine 3 x 3 sub-boxes of the grid must contain the digits 1-9 without repetition.

        std::set<char> existNumberRow;
        std::set<char> existNumberColumn;
        for (int i = 0; i < board.size() && i < 9; i++)
        {
            existNumberRow.clear(); // clear all Row in this set before checking that j column
            // clear all colum numbers in this set before checking that j column
            for (int j = 0; j < board[i].size() && j < 9; j++)
            {
                if (board[i][j] != '.') // ignore dot and then check other elements
                {

                    if (existNumberRow.count(board[i][j])) // count will return 1 or 0 mean if number is already exist in set then 1(true) otherwise 0
                    {
                        return false; // check rows at least contain digits between 1-9
                    }
                    else
                    {
                        existNumberRow.insert(board[i][j]);
                    }
                }
            }
        }
        for (int i = 0; i < board.size() && i < 9; i++)
        {
            existNumberColumn.clear();
            // clear all colum numbers in this set before checking that j column
            for (int j = 0; j < board[i].size() && j < 9; j++)
            {
                if (board[j][i] != '.')
                {
                    if (existNumberColumn.count(board[j][i]))
                    { // check colums
                        return false;
                    }
                    else
                    {
                        existNumberColumn.insert(board[j][i]);
                    }
                }
            }
        }

        std::set<char> block[3][3];

        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
            {
                int blockRow = i / 3;    // it will divide mean in i=0, next i will 1 mean again 0 then in i=2 again 0
                int blockColumn = j / 3; //  same like row here j will 0,1,2.see in the commented diagram

                //        j →
                //        0 1 2 | 3 4 5 | 6 7 8
                //      --------------------------------
                // i=0   5 3 . | . 7 . | . . .
                // i=1   6 . . | 1 9 5 | . . .
                // i=2   . 9 8 | . . . | . 6 .
                //      --------------------------------
                // i=3   8 . . | . 6 . | . . 3
                // i=4   4 . . | 8 . 3 | . . 1
                // i=5   7 . . | . 2 . | . . 6
                //      --------------------------------
                // i=6   . 6 . | . . . | 2 8 .
                // i=7   . . . | 4 1 9 | . . 8
                // i=8   . . . | . 8 . | . 7 9
                if (board[i][j] != '.')
                {
                    if (block[blockRow][blockColumn].count(board[i][j]))
                    {
                        return false;
                    }
                    else
                        block[blockRow][blockColumn].insert(board[i][j]);
                }
            }
        }
        return true;
    }
};
int main()
{
    Solution sol;
    std::vector<std::vector<char>> board =
        {
            {'5', '3', '.', '.', '7', '.', '.', '.', '.'},
            {'6', '.', '.', '1', '9', '5', '.', '3', '.'},
            {'.', '9', '8', '.', '.', '.', '.', '.', '.'},
            {'8', '.', '.', '.', '6', '.', '.', '.', '.'},
            {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
            {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
            {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
            {'.', '.', '.', '4', '1', '9', '.', '.', '8'},
            {'.', '.', '.', '.', '8', '.', '.', '7', '9'}};
    std::cout << std::boolalpha << sol.isValidSudoku(board) << std::endl;

    return 0;
}