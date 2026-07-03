class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();

        int sum = 0;
        for(int i=0; i<n; i++) sum += nums[i];
        if(sum % 2) return false;

        sum = sum/2;
        vector<bool> prev(sum+1, 0);
        prev[0] = 0;
        if(nums[0] <= sum) prev[nums[0]] = true;


        for(int ind=1; ind<n; ind++){
            vector<bool> curr(sum+1, 0);
            curr[0] = 1;
            for(int target=1; target<=sum; target++){
                int notTake = prev[target];
                int take = false;
                if(nums[ind] <= target) take = prev[target-nums[ind]];

                curr[target] = take | notTake;
            }
            prev = curr;
        }

        return prev[sum];
    }
};