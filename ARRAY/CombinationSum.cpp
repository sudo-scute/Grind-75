void solve(vector<int>& temp, int ind, vector<int>& candidates, int target,
               vector<vector<int>>& ans) {

        if(target == 0){
            ans.push_back(temp);
            return;
        }

        if(target < 0 || ind == candidates.size()){
            return;
        }
        temp.push_back(candidates[ind]);
        solve(temp,ind,candidates,target - candidates[ind],ans);
        temp.pop_back();
        solve(temp,ind + 1,candidates,target,ans);
}

vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> temp;
        solve(temp,0,candidates,target,ans);
        return ans;
}
