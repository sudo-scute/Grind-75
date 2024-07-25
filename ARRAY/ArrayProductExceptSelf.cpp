vector<int> productExceptSelf(vector<int>& nums) {
        int len = nums.size();
        vector<int> prefix(len);
        int factor = 1;

        for (int i = 0; i < len; i++) {
            prefix[i] = factor;
            factor = factor * nums[i];
        }

        factor = 1;
        for (int i = len - 1; i >= 0; i--) {
            prefix[i] = prefix[i] * factor;
            factor = factor * nums[i];
        }

        return prefix;
}
