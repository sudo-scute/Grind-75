class Solution {
public:

    vector<pair<int, int>> directions = {{0,1} , {0,-1} , {1,0} , {-1, 0}};

    void bfs(vector<vector<int>>& grid, queue<pair<int, int>>&q, int &fresh , int &minutes , int m , int n){
    
        while (!q.empty()) {
            int size = q.size();
            bool isOne = false;

            // one more loop to traverse queue to just work on a fixed condition of queue
            for (int i = 0; i < size; ++i) {
                int r = q.front().first;
                int c = q.front().second;
                q.pop();

                for (auto it : directions) {
                    int nR = r + it.first;
                    int nC = c + it.second;
                    if (0 <= nR && nR < m && 0 <= nC && nC < n && grid[nR][nC] == 1) {
                        grid[nR][nC] = 2; // conversion
                        fresh--;
                        q.push({nR, nC});
                        isOne = true;
                    }
                }
            }

            if (isOne) {
                minutes++;
            }
        }
    }

    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        queue<pair<int, int>>q;

        int fresh = 0; // number of ones ( fresh oranges )
        int minutes = 0;

        for(int i = 0 ; i < m;i++){
            for(int j = 0; j < n ; j++){
                // means its rotting orange
                if(grid[i][j] == 2){
                    q.push({i, j});
                }
                else if(grid[i][j] == 1){
                    fresh++;
                }
            }
        }

        if(fresh == 0){
            return 0;
        }
        if(q.empty()){
            return -1;
        }
        bfs(grid,q,fresh ,minutes , m , n);

        // if number of fresh oranges initially == 0
        if(fresh == 0){
            return minutes;
        }
        else{
            // means all fresh oranges can not get rotten finally
            return -1;
        }
    }
};
