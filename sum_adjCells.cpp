#include <iostream>

const int MAX_SIZE = 100;

int main() {
    int R, C;
    std::cin >> R >> C;

    int grid[MAX_SIZE][MAX_SIZE];

    for (int row = 0; row < R; row++) {
        for (int col = 0; col < C; col++) {
            std::cin >> grid[row][col];
        }
    }

    int row, col;
    std::cin >> row >> col;

    int diff[8][2] = {
        {-1, -1}, {-1, 0}, {-1, 1},
        {0, -1},           {0, 1},
        {1, -1},  {1, 0},  {1, 1}
    };

    long long sum = 0;

    for (int i = 0; i < 8; i++) {
        int adjRow = row + diff[i][0];
        int adjCol = col + diff[i][1];

        if (adjRow >= 0 && adjRow < R && adjCol >= 0 && adjCol < C) {
            sum += grid[adjRow][adjCol];
        }
    }

    std::cout << sum << std::endl;

    return 0;
}
