// height -- max depth from root to farthest leaf node
int maxDepth(TreeNode* root) {
  
        //simply think of a single node
        if(root == nullptr){
            return 0;
        }
        int lef = maxDepth(root->left);
        int rig =maxDepth(root->right);
        return max(lef , rig) + 1;  // 1 added for root node
}
