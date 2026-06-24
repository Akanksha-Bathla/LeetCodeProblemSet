class Solution {
private:
    // int f(int ind, vector<int>& arr, vector<int>& dp){
    //     if(ind == 0) return arr[0];
    //     if(ind < 0) return 0;
    //     if(dp[ind] != -1) return dp[ind];

    //     int pick = arr[ind] + f(ind-2, arr, dp);
    //     int notPick = 0 + f(ind-1, arr, dp); 

    //     return dp[ind] = max(pick, notPick);
    // }
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, -1);

        dp[0] = nums[0];
        for(int i=1; i<n; i++){
            int pick = nums[i];
            if(i > 1){
                pick = nums[i] + dp[i-2];
            }
            int notPick = 0 + dp[i-1];
            
            dp[i] = max(pick, notPick);
        }

        return dp[n-1];
        // return f(n-1, nums, dp);
    }
};