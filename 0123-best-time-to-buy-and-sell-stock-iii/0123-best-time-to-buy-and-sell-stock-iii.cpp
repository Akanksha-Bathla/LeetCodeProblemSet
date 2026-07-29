class Solution {
private:
    int f(int ind, int transaction, vector<int>& prices, int n, vector<vector<int>>& dp){
        if(transaction == 4 || ind == prices.size()) return 0;
        if(dp[ind][transaction] != -1) return dp[ind][transaction];

        if(transaction%2 == 0) //buy
        { 
            return dp[ind][transaction] = max(-prices[ind] + f(ind+1, transaction+1, prices, n, dp),  
                                                f(ind+1, transaction, prices, n, dp));
        }
        return dp[ind][transaction] = max(prices[ind] + f(ind+1, transaction+1, prices, n, dp), 
                                            f(ind+1, transaction, prices, n, dp));
        
    }
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>>dp(n+1, vector<int>(5, 0));

        for(int ind=n-1; ind>=0; ind--){
            for(int transaction=3; transaction>=0; transaction--){
                if(transaction%2 == 0) //buy
                { 
                    dp[ind][transaction] = max(-prices[ind] + dp[ind+1][transaction+1],  
                                                        dp[ind+1][transaction]);
                }
                else {
                    dp[ind][transaction] = max(prices[ind] + dp[ind+1][transaction+1], 
                                                    dp[ind+1][transaction]);
                }
            }
        }
        return dp[0][0];
    }
};