void permutationString(vector<int>& nums, vector<vector<int>>& ans, int ind) {

        if (ind >= nums.size()) {
            ans.push_back(nums);
            return;
        }

        for (int i = ind; i < nums.size(); i++) {
            swap(nums[ind], nums[i]);
            permutationString(nums, ans, ind + 1);
            swap(nums[ind], nums[i]);   // after coming back from recursion putting the element into its original posi.
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {

        vector<vector<int>> ans;
        int ind = 0;

        permutationString(nums, ans, ind);
        return ans;
    }
