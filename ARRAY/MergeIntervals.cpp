vector<vector<int>> merge(vector<vector<int>>& intervals) {
        
        vector<vector<int>> ans;
        //custom sort function for vector of vector on basis of first element
        sort(intervals.begin() , intervals.end() , [] (vector<int> &a , vector<int> &b){
            return a[0] < b[0];
        });
        ans.push_back(intervals[0]);
        for( int i = 1 ; i < intervals.size(); i++){

            vector<int>curr = intervals[i];
            vector<int>&tops = ans.back(); // last element of ans vector of vector

            //if curr interval overlaps then merge
            if(curr[0] <= tops[1]){
                tops[1] = max(curr[1], tops[1]);
            }
            else{
                ans.push_back(curr);
            }
        }
        return ans;

}
