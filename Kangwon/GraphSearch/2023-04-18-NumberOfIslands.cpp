#include <iostream>
#include <vector>

void BFS(std::vector<std::vector<bool>>& array, int col, int row);

int main() {
    int row, col;
    std::cin >> col >> row;
    std::vector<std::vector<bool>> array(col, std::vector<bool>(row, false));

    for (int i = 0; i < col; i++) {
        for (int j = 0; j < row; j++) {
            int chk;
            std::cin >> chk;
            array[i][j] = chk;
        }
    }

    for (int i = 0; i < col; i++) {
        for (int j = 0; j < row; j++) {
            BFS(array, i, j);
        }
    }

    return 0;
}

void BFS(std::vector<std::vector<bool>>& array, int col, int row) {
    
    if (array[col][row]) {
        array[col][row] = false;
        if (array.size() > col+1) {
            BFS(array, col + 1, row);
        }
        if (array[0].size() > row+1) {
            BFS(array, col, row + 1);
        }
    }
}
