// set max profit at index i by either include or exclude current ele
// include exclude recursion + dp
int incExc(int i, vector<vector<int>>&job , int n , vector<int>&dp , vector<int>&startTime){

    if(i >= n){
        return 0;
    }

    if(dp[i] != -1){
        return dp[i];
    }
    // inclusion
    // if include then find the index for next ele to pass the control to [ recursion ]
    int nextIndex = lower_bound(startTime.begin() , startTime.end() , job[i][1]) - startTime.begin();
  
    //exclusion
    int include = job[i][2] + incExc(nextIndex ,  job, n , dp , startTime);
    int exclude = incExc(i + 1, job, n , dp , startTime);
    dp[i] = max(include, exclude);
    return dp[i];
}

// driver code
int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
    vector<vector<int>>job;
    int n = startTime.size(); // no. of jobs
    for(int i = 0 ; i < n ; i++){
        job.push_back({startTime[i],endTime[i] , profit[i]});
    }
    // sorting jobs on basis of start time
    sort(job.begin(), job.end());

    sort(startTime.begin() , startTime.end()); // to find the index of next ele for passing the control over to 
    vector<int>dp(n , -1); // dp[i] stores the max profit starting from including ele of index i
    return incExc(0, job, n , dp , startTime);
}
