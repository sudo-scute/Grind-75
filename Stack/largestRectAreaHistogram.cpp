// index of first smaller element than the current element 
    vector<int>rightSmaller(vector<int>& heights , int n){
        stack<int> s;
        s.push(-1);
        vector<int>ans(n);
        //filling out from right to left for elements
        for(int i = n-1 ; i >= 0 ; i--){
            int curr = heights[i];
            while(s.top() != -1 && heights[s.top()] >= curr){

                // popping the elements from stack which are bigger than curr (means they r useful)
                // and then finally getting the index for first smaller element
                s.pop();
            }
            ans[i] = s.top();
            s.push(i);
        }

        return ans;
    }


    // index of first smaller element on left side than the current element 
    vector<int>leftSmaller(vector<int>& heights , int n){
        stack<int> s;
        s.push(-1);
        vector<int>ans(n);
        //filling out from right to left for elements
        for(int i = 0; i<n ; i++){
            int curr = heights[i];
            while(s.top() != -1 && heights[s.top()] >= curr){

                // popping the elements from stack which are bigger than curr (means they r useful)
                // and then finally getting the index for first smaller element
                s.pop();
            }
            ans[i] = s.top();
            s.push(i);
        }

        return ans;
    }



    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int>left = leftSmaller(heights ,  n);
        vector<int>right = rightSmaller(heights ,  n);

        int ans = INT_MIN;
        int temp = 0;
        for(int i = 0 ; i < n; i++){
            if(right[i] == -1){
                right[i] = n;
            }
            temp = heights[i] * (right[i] - left[i] - 1);
            ans = max(ans , temp);
            temp = 0;
        }
        return ans;
    }
