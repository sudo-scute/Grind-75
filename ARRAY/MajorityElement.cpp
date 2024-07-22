int majorityElement(vector<int>& nums) {
        map<int, int> mapi;
        int n = nums.size();
        for(int i = 0 ; i < n; i++){
            mapi[nums[i]]++;
            if(mapi[nums[i]] > (n/2)){
                return nums[i];
            }
        }
        return -1;
}
