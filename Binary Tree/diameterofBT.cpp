// pair.first = diameter
//  pair.second = height

// The diameter of a binary tree is the length of the longest path between any two nodes in a tree.
pair<int, int> Dia(TreeNode* &root) {

        if (root == nullptr) {
            pair<int, int> p = make_pair(0 ,0 );
            return p;
        }

        pair<int, int> l = Dia(root->left); // longest path b/w nodes of left subtree  +  height of left subtree
        pair<int, int> r = Dia(root->right); // longest path b/w nodes of right subtree  +  height of right subtree

        // diameters
        int op1 = l.first;
        int op2 = r.first;

        int op3 = l.second + r.second;

        pair<int, int> ans;
        ans.first = max(op1, max(op2, op3));
        ans.second = max(l.second, r.second) + 1; 
        return ans;
}

int diameterOfBinaryTree(TreeNode* root) {
        pair<int, int> ans = Dia(root);
        return ans.first;
}
