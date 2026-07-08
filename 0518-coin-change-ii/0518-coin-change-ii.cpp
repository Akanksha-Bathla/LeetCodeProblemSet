class Solution {
private:
    int f(int ind, int sum, vector<int>& coins, vector<vector<int>>& dp){
        if(sum == 0) return 1;
        if(ind == 0){
            if(sum % coins[0] == 0) return 1;
            return 0;
        }
        if(dp[ind][sum] != -1) return dp[ind][sum];

        int notTake = f(ind-1, sum, coins, dp);
        int take = 0;
        if(sum >= coins[ind]) take = f(ind, sum-coins[ind], coins, dp);

        return dp[ind][sum] = take + notTake;
    }
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();

        vector<vector<int>> dp(n, vector<int>(amount+1, -1));

        // for(int ind=0; ind<n; ind++) dp[ind][0] = 1;
        // for(int sum=0; sum<=amount; sum++){
        //     if(sum % coins[0] == 0) dp[0][sum] = 1;
        //     else dp[0][sum] = 0;
        // } 

        // for(int ind=1; ind<n; ind++){
        //     for(int sum=0; sum<=amount; sum++){
        //         long long notTake = dp[ind-1][sum];
        //         long long take = 0;
        //         if(sum >= coins[ind]) take = dp[ind][sum-coins[ind]];

        //         dp[ind][sum] = take + notTake;
        //     }
        // }


        return f(n-1, amount, coins, dp);
    }
};