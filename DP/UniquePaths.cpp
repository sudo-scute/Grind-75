int uniquePaths(int m, int n) {
  
        // this dp vector stores the no. of unique paths to reach dp[i][j] element / position
        vector<vector<int>>dp(m, vector<int>(n, 0));
        dp[0][0] = 0; // 0 path to reach it

        // we can reach first row elements by simply pressing right
        for(int i = 0 ; i < n ; i++){
            dp[0][i] = 1;
        }

        // similarly for first column we can reach it by just pressing down
        for(int i = 0 ; i < m ; i++){
            dp[i][0] = 1;
        }

        // filling for the other entries

        // we can reach to a cell from previous cell of same row and also from above cell of same col 
        for(int i = 1 ; i < m ; i++ ){
            for(int j = 1 ; j < n ; j++){
                dp[i][j] = dp[i-1][j] + dp[i][j-1];
            }
        }

        return dp[m-1][n-1];
}
