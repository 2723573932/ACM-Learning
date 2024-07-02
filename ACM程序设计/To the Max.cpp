#include <iostream>
#include <vector>
#include <climits>

int findMaxSubRectangle(const std::vector<std::vector<int>> &matrix)
{
    int rows = matrix.size();
    int cols = matrix[0].size();

    int maxSum = INT_MIN;

    for (int left = 0; left < cols; ++left)
    {
        std::vector<int> temp(rows, 0);

        for (int right = left; right < cols; ++right)
        {
            for (int i = 0; i < rows; ++i)
            {
                temp[i] += matrix[i][right];
            }

            int currentSum = 0;
            int maxEndingHere = 0;

            for (int i = 0; i < rows; ++i)
            {
                maxEndingHere = std::max(maxEndingHere + temp[i], temp[i]);
                currentSum = std::max(currentSum, maxEndingHere);
            }

            maxSum = std::max(maxSum, currentSum);
        }
    }

    return maxSum;
}

int main()
{
    std::vector<std::vector<int>> matrix = {
        {0, -2, -7, 0},
        {9, 2, -6, 2},
        {-4, 1, -4, 1},
        {-1, 8, 0, -2}};

    int maxSum = findMaxSubRectangle(matrix);
    std::cout << maxSum << std::endl;

    return 0;
}