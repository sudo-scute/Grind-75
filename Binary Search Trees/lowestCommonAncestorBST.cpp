TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        
    if (root == NULL)
    {
        return NULL;
    }

    // both p and q on right side
    if (root->val < p->val && root->val < q->val)
    {

        return lowestCommonAncestor(root->right, p, q);
    }

    // both p and q on left side
    if (root->val > p->val && root->val > q->val)
    {

        return lowestCommonAncestor(root->left, p, q);
    }

    // when root.data > p.data && root.data < q.data ==> means root is in the middle of p and q
    return root;
}
