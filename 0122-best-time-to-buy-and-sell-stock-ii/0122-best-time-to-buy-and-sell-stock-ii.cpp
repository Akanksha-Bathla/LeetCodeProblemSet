class Solution {
private:
    int f(int ind, int buy, vector<int>& arr, int n, vector<vector<int>> &dp){
        if(ind == n) return 0;

        if(dp[ind][buy] != -1) return dp[ind][buy];

        int profit = 0;
        if(buy){
            profit = max(-arr[ind] + f(ind+1, 0, arr, n, dp), f(ind+1, 1, arr, n, dp));
        }
        else{
            profit = max(arr[ind] + f(ind+1, 1, arr, n, dp), f(ind+1, 0, arr, n, dp));
        }

        return dp[ind][buy] = profit;
    }
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();

        vector<vector<int>> dp(n+1, vector<int>(2, 0));
        dp[n][0] = dp[n][1] = 0;

        for(int i=n-1; i>=0; i--){
            for(int b=0; b<2; b++){
                int profit = 0;
                if(b) profit = max(-prices[i] + dp[i+1][0], dp[i+1][1]);
                else profit = max(prices[i] + dp[i+1][1], dp[i+1][0]);
                dp[i][b] = profit;
            }
        }

        return dp[0][1];
    }
};