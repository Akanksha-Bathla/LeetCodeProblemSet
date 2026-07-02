class Solution {
// private:
//     int f(int i, int j, vector<vector<int>>& grid, int n, vector<vector<int>>& dp){
//         if(j<0 || j>=n) return 1e9;
//         if(i==0) return dp[i][j] = grid[i][j];

//         if(dp[i][j] != -1) return dp[i][j];

//         int next = 1e9;
//         dp[i][j] = 1e9;
//         for(int k=0; k<n; k++){
//             if(k==j) continue;
//             next = grid[i][j] + f(i-1, k, grid, n, dp);
//             dp[i][j] = min(dp[i][j], next);
//         }

//         return dp[i][j];
//     }
public:
    int minFallingPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));

        for(int j=0; j<n; j++){
            dp[0][j] = grid[0][j];
        }

        for(int i=1; i<n; i++){
            for(int j=0; j<n; j++){
                int next = 1e9;
                dp[i][j] = 1e9;
                for(int k=0; k<n; k++){
                    if(k==j) continue;
                    next = grid[i][j] + dp[i-1][k];
                    dp[i][j] = min(dp[i][j], next);
                }
            }

        }

        int mini = 1e9;
        for(int j=0; j<n; j++){
            // mini = min(f(n-1, j, grid, n, dp), mini);
            mini = min(dp[n-1][j], mini);
        }
        return mini;
    }
};