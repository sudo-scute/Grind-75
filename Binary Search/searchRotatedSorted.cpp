//binary search function
int binarySearch(vector<int>& nums,int s, int e, int target){


    int n = nums.size();
    int mid = s + (e - s)/2;
    while(s <= e){

        if(nums[mid] == target){
            return mid;
        }
        else if(nums[mid] < target){
            s = mid + 1;
        }
        else{
            e = mid - 1;
        }

        mid = s + (e - s)/2;

    }
    return -1;
}
// index of smallest element in rotated sorted array
int pivotELE(vector<int>& nums){

    int n = nums.size();
    int s = 0;
    int e = n-1;
    int mid = s +(e-s)/2;

    while(s < e){
        if(nums[mid] > nums[n-1]){
            s = mid + 1;
        }
        else{
            e = mid;
        }

        mid = s +(e-s)/2;
    }

    return s;
}

// driver code
int search(vector<int>& nums, int target) {
    int pivout = pivotELE(nums);
    int n = nums.size();
    if(nums[pivout] <= target && target <= nums[n-1]){
        return binarySearch(nums , pivout , n - 1 , target);
    }
    else{
        return binarySearch(nums , 0 , pivout - 1, target);
    }
}
