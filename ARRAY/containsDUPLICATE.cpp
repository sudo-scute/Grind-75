bool containsDuplicate(vector<int>& nums) {
        unordered_map<int , int> umap;
        for(int i = 0; i < nums.size(); i++){
            int ele = nums[i];
            umap[ele]++;
            if(umap[ele] >= 2){
                return true;
            }
        } 

        return false;
  }
