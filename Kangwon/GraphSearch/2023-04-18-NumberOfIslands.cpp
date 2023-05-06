#include <iostream>
#include <vector>

void DFS(std::vector<std::vector<bool>>& array, int col, int row);

int main()
{
    while (true)
    {
        int row, col;
        std::cin >> row >> col;
        if (row == 0 && col == 0) break;

        std::vector<std::vector<bool>> array(col, std::vector<bool>(row, false));
        int result = 0;
        for (int i = 0; i < col; i++)
        {
            for (int j = 0; j < row; j++)
            {
                int chk;
                std::cin >> chk;
                array[i][j] = chk;
            }
        }

        for (int i = 0; i < col; i++)
        {
            for (int j = 0; j < row; j++)
            {
                if (array[i][j])
                {
                    result++;
                    DFS(array, i, j);
                }
            }
        }

        std::cout << result << std::endl;

    }

    return 0;
}

void DFS(std::vector<std::vector<bool>>& array, int col, int row)
{
    if (array[col][row] == true)
    {
        array[col][row] = false;

        if (array[0].size() > row + 1)
        {
            DFS(array, col, row + 1);
        }

        if (row - 1 >= 0)
        {
            DFS(array, col, row - 1);
        }

        if (array.size() > col + 1)
        {
            DFS(array, col + 1, row);

            if (array[0].size() > row + 1)
            {
                DFS(array, col + 1, row + 1);
            }

            if (row - 1 >= 0)
            {
                DFS(array, col + 1, row - 1);
            }
        }
        if (col - 1 >= 0)
        {
            DFS(array, col - 1, row);

            if (array[0].size() > row + 1)
            {
                DFS(array, col - 1, row + 1);
            }

            if (row - 1 >= 0)
            {
                DFS(array, col - 1, row - 1);
            }
        }
    }
}
