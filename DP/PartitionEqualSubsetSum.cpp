 // recur + memo
    bool solve(vector<int> &nums , int ind , int totalsum , int n ,vector<vector<int>> &dp){

        // base cases
        if(ind >= n ){
            return 0;
        }
        if(totalsum < 0){
            return 0;
        }   
        // after incl or excl we got the elmnts which totalsum = 0 :)
        if(totalsum == 0){
            return 1;
        }

        // step 3
        if(dp[ind][totalsum] != -1){
            return dp[ind][totalsum];
        }
        // inclusion
        bool incl = solve(nums , ind + 1 , totalsum - nums[ind] , n , dp);
        // exclusion
        bool excl = solve(nums , ind + 1 , totalsum , n , dp);
        dp[ind][totalsum] = (incl || excl); // if by including or excluding we get the result we are happy
        return dp[ind][totalsum];
    }
    bool canPartition(vector<int>& nums) {
        int totalsum = 0;

        for(auto it : nums){
            totalsum += it;
        }
        
        if(totalsum % 2 != 0){
            // odd totalsum cant be created 
            return false;
        }
        totalsum = totalsum /2;
        int n = nums.size();

        vector<vector<int>> dp(n , vector<int>(totalsum + 1 , -1));
        return solve(nums , 0 , totalsum , n , dp);
    }
};
