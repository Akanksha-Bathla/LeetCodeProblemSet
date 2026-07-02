class Solution {
private:
    int f(int i, int j, vector<vector<int>>& arr, vector<vector<int>>& dp){
        if(i==0 && j==0) return arr[i][j];
        if(i<0 || j<0) return INT_MAX;

        if(dp[i][j] != -1) return dp[i][j];


        int up = INT_MAX, left = INT_MAX;
        if(i>0) up = arr[i][j] + f(i-1, j, arr, dp);
        if(j>0) left = arr[i][j] + f(i, j-1, arr, dp);

        return dp[i][j] = min(up, left);
    }
public:
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> dp(n, vector<int>(m, -1));\
        return f(n-1, m-1, grid, dp);
    }
};