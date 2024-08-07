class Solution {
public:
    // same row upper col; lower col
    // same col upper row; lowerrow
    vector<pair<int, int>>directions = {{0,1} , {0,-1} , {1,0} , {-1,0}};

    void bfs(queue<pair<pair<int,int>,int>>&q, vector<vector<int>>& ans , vector<vector<int>>& visited, vector<vector<int>>& mat, int n , int  m) {
        
        while(!q.empty()){

            int currRow = q.front().first.first;
            int currCol = q.front().first.second;
            int currDistance = q.front().second;
            q.pop();

            visited[currRow][currCol] = 1;  // curr node marked visited
            ans[currRow][currCol] = currDistance;    


            for(auto it : directions){

                int nextRow = currRow + it.first;
                int nextCol = currCol + it.second; 
                
                if(0 <= nextRow && nextRow < m && 0 <= nextCol && nextCol < n && mat[nextRow][nextCol] == 1 && visited[nextRow][nextCol] == 0){

                    visited[nextRow][nextCol] = 1;
                    
                    q.push({{nextRow, nextCol},currDistance + 1});
                }
            }

        }

    }


    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();

        vector<vector<int>> visited(m, vector<int>(n, 0)); // visited vvi
        vector<vector<int>> ans(m , vector<int>(n, 0)); // ans vvi

        // queue will contain only those elements with their final smallest distances 
        queue<pair<pair<int,int>,int>>q;

        for(int i = 0; i < m ; i++){
            for(int j = 0; j < n ; j++){

                // firstly pushing only members with value = 0 like base cases
                if(mat[i][j] == 0){

                    // '0' elements have final distance = 0 and thus are pushed to queue
                    q.push({{i,j}, 0});
                    visited[i][j] = 1;
                }

            }
        }

        bfs(q, ans, visited, mat , n , m);
        return ans;
    }
};
