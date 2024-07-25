vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;
        int startRow = 0;
        int startCol = 0;
        int endRow = matrix.size() - 1;
        int endCol = matrix[0].size() - 1;

        int count = 0;
        int total = matrix.size() * matrix[0].size();

        while (count < total) {

            // printing starting row
            for (int i = startCol; i <= endCol && count < total; i++) {
                ans.push_back(matrix[startRow][i]);
                count++;
            }
            startRow++;

            // printing last COl
            for (int i = startRow; i <= endRow && count < total; i++) {
                ans.push_back(matrix[i][endCol]);
                count++;
            }
            endCol--;

            // printing last / bottom row
            for (int i = endCol; i >= startCol && count < total; i--) {
                ans.push_back(matrix[endRow][i]);
                count++;
            }
            endRow--;

            // printing first col from bottom to top
            for (int i = endRow; i >= startRow && count < total; i--) {
                ans.push_back(matrix[i][startCol]);
                count++;
            }
            startCol++;
        }

        return ans;
    }
