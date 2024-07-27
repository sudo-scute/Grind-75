TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
  
        if(root == nullptr || root == p || root == q){
            return root;
        }
        
        TreeNode* isNodePrsntLeft = lowestCommonAncestor(root->left, p, q);
        TreeNode* isNodePrsntRight = lowestCommonAncestor(root->right, p, q);

        // one node on left subtree and one on right subtree of root node 
        // root is the lowest common ancestor
        if(isNodePrsntLeft != nullptr && isNodePrsntRight != nullptr){
            return root;
        }
        // both nodes exists in left subtree
        else if(isNodePrsntLeft != nullptr){
            return isNodePrsntLeft;
        }
        // both in right subtree
        else{
            return isNodePrsntRight;
        }
}
