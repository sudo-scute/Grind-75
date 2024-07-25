bool isBST(TreeNode*& root, long long int mini, long long int maxi) {

        // base case
        if (root == nullptr) {
            return true;
        }

        if (root->val > mini && root->val < maxi) {

            // checking for subtrees
            bool le = isBST(root->left, mini, root->val);
            bool ri = isBST(root->right, root->val, maxi);

            return (le && ri);
        }

        // if even a single val doesnt lie in its range
        else {
            return false;
        }
}
bool isValidBST(TreeNode* root) {
        return isBST(root , INT64_MIN , INT64_MAX);
}
