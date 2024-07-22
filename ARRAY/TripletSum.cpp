#include<set>
vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        set<vector<int>> sett;

        sort(nums.begin() , nums.end());
        for( int i = 0; i < n; i++){
            int j = i + 1;
            int k = n-1;
            while(j < k){
                if(nums[i] + nums[j] + nums[k] == 0){
                    sett.insert({nums[i], nums[j], nums[k]});
                    j++;
                    k--;
                }
                else if(nums[i] + nums[j] + nums[k] < 0){
                    j++;
                }
                else{
                    k--;
                }
            }
        }

        vector<vector<int>> ans;
        for(auto it : sett){
            ans.push_back(it);
        }

        return ans;
}
