class Solution {
public:

    bool canMakeWord(int i, int j, int wordIndex, string& word,
                     vector<vector<char>>& board,
                     vector<vector<int>>& visited) {

        // base cases

        if (wordIndex == word.size()) {
            return true; // word is completed
        }

        // conditions priority
        // 1. out of bounds
        // 2. visited or not
        // 3. char doesnot match
        if (i < 0 || i >= board.size() || j < 0 || j >= board[0].size() ||
            visited[i][j] == 1 || board[i][j] != word[wordIndex]) {
            return false;
        }

        visited[i][j] = 1;

        bool ans =
            (canMakeWord(i, j + 1, wordIndex + 1, word, board, visited) ||
             canMakeWord(i, j - 1, wordIndex + 1, word, board, visited) ||
             canMakeWord(i + 1, j, wordIndex + 1, word, board, visited) ||
             canMakeWord(i - 1, j, wordIndex + 1, word, board, visited));

    
        // backtracking

        // this part runs when returning back from base case
        visited[i][j] = 0; // to resuse the visited chars
        return ans;
    }

    bool exist(vector<vector<char>>& board, string word) {

        int m = board.size();
        int n = board[0].size();

        vector<vector<int>> visited(m, vector<int>(n, 0));

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {

                if (board[i][j] == word[0] &&
                    canMakeWord(i, j, 0, word, board, visited)) {

                    return true;
                };
            }
        }

        return false;
    }
};
