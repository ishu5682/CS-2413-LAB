#include <stdbool.h>

void dfs(char** grid, int gridSize, int* gridColSize, int i, int j) {
    if (i < 0 || i >= gridSize || j < 0 || j >= gridColSize[i] || grid[i][j] != '1') {
        return;
    }

    // Mark the current cell as visited by setting it to '0'
    grid[i][j] = '0';

    // Visit all four adjacent directions
    dfs(grid, gridSize, gridColSize, i + 1, j); // down
    dfs(grid, gridSize, gridColSize, i - 1, j); // up
    dfs(grid, gridSize, gridColSize, i, j + 1); // right
    dfs(grid, gridSize, gridColSize, i, j - 1); // left
}

int numIslands(char** grid, int gridSize, int* gridColSize){
    if (grid == NULL || gridSize == 0) return 0;

    int count = 0;
    for (int i = 0; i < gridSize; i++) {
        for (int j = 0; j < gridColSize[i]; j++) {
            if (grid[i][j] == '1') {
                count++;
                dfs(grid, gridSize, gridColSize, i, j);
            }
        }
    }

    return count;
}

