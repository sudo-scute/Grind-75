// solution using kadane's algorithm
    int maxSubArray(vector<int>& nums) {
        int maxsum = INT_MIN;
        int currSum = 0;

        for(int i = 0; i< nums.size() ; i++){
            currSum = currSum + nums[i];
            // updating the maxsum
            if(currSum > maxsum){
                maxsum = currSum;
            }
            // not including -ve currsum as it'll reduce the sum afterwards
            // its like cutoffing the subarray from including further elements
            if(currSum < 0){
                currSum = 0;
            }
        }
        return maxsum;
    }
