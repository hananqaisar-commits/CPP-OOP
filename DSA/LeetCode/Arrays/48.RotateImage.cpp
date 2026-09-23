#include <iostream>
#include <vector>
class Solution
{
public:
    void rotate(std::vector<std::vector<int>> &matrix)

    {
        std::vector<std::vector<int>> copymatrix = matrix;
        int row = 0;
        for (int i = 0; i < matrix.size(); i++)
        {
            int column = 0;
            for (int j = (matrix[i].size() - 1); j >= 0; j--)
            {
                matrix[row][column] = copymatrix[j][row];
                column++;
            }
            row++;
        }
    }
};
int main()
{
    Solution *sol = new Solution();
    std::vector<std::vector<int>> array = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};

    sol->rotate(array);

    for (std::vector<int> x : array)
    {
        for (int value : x)
        {
            std::cout << value << " ";
        }
        std::cout << std::endl;
    }

    delete sol;
    return 0;
}