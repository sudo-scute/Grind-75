// each row takes only 1 level
vector<vector<int>> levelOrder(TreeNode* root) {
  
        vector<vector<int>> ans;
        queue<TreeNode*> q;
        if (root != nullptr) {
            q.push(root);
        } else {
            return ans;
        }
        q.push(nullptr);

        vector<int> arr; // for storing a single level
        while (!q.empty()) {
          
            TreeNode* temp = q.front();
            q.pop();

            // a level is completed
            if (temp == nullptr) {
                ans.push_back(arr); // pushing current level vector in ans
                arr.clear();      // clearing vector for new level
                if (!q.empty()) {
                    q.push(nullptr);
                }
            } 
            else {
                arr.push_back(temp->val);
                
                if (temp->left != nullptr) {
                    q.push(temp->left);
                }
                if (temp->right != nullptr) {
                    q.push(temp->right);
                }
            }
        }

        return ans;
}
