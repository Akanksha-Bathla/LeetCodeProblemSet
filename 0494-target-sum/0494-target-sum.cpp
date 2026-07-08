class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int diff) {
        int n = nums.size();

        int sum = 0;
        for(int i=0; i<n; i++) sum += nums[i];

        int target = 0;
        if( (sum - diff)%2 == 0 && (sum - diff)>=0){
            target = (sum-diff)/2;
        }else{
            return 0;
        }

        vector<vector<int>> dp(n, vector<int>(target+1, 0));

        for(sum=0; sum<=target; sum++){
            if(sum == 0 && nums[0] == 0) dp[0][sum] = 2;
            else if(sum == 0 || sum == nums[0]) dp[0][sum] = 1;
            else dp[0][sum] = 0;
        }

        for(int ind = 1; ind<n; ind++){
            for(int sum = 0; sum<=target; sum++){
                int notTake = dp[ind-1][sum];
                int take = 0;
                if(nums[ind] <= sum) take = dp[ind-1][sum - nums[ind]];
                dp[ind][sum] = take + notTake;
            }
        }

        return dp[n-1][target];
    }
};