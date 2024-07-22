// simple sort 012 code using dutch national flag algorithm
void sortColors(vector<int>& nums) {
        // 0 to (lo - 1) index ==> 0
        // lo to (mid -1) index ==> 1
        // rest ==> 2

        int lo = 0;
        int mid = 0;
        int hi = nums.size() - 1;
        while(mid <= hi){
            if(nums[mid] == 0){
                swap(nums[lo++] , nums[mid++]);
            }
            else if(nums[mid] == 1){
                mid++;
            }
            else{
                swap(nums[mid] , nums[hi--]);
            }
        }

}
