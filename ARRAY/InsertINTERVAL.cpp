#include<stack>
vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
    
        intervals.push_back(newInterval);
        stack<vector<int>> s;
        //custom sort function for vector of vector on basis of first element
        sort(intervals.begin() , intervals.end() , [] (vector<int> &a , vector<int> &b){
            return a[0] < b[0];
        });
        s.push(intervals[0]);
        for( int i = 1 ; i < intervals.size(); i++){

            vector<int>curr = intervals[i];
            vector<int> &tops = s.top();

            //if curr interval overlaps then merge
            if(curr[0] <= tops[1]){
                tops[1] = max(curr[1], tops[1]);
            }
            else{
                s.push(curr);
            }
        }


        intervals.clear(); // clearing all intervals in initial vector
        vector<int> tops;
        while(!s.empty()){
            tops = s.top();
            s.pop();
            intervals.push_back(tops); // insertion in same to save space
        }

        sort(intervals.begin() , intervals.end() , [] (vector<int> &a , vector<int> &b){
            return a[0] < b[0];
        });

        return intervals;
} 
