int trap(vector<int>& height) {
        int n = height.size();
        if(n == 0){
            return 0;
        }
        vector<int>leftMAX(n); // stores the max height left bar upto that index 
        vector<int>rightMAX(n); // stores the max height right bar upto that index 

        leftMAX[0] = height[0];
        rightMAX[n-1] = height[n-1];

        for(int i = 1 ; i < n; i++){
            leftMAX[i] = max(height[i] , leftMAX[i-1]);
        }
        for(int i = n-2; i >= 0 ; i--){
            rightMAX[i] = max(height[i] , rightMAX[i+1]);
        }

        int ans = 0;
        for(int i = 0; i < n ;i++){
            ans += min(leftMAX[i] , rightMAX[i]) - height[i];
        }

        return ans;
}
