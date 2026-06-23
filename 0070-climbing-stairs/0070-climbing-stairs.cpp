class Solution {
private:
    int solve(int n, vector<int>& dp){
        if(n <= 1) return 1;
        if(dp[n] != -1) return dp[n];

        return dp[n] = solve(n-1, dp) + solve(n-2, dp);
    }
public:
    int climbStairs(int n) {
        // vector<int> dp(n+1, -1);
        // dp[0] = 1;
        // dp[1] = 1;
        int prev2 = 1; //0th stair
        int prev = 1; // 1st stair

        for(int i=2; i<=n; i++){
            // dp[i] = dp[i-1] + dp[i-2];
            int curr = prev + prev2;
            prev2 = prev;
            prev = curr;
        }
        return prev;
    }
};