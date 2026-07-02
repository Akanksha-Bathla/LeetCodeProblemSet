class Solution {
// private:
//     int f(int i, int j, vector<vector<int>>& triangle, int n, vector<vector<int>>& dp){
//         if(i==n-1) return triangle[n-1][j];
//         if(dp[i][j] != -1) return dp[i][j];

//         int d = triangle[i][j] + f(i+1, j, triangle, n, dp);
//         int dg = triangle[i][j] + f(i+1, j+1, triangle, n, dp);
        
//         return dp[i][j] = min(d, dg);
//     }
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        // vector<vector<int>> dp(n, vector<int>(n, -1));
        vector<int> last(n, -1);
        for(int j=0; j<n; j++){
            last[j] = triangle[n-1][j];
        }

        for(int i=n-2; i>=0; i--){
            vector<int> curr(n, 0);
            for(int j=i; j>=0; j--){
                int d = triangle[i][j] + last[j];
                int dg = triangle[i][j] + last[j+1]; 

                curr[j] = min(d, dg);
            }
            last = curr;
        }
        return last[0];
    }
};