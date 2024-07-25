// foundational include exclude problem 
void allSubsets(vector<int>& nums, vector<int>& temp, vector<vector<int>>& ans, int ind ,int n) {

        if (ind == n) {
            ans.push_back(temp);
            return;
        }

        // include current element
        temp.push_back(nums[ind]);
        allSubsets(nums, temp, ans, ind + 1 , n);

        // exclude the latestly added element after coming back from recursion
        temp.pop_back();
        // moving forward without that element  // exclusion case
        allSubsets(nums, temp, ans, ind + 1 , n);
    }

vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> temp;
        vector<vector<int>> ans;

        int n = nums.size();
        int ind = 0;
        allSubsets(nums, temp, ans, ind , n);
        return ans;
    }
