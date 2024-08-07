class Solution {
public:
    // again similar question like flood fills where we have to color the
    // neighbouring nodes of starting node to some color

    // and here we have to move till we are getting '1' ( land )

    vector<pair<int, int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

    // void bfs(vector<vector<char>>& grid, queue<pair<int, int>>& q, int m,
    //          int n) {

    //     // now checking for its neighbours which have value == 1
    //     while (!q.empty()) {

    //         // current land
    //         int row = q.front().first;
    //         int col = q.front().second;
    //         q.pop();

    //         grid[row][col] = '0';

    //         for (auto it : directions) {

    //             int nextRow = row + it.first;
    //             int nextCol = col + it.second;

    //             if (0 <= nextRow && nextRow < m && 0 <= nextCol &&
    //                 nextCol < n && grid[nextRow][nextCol] == '1') {

    //                 q.push({nextRow, nextCol});
    //             }
    //         }
    //     }
    // }

    int numIslands(vector<vector<char>>& grid) {

        int numOFislands = 0;

        queue<pair<int, int>> q;

        int m = grid.size();
        int n = grid[0].size();

        // in flood fills problem we had only 1 bfs call with sr and sc

        // but here we need to go through each cell to check its an island or
        // not
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {

                if (grid[i][j] == '1') {
                    numOFislands++;
                    q.push({i, j});
                    while (!q.empty()) {

                        auto [x, y] = q.front();
                        q.pop();

                        if (x < 0 || x >= m || y < 0 || y >= n ||
                            grid[x][y] != '1') {
                            continue;
                        } else {
                            grid[x][y] = '0';
                            for (auto& it : directions) {

                                int nextRow = x + it.first;
                                int nextCol = y + it.second;

                                if (0 <= nextRow && nextRow < m &&
                                    0 <= nextCol && nextCol < n &&
                                    grid[nextRow][nextCol] == '1') {

                                    q.push({nextRow, nextCol});
                                }
                            }
                        }
                    }
                }
            }
        }

        return numOFislands;
    }
};
