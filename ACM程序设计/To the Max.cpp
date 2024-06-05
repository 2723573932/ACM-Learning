#include <iostream>
#include <vector>
#include <climits>

int findMaxSubRectangle(const std::vector<std::vector<int> > &matrix)
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
    int n;
    std::cin>>n;
    std::vector<std::vector<int> > matrix(n, std::vector<int>(n, 0));
    for(int i = 0; i < n; ++i)
    {
        for(int j = 0; j < n; ++j)
        {
            std::cin>>matrix[i][j];
        }
    }
    int maxSum = findMaxSubRectangle(matrix);
    std::cout << maxSum << std::endl;

    return 0;
}