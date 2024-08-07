class Solution {
public:
    // same row upper col; lower col
    // same col upper row; lowerrow
    vector<pair<int, int>>directions = {{0,1} , {0,-1} , {1,0} , {-1,0}};

    void bfs(int i, int j, int reqColor, int newColor, vector<vector<int>>& visited, vector<vector<int>>& image , int n , int  m) {

        visited[i][j] = 1; // current node marked visited
        queue<pair<int, int>>q;

        // at starting i and j are sr and sc thus firstnode is colored with newColor
        q.push({i, j});
        image[i][j] = newColor; 

        // now checking for its neighbours which have reqColor
        while(!q.empty()){

            int row = q.front().first;
            int col = q.front().second;
            q.pop();

            // checking for all possible valid directioned cells 
            for(auto it : directions){

                int nextRow = row + it.first;
                int nextCol = col + it.second;

                // checking if nextRow and nextCol are in bounds
                // checking if cell has reqColor
                // checking if cell is unvisited
                if(0 <= nextRow && nextRow < n && 0 <= nextCol && nextCol < m && image[nextRow][nextCol] == reqColor && visited[nextRow][nextCol] == 0){

                    visited[nextRow][nextCol] = 1;
                    image[nextRow][nextCol] = newColor; // colored to newColor
                    q.push({nextRow, nextCol});
                }

            }
            
        }


    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {

        int n = image.size();
        int m = image[0].size();

        // to check if cell is already visited or not
        vector<vector<int>> visited(n, vector<int>(m, 0));

        int reqColor = image[sr][sc]; // reqColor is the color of starting cell

        // if color of current cell is same as reqColor then recolor it to given (color)

        // bfs will first color the cells that are neighbour of cell if they match the conditions
        bfs(sr, sc, reqColor, color, visited, image , n , m);
        return image;
    }
};
