class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l=0;
        int h=nums.size()-1;

        while(l<=h){
            int mid = (l+h)/2;
            if(nums[mid] == target) return mid;
            else if(nums[l] <= nums[mid]){ // left sorted
                if(nums[l] <= target && nums[mid] > target){
                    h = mid-1;
                }else{
                    l = mid+1;
                }
            }else{ //right sorted
                if(nums[mid] < target && nums[h] >= target){
                    l = mid+1;
                }else{
                    h = mid-1;
                }
            }
        }
        return -1;
    }
};