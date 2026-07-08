class Solution {
private:
    int f(int ind, int sum, vector<int>& coins, vector<vector<int>>& dp){
        if(ind==0){
            if(sum%coins[0] == 0) return sum/coins[0];
            return 1e9; 
        }

        if(dp[ind][sum] != -1) return dp[ind][sum];

        int take = INT_MAX;
        if(coins[ind] <= sum) take = 1 + f(ind, sum-coins[ind], coins, dp);

        int notTake = f(ind-1, sum, coins, dp);

        return dp[ind][sum] = min(take, notTake);
    }
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount+1, -1));

        int ans = f(n-1, amount, coins, dp);

        if(ans >= 1e9) return -1;
        return ans;
    }
};