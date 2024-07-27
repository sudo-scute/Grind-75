
void solve(TreeNode* root , vector<int> &ans , int level){

        if(!root){
            return;
        }

        if(ans.size() == level){
            ans.push_back(root->val);
        }

        solve(root->right , ans , level + 1);
        solve(root->left , ans , level + 1);

}

vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        solve(root, ans, 0);
        return ans;
}
