class Solution {
// private:
//     int f(int ind, int sum, vector<int>& coins, vector<vector<int>>& dp){
//         if(ind==0){
//             if(sum%coins[0] == 0) return sum/coins[0];
//             return 1e9; 
//         }

//         if(dp[ind][sum] != -1) return dp[ind][sum];

//         int take = INT_MAX;
//         if(coins[ind] <= sum) take = 1 + f(ind, sum-coins[ind], coins, dp);

//         int notTake = f(ind-1, sum, coins, dp);

//         return dp[ind][sum] = min(take, notTake);
//     }
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        // vector<vector<int>> dp(n, vector<int>(amount+1, 1e9));
        vector<int> prev(amount+1, 0);

        for(int T=0; T<=amount; T++){
            if(T%coins[0] == 0) prev[T] = T/coins[0];
            else prev[T] = 1e9;
        }

        for(int ind=1; ind<n; ind++){
            for(int sum=0; sum<=amount; sum++){
                int take = INT_MAX;
                if(coins[ind] <= sum) take = 1 + prev[sum-coins[ind]];

                int notTake = prev[sum];
                prev[sum] = min(take, notTake);
            }
        }

        int ans = prev[amount];

        if(ans >= 1e9) return -1;
        return ans;
    }
};