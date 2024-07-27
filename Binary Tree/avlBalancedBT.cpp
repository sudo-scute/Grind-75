// recursive fast solution to include height and isBalanced boolean value together 
// just going from top to bottom and checking if its balanced node or not

pair<bool, int> checkBALANCED(TreeNode* root) {
        // null nodes are balanced and their height = 0
        if (root == nullptr) {
            pair<bool, int> p = make_pair(true, 0);
            return p;
        }

        pair<bool, int> l = checkBALANCED(root->left); // checking left subtree
        pair<bool, int> r = checkBALANCED(root->right); // checking right subtree

        bool leftISbalanced = l.first;
        bool rightISbalanced = r.first;

        bool heightDifference = abs(l.second - r.second) <= 1;

        pair<bool, int> ans;

        ans.second = max(l.second, r.second) + 1; // simple height

        if (leftISbalanced && rightISbalanced && heightDifference) {
            ans.first = true;
        }

        return ans;
}

bool isBalanced(TreeNode* root) {
        pair<bool, int> ans = checkBALANCED(root);
        return ans.first;
}
