// converting binary tree into its mirror image
TreeNode* invertTree(TreeNode* root) {
        
        if(root == nullptr){return nullptr;}

        // swapping left and right TREENODE(completely)
        // this also lets them carry their children with them

        TreeNode* temp = root->left;
        root->left = root->right;
        root->right = temp;

        // now swapping for their own children
        invertTree(root->left);
        invertTree(root->right);

        return root;
}
