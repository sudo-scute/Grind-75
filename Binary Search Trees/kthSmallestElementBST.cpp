void inorderSmallest(TreeNode*& root, int k, int& count, int& result) {

        if (root == nullptr) {
            return;
        }

        // left subtree of bst gives smallest values
        inorderSmallest(root->left, k, count, result);

        // increase the count when got a null
        count++;

        if (count == k) {
            result = root->val;
            return;
        }

        // if count is not equal to k
        inorderSmallest(root->right, k, count, result);
}

    int kthSmallest(TreeNode* root, int k) {
        int count = 0; // no. of nodes
        int result = -1;

        inorderSmallest(root, k, count, result);

        return result;
    }
