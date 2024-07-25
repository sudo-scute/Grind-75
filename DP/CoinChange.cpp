int coinChange(vector<int>& coins, int amount) {
        
        // min no. of coins to make amount  = ith index
        vector<int>dp(amount + 1, INT_MAX);

        dp[0] = 0;
         int n = coins.size();
        for( int amt = 1 ; amt <= amount; amt++){


            //hovering through whole changes array to make sum = amt
            for(int i = 0 ; i < n ; i++){

                // if the subtracted val is valid and and we have the dpval for it 
                if(amt - coins[i] >= 0  && dp[amt - coins[i]] != INT_MAX ){

                    dp[amt] = min(dp[amt] , dp[amt - coins[i]] + 1);
                }
            }

        }
        //finally
        if(dp[amount] != INT_MAX){
            return dp[amount];
        }
            return -1;
    }
